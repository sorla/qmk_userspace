#include QMK_KEYBOARD_H
#include "keymap_uk.h"
#include "keymap_steno.h"
#include "custom_keys.h"

// for the microscope, and anywhere else that needs a counter
uint8_t file_counter = 0;
// Things to make sarcasm case a reality...
bool sarcasm_case = false;
bool sarcasm_shift = false;

enum ferris_layers {
    _COLEMAK,
    _NAV,
    _NUMBERS,
    _MATHS,
    _FUNCTION,
    _MOUSE,
    _LHNAV,
};


 // macro keys
enum ferris_keycodes {
    STP_CAP = SAFE_RANGE,
    ALT_TAB,
    QTY_OFF,
    EM_WORK,
    EM_HOME,
    EXPN,
    W_THE, WS_THE,
    MIC_CAP,
    FC_RST,
    FC_INS,
    SARCASM,
};

// Set up for alt-tab macro
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

// All the combo magic
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_COLEMAK] = LAYOUT(
	      KC_Q,    KC_W,   KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,
		 A_GUI,   R_ALT,  S_CTL,   T_NAV,    KC_G,    KC_M,   N_NUM,   E_CTL,   I_ALT,   O_GUI,
		  KC_Z,    KC_X, C_RALT,  D_MOUS,    KC_V,    KC_K,   H_FUN, CM_RALT,  KC_DOT, KC_SLSH,
		                         ESC_ALT, BSP_SFT, SPC_CTL, ENT_GUI ),


// NOT NEEDED? OR MAKE SYMBOLS
	[_MATHS] = LAYOUT(
	      KC_Q,    KC_W,   KC_F,    KC_P, GO_HOME, GO_HOME, _______, _______, _______, _______,
		  KC_8,    KC_6,   KC_2,    KC_0,    KC_G,    KC_M,    KC_3,    KC_1,    KC_7,    KC_9,
	   _______,    KC_X,   KC_C,    KC_4,    KC_V,    KC_K,    KC_5, KC_COMM,  KC_DOT, KC_SLSH,
		                         _______, _______, _______, _______ ),

	[_NAV] = LAYOUT(
	  KC_PSCR,  KC_APP, KC_LSFT, _______, GO_HOME, GO_HOME, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,
	  KC_LGUI, KC_LALT, KC_LCTL, _______, OS_RALT, C(KC_V), KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,
	  C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y), C(KC_C), KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,
		                         _______, _______, _______, _______ ),
// CALL SOL, MAYBE REARRANGE NUMBERS
	[_NUMBERS] = LAYOUT(
	      KC_7,    KC_6,   KC_5,    KC_4, GO_HOME, GO_HOME,    KC_L,    KC_U,    KC_Y, KC_QUOT,
	      KC_3,    KC_2,   KC_1,    KC_0, KC_MINS,    KC_M, _______,  OS_CTL,  OS_ALT,  OS_GUI,
	   KC_SLSH,  KC_DOT,   KC_9,    KC_8,    KC_X,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,
		                         _______, _______, _______, _______ ),

	// [_MOUSE] = LAYOUT(
	//      KC_Q,    KC_W,    KC_F,    KC_P, GO_HOME, GO_HOME, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
	//    OS_GUI,  OS_ALT,  OS_CTL,  OS_CTL, OS_RALT, C(KC_V), KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
	//   C(KC_Z), C(KC_X), C(KC_C), _______, C(KC_Y), C(KC_C), KC_BTN1, KC_BTN2, KC_BTN3, KC_MPLY,
	// 	                         _______, _______, _______, _______ ),
    [_MOUSE] = LAYOUT(
	     KC_Q,    KC_W,    KC_F,    KC_P, GO_HOME, GO_HOME, SARCASM, MIC_CAP,  FC_INS,   FC_RST,
	  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, OS_RALT, C(KC_V), EM_HOME, EM_WORK,  WS_THE,    W_THE,
	  C(KC_Z), C(KC_X), KC_RALT, _______, C(KC_Y), C(KC_C), KC_BTN1, KC_BTN2, KC_BTN3, KC_MPLY,
		                         _______, _______, _______, _______ ),
