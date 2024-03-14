/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
uint8_t mod_state;
enum layers {
    _BASE=0,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
    _WORDS
};

// enum custom_keycodes {
//     ALTREP2 = SAFE_RANGE,
//     ALTREP3,
// #include "enumfile.def"
// };

#include "sorla.c"
#include "g/keymap_combo.h"
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
     CW_TOGG, SO_Q, SO_W,  SO_F  ,  SO_P  ,  SO_B  ,                                           SO_J,   SO_L,   SO_U ,   SO_Y ,SO_QUOT, SO_SCLN,
     SO_LPRN, SO_A, SO_R,  SO_S  ,  SO_T  ,  SO_G  ,                                           SO_M,   SO_N,   SO_E ,   SO_I ,  SO_O , SO_RPRN,
     SO_EQL , SO_Z, SO_X,  SO_C  ,  SO_D  ,  SO_V  , QK_REP , KC_MUTE,     KC_PSCR, QK_AREP,   SO_K,   SO_H, SO_COMM, SO_DOT ,SO_SLSH, SO_MINS,
                           ADJUST,  SH_MON,  SO_ESC, SO_BSPC,  SO_DEL,      SO_TAB, SO_SPC , SO_ENT, KC_APP, KC_LGUI
    ),


    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                       _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_VOLU,
      KC_CAPS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                       _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PSCR,
      _______, _______, _______, _______, _______, _______, _______, KC_MSTP,   _______, _______,KC_PAUSE, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_PAUS,
                                 _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT(
     SO_TILD , SO_EXLM,  SO_AT ,  SW_POW, SO_LBRC, SO_PERC,                                     SO_CIRC, SO_RBRC, SO_ASTR, SO_LPRN, SO_RPRN, SO_PLUS,
      SO_GRV ,   SO_8 ,   SO_6 ,   SO_2 ,   SO_0 , SW_DEGC,                                       SO_6 ,   SO_3 ,   SO_1 ,   SO_7 ,   SO_9 , SO_EQL ,
     SO_PIPE , SO_BSLS, SO_COLN, SO_SCLN,   SO_4 , SO_LBRC, SO_LCBR, _______, _______, SO_RCBR, SO_RBRC,   SO_5 , SO_COMM,  SO_DOT, SO_SLSH, SO_QUES,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     QK_BOOT, QK_RBT , _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

    [_WORDS] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
    [_NAV]      = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_WH_L, KC_WH_R) },
    [_SYM]      = { ENCODER_CCW_CW(KC_MRWD, KC_MFFD), ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
    [_FUNCTION] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_WH_L, KC_WH_R) },
    [_ADJUST]   = { ENCODER_CCW_CW(KC_MRWD, KC_MFFD), ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
    [_WORDS]    = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_WH_L, KC_WH_R) },
};
#define SOW(word) case keyname:\
if (record->event.pressed) {SEND_STRING(word);} else {} break;

// bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
//                             uint8_t* remembered_mods) {
//     switch (keycode) {
//         case ALTREP2:
//         case ALTREP3:
//             return false;  // Ignore ALTREP keys.
//     }

//     return true;  // Other keys can be repeated.
// }

// static void process_altrep2(uint16_t keycode, uint8_t mods) {
//     switch (keycode) {
//         case KC_A: SEND_STRING(/*a*/"tion"); break;
//         case KC_I: SEND_STRING(/*i*/"tion"); break;
//         case KC_S: SEND_STRING(/*s*/"sion"); break;
//         case KC_T: SEND_STRING(/*t*/"heir"); break;
//         case KC_W: SEND_STRING(/*w*/"hich"); break;
//     }
// }

// static void process_altrep3(uint16_t keycode, uint8_t mods) {
//     switch (keycode) {
//         case KC_A: SEND_STRING(/*a*/"bout"); break;
//         case KC_I: SEND_STRING(/*i*/"nter"); break;
//         case KC_S: SEND_STRING(/*s*/"tate"); break;
//         case KC_T: SEND_STRING(/*t*/"here"); break;
//         case KC_W: SEND_STRING(/*w*/"ould"); break;
//     }
// }

// uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
//     switch (keycode) {
// #include "self_handled_alt_reps.def"
//     }
//     return KC_TRNS;
// }


// Tri-layer state as a possible future addition.
// layer_state_t layer_state_set_user(layer_state_t state) {
//   state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
//   state = update_tri_layer_state(state, _RAISE, _SYMB, _SPECIAL);
//   return state;
// }



oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _BASE:
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }


        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUM ") : PSTR("    "), false);
        if (led_usb_state.caps_lock | is_caps_word_on()) { // either capitalization feature
            oled_write_P("CAP", false);
            oled_write_P(led_usb_state.caps_lock   ? PSTR("LCK ") : PSTR("WRD "), false);
        } else {
            oled_write_P("       ", false);
        }
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
        oled_write_P(is_swap_hands_on() ? PSTR("SH") : PSTR("  "), false);
        oled_write_P(PSTR("\n"), false);

        // Write mod state
        mod_state = get_mods() | get_oneshot_mods();
        oled_write_P(mod_state & MOD_MASK_GUI ? PSTR("G") : PSTR(" "), false);
        oled_write_P(mod_state & MOD_BIT(KC_LALT) ? PSTR("A") : PSTR(" "), false);
        oled_write_P(mod_state & MOD_BIT(KC_RALT) ? PSTR("R") : PSTR(" "), false);
        oled_write_P(mod_state & MOD_MASK_CTRL ? PSTR("C") : PSTR(" "), false);
        oled_write_P(mod_state & MOD_MASK_SHIFT ? PSTR("S") : PSTR(" "), false);


    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}

