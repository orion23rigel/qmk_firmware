/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

//#define VIAL_KEYBOARD_UID {0xAB, 0x22, 0x68, 0x8B, 0x59, 0xD0, 0x81, 0x11}
//#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
//#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

#if defined(__AVR_ATmega32U4__)
    #undef ENABLE_RGB_MATRIX_BAND_SAT
    #undef ENABLE_RGB_MATRIX_BAND_VAL
#endif

#define DYNAMIC_KEYMAP_LAYER_COUNT 10
#define QUICK_TAP_TERM 0
#define TAPPING_TERM 200
#define FLOW_TAP_TERM 150
