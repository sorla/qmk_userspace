#include QMK_KEYBOARD_H
#include "keymap_uk.h"
#include "keymap_plover.h"

#define ___x___ KC_NO
#define GO_PLV TO(_PLOVER)
#define GO_MPAD TO(_MPAD)

#define OS_CTL OSM(MOD_LCTL)
#define OS_SFT OSM(MOD_LSFT)
#define OS_ALT OSM(MOD_LALT)
#define OS_GUI OSM(MOD_LGUI)
#define OS_RAL OSM(MOD_RALT)

// Set up for alt-tab macro
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

 enum plaid_layers {
    _PLOVER,
    _MPAD,
 };

 // macro keys
 enum plaid_keycodes {
	 ALT_TAB = SAFE_RANGE,
     QTY_OFF,
};
// #include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_PLOVER] = LAYOUT_plaid_grid(
         PV_LS,   PV_LT,   PV_LP,   PV_LH, PV_STAR, ___x___, PV_STAR,   PV_RF,   PV_RP,   PV_RL,   PV_RT,   PV_RD,
         PV_LS,   PV_LK,   PV_LW,   PV_LR, PV_STAR, ___x___, PV_STAR,   PV_RR,   PV_RB,   PV_RG,   PV_RS,   PV_RZ,
       ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,
       GO_MPAD, ___x___,  PV_NUM,    PV_A,    PV_O,  PV_NUM,    PV_E,    PV_U,  PV_NUM, ___x___, ___x___, ___x___
       ),


	[_MPAD] = LAYOUT_plaid_grid(
		 KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   RESET, KC_PPLS,  KC_P7,   KC_P8,   KC_P9, KC_PSLS,
		 KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_NUM,  KC_TAB,  KC_P4,   KC_P5,   KC_P6, KC_BSPC,
		KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18, ___x___, KC_PMNS,  KC_P1,   KC_P2,   KC_P3, KC_PAST,
	    OS_GUI,  OS_ALT,  OS_SFT,  OS_CTL,  KC_F19,  KC_F20,  GO_PLV, KC_PENT,  KC_P0, KC_PDOT, KC_PCMM, KC_PEQL
        ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case ALT_TAB:
			  if (record->event.pressed) {
				if (!is_alt_tab_active) {
				  is_alt_tab_active = true;
				  register_code(KC_LALT);
				}
				alt_tab_timer = timer_read();
				register_code(KC_TAB);
			  } else {
				unregister_code(KC_TAB);
			  }
			  break;

        case QTY_OFF:
			  if (record->event.pressed) {
                  SEND_STRING("off");
              }
              break;

		  }

    return true;
};

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }

    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case _PLOVER:
            writePinHigh(LED_RED);
			writePinLow(LED_GREEN);
            break;

        case _MPAD:
            writePinHigh(LED_GREEN);
			writePinLow(LED_RED);
            break;

		default:
            writePinLow(LED_GREEN);
            writePinLow(LED_RED);
    }
}

void matrix_init_user(void) {
	eeconfig_init();
}
