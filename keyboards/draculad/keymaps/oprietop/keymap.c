/*
opyright 2021 @mangoiv

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
}
#include "print.h"

#endif

#include "defines.h"

#ifdef OLED_ENABLE
#include "oled.c"
#endif

#ifdef ENCODER_ENABLE
#include "encoder.c"
#endif

#include "functions.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Colemak Mod DH
   * ,----------------------------------.         ,----------------------------------.
   * |   Q  |   W  |   F  |   P  |B/RALT|         |J/RALT|   L  |   U  |   Y  |   ;  |
   * |------+------+------+------+------|         |------+------+------+------+------|
   * |   A  |   R  |   S  |   T  |   G  |         |   M  |   N  |   E  |   I  |   O  |
   * |------+------+------+------+------|         |------+------+------+------+------|
   * |Z/LGUI|X/LALT|   C  |   D  |   V  |         |   K  |   H  |   ,  |./LALT|/_RGUI|
   * `------+------+------+------+------+---. ,---+------+------+------+------+------'
   *                   |Esc/AD|Tab/SH|Spc/Lo| |Bks/Up|Del/SH|   \  |
   *                   `--------------------' `--------------------'
   */
  [_DH] = LAYOUT (
    KC_Q,      KC_W,      KC_F,      KC_P,   AGT(KC_B),         AGT(KC_J), KC_L,  KC_U,         KC_Y,        KC_SCLN,      \
    KC_A,      KC_R,      KC_S,      KC_T,   KC_G,              KC_M,      KC_N,  KC_E,         KC_I,        KC_O,         \
    LCT(KC_Z), LGT(KC_X), TAT(KC_C), KC_D,   KC_V,              KC_K,      KC_H,  TAT(KC_COMM), RGT(KC_DOT), RCT(KC_SLSH), \
                                             KC_MUTE,           TG(_AD), \
                          LT_ESC,    EX_TAB, LT_SPC,            LT_BSPC,   S_DEL, KC_BSLS \
  ),
  /* Qwerty
   * ,----------------------------------.         ,----------------------------------.
   * |   Q  |   W  |   E  |   R  |T/RALT|         |Y/RALT|   U  |   I  |   O  |   P  |
   * |------+------+------+------+------|         |------+------+------+------+------|
   * |   A  |   S  |   D  |   F  |   G  |         |   H  |   J  |   K  |   L  |   ;  |
   * |------+------+------+------+------|         |------+------+------+------+------|
   * |Z/LGUI|X/LALT|   C  |   V  |   B  |         |   N  |   M  |   ,  |./LALT|/_RGUI|
   * `------+------+------+------+------+---. ,---+------+------+------+------+------'
   *                   |Esc/AD|Tab/SH|Spc/Lo| |Bks/Up|Del/SH|   \  |
   *                   `--------------------' `--------------------'
   */
  [_QW] = LAYOUT (
    _______, _______, KC_E,    KC_R,    AGT(KC_T),          AGT(KC_Y), KC_U,    KC_I,    KC_O,    KC_P,    \
    _______, KC_S,    KC_D,    KC_F,    _______,            KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN, \
    _______, _______, _______, KC_V,    KC_B,               KC_N,      KC_M,    _______, _______, _______, \
                                        _______,            _______, \
                    _______, _______,   _______,            _______,   _______, _______ \
  ),
  /* Dvorak
   * ,----------------------------------.         ,----------------------------------.
   * |   '  |   ,  |   .  |   P  |Y/RALT|         |F/RALT|   G  |   C  |   R  |   L  |
   * |------+------+------+------+------|         |------+------+------+------+------|
   * |   A  |   O  |   E  |   U  |   I  |         |   D  |   H  |   T  |   N  |   S  |
   * |------+------+------+------+------|         |------+------+------+------+------|
   * |;/LGUI|Q/LALT|   J  |   K  |   X  |         |   B  |   M  |   W  |V/LALT|Z/RGUI|
   * `------+------+------+------+------+---. ,---+------+------+------+------+------'
   *                   |Esc/AD|Tab/SH|Spc/Lo| |Bks/Up|Del/SH|   \  |
   *                   `--------------------' `--------------------'
   */
  [_DV] = LAYOUT (
    KC_QUOT,      KC_COMM,   KC_DOT,    KC_P,    AGT(KC_Y),        AGT(KC_F), KC_G,    KC_C,      KC_R,      KC_L,      \
    KC_A,         KC_O,      KC_E,      KC_U,    KC_I,             KC_D,      KC_H,    KC_T,      KC_N,      KC_S,      \
    LCT(KC_SCLN), LGT(KC_Q), TAT(KC_J), KC_K,    KC_X,             KC_B,      KC_M,    TAT(KC_W), RGT(KC_V), RCT(KC_Z), \
                                                 _______,          _______, \
                             _______,   _______, _______,          _______,   _______, _______ \
  ),
  /* Lower
   * ,----------------------------------.         ,----------------------------------.
   * |  Esc | Copy | W_Up |  CUT | PASTE|         | PgUp |M_Btn1| M_Up |M_Btn2|M_Btn3|
   * |------+------+------+------+------|         |-------------+------+------+------|
   * |  Tab | W_Le | W_Do | W_Ri |M_Btn3|         | Home | M_Le | M_Do | M_Ri | End  |
   * |------+------+------+------+------|         |-------------+------+------+------|
   * | Ctrl | Shift| Gui  |M_Btn1|M_Btn2|         | PgDN | Left | Down |  Up  | Rght |
   * `------+------+------+------+------+---. ,---+------+------+------+------+------'
   *                   |      |      |      | | Enter| Ins  |      |
   *                   `--------------------' `--------------------'
   */
  [_LO] = LAYOUT (
    KC_ESC,  COPY,    KC_WH_U, CUT,     PASTE,            KC_PGUP, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, \
    KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_R, KC_BTN3,          KC_HOME, KC_MS_L, KC_MS_D, KC_MS_R, KC_END,  \
    KC_LCTL, KC_LSFT, KC_LGUI, KC_BTN1, KC_BTN2,          KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, \
                                        _______,          _______, \
                      _______, _______, _______,          KC_ENT,  KC_INS,  _______ \
  ),
  /* Raise
   * ,----------------------------------.         ,----------------------------------.
   * |   !  |   @  |   #  |   $  |   %  |         |   ^  |   &  |   *  |   (  |   )  |
   * |------+------+------+------+------|         |------+------+------+------+------|
   * |   1  |   2  |   3  |   4  |   5  |         |   6  |   7  |   8  |   9  |   0  |
   * |------+------+------+------+------|         |------+------+------+------+------|
   * |  F1  |  F2  |  F3  |  F4  |  F5  |         |  F6  |  F7  |  F8  |  F9  |  F10 |
   * `------+------+------+------+------+---. ,---+------+------+------+------+------'
   *                   |      |      |Enter | |      |      |      |
   *                   `--------------------' `--------------------'
   */
  [_RA] = LAYOUT (
    KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC,                  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
    KC_1,    KC_2,  KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
    KC_F1,   KC_F2, KC_F3,   KC_F4,   KC_F5,                    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  \
                                      _______,                  _______, \
                     KC_F11,  KC_F12, KC_ENT,                   _______, _______, _______ \
  ),
  [_EX] = LAYOUT (
    _______, _______, _______, _______, KC_NUM,         KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_PIPE, \
    _______, _______, _______, _______, KC_CAPS,        KC_TILD, KC_GRV,  KC_QUOT, KC_DQUO, KC_BSLS, \
    _______, _______, _______, _______, KC_SCRL,        KC_UNDS, KC_MINS, KC_EQL,  KC_PLUS, KC_SLSH, \
                                        _______,        _______, \
                      _______, _______, _______,        _______, KC_RSFT, _______ \
  ),
  /* Adjust
   * ,----------------------------------.         ,----------------------------------.
   * |CoMoDH|Qwerty|Dvorak|      |PrtScr|         | Minus|  P7  |  P8  |  P9  | Slash|
   * |------+------+------+------+------|         |------+------+------+------+------|
   * |RgbRMo|RgbHui|RgbSai|RgbVai|BrghUp|         |  P0  |  P4  |  P5  |  P6  | Dot  |
   * |------+------+------+------+------|         |------+------+------+------+------|
   * |RgbMod|RbgHud|RgbSad|RgbVad|BrghDo|         | Plus |  P1  |  P2  |  P3  | Ast  |
   * `------+------+------+------+------+---. ,---+------+------+------+------+------'
   *                   |      |Random| Emoji| |BckSpc|  Del |PEnter|
   *                   `--------------------' `--------------------'
   */
  [_AD] = LAYOUT (
     MODDH,    QWERTY,  DVORAK,  _______, KC_PSCR,          KC_PMNS, KC_P7,  KC_P8, KC_P9, KC_PSLS, \
     RGB_RMOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_BRIU,          KC_P0,   KC_P4,  KC_P5, KC_P6, KC_PDOT, \
     RGB_MOD,  RGB_HUD, RGB_SAD, RGB_VAD, KC_BRID,          KC_PPLS, KC_P1,  KC_P2, KC_P3, KC_PAST, \
                                          _______,          _______, \
                        XXXXXXX, M_RAN64, EMOJI,            KC_BSPC, KC_DEL, KC_PENT \
  ),

  // Emoji
  [_EM] = LAYOUT (
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          UC_TABL, UC_FLIP, UC_RAGE, UC_NOOO, UC_LENY, \
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          UC_SCRE, UC_DISA, UC_WALL, UC_SOB,  UC_WHAT, \
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          UC_SALU, UC_DANC, UC_SHRG, UC_DEAL, UC_CRY,  \
                                         XXXXXXX,          XXXXXXX, \
                       XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX \
  )
};
