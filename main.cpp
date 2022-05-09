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

int main(void) {
  setbuf(stdin, NULL), setbuf(stdout, NULL);

  unordered_map<int, int> subs;
  int cur_page = 0;
  bool root_sus = false;
  bool pedal = false;

  struct input_event event;
  while (fread(&event, sizeof(event), 1, stdin) == 1) {
    if (event.type == EV_KEY) {
      if (event.value == 1) {
        if (cur_page == 0) {
          if (REALBOOK.find(event.code) != REALBOOK.end()) {
            cur_page = event.code;
            root_sus = true;
            pedal = false;
          } else {
            fwrite(&event, sizeof(event), 1, stdout);
          }
        } else {
          auto page = REALBOOK.at(cur_page);
          if (page.find(event.code) != page.end()) {
            int fake_code = page.at(event.code);
            subs[event.code] = fake_code & MASK_KEY;
            event.code = fake_code;
          }
          if (event.code & SHIFT) {
            event.code ^= SHIFT;
            fwrite(&shift_down, sizeof(event), 1, stdout);
            fwrite(&syn, sizeof(event), 1, stdout);
            usleep(20000);
            fwrite(&event, sizeof(event), 1, stdout);
            fwrite(&syn, sizeof(event), 1, stdout);
            usleep(20000);
            fwrite(&shift_up, sizeof(event), 1, stdout);
          } else {
            fwrite(&event, sizeof(event), 1, stdout);
          }

          if (!root_sus)
            cur_page = 0;
          else
            pedal = true;
        }
      } else if (event.value == 0) {

        if (event.code == cur_page) {
          root_sus = false;
          if (pedal)
            cur_page = 0;

        } else if (subs.find(event.code) != subs.end()) {
          int real_code = event.code;
          event.code = subs[real_code];
          subs.erase(real_code);
          fwrite(&event, sizeof(event), 1, stdout);
        } else
          fwrite(&event, sizeof(event), 1, stdout);
      }
    } else if (event.type == EV_MSC && event.code == MSC_SCAN) {
      // pass
    } else {
      fwrite(&event, sizeof(event), 1, stdout);
    }
  }
}
