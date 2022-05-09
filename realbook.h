// clang-format off
#include <linux/input.h>
#include <unordered_map>

typedef __u16 key;

#define SHIFT    0x1000
#define MASK_KEY 0x0fff

#define IS_MOD(code) code == KEY_LEFTSHIFT || code == KEY_RIGHTSHIFT || \
                     code == KEY_LEFTCTRL  || code == KEY_RIGHTCTRL  || \
                     code == KEY_LEFTALT   || code == KEY_RIGHTALT
                     // code == KEY_LEFTMETA  || code == KEY_RIGHTMETA

const std::unordered_map<key, key> J_PAGE = {
  {KEY_Q         , KEY_Q                 },
  {KEY_W         , KEY_J                 },
  {KEY_E         , KEY_MINUS      | SHIFT},
  {KEY_R         , KEY_EQUAL      | SHIFT},
  {KEY_T         , KEY_GRAVE      | SHIFT},
  {KEY_A         , KEY_Y                 },
  {KEY_S         , KEY_B                 },
  {KEY_D         , KEY_MINUS             },
  {KEY_F         , KEY_EQUAL             },
  {KEY_G         , KEY_GRAVE             },
  {KEY_Z         , KEY_Z                 },
  {KEY_X         , KEY_X                 },
  {KEY_C         , KEY_I                 },
  {KEY_V         , KEY_P                 },

  {KEY_I         , KEY_LEFTBRACE  | SHIFT},
  {KEY_O         , KEY_RIGHTBRACE | SHIFT},
  {KEY_P         , KEY_BACKSLASH  | SHIFT},
  {KEY_K         , KEY_9          | SHIFT},
  {KEY_L         , KEY_0          | SHIFT},
  {KEY_SEMICOLON , KEY_BACKSLASH         },
  {KEY_COMMA     , KEY_LEFTBRACE         },
  {KEY_DOT       , KEY_RIGHTBRACE        },
  {KEY_SLASH     , KEY_RIGHTSHIFT        },
};

const std::unordered_map<key, key> X_PAGE = {
  {KEY_F         , KEY_RIGHTMETA},
  {KEY_Z         , KEY_RIGHTCTRL},
  {KEY_C         , KEY_RIGHTALT},

  {KEY_U         , KEY_HOME},
  {KEY_I         , KEY_PAGEDOWN},
  {KEY_O         , KEY_PAGEUP},
  {KEY_P         , KEY_END},
  {KEY_J         , KEY_LEFT},
  {KEY_K         , KEY_DOWN},
  {KEY_L         , KEY_UP},
  {KEY_SEMICOLON , KEY_RIGHT},
  {KEY_N         , KEY_BACKSPACE},
  {KEY_M         , KEY_DELETE},
  {KEY_COMMA     , KEY_7|SHIFT},
  {KEY_DOT       , KEY_8|SHIFT},
};

const std::unordered_map<key, key> Z_PAGE = {
  {KEY_D         , KEY_ESC},
  {KEY_X         , KEY_TAB},
  {KEY_C         , KEY_ENTER},

  {KEY_U         , KEY_0},
  {KEY_I         , KEY_1},
  {KEY_O         , KEY_2},
  {KEY_P         , KEY_3},
  {KEY_LEFTBRACE , KEY_4},
  {KEY_H         , KEY_1|SHIFT},
  {KEY_J         , KEY_2|SHIFT},
  {KEY_K         , KEY_3|SHIFT},
  {KEY_L         , KEY_4|SHIFT},
  {KEY_SEMICOLON , KEY_5|SHIFT},
  {KEY_APOSTROPHE, KEY_6|SHIFT},
  {KEY_N         , KEY_5},
  {KEY_M         , KEY_6},
  {KEY_COMMA     , KEY_7},
  {KEY_DOT       , KEY_8},
  {KEY_SLASH     , KEY_9},
};

const std::unordered_map<key, key> Q_PAGE = {
  {KEY_W         , KEY_PREVIOUSSONG},
  {KEY_E         , KEY_PLAYPAUSE},
  {KEY_R         , KEY_NEXTSONG},
  {KEY_S         , KEY_MUTE},
  {KEY_D         , KEY_VOLUMEDOWN},
  {KEY_F         , KEY_VOLUMEUP},

  {KEY_U         , KEY_BRIGHTNESSDOWN},
  {KEY_I         , KEY_BRIGHTNESSUP},
  {KEY_O         , KEY_F1},
  {KEY_P         , KEY_F2},
  {KEY_LEFTBRACE , KEY_F3},
  {KEY_H         , KEY_F4},
  {KEY_J         , KEY_F5},
  {KEY_K         , KEY_F6},
  {KEY_L         , KEY_F7},
  {KEY_SEMICOLON , KEY_F8},
  {KEY_APOSTROPHE, KEY_F9},
  {KEY_N         , KEY_F10},
  {KEY_M         , KEY_F11},
  {KEY_COMMA     , KEY_F12},
  {KEY_DOT       , KEY_INSERT},
  {KEY_SLASH     , KEY_PRINT},
};

const std::unordered_map<key, std::unordered_map<key, key>> REALBOOK = {
    {KEY_J, J_PAGE},
    {KEY_X, X_PAGE},
    {KEY_Z, Z_PAGE},
    {KEY_Q, Q_PAGE},
};
// clang-format on