// SWAP HANDS
	[_FUNCTION] = LAYOUT(
	    KC_F12, KC_F11, KC_F10,  KC_F9,  OS_ALT, GO_HOME,  KC_F9,  KC_F10, QK_MAKE, QK_BOOT,
	     KC_F4,  KC_F3,  KC_F2,  KC_F1,  OS_CTL, OS_RALT, _______, OS_CTL, OS_ALT,   OS_GUI,
		 KC_F8,  KC_F7,  KC_F6,  KC_F5,  OS_SFT, _______, _______,  KC_F6,  KC_F7,   KC_F8,
		                            _______, _______, _______, _______ ),
    [_LHNAV] = LAYOUT(
	  KC_PSCR, KC_HOME,   KC_UP,  KC_END, KC_PGUP, KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_PSCR,
	  KC_LALT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_LALT,
	  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, GO_HOME, GO_HOME, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,
		                         ESC_SFT, BSP_CTL, _______, _______ ),

};

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case A_GUI:
        case R_ALT:
        case S_CTL:
        case T_NAV:
        case D_MOUS:
        case C_RALT:
        case N_NUM:
        case E_CTL:
        case I_ALT:
        case O_GUI:
        case H_FUN:
        case CM_RALT:
        case WS_THE:
            return true;
        default:
            return false;
    }
}
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (sarcasm_case) {
    // quit if esc, sarcasm or caps hit
    switch (keycode) {
      case KC_CAPS:
      case ESC_ALT:
      case SARCASM:
        if (record->event.pressed) {
            sarcasm_case = false;
        }
        return false;
      case KC_A ... KC_Z:
      case A_GUI:
      case R_ALT:
      case S_CTL:
      case T_NAV:
      case D_MOUS:
      case C_RALT:
      case N_NUM:
      case E_CTL:
      case I_ALT:
      case O_GUI:
      case H_FUN:
      case BSP_SFT:
        if (record->event.pressed) {
            tap_code(KC_CAPS);
        }
    }
    // Every time we type a character, we alternate caps lock. Might not play well with nav
    // or word boundaries, but should be fine for the purpose of conveying sarcasm...

  }


  mod_state = get_mods()|get_weak_mods();
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

    case STP_CAP:
      if (record->event.pressed) {
        SEND_STRING(". ");
        set_oneshot_mods(MOD_MASK_SHIFT);
        }
      break;

    case QTY_OFF:
      if (record->event.pressed) {
        SEND_STRING("off");
      }
      break;

    case EM_HOME:
        if (record->event.pressed) {
            SEND_STRING("alan.bloomer\"gmail.com");} break;

    case EM_WORK:
        if (record->event.pressed) {
            SEND_STRING("alan.bloomer\"kanthal.com");} break;
    case EXPN:
        if (record->event.pressed) {
          SEND_STRING("exponential ");} break;

    case W_THE:
      if (!record->event.pressed){
        if ((mod_state & MOD_MASK_SHIFT) && (mod_state & MOD_MASK_CTRL)) {
          del_mods(MOD_MASK_CTRL);
          SEND_STRING("They ");
        }
        else if (mod_state & MOD_MASK_SHIFT) {SEND_STRING("The ");}
        else if (mod_state & MOD_BIT(KC_RALT)) {
          del_mods(MOD_BIT(KC_RALT));
          SEND_STRING("their ");
        }
        else if (mod_state & MOD_BIT(KC_LALT)) {
          del_mods(MOD_BIT(KC_LALT));
          SEND_STRING("them ");
        }
        else if (mod_state & MOD_MASK_CTRL) {
          del_mods(MOD_MASK_CTRL);
          SEND_STRING("they ");
        }
        // else if (mod_state & MOD_BIT(KC_LALT)) {
        //   del_mods(MOD_MASK_ALT);
        //   SEND_STRING("Their ");
        // } With Alt, the menu is activated before you get to send the code...
        else {SEND_STRING("the ");}
      }
      break;
    case MIC_CAP:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F8)SS_TAP(X_RGHT)"\b\b");
        send_byte( file_counter) ;
        file_counter++;
      }
      break;
    case FC_RST:
      if (record->event.pressed) {
        file_counter = 0;
      }
      break;

    case FC_INS:
      if (record->event.pressed) {
        //char str[3];
        //sprintf(str, "%02d", file_counter);
        // send_string(str);
        send_byte(/*string( sprintf("%02d", */file_counter );
        file_counter++;
      }
      break;
    case SARCASM:
      if (record->event.pressed) {sarcasm_case = true; SEND_STRING("SaRcAsM AcTiVaTeD");}
      break;

  }
  return true;
};


void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case WS_THE:
            if (shifted) {SEND_STRING("The ");} else {SEND_STRING("the ");};
            break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

void matrix_init_user(void) {
	eeconfig_init();
}
