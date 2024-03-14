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
