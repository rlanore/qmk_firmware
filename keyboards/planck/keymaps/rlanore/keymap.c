/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"
#include "../../../../quantum/keymap_extras/keymap_french.h"


enum planck_layers {
  _AZERTY,
  _LOWER,
  _RAISE,
  _NUMPAD,
  _FUNCTION,
  _ADJUST
};

enum planck_keycodes {
  AZERTY = SAFE_RANGE,
  TMUX,
  LWORD,
  RWORD,
  WBKSP,
  CBL
};

// Tap Dance declarations
//enum {
  //MP,
  //CS,
  //DC,
  //SE,
  //PE
//};

// Tap Dance definitions
//qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for Escape, twice for Caps Lock
  //[MP] = ACTION_TAP_DANCE_DOUBLE(FR_MINS, FR_PLUS),
  //[CS] = ACTION_TAP_DANCE_DOUBLE(FR_COMM, FR_DOT),
  //[DC] = ACTION_TAP_DANCE_DOUBLE(FR_COMM, FR_DOT),
  //[SE] = ACTION_TAP_DANCE_DOUBLE(FR_SLSH, FR_EXLM),
  //[PE] = ACTION_TAP_DANCE_DOUBLE(FR_PIPE, FR_EQL)
//};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SHFCAP MT(MOD_LSFT,KC_CAPS)
#define CTLSPC MT(MOD_LCTL, KC_SPACE)
#define LPAD LT(_NUMPAD,KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Azerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |SHFCAP|   W  |   X  |   C  |   V  |   B  |   N  |   .  |  :   |   ,  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | TMUX |Lower | LCTL/Space  |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_AZERTY] = LAYOUT_planck_grid(
    KC_ESC,  FR_A,    FR_Z,    KC_E, KC_R,  KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  FR_Q,    KC_S,    KC_D, LPAD,  KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    FR_M,    KC_ENT,
    SHFCAP,  FR_W,    KC_X,    KC_C, KC_V,  KC_B,   KC_N,   FR_DOT, FR_COLN, FR_COMM, FR_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI, TMUX, LOWER, CTLSPC, CTLSPC, RAISE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   &  |   é  |   "  |   '  |   (  |   )  |   è  |   _  |   ç  |   à  |WBKSP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   >  |  %   |  ;   |  F2  |   [  |   ]  |   -  |   *  |   @  |   $  |  #   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   <  |  ?   |  \   |  F4  |   {  |   }  |   |  |   +  |   !  |   ^  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home |      |      | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    FR_TILD, FR_AMPR, FR_EACU, FR_DQUO, FR_QUOT, FR_LPRN, FR_RPRN, FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, WBKSP,
    KC_DEL,  FR_RABK, FR_PERC, FR_SCLN, KC_F2,   FR_LBRC, FR_RBRC, FR_MINS, FR_ASTR, FR_AT,   FR_DLR,  FR_HASH,
    _______, FR_LABK, FR_QUES, FR_BSLS, KC_F4,   FR_LCBR, FR_RCBR, FR_PIPE, FR_PLUS, FR_EXLM, FR_CIRC, FR_EQL,
   _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, _______, _______, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |WBKSP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  | ```  |  F5  |  F6  |  LW  |  RW  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    FR_GRV,  FR_1,    FR_2,    FR_3,    FR_4,    FR_5,    FR_6,    FR_7,    FR_8,    FR_9,    FR_0,    WBKSP,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   CBL,   KC_F5,   KC_F6,   LWORD,   RWORD,   KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* NUMPAD ( LPAD  )
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   /  |WBKSP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   =  |   0  |   .  |   *  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
    KC_GRV,  FR_1,    FR_2,    FR_3,    FR_4,    FR_5,    FR_6,    FR_7,   FR_8, FR_9,   FR_SLSH, WBKSP,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FR_4,   FR_5, FR_6,   FR_PLUS, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FR_1,   FR_2, FR_3,   FR_MINS, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, FR_EQL, FR_0, FR_DOT, FR_ASTR, _______
),

/* Function Key ( ??? )
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   /  |WBKSP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   =  |   0  |   .  |   *  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_planck_grid(
    KC_GRV,  FR_1,    FR_2,    FR_3,    FR_4,    FR_5,    FR_6,    FR_7, FR_8,   FR_9,    FR_SLSH, WBKSP,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FR_4, FR_5,   FR_6,    FR_PLUS, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FR_1, FR_2,   FR_3,    FR_MINS, XXXXXXX,
    _______, _______, _______, _______, _______, _______, FR_EQL,  FR_0, FR_DOT, FR_ASTR, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Azerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, AZERTY,  _______,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case AZERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_AZERTY);
      }
      return false;
      break;
    case TMUX:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_SPACE);
        unregister_code(KC_LCTL);
        unregister_code(KC_SPACE);
      }
      return false;
      break;
    case LWORD:
      if (record->event.pressed) {
        register_code(KC_LALT);
        register_code(KC_LEFT);
        unregister_code(KC_LEFT);
        unregister_code(KC_LALT);
      }
      return false;
      break;
    case RWORD:
      if (record->event.pressed) {
        register_code(KC_LALT);
        register_code(KC_RGHT);
        unregister_code(KC_RGHT);
        unregister_code(KC_LALT);
      }
      return false;
      break;
    case WBKSP:
      if (record->event.pressed) {
        register_code(KC_LALT);
        register_code(KC_BSPC);
        unregister_code(KC_BSPC);
        unregister_code(KC_LALT);
      }
      return false;
      break;
    case CBL:
      if (record->event.pressed) {
        register_code(FR_GRV);
        unregister_code(FR_GRV);
        register_code(FR_GRV);
        unregister_code(FR_GRV);
        register_code(FR_GRV);
        unregister_code(FR_GRV);
      }
      return false;
      break;
    case RESET:
      if (record->event.pressed) {
        reset_keyboard();
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
}

void matrix_scan_user(void) {
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
