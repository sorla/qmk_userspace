#include QMK_KEYBOARD_H
#include "keymap_uk.h"
// #include "custom_keys.h"

/* #define A_GUI GUI_T(KC_A)
#define R_ALTT ALT_T(KC_R)
#define S_SFT SFT_T(KC_S)
#define T_CTRL CTL_T(KC_T)
#define N_CTRL CTL_T(KC_N)
#define E_SFT SFT_T(KC_E)
#define I_ALT ALT_T(KC_I)
#define O_GUI GUI_T(KC_O) */

#define GO_HOME TO(_COLEMAK)
#define GO_NUMS TO(_NUMBERS)
#define GO_NAV TO(_NAV)

#define ESC_NAV LT(_NAV,KC_ESC)
#define ESC_CTL MT(MOD_LCTL,KC_ESC)
#define BSP_NUM LT(_NUMBERS,KC_BSPC)
#define DEL_FUN LT(_FUNCTION,KC_DEL)
#define SPC_NUM LT(_NUMROW,KC_SPC)
#define TAB_ALT MT(MOD_LALT,KC_TAB)

#define OS_CTL OSM(MOD_LCTL)
#define OS_SFT OSM(MOD_LSFT)
#define OS_ALT OSM(MOD_LALT)
#define OS_GUI OSM(MOD_LGUI)
#define OS_RAL OSM(MOD_RALT)

// Shortcuts for Teams
#define TM_QUIT C(S(KC_B))
#define TM_MUTE C(S(KC_M))
#define TM_HAND C(S(KC_K))

 enum plaid_layers {
	 _COLEMAK,
	 _NUMROW,
	 _NAV,
	 _NUMBERS,
	 _FUNCTION,
 };

 // macro keys
//  enum plaid_keycodes {
// 	 COLEMAK = SAFE_RANGE,
// };
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_COLEMAK] = LAYOUT_plaid_grid(
	      KC_Q,    KC_W,    KC_F,    KC_P,    KC_B, _______, TM_QUIT,    KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,
		  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,  KC_EQL, TM_MUTE,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
		  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, _______, TM_HAND,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,
		OS_CTL,  OS_ALT, KC_LGUI, ESC_NAV, KC_BSPC, DEL_FUN,  KC_TAB, SPC_NUM,  KC_ENT, GO_NUMS,  OS_RAL, UK_HASH),

	[_NAV] = LAYOUT_plaid_grid(
		_______, _______, _______, _______, _______, _______, _______, _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP,
		KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, _______, C(KC_S), KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
		_______, _______, _______, KC_RALT, _______, _______, _______,  KC_APP, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, GO_HOME, _______
        ),

    [_NUMROW] = LAYOUT_plaid_grid(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		   KC_8,    KC_6,    KC_2,    KC_0, _______, _______, _______, _______,    KC_3,    KC_1,    KC_7,    KC_9,
		_______, _______, _______,    KC_4, _______, _______, _______, _______,    KC_5, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        ),

	[_NUMBERS] = LAYOUT_plaid_grid(
		   KC_7,    KC_6,    KC_5,    KC_4, KC_MINS, _______, _______, _______, _______, _______, _______, _______,
		   KC_3,    KC_2,    KC_1,    KC_0,  KC_EQL, _______, _______, _______, _______, _______, _______, _______,
	    KC_SLSH,  KC_DOT,    KC_9,    KC_8, KC_COLN, _______, _______, _______, _______, _______, _______, _______,
		 KC_TAB, GO_HOME, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        ),

	[_FUNCTION] = LAYOUT_plaid_grid(
		_______, _______, _______, _______, _______, QK_BOOT, _______,  KC_F15,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
		KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, _______,  KC_F13,   KC_F1,   KC_F2,   KC_F3,   KC_F4,
		_______, _______, _______, KC_RALT, _______, _______, _______,  KC_F14,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        ),

};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {


//         case STP_CAP:
// 			  if (record->event.pressed) {
//                   SEND_STRING(". ");
//                   set_oneshot_mods(MOD_MASK_SHIFT);
//               }
//               break;

//     return true;
//     }
// };

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case _NUMBERS:
            writePinHigh(LED_GREEN);
			writePinLow(LED_RED);
            break;
        case _NUMROW:
            writePinHigh(LED_RED);
			writePinLow(LED_GREEN);
            break;
		case _FUNCTION:
			writePinHigh(LED_GREEN);
			writePinHigh(LED_RED);
			break;
		default:
            writePinLow(LED_GREEN);
            writePinLow(LED_RED);
    }
}

void matrix_init_user(void) {
	eeconfig_init();
}
