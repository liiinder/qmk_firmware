#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_80_iso_with_macro(
    _______,            KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,               KC_MPLY,
    KC_F1,   KC_F2,     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,               KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_BSPC,  KC_PGUP,
    KC_F3,   KC_F4,     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,              KC_PGDN,
    KC_F5,   KC_F6,     KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,      KC_HOME,
    KC_F7,   KC_F8,     KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,               KC_UP,  KC_END,
    KC_F9,   KC_F10,    KC_LCTL, KC_LGUI, KC_LALT, MO(1),   _______,  KC_SPC,                     _______,   KC_ENT,  KC_RALT, KC_RCTL, _______,          KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [1] = LAYOUT_80_iso_with_macro(
    KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                        KC_MUTE,
    RGB_HUI, RGB_HUD,   KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO, KC_NO, KC_NO,
    RGB_SAI, RGB_SAD,   KC_NO, KC_NO, KC_UP,   RGB_TOG, RGB_MOD, KC_NO,                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          
    RGB_VAI, RGB_VAD,   KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO,                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    _______, KC_NO, _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case 0:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
                }
            } else if (index == 1) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            }
            break;
        case 1:
            if (index == 1) {
                if (clockwise) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
                }
            }
            break;
    }
    return false;
}