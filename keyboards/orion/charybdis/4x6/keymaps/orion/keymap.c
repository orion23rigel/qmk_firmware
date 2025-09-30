/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// Tap Dance declarations
enum {
    TD_ESC_TO_0,
	TD_TIL_TO_0,
	TD_F12_TO_0,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_TO_0] = ACTION_TAP_DANCE_LAYER_MOVE(KC_ESC, 0),
    [TD_TIL_TO_0] = ACTION_TAP_DANCE_LAYER_MOVE(KC_TILD, 0),
    [TD_F12_TO_0] = ACTION_TAP_DANCE_LAYER_MOVE(KC_F12, 0)
};

// COMBOS

enum combos {
  HOLD_LAYER_1,
  HOLD_LAYER_2,
  HOLD_LAYER_3,
};

const uint16_t PROGMEM hold_1_combo[] = {LT(1,KC_X), LT(1,KC_DOT), COMBO_END};
const uint16_t PROGMEM hold_2_combo[] = {LT(2,KC_C), LT(2,KC_COMM), COMBO_END};
const uint16_t PROGMEM hold_3_combo[] = {LT(3,KC_V), LT(3,KC_M), COMBO_END};

combo_t key_combos[] = {
  [HOLD_LAYER_1] = COMBO(hold_1_combo, TO(1)),
  [HOLD_LAYER_2] = COMBO(hold_2_combo, TO(2)),
  [HOLD_LAYER_3] = COMBO(hold_3_combo, TO(3)),
};

// MACROS

enum custom_keycodes {
    ENDASH = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ENDASH:
        if (record->event.pressed) {
            // when keycode ENDASH is pressed
            SEND_STRING(SS_DOWN(X_LALT)"0150"SS_UP(X_LALT));
        } else {
            // when keycode ENDASH is released
        }
        break;
    }
    return true;
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, 
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, 
		LALT(KC_RGHT), LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT, 
		LALT(KC_LEFT), KC_Z, LT(1,KC_X), LT(2,KC_C), LT(3,KC_V), KC_B, KC_N, LT(3,KC_M), LT(2,KC_COMM), LT(1,KC_DOT), KC_SLSH, RALT(KC_LEFT), 
		DRGSCRL, KC_SPC, KC_BSPC, MS_BTN1, KC_ENT, MS_BTN1, MS_BTN2, MS_BTN2),
    [1] = LAYOUT(TD(TD_TIL_TO_0), KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, 
		KC_NUM, KC_LBRC, KC_P7, KC_P8, KC_P9, KC_RBRC, KC_PSCR, KC_NO, KC_UP, KC_NO, LALT(KC_F4), KC_TRNS, 
		KC_PEQL, KC_PPLS, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, LALT(KC_LEFT), KC_TRNS, 
		KC_PDOT, KC_PAST, KC_P1, KC_P2, KC_P3, KC_PSLS, KC_NO, KC_PGUP, KC_PGDN, LALT(KC_LEFT), LALT(KC_RGHT), KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0),
    [2] = LAYOUT(TD(TD_F12_TO_0), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
		KC_TRNS, KC_PSCR, KC_NO, KC_UP, KC_NO, LALT(KC_F4), KC_LBRC, KC_P7, KC_P8, KC_P9, KC_RBRC, KC_NUM, 
		KC_TRNS, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, LALT(KC_LEFT), KC_PPLS, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_PEQL, 
		KC_TRNS, KC_NO, KC_PGUP, KC_PGDN, LALT(KC_LEFT), LALT(KC_RGHT), KC_PAST, KC_P1, KC_P2, KC_P3, KC_PSLS, KC_PDOT, 
		KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0),
    [3] = LAYOUT(TD(TD_ESC_TO_0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ENDASH, 
		KC_TRNS, KC_DEL, KC_TRNS, DPI_RMOD, S_D_RMOD, LCTL(KC_F4), KC_TRNS, S_D_MOD, DPI_MOD, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LALT(KC_LEFT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, DRGSCRL, SNIPING, LALT(KC_LEFT), LALT(KC_RGHT), KC_TRNS, KC_TRNS, SNIPING, DRGSCRL, MS_BTN3, KC_TRNS, KC_TRNS, MS_BTN3, KC_TRNS, 
		KC_TRNS, MS_BTN3, KC_DEL, KC_TRNS, KC_TRNS),
};
// clang-format on

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif
