#include QMK_KEYBOARD_H

// Allow printing version info
#include "version.h"

extern keymap_config_t keymap_config;

// Layers
#define _DH 0
#define _QW 1
#define _DV 2
#define _LO 3
#define _RA 4
#define _AD 5
#define _EM 6

enum keycodes {
  MODDH = SAFE_RANGE,
  QWERTY,
  DVORAK,
  M_BSPC,
  M_WIPE,
  M_RAN64,
  // Macros
  KC_VER,
  KC_PULL,
  KC_PUSH,
  KC_LS,
  KC_INCL,
  #ifdef UNICODE_ENABLE
    UC_FLIP,
    UC_TABL,
    UC_SHRG,
    UC_DISA,
    UC_DANC,
    UC_SCRE,
    UC_WALL,
    UC_SOB,
    UC_DEAL,
    UC_RAGE,
    UC_NOOO,
    UC_SALU,
    UC_LENY,
    UC_WHAT,
    UC_CRY,
    UC_SHR2,
    UC_HAPY,
    UC_STRG,
  #endif
//  #ifdef AUDIO_ENABLE
    S_BSKTC,
    S_ODEJY,
    S_RCKBY,
    S_DOEDR,
    S_SCALE,
    S_ONEUP,
    S_COIN,
    S_SONIC,
    S_ZELDA,
    S_DOOM,
    S_RICKR,
//  #endif
};

#ifdef AUDIO_ENABLE
  float song_basketcase[][2] = SONG(BASKET_CASE);
  float song_ode_to_joy[][2] = SONG(ODE_TO_JOY);
  float song_rock_a_bye_baby[][2] = SONG(ROCK_A_BYE_BABY);
  float song_doe_a_deer[][2] = SONG(DOE_A_DEER);
  float song_scale[][2] = SONG(MUSIC_SCALE_SOUND);
  float song_coin[][2] = SONG(COIN_SOUND);
  float song_one_up[][2] = SONG(ONE_UP_SOUND);
  float song_sonic_ring[][2] = SONG(SONIC_RING);
  float song_zelda_puzzle[][2] = SONG(ZELDA_PUZZLE);
  float song_zelda_treasure[][2] = SONG(ZELDA_TREASURE);
  float song_doom[][2] = SONG(E1M1_DOOM);
  float song_all_star[][2] = SONG(ALL_STAR);
  float song_mario_theme[][2] = SONG(MARIO_THEME);
  float song_mario_gameover[][2] = SONG(MARIO_GAMEOVER);
  float song_mario_mushroom[][2] = SONG(MARIO_MUSHROOM);
  float song_victory_fanfare_short[][2] = SONG(VICTORY_FANFARE_SHORT);
  float song_old_spice[][2] = SONG(OLD_SPICE);
  float song_rick_roll[][2] = SONG(RICK_ROLL);
#endif

// Shortcuts
#define COPY LCTL(KC_INS)
#define CUT LSFT(KC_DEL)
#define PASTE RSFT(KC_INS)
#define EMOJI TT(_EM)

// Mod-Taps
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md
#define LST(X) LSFT_T(X)
#define RST(X) RSFT_T(X)
#define LCT(X) LCTL_T(X)
#define RCT(X) RCTL_T(X)
#define LGT(X) LGUI_T(X)
#define RGT(X) RGUI_T(X)
#define TAT(X) LALT_T(X)
#define AGT(X) RALT_T(X)

// Modifiers
#define LT_ESC LT(_AD, KC_ESC)
#define S_TAB LSFT_T(KC_TAB)
#define LT_SPC LT(_LO, KC_SPC)
#define LT_BSPC LT(_RA, KC_BSPC)
#define S_DEL RSFT_T(KC_DEL)

