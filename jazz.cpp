#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unordered_map>

#include "realbook.h"

using namespace std;

// clang-format off
const input_event
syn =        {.type = EV_SYN, .code = SYN_REPORT    , .value = 0},
shift_down = {.type = EV_KEY, .code = KEY_RIGHTSHIFT, .value = 1},
shift_up   = {.type = EV_KEY, .code = KEY_RIGHTSHIFT, .value = 0};
// clang-format on

enum mod_state {
  attack,
  sustain,
  release,
};

static unordered_map<key, mod_state> modifiers;
static key cur_page = 0;
static mod_state root_state;

// Emit a keypress and do associated state updates
// for the root and modifiers.
void emit(const input_event &event) {
  fwrite(&event, sizeof(event), 1, stdout);

  if (IS_MOD(event.code)) {

    if (modifiers[event.code] == release) {
      modifiers.erase(event.code);
    } else
      modifiers[event.code] = attack;

  } else {
    auto itr = modifiers.begin();
    while (itr != modifiers.end()) {
      switch (itr->second) {
      case attack:
        itr->second = sustain;
      case sustain:
        itr++;
        break;
      case release:
        input_event rel = {.type = EV_KEY, .code = itr->first, .value = 0};
        fwrite(&rel, sizeof(rel), 1, stdout);
        itr = modifiers.erase(itr);
        break;
      }
    }

    switch (root_state) {
    case attack:
      root_state = sustain;
      break;
    case sustain:
      break;
    case release:
      cur_page = 0;
      break;
    }
  }
}

int main(void) {
  setbuf(stdin, NULL), setbuf(stdout, NULL);

  unordered_map<key, key> subs;

  struct input_event event;
  while (fread(&event, sizeof(event), 1, stdin) == 1) {
    if (event.type == EV_KEY) {
      if (event.value == 1) { // Key down

        if (cur_page == 0) { // Normal typing
          if (REALBOOK.find(event.code) != REALBOOK.end()) {
            cur_page = event.code;
            root_state = attack;
          } else {
            emit(event);
          }

        } else if (event.code == cur_page) { // Press root again to cancel
          cur_page = 0;

        } else {
          auto page = REALBOOK.at(cur_page);
          if (page.find(event.code) != page.end()) {
            key fake_code = page.at(event.code);
            subs[event.code] = fake_code & MASK_KEY;
            event.code = fake_code;
            // As a special case, if we enter a modifier from a chord
            // then we still have to progress the root state.
            if (IS_MOD(fake_code))
              switch (root_state) {
              case attack:
                root_state = sustain;
                break;
              case sustain:
                break;
              case release:
                cur_page = 0;
                break;
              }
          }

          if (event.code & SHIFT) {
            event.code ^= SHIFT;
            fwrite(&shift_down, sizeof(event), 1, stdout);
            // fwrite(&syn, sizeof(event), 1, stdout);
            // usleep(20000);
            emit(event);
            // fwrite(&syn, sizeof(event), 1, stdout);
            // usleep(20000);
            fwrite(&shift_up, sizeof(event), 1, stdout);
          } else {
            emit(event);
          }
        }
      } else if (event.value == 0) { // Key up

        if (event.code == cur_page) { // Root state transitions
          switch (root_state) {
          case attack:
            root_state = release;
            break;
          case sustain:
            cur_page = 0;
            break;
          case release:
            break;
          }

        } else {
          if (subs.find(event.code) != subs.end()) { // Make substitutions
            key real_code = event.code;
            event.code = subs[real_code];
            subs.erase(real_code);
          }

          if (modifiers.find(event.code) != // Modifier state transitions
              modifiers.end()) {
            switch (modifiers[event.code]) {
            case attack:
              modifiers[event.code] = release;
              break;
            case sustain:
              fwrite(&event, sizeof(event), 1, stdout);
              modifiers.erase(event.code);
              break;
            case release:
              break;
            }

          } else // Normal or substituted
            fwrite(&event, sizeof(event), 1, stdout);
        }
      }
    } else if (event.type == EV_MSC && event.code == MSC_SCAN) {
      // pass
    } else {
      fwrite(&event, sizeof(event), 1, stdout);
    }
  }
}
