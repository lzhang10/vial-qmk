// Copyright lzhang 2026
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "layout.h"

// lzhang: idle wake - tap KC_SYSTEM_WAKE after 4m30s without key input, so the
// host PC does not fall asleep while the keyboard is attached. Ported from the
// lzhang10.magic Vial keymap (it originally lived in the old
// converter/usb_usb custom_matrix.cpp, which is disabled for Vial builds).
// 32-bit timers, since a uint16_t 570000ms limit wraps to ~45s.
static uint32_t last_activity_timer = 0;
#define IDLE_WAKE_LIMIT_MS 270000 // 4m30s in milliseconds

void matrix_scan_user(void) {
    if (timer_elapsed32(last_activity_timer) > IDLE_WAKE_LIMIT_MS) {
        tap_code(KC_SYSTEM_WAKE); // harmless key press to keep the system awake
        last_activity_timer = timer_read32();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        last_activity_timer = timer_read32();
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: standard Kinesis Advantage 2 layout, plain keycodes, three Vial-editable
     *    layers. Same physical wiring as the QMK lzhang10.advantage2 BASE layer
     *    (see LAYOUT_kinesis), but every customized keycode replaced by the
     *    plain standard code of the physical key it sits on. Differences from
     *    the QMK BASE: LF0-LF5 are KC_ESC/KC_F1-F5 (QMK has app-launcher
     *    unicode/tapdances there), L10 is KC_TAB (QMK: KC_CAPS), L20 is
     *    KC_CAPS (QMK: MS_BTN3), the A-S-D-F-G/N-M row customs are plain
     *    letters, R05 is KC_MINS and R15 is KC_BSLS (QMK swaps them), L43/R42
     *    are KC_LEFT/KC_DOWN etc. (QMK also plain there), and the bottom
     *    cluster is plain LCTL/LALT/BSPC/DEL/HOME/END and RGUI/RCTL/PGUP/
     *    PGDN/ENT/SPC (QMK: layer taps/combos). RF7/RF8 are adv2-internal
     *    Keypad/Progrm keys with no matrix wiring.
     *
     *    Remap everything in the Vial web UI across the three layers.
     */
    [0] = LAYOUT_kinesis(
    KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,      KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_MUTE, KC_VOLD, KC_VOLU, XXX, XXX,
                          KC_EQL,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
                          KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
                          KC_CAPS, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
                          KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                KC_GRV,  KC_BSLS, KC_LEFT, KC_RGHT,                       KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,
                                                    KC_LCTL, KC_LALT, KC_HOME, KC_BSPC, KC_DEL,  KC_END,
                                                                      KC_RGUI, KC_RCTL, KC_PGUP, KC_PGDN, KC_ENT,  KC_SPC,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO  // F13-F24: reserved in the matrix for later use
    ),
};
