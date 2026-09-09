// Copyright lzhang 2026
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// One Vial-editable layer.
//
// The virtual matrix of converter/usb_usb is 16x16 (matrix cell = HID keycode
// bits), and Vial stores DYNAMIC_KEYMAP_LAYER_COUNT * 16 * 16 * 2 bytes in the
// ATmega32u4's 1KB EEPROM. Two layers would need exactly 1024B for the keymap
// alone, leaving no room for eeconfig/qmk_settings/etc., so 1 is the maximum
// that fits. Remap everything in the Vial web UI on this single layer.
#define DYNAMIC_KEYMAP_LAYER_COUNT 1

// Identifies this keyboard to the Vial web interface.
#define VIAL_KEYBOARD_UID {0x5A, 0x3C, 0x91, 0x7B, 0xE4, 0x2D, 0x86, 0xF0}

// The default Vial unlock combo (both Shifts + both Ctrl held) cannot work on
// this virtual matrix: all eight modifier keys are synthesized into row 14
// (cols 0-7), so two of them can never occupy distinct matrix rows. VIAL_INSECURE
// in rules.mk skips the unlock combo entirely (recommended for this single-user
// converter device). The definitions below exist only to satisfy vial.c.
#define VIAL_UNLOCK_COMBO_ROWS { 14, 14 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }
