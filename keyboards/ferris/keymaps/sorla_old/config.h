#pragma once

// HOME ROW MODS
#define TAPPING_TERM 150
#define IGNORE_MOD_TAP_INTERRUPT
// #define TAPPING_FORCE_HOLD
// #define PERMISSIVE_HOLD

#define AUTO_SHIFT_MODIFIERS
#define AUTO_SHIFT_TIMEOUT 130
#define RETRO_SHIFT 1000

#define COMBO_TERM 45
#define TAPPING_TOGGLE 2

// Set the mouse settings to a comfortable speed/accuracy trade-off,
// assuming a screen refresh rate of 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
#define MOUSEKEY_INTERVAL 25
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#define MOUSEKEY_DELAY 100
// It makes sense to use the same delay for the mouseweel
#define MOUSEKEY_WHEEL_DELAY 100
// The default is 100
#define MOUSEKEY_WHEEL_INTERVAL 50
// The default is 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100


#undef EE_HANDS
#define MASTER_RIGHT
#undef DIRECT_PINS
#define DIRECT_PINS { \
    { E6, F7,     F6,     F5,     F4 }, \
    { B1, B3,     B2,     B6,     D3 }, \
    { D1, D0,     D4,     C6,     D7 }, \
    { B4, B5, NO_PIN, NO_PIN, NO_PIN } \
}


#undef DIRECT_PINS_RIGHT
#define DIRECT_PINS_RIGHT { \
    { F4, F5,     F6,     F7,     E6 }, \
    { D3, B6,     B2,     B3,     B1 }, \
    { D7, C6,     D4,     D0,     D1 }, \
    { B5, B4, NO_PIN, NO_PIN, NO_PIN } \
}
