#pragma once

// Want all removed songs from https://github.com/qmk/qmk_firmware/pull/5905
#include "custom_song_list.h"

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(ZELDA_PUZZLE)
    // #define STARTUP_SONG SONG(NO_SOUND)
    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

// Force NKRO
//#define FORCE_NKRO


// Better latency
//#define USB_POLLING_INTERVAL_MS 1
//#define QMK_KEYS_PER_SCAN 12

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md
/* Macro and tapping behaviour */
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 200

#ifdef UNICODE_ENABLE
#  define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
#endif

/* Mouse Settings */
#ifdef MOUSEKEY_ENABLE
#  define MOUSEKEY_INTERVAL 16
#  define MOUSEKEY_DELAY 0
#  define MOUSEKEY_TIME_TO_MAX 60
#  define MOUSEKEY_MAX_SPEED 7
#  define MOUSEKEY_WHEEL_DELAY 0
#  define MOUSEKEY_WHEEL_MAX_SPEED 2
#  define MOUSEKEY_WHEEL_TIME_TO_MAX 6
#endif

/* Disable unused and unneeded features to reduce on firmware size */
#ifdef LOCKING_SUPPORT_ENABLE
#   undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#   undef LOCKING_RESYNC_ENABLE
#endif

/* Get more space if uning less than 8 layeer */
#define LAYER_STATE_8BIT
#define NO_ACTION_ONESHOT
