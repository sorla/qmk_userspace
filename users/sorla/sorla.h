#pragma once
#include "keycodes.h"
#include "keymap_uk.h"
// clang-format off

// Aliases
#define	SO_ESC	LT(_NAV, KC_ESC)
#define	SO_BSPC	KC_BSPC
#define	SO_DEL	KC_DEL
#define SO_SPC  LT(_SYM, KC_SPC)
#define SO_ENT  LT(_FUNCTION, KC_ENT)
#define	SO_TAB	KC_TAB
#define	SO_CAPS	KC_CAPS
#define ADJUST  MO(_ADJUST)
#define WORDS   MO(_WORDS)

#define SO_Q    UK_Q    // Q
#define SO_W    UK_W    // W
#define SO_F    UK_F    // F
#define SO_P    UK_P    // P
#define SO_B    UK_B    // B
#define SO_J    UK_J    // J
#define SO_L    UK_L    // L
#define SO_U    UK_U    // U
#define SO_Y    UK_Y    // Y
#define SO_QUOT UK_QUOT // '
#define SO_A    UK_A    // A
#define SO_R    UK_R    // R
#define SO_S    UK_S    // S
#define SO_T    UK_T    // T
#define SO_G    UK_G    // G
#define SO_M    UK_M    // M
#define SO_N    UK_N    // N
#define SO_E    UK_E    // E
#define SO_I    UK_I    // I
#define SO_O    UK_O    // O
#define SO_Z    GUI_T(UK_Z)    // Z
#define SO_X    ALT_T(UK_X)    // X
#define SO_C    ALGR_T(UK_C)    // C
#define SO_D    CTL_T(UK_D)    // D
#define SO_V    UK_V    // V
#define SO_K    UK_K    // K
#define SO_H    CTL_T(UK_H)    // H
#define SO_COMM ALGR_T(UK_COMM) // ,
#define SO_DOT  ALT_T(UK_DOT)  // .
#define SO_SLSH GUI_T(UK_SLSH) // /

#define SO_GRV  UK_GRV  // `
#define SO_1    UK_1    // 1
#define SO_2    UK_2    // 2
#define SO_3    UK_3    // 3
#define SO_4    UK_4    // 4
#define SO_5    UK_5    // 5
#define SO_6    UK_6    // 6
#define SO_7    UK_7    // 7
#define SO_8    UK_8    // 8
#define SO_9    UK_9    // 9
#define SO_0    UK_0    // 0
#define SO_MINS UK_MINS // -
#define SO_EQL  UK_EQL  // =
#define SO_LBRC UK_LBRC // [
#define SO_RBRC UK_RBRC // ]
#define SO_SCLN UK_SCLN // ;
#define SO_HASH UK_HASH // #
#define SO_BSLS UK_BSLS // (backslash)
#define SO_NOT  UK_NOT  // ¬
#define SO_EXLM UK_EXLM // !
#define SO_DQUO UK_DQUO // "
#define SO_PND  UK_PND  // £
#define SO_DLR  UK_DLR  // $
#define SO_PERC UK_PERC // %
#define SO_CIRC UK_CIRC // ^
#define SO_AMPR UK_AMPR // &
#define SO_ASTR UK_ASTR // *
#define SO_LPRN UK_LPRN // (
#define SO_RPRN UK_RPRN // )
#define SO_UNDS UK_UNDS // _
#define SO_PLUS UK_PLUS // +
#define SO_LCBR UK_LCBR // {
#define SO_RCBR UK_RCBR // }
#define SO_COLN UK_COLN // :
#define SO_AT   UK_AT   // @
#define SO_TILD UK_TILD // ~
#define SO_PIPE UK_PIPE // |
#define SO_LABK UK_LABK // <
#define SO_RABK UK_RABK // >
#define SO_QUES UK_QUES // ?
#define SO_BRKP UK_BRKP // ¦
#define SO_EURO UK_EURO // €
#define SO_EACU UK_EACU // É
#define SO_UACU UK_UACU // Ú
#define SO_IACU UK_IACU // Í
#define SO_OACU UK_OACU // Ó
#define SO_AACU UK_AACU // Á

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case SO_Z:
        case SO_X:
        case SO_C:
        case SO_D:
        case SO_V:
        case SO_K:
        case SO_H:
        case SO_COMM:
        case SO_DOT:
        case SO_SLSH:
        case SO_A:
        case SO_R:
        case SO_S:
        case SO_T:
        case SO_G:
        case SO_M:
        case SO_N:
        case SO_E:
        case SO_I:
        case SO_O:
        case SO_Q:
        case SO_W:
        case SO_F:
        case SO_P:
        case SO_B:
        case SO_J:
        case SO_L:
        case SO_U:
        case SO_Y:
        case SO_QUOT:
            return true;
        default:
            return false;
    }
}


enum custom_keycodes {
    ALTREP2 = SAFE_RANGE,
    ALTREP3,
    KC_MAKE,
    #include "enumfile.def"
};
