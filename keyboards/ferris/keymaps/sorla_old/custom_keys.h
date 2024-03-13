// More readable non-keys
// #define _______ KC_TRNS
#define ___x___ KC_NO

// Home row mods
#define A_GUI MT(MOD_LGUI, KC_A)
#define A_SFT MT(MOD_LSFT, KC_A)
#define R_ALT MT(MOD_LALT, KC_R)
#define S_CTL MT(MOD_LCTL, KC_S)
#define T_NAV LT(_NAV, KC_T)
#define D_MOUS LT(_MOUSE, KC_D)
#define C_RALT MT(MOD_RALT, KC_C)

#define N_NUM LT(_NUMBERS, KC_N)
#define E_CTL MT(MOD_RCTL, KC_E)
#define I_ALT MT(MOD_LALT, KC_I)
#define O_GUI MT(MOD_RGUI, KC_O)
#define O_SFT MT(MOD_RSFT, KC_O)
#define H_FUN LT(_FUNCTION, KC_H)
#define CM_RALT MT(MOD_RALT, KC_COMM)



// One shot mods
#define OS_SFT OSM(MOD_LSFT)
#define OS_GUI OSM(MOD_LGUI)
#define ATAB LCA(KC_TAB)
#define OS_ALT OSM(MOD_LALT)
#define OS_CTL OSM(MOD_LCTL)
#define CBSP C(KC_BSPC)
#define OS_RALT OSM(MOD_RALT)
#define OS_FUNC OSL(_FUNCTION)

// Layer manipulation
#define GO_HOME TO(_COLEMAK)
#define GO_NUMS TO(_NUMBERS)
#define GO_MATH TO(_MATHS)
#define MO_FUNC MO(_FUNCTION)
#define GO_NAV TO(_NAV)
#define TO_LHNAV TO(_LHNAV)


#define MO_FUN  MO(_FUNCTION)
#define GO_MOUS TO(_MOUSE)

#define ESC_ALT LT(_NUMBERS, KC_ESC) // MT(MOD_LALT,KC_ESC)
#define ESC_SFT MT(MOD_LSFT,KC_ESC)
#define BSP_SFT SH_T(KC_BSPC) //MT(MOD_LSFT,KC_BSPC)
#define BSP_CTL MT(MOD_LCTL,KC_BSPC)
#define SPC_CTL SH_T(KC_SPC) //MT(MOD_LCTL,KC_SPC)
#define ENT_GUI MT(MOD_LGUI,KC_ENT)

