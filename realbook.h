#pragma once
#include <linux/input.h>
#include <unordered_map>

typedef __u16 key;

#define SHIFT    0x1000
#define MASK_KEY 0x0fff

// clang-format off
#define IS_MOD(code) code == KEY_LEFTSHIFT || code == KEY_RIGHTSHIFT || \
                     code == KEY_LEFTCTRL  || code == KEY_RIGHTCTRL  || \
                     code == KEY_LEFTALT   || code == KEY_RIGHTALT
                     // code == KEY_LEFTMETA  || code == KEY_RIGHTMETA

const std::unordered_map<key, key> J_PAGE = {
  {KEY_Q         , KEY_Q                 },
  {KEY_W         , KEY_6          | SHIFT},
  {KEY_E         , KEY_MINUS      | SHIFT},
  {KEY_R         , KEY_EQUAL      | SHIFT},
  {KEY_T         , KEY_GRAVE      | SHIFT},
  {KEY_A         , KEY_7          | SHIFT},
  {KEY_S         , KEY_8          | SHIFT},
  {KEY_D         , KEY_MINUS             },
  {KEY_F         , KEY_EQUAL             },
  {KEY_G         , KEY_GRAVE             },
  {KEY_Z         , KEY_Z                 },
  {KEY_X         , KEY_X                 },
  {KEY_C         , KEY_4          | SHIFT},
  {KEY_V         , KEY_5          | SHIFT},

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
  {KEY_F         , KEY_LEFTMETA },
  {KEY_Z         , KEY_RIGHTALT },
  {KEY_C         , KEY_RIGHTCTRL},

  {KEY_U         , KEY_ESC      },
  {KEY_I         , KEY_BACKSPACE},
  {KEY_O         , KEY_DELETE   },
  {KEY_H         , KEY_TAB      },
  {KEY_J         , KEY_LEFT     },
  {KEY_K         , KEY_DOWN     },
  {KEY_L         , KEY_UP       },
  {KEY_SEMICOLON , KEY_RIGHT    },
  {KEY_N         , KEY_ENTER    },
  {KEY_M         , KEY_HOME     },
  {KEY_COMMA     , KEY_PAGEDOWN },
  {KEY_DOT       , KEY_PAGEUP   },
  {KEY_SLASH     , KEY_END      },
};

const std::unordered_map<key, key> Z_PAGE = {
  {KEY_D         , KEY_1 | SHIFT},
  {KEY_F         , KEY_B | SHIFT},
  {KEY_X         , KEY_2 | SHIFT},
  {KEY_C         , KEY_3 | SHIFT},

  {KEY_U         , KEY_2        },
  {KEY_I         , KEY_1        },
  {KEY_O         , KEY_0        },
  {KEY_H         , KEY_3        },
  {KEY_J         , KEY_J        },
  {KEY_K         , KEY_Y        },
  {KEY_L         , KEY_I        },
  {KEY_SEMICOLON , KEY_P        },
  {KEY_APOSTROPHE, KEY_9        },
  {KEY_N         , KEY_4        },
  {KEY_M         , KEY_5        },
  {KEY_COMMA     , KEY_6        },
  {KEY_DOT       , KEY_7        },
  {KEY_SLASH     , KEY_8        },
};

const std::unordered_map<key, key> Q_PAGE = {
  {KEY_W         , KEY_PREVIOUSSONG  },
  {KEY_E         , KEY_PLAYPAUSE     },
  {KEY_R         , KEY_NEXTSONG      },
  {KEY_S         , KEY_MUTE          },
  {KEY_D         , KEY_VOLUMEDOWN    },
  {KEY_F         , KEY_VOLUMEUP      },

  {KEY_U         , KEY_BRIGHTNESSDOWN}, // Doesn't actually work :(
  {KEY_I         , KEY_BRIGHTNESSUP  },
  {KEY_O         , KEY_F1            },
  {KEY_P         , KEY_F2            },
  {KEY_LEFTBRACE , KEY_F3            },
  {KEY_H         , KEY_F4            },
  {KEY_J         , KEY_F5            },
  {KEY_K         , KEY_F6            },
  {KEY_L         , KEY_F7            },
  {KEY_SEMICOLON , KEY_F8            },
  {KEY_APOSTROPHE, KEY_F9            },
  {KEY_N         , KEY_F10           },
  {KEY_M         , KEY_F11           },
  {KEY_COMMA     , KEY_F12           },
  {KEY_DOT       , KEY_INSERT        },
  {KEY_SLASH     , KEY_PRINT         },
};

const std::unordered_map<key, std::unordered_map<key, key>> REALBOOK = {
    {KEY_J, J_PAGE},
    {KEY_X, X_PAGE},
    {KEY_Z, Z_PAGE},
    {KEY_Q, Q_PAGE},
};
