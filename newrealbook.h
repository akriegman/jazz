#pragma once
#include <linux/input.h>
#include <unordered_map>

typedef __u16 key;

#define SHIFT 0x1000
#define MASK_KEY 0x0fff

// clang-format off
#define IS_MOD(code) code == KEY_LEFTSHIFT || code == KEY_RIGHTSHIFT || \
                     code == KEY_LEFTCTRL  || code == KEY_RIGHTCTRL  || \
                     code == KEY_LEFTALT   || code == KEY_RIGHTALT //  || \
                     // code == KEY_LEFTMETA  || code == KEY_RIGHTMETA

const std::unordered_map<key, key> J_PAGE = {
  {KEY_Q         , 
  {KEY_W         , KEY_BACKSPACE},
  {KEY_E         , KEY_DELETE},
  {KEY_R         , 
  {KEY_T         , },
  {KEY_A         ,  KEY_LEFT},
  {KEY_S         ,  KEY_DOWN},
  {KEY_D         ,  KEY_UP},
  {KEY_F         ,  KEY_RIGHT},
  {KEY_G         , KEY_EQUAL             },
  {KEY_Z         , KEY_1          | SHIFT},
  {KEY_X         , KEY_2          | SHIFT},
  {KEY_C         , KEY_7          | SHIFT},
  {KEY_V         , KEY_8          | SHIFT},

  {KEY_I         , KEY_ENTER             },
  {KEY_O         , KEY_LEFTMETA},
    {KEY_P         , KEY_ESC},
  {KEY_K         , KEY_RIGHTCTRL},
  {KEY_L         , KEY_LEFTALT},
  {KEY_SEMICOLON , KEY_RIGHTSHIFT},
  {KEY_N         , KEY_RIGHTCTRL         },
  {KEY_COMMA     , KEY_LEFTBRACE         },
  {KEY_DOT       , KEY_RIGHTBRACE        },
  {KEY_SLASH     , KEY_BACKSLASH         },
};

const std::unordered_map<key, key> X_PAGE = {
  {KEY_R         , KEY_PLAYPAUSE         },
  {KEY_T         , KEY_NEXTSONG          },
  {KEY_A         , KEY_LEFTMETA          },
  {KEY_S         , KEY_ESC               },
  {KEY_F         , KEY_ENTER             },
  {KEY_Z         , KEY_LEFTALT           },
  {KEY_C         , KEY_RIGHTCTRL         },

  {KEY_I         , KEY_BACKSPACE         },
  {KEY_O         , KEY_DELETE            },
  {KEY_H         , KEY_PAGEUP            },
  {KEY_J         , KEY_UP                },
  {KEY_K         , KEY_LEFT              },
  {KEY_L         , KEY_RIGHT             },
  // {KEY_SEMICOLON , KEY_VOLUMEUP          },
  {KEY_N         , KEY_PAGEDOWN          },
  {KEY_M         , KEY_DOWN              },
  {KEY_COMMA     , KEY_HOME              },
  {KEY_DOT       , KEY_END               },
  // {KEY_SLASH     , KEY_VOLUMEDOWN        },
  {KEY_SPACE     , KEY_TAB               },
};

const std::unordered_map<key, key> Z_PAGE = {
  {KEY_E         , KEY_VOLUMEDOWN        },
  {KEY_R         , KEY_VOLUMEUP          },
  {KEY_D         , KEY_X                 },
  {KEY_F         , KEY_Z                 },
  {KEY_X         , KEY_I                 },
  {KEY_C         , KEY_J                 },

  {KEY_U         , KEY_Z                 },
  {KEY_I         , KEY_Y                 },
  {KEY_O         , KEY_X                 },
  {KEY_H         , KEY_0                 },
  {KEY_J         , KEY_1                 },
  {KEY_K         , KEY_2                 },
  {KEY_L         , KEY_3                 },
  {KEY_SEMICOLON , KEY_4                 },
  {KEY_N         , KEY_5                 },
  {KEY_M         , KEY_6                 },
  {KEY_COMMA     , KEY_7                 },
  {KEY_DOT       , KEY_8                 },
  {KEY_SLASH     , KEY_9                 },
};

const std::unordered_map<key, key> Q_PAGE = {
  {KEY_W         , KEY_PREVIOUSSONG      },
  {KEY_E         , KEY_PLAYPAUSE         },
  {KEY_R         , KEY_NEXTSONG          },
  {KEY_S         , KEY_MUTE              },
  {KEY_D         , KEY_VOLUMEDOWN        },
  {KEY_F         , KEY_VOLUMEUP          },

  {KEY_U         , KEY_BRIGHTNESSDOWN    }, // Doesn't actually work :(
  {KEY_I         , KEY_BRIGHTNESSUP      },
  {KEY_O         , KEY_F1                },
  {KEY_P         , KEY_F2                },
  {KEY_LEFTBRACE , KEY_F3                },
  {KEY_H         , KEY_F4                },
  {KEY_J         , KEY_F5                },
  {KEY_K         , KEY_F6                },
  {KEY_L         , KEY_F7                },
  {KEY_SEMICOLON , KEY_F8                },
  {KEY_APOSTROPHE, KEY_F9                },
  {KEY_N         , KEY_F10               },
  {KEY_M         , KEY_F11               },
  {KEY_COMMA     , KEY_F12               },
  {KEY_DOT       , KEY_INSERT            },
  {KEY_SLASH     , KEY_PRINT             },
};

const std::unordered_map<key, std::unordered_map<key, key>> REALBOOK = {
    {KEY_J, J_PAGE},
    {KEY_X, X_PAGE},
    {KEY_Z, Z_PAGE},
    // {KEY_Q, Q_PAGE},
};
