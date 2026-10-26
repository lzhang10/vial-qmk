// Copyright 2026 lzhang
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "process_num_word.h"
#include "num_word.h"
#include "keycodes.h"
#include "quantum_keycodes.h"

/**
 * @brief Keycodes that keep the Num Word mode armed.
 */
static bool is_num_word_keep_keycode(uint16_t keycode) {
    switch (keycode) {
        // Digits. KC_0 sorts after KC_9, so the top row is listed as a
        // range plus the zero. The numpad digits are not contiguous.
        case KC_1 ... KC_9:
        case KC_0:
        case KC_P1:
        case KC_P2:
        case KC_P3:
        case KC_P4:
        case KC_P5:
        case KC_P6:
        case KC_P7:
        case KC_P8:
        case KC_P9:
        case KC_P0:
        case KC_MINS:
        case KC_EQL:
        case KC_DOT:
            return true;
        default:
            return false;
    }
}

/**
 * @brief Layer keycodes that do not affect the Num Word mode.
 */
static bool is_num_word_layer_keycode(uint16_t keycode) {
    switch (keycode) {
        case QK_MOMENTARY ... QK_MOMENTARY_MAX:
        case QK_TO ... QK_TO_MAX:
        case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
        case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
        case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
        case QK_PERSISTENT_DEF_LAYER ... QK_PERSISTENT_DEF_LAYER_MAX:
            return true;
        default:
            return false;
    }
}

bool process_num_word(uint16_t keycode, keyrecord_t* record) {
    // TG(n) arms (or re-targets) the mode on press. Consume press and
    // release so the standard toggle action never fires. A release that
    // falls through would be re-derived as TG by process_action_record()
    // and execute the stock toggle, fighting the mode.
    if (keycode >= QK_TOGGLE_LAYER && keycode <= QK_TOGGLE_LAYER_MAX) {
        if (record->event.pressed) {
            num_word_arm(QK_TOGGLE_LAYER_GET_LAYER(keycode));
        }
        return false;
    }

    // Other releases never change the mode. Pass through.
    if (!record->event.pressed) {
        return true;
    }

    if (!is_num_word_on()) {
        return true;
    }

    // Keycodes that keep the mode armed. The key processes normally with
    // the target layer on.
    if (is_num_word_keep_keycode(keycode) || is_num_word_layer_keycode(keycode)) {
#if NUM_WORD_IDLE_TIMEOUT > 0
        num_word_reset_idle_timer();
#endif
        return true;
    }

    // Any other keycode disarms the mode. The key then processes normally
    // on the restored layer state.
    num_word_disarm();
    return true;
}
