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

#pragma once

#include <stdbool.h>
#include <stdint.h>

#ifndef NUM_WORD_IDLE_TIMEOUT
#    define NUM_WORD_IDLE_TIMEOUT 5000 // Default timeout of 5 seconds.
#endif

/** @brief Housekeeping task for the Num Word feature. */
void num_word_task(void);

#if NUM_WORD_IDLE_TIMEOUT > 0
/** @brief Resets timer for Num Word idle timeout. */
void num_word_reset_idle_timer(void);
#endif

/** @brief Arms Num Word for the given target layer. Re-targets if already armed. */
void num_word_arm(uint8_t target_layer);

/** @brief Disarms Num Word. */
void num_word_disarm(void);

/** @brief Gets whether currently armed. */
bool is_num_word_on(void);

/** @brief Gets the target layer while armed. */
uint8_t num_word_target_layer(void);

/**
 * @brief Num Word set callback.
 *
 * @param active True if Num Word is armed, false otherwise
 */
void num_word_set_user(bool active);
