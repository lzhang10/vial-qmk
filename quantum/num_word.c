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

#include "num_word.h"
#include "timer.h"
#include "action_layer.h"

/** @brief True when Num Word is armed. */
static bool armed = false;

/** @brief Layer typed from while armed. */
static uint8_t target_layer = 0;

#if NUM_WORD_IDLE_TIMEOUT > 0
// Constrain timeout to a sensible range. With 16-bit timers, the longest
// timeout possible is 32768 ms, rounded here to 30000 ms = half a minute.
#    if NUM_WORD_IDLE_TIMEOUT < 100 || NUM_WORD_IDLE_TIMEOUT > 30000
#        error "NUM_WORD_IDLE_TIMEOUT must be between 100 and 30000 ms"
#    endif

/** @brief Deadline for idle timeout. */
static uint16_t idle_timer = 0;

void num_word_task(void) {
    if (armed && timer_expired(timer_read(), idle_timer)) {
        num_word_disarm();
    }
}

void num_word_reset_idle_timer(void) {
    idle_timer = timer_read() + NUM_WORD_IDLE_TIMEOUT;
}
#else
void num_word_task(void) {}
#endif // NUM_WORD_IDLE_TIMEOUT > 0

void num_word_arm(uint8_t target) {
    if (armed) {
        // Re-target: turn off the current target layer, turn on the new one.
        if (target_layer != target) {
            layer_off(target_layer);
            target_layer = target;
            layer_on(target_layer);
        }
    } else {
        armed        = true;
        target_layer = target;
        layer_on(target_layer);
        num_word_set_user(true);
    }
#if NUM_WORD_IDLE_TIMEOUT > 0
    num_word_reset_idle_timer();
#endif // NUM_WORD_IDLE_TIMEOUT > 0
}

void num_word_disarm(void) {
    if (!armed) {
        return;
    }

    armed = false;
    layer_off(target_layer);
    target_layer = 0;
    num_word_set_user(false);
}

bool is_num_word_on(void) {
    return armed;
}

uint8_t num_word_target_layer(void) {
    return target_layer;
}

__attribute__((weak)) void num_word_set_user(bool active) {}