// Planck Only
#define OS_ALT OSM(MOD_LALT)
#define OS_CTL OSM(MOD_LCTL)
#define OS_GUI OSM(MOD_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Colemak Mod DH
   * ,-----------------------------------------.       ,-----------------------------------------.
   * |   [  |   Q  |   W  |   E  |   R  |T/RALT|       |Y/RALT|   U  |   I  |   O  |   P  |   ]  |
   * |------+------+------+------+------+------|       |------+------+------+------+------+------|
   * | `/SFT|   A  |   S  |   D  |   F  |   G  |       |   H  |   J  |   K  |   L  |   ;  | '/SFT|
   * |------+------+------+------+------+------|       |------+------+------+------+------+------|
   * |-/LCTR|Z/LGUI|X/LALT|   C  |   V  |   B  |       |   N  |   M  |   ,  |./LALT|/_RGUI|=/RCTR|
   * |------+------+------+------+------+------|       |------+------+------+------+------+------|
   * | Ctrl | GUI  | Alt  |Esc/AD|Tab/SH|Spc/Lo|       |Bks/Up|Del/SH| Left | Down |  Up  |Right |  
   * `-----------------------------------------'       `-----------------------------------------'
   */
  [_DH] = LAYOUT_ortho_4x12(
    KC_LBRC,      KC_Q,      KC_W,      KC_F,   KC_P,   AGT(KC_B),        AGT(KC_J), KC_L,    KC_U,    KC_Y,        KC_SCLN,      KC_RBRC,      \
    LST(KC_GRV),  KC_A,      KC_R,      KC_S,   KC_T,   KC_G,             KC_M,      KC_N,    KC_E,    KC_I,        KC_O,         RST(KC_QUOT), \
    LCT(KC_MINS), LGT(KC_Z), TAT(KC_X), KC_C,   KC_D,   KC_V,             KC_K,      KC_H,    KC_COMM, TAT(KC_DOT), RGT(KC_SLSH), RCT(KC_EQL),  \
    KC_LCTL,      KC_LGUI,   KC_LALT,   LT_ESC, S_TAB,  LT_SPC,           LT_BSPC,   S_DEL,   KC_LEFT, KC_DOWN,     KC_UP,        KC_RGHT
  ),
  /* Qwerty
   * ,-----------------------------------------.       ,-----------------------------------------.
   * | [    |   Q  |   W  |   E  |   R  |T/RALT|       |Y/RALT|   U  |   I  |   O  |   P  | ]    |
   * |------+------+------+------+------+------|       |------+------+------+------+------+------|
   * | `/SFT|   A  |   S  |   D  |   F  |   G  |       |   H  |   J  |   K  |   L  |   ;  | '/SFT|
   * |------+------+------+------+------+------|       |------+------+------+------+------+------|
   * |-/LCTR|Z/LGUI|X/LALT|   C  |   V  |   B  |       |   N  |   M  |   ,  |./LALT|/_RGUI|=/RCTR|
   * |------+------+------+------+------+------|       |------+------+------+------+------+------|
   * | Ctrl | GUI  | Alt  |Esc/AD|Tab/SH|Spc/Lo|       |Bks/Up|Del/SH| Left | Down |  Up  |Right |  
   * `-----------------------------------------'       `-----------------------------------------'
   */
  [_QW] = LAYOUT_ortho_4x12(
    _______, _______, _______, KC_E,    KC_R,    AGT(KC_T),        AGT(KC_Y), KC_U,    KC_I,    KC_O,    KC_P,    _______, \
    _______, _______, KC_S,    KC_D,    KC_F,    _______,          KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN, _______, \
    _______, _______, _______, _______, KC_V,    KC_B,             KC_N,      KC_M,    _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,          _______,   _______, _______, _______, _______, _______
  ),
  /* Dvorak
   * ,-----------------------------------------.       ,-----------------------------------------.
   * | [    |   '  |   ,  |   .  |   P  |Y/RALT|       |F/RALT|   G  |   C  |   R  |   L  | ]    |
   * |------+------+------+------+------+------|       |------+------+------+------+------+------|
   * | `/SFT|   A  |   O  |   E  |   U  |   I  |       |   D  |   H  |   T  |   N  |   S  | /    |
   * |------+------+------+------+------+------|       |------+------+------+------+------+------|
   * |-/LCTR|;/LGUI|Q/LALT|   J  |   K  |   X  |       |   B  |   M  |   W  |V/LALT|Z/RGUI|=/RCTR|
   * |------+------+------+------+------+------|       |------+------+------+------+------+------|
   * | Ctrl | GUI  | Alt  |Esc/AD|Tab/SH|Spc/Lo|       |Bks/Up|Del/SH| Left | Down |  Up  |Right |  
   * `-----------------------------------------'       `-----------------------------------------'
   */
  [_DV] = LAYOUT_ortho_4x12(
    KC_QUOT, KC_COMM,      KC_DOT,    KC_P,    AGT(KC_Y), _______,          _______,   AGT(KC_F), KC_G,    KC_C,      KC_R,      KC_L, \
    _______, KC_QUOT,      KC_COMM,   KC_DOT,  KC_P,      AGT(KC_Y),        AGT(KC_F), KC_G,      KC_C,    KC_R,      KC_L,      _______, \
    _______, LGT(KC_SCLN), TAT(KC_Q), KC_J,    KC_K,      KC_X,             KC_B,      KC_M,      KC_W,    TAT(KC_V), RGT(KC_Z), _______, \
    _______, _______,      _______,   _______, _______,   _______,          _______,   _______,   _______, _______,   _______,   _______
  ),
  /* Lower
   * ,-----------------------------------------.       ,-----------------------------------------.
   * |Vol Up|  Esc | Copy | W_Up |  CUT | PASTE|       | PgUp |M_Btn1| M_Up |M_Btn2|M_Btn3| Next |
   * |------+------+------+------+------+------|       |-------------+------+------+------+------|
   * |Vol Do|  Tab | W_Le | W_Do | W_Ri |M_Btn3|       | Home | M_Le | M_Do | M_Ri | End  | Prev |
   * |------+------+------+------+------+------|       |-------------+------+------+------+------|
   * | Mute | Ctrl | Shift| Gui  |M_Btn1|M_Btn2|       | PgDN | Left | Down |  Up  | Rght | Play |
   * |------+------+------+------+------+------|       |------+------+------+------+------+------|
   * |      |      |      |      |      |XXXXXX|       | Enter| Ins  | Bksp | Left | Down | Right|
   * `-----------------------------------------'       `-----------------------------------------'
   */
  [_LO] = LAYOUT_ortho_4x12(
    KC_VOLU, KC_ESC,  COPY,    KC_WH_U, CUT,     PASTE,          KC_PGUP, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_MNXT, \
    KC_VOLD, KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_R, KC_BTN3,        KC_HOME, KC_MS_L, KC_MS_D, KC_MS_R, KC_END,  KC_MPRV, \
    KC_MUTE, KC_LCTL, KC_LSFT, KC_LGUI, KC_BTN1, KC_BTN2,        KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MPLY, \
    _______, _______, _______, _______, _______, XXXXXXX,        KC_ENT,  KC_INS,  KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  /* Raise
   * ,-----------------------------------------.       ,-----------------------------------------.
   * |   |  |   !  |   @  |   #  |   $  |   %  |       |   ^  |   &  |   *  |   (  |   )  |   \  |
   * |-------------+------+------+------+------|       |------+------+------+------+------+------|
   * |   .  |   1  |   2  |   3  |   4  |   5  |       |   6  |   7  |   8  |   9  |   0  |   ,  |
   * |-------------+------+------+------+------|       |------+------+------+------+------+------|
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |       |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------|       |------+------+------+------+------+------|
   * |  M1  |  M2  |  M3  |  M4  |RANDOM| Enter|       |XXXXXX| Ins  |      |      |      |      |
   * `-----------------------------------------'       `-----------------------------------------'
   */
  [_RA] = LAYOUT_ortho_4x12(
    KC_PIPE, KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, \
    KC_DOT,  KC_1,    KC_2,  KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_COMM, \
    KC_F11,  KC_F1,   KC_F2, KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    KC_PULL, KC_PUSH, KC_LS, KC_VER,  M_RAN64, KC_ENT,        XXXXXXX, KC_INS,  _______, _______, _______, _______
  ),
  /* Adjust
   * ,-----------------------------------------.       ,-----------------------------------------.
   * | Reset|CoMoDH|Qwerty|Dvorak|      |PrtScr|       | Minus|  P7  |  P8  |  P9  | Slash|NumLck|
   * |-------------+------+------+------+------|       |------+------+------+------+------+------|
   * | Wipe |RgbRMo|RgbHui|RgbSai|RgbVai|BrghUp|       |  P0  |  P4  |  P5  |  P6  | Dot  |CapLck|
   * |-------------+------+------+------+------|       |------+------+------+------+------+------|
   * |RbgTog|RgbMod|RbgHud|RgbSad|RgbVad|BrghDo|       | Plus |  P1  |  P2  |  P3  | Ast  |ScrLck|
   * |------+------+------+------+------+------|       |------+------+------+------+------+------|
   * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|Emoji |       |XXXXXX|BckSpc|  Del |PEnter|XXXXXX|XXXXXX|
   * `-----------------------------------------'       `-----------------------------------------'
   */
  [_AD] = LAYOUT_ortho_4x12(
      QK_RBT,    MODDH,  QWERTY,  DVORAK, XXXXXXX, KC_PSCR,        KC_PMNS,   KC_P7,  KC_P8,   KC_P9, KC_PSLS, KC_NUM,
     M_WIPE, RGB_RMOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_BRIU,          KC_P0,   KC_P4,  KC_P5,   KC_P6, KC_PDOT, KC_CAPS,
    RGB_TOG,  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_BRID,        KC_PPLS,   KC_P1,  KC_P2,   KC_P3, KC_PAST, KC_SCRL,
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   EMOJI,        XXXXXXX, KC_BSPC, KC_DEL, KC_PENT, XXXXXXX, XXXXXXX
  ),
  // Sound And Emoji
  [_EM] = LAYOUT_ortho_4x12(
    S_BSKTC, S_ODEJY, S_RCKBY, XXXXXXX, XXXXXXX, XXXXXXX,        UC_TABL, UC_FLIP, UC_RAGE, UC_NOOO, UC_LENY, UC_SHR2,
    S_DOEDR, S_SCALE, S_ONEUP, S_RICKR, XXXXXXX, XXXXXXX,        UC_SCRE, UC_DISA, UC_WALL, UC_SOB,  UC_WHAT, UC_HAPY,
     S_COIN, S_SONIC, S_ZELDA,  S_DOOM, XXXXXXX, XXXXXXX,        UC_SALU, UC_DANC, UC_SHRG, UC_DEAL,  UC_CRY, UC_STRG,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QW);
      }
      return false;
      break;
    case MODDH:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DH);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DV);
      }
      return false;
      break;
    case M_WIPE: // Wipe the eeprom and reset the board
      if (record->event.pressed) {
        eeconfig_init();
        reset_keyboard();
      }
      return false;
      break;
    case M_RAN64:
      if (record->event.pressed) {
        tap_random_base64();
      }
      return false;
      break;
    // Macros
    case KC_INCL:
      if (record->event.pressed) {
        SEND_STRING("#include <>"SS_TAP(X_LEFT));
      }
      return false;
    case KC_PULL:
      if (record->event.pressed) {
        SEND_STRING("git pull"SS_TAP(X_ENTER));
      }
      return false;
    case KC_PUSH:
      if (record->event.pressed) {
        SEND_STRING("git push"SS_TAP(X_ENTER));
      }
      return false;
    case KC_LS:
      if (record->event.pressed) {
        SEND_STRING("ls -la"SS_TAP(X_ENTER));
      }
      return false;
    case KC_VER:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_VERSION "@" QMK_BUILDDATE);
      }
      return false;
    #ifdef AUDIO_ENABLE
      case S_BSKTC:
        if (record->event.pressed) {
            stop_all_notes();
            PLAY_SONG(song_basketcase);
        }
        return false;
      case S_ODEJY:
        if (record->event.pressed) {
            stop_all_notes();
            PLAY_SONG(song_ode_to_joy);
        }
        return false;
      case S_RCKBY:
        if (record->event.pressed) {
            stop_all_notes();
            PLAY_SONG(song_rock_a_bye_baby);
        }
        return false;
      case S_DOEDR:
        if (record->event.pressed) {
            stop_all_notes();
            PLAY_SONG(song_doe_a_deer);
        }
        return false;
      case S_SCALE:
        if (record->event.pressed) {
            stop_all_notes();
            PLAY_SONG(song_scale);
        }
        return false;
      case S_ONEUP:
        if (record->event.pressed) {
            stop_all_notes();
            PLAY_SONG(song_one_up);
        }
        return false;
      case S_COIN:
        if (record->event.pressed) {
            stop_all_notes();
            PLAY_SONG(song_coin);
        }
        return false;
      case S_SONIC:
        if (record->event.pressed) {
            stop_all_notes();
            PLAY_SONG(song_sonic_ring);
        }
        return false;
      case S_ZELDA:
        if (record->event.pressed) {
            stop_all_notes();
            PLAY_SONG(song_zelda_puzzle);
        }
        return false;
      case S_DOOM:
        if (record->event.pressed) {
            stop_all_notes();
            PLAY_SONG(song_doom);
        }
        return false;
      case S_RICKR:
        if (record->event.pressed) {
            stop_all_notes();
            PLAY_SONG(song_rick_roll);
        }
        return false;
    #endif
    #ifdef UNICODE_ENABLE
      // Some Emojis
      // https://r12a.github.io/app-conversion/
      // https://gist.github.com/endolith/157796
      // case UC_: //
      //   if (record->event.pressed) {
      //     send_unicode_string("");
      //   }
      //   return false;
      //   break;
      case UC_LENY: // ( ͡° ͜ʖ ͡°)
        if (record->event.pressed) {
          send_unicode_string("0028 0020 0361 00B0 0020 035C 0296 0020 0361 00B0 0029");
        }
        return false;
        break;
      case UC_WHAT: // WHATщ(ﾟДﾟщ)
        if (record->event.pressed) {
          send_unicode_string("0057 0048 0041 0054 0449 0028 FF9F 0414 FF9F 0449 0029");
        }
        return false;
        break;
      case UC_CRY: // ಥ_ಥ
        if (record->event.pressed) {
          send_unicode_string("0CA5 005F 0CA5");
        }
        return false;
        break;
      case UC_SHR2: // ¯\(ºдಠ)/¯
        if (record->event.pressed) {
          send_unicode_string("00AF 005C 0028 00BA 0434 0CA0 0029 002F 00AF");
        }
        return false;
        break;
      case UC_HAPY: // ✌.|•͡˘‿•͡˘|.✌
        if (record->event.pressed) {
          send_unicode_string("270C 002E 007C 2022 0361 02D8 203F 2022 0361 02D8 007C 002E 270C");
        }
        return false;
        break;
      case UC_STRG: // ᕙ(⇀‸↼‶)ᕗ
        if (record->event.pressed) {
          send_unicode_string("1559 0028 21C0 2038 21BC 2036 0029 1557 000A");
        }
        return false;
        break;
      case UC_FLIP: // (ノಠ痊ಠ)ノ彡┻━┻
        if (record->event.pressed) {
          send_unicode_string("0028 30CE 0CA0 75CA 0CA0 0029 30CE 5F61 253B 2501 253B");
        }
        return false;
        break;
      case UC_TABL: // ┬─┬ノ( º _ ºノ)
        if (record->event.pressed) {
          send_unicode_string("252C 2500 252C 30CE 0028 0020 00BA 0020 005F 0020 00BA 30CE 0029");
        }
        return false;
        break;
      case UC_SHRG: // ¯\_(ツ)_/¯
        if (record->event.pressed) {
          send_unicode_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
        }
        return false;
        break;
      case UC_DISA: // ಠ_ಠ
        if (record->event.pressed) {
          send_unicode_string("0CA0 005F 0CA0");
        }
        return false;
        break;
      case UC_DANC: // (〜￣△￣)〜
        if (record->event.pressed) {
          send_unicode_string("0028 301C FFE3 25B3 FFE3 0029 301C");
        }
        return false;
        break;
      case UC_SCRE: // ヽ(ﾟДﾟ)ﾉ
        if (record->event.pressed) {
          send_unicode_string("30FD 0028 FF9F 0414 FF9F 0029 FF89");
        }
        return false;
        break;
      case UC_WALL: // ┬┴┬┴┤(･_├┬┴┬┴
        if (record->event.pressed) {
          send_unicode_string("252C 2534 252C 2534 2524 0028 FF65 005F 251C 252C 2534 252C 2534");
        }
        return false;
        break;
      case UC_SOB: // (ಢ⊱ಢ ｡)
        if (record->event.pressed) {
          send_unicode_string("0028 0CA2 22B1 0CA2 0020 FF61 0029");
        }
        return false;
        break;
      case UC_DEAL: // ( ∙_∙) ( ∙_∙)>⌐■-■ (⌐■_■)
        if (record->event.pressed) {
          send_unicode_string("0028 0020 2219 005F 2219 0029 0020 0028 0020 2219 005F 2219 0029 003E 2310 25A0 002D 25A0 0020 0028 2310 25A0 005F 25A0 0029");
        }
        return false;
        break;
      case UC_RAGE: // （╬ಠ益ಠ)
        if (record->event.pressed) {
          send_unicode_string("FF08 256C 0CA0 76CA 0CA0 0029");
        }
        return false;
        break;
      case UC_NOOO: // (」ﾟﾛﾟ)｣NOOOooooo━
        if (record->event.pressed) {
          send_unicode_string("0028 300D FF9F FF9B FF9F 0029 FF63 004E 004F 004F 004F 006F 006F 006F 006F 006F 2501");
        }
        return false;
        break;
      case UC_SALU: // (￣^￣)ゞ
        if (record->event.pressed) {
          send_unicode_string("0028 FFE3 005E FFE3 0029 309E");
        }
        return false;
        break;
    #endif
  }
  return true;
};
