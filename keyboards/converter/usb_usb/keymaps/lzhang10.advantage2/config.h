// Copyright lzhang 2026
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// Three Vial-editable layers.
//
// The virtual matrix of converter/usb_usb is 8x16 for this keymap (below):
// rows 0-6 keep the natural HID-usage mapping (cell == usage byte,
// 0x00-0x6F, which includes F13-F20) and row 7 is a packed tail row
// (CONVERTER_TAIL_ROW) holding F21-F24 and the eight modifier usages that
// the converter synthesizes from the HID report's modifier byte. Vial stores
// DYNAMIC_KEYMAP_LAYER_COUNT * 8 * 16 * 2 = 768 bytes in the ATmega32u4's
// 1KB EEPROM, leaving room for eeconfig/qmk_settings/macros (~196B left over).
#define DYNAMIC_KEYMAP_LAYER_COUNT 3

// Vial+QMK_SETTINGS defines CHORDAL_HOLD (builddefs/build_vial.mk), which
// makes the generated default_keyboard.c initialize
// chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] from the keyboard info.json's
// 16-row LAYOUT_all - too many rows for the shrunken matrix. Chordal hold is
// not useful on this virtual matrix anyway, so drop it (all users of
// CHORDAL_HOLD are #ifdef-guarded, so this is self-consistent).
#undef CHORDAL_HOLD

// The shared board default is 16x16 (keyboards/converter/usb_usb/config.h);
// this keymap only needs 8 rows. The keymap config.h is included after the
// keyboard's in every TU, so this overrides the board default.
#undef MATRIX_ROWS
#define MATRIX_ROWS 8

// Tail row 7: cols 0-3 = F21-F24 (reserved), cols 4-11 = the eight modifier
// usages 0xE0-0xE7, cols 12-15 = invalid (0xFF). Consumed by
// custom_matrix.cpp; see the comment there for the mapping rules.
#define CONVERTER_TAIL_ROW { 0x70, 0x71, 0x72, 0x73, 0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xFF, 0xFF, 0xFF, 0xFF }

// Identifies this keyboard to the Vial web interface (distinct from the
// lzhang10.magic keymap).
#define VIAL_KEYBOARD_UID {0x6A, 0x16, 0x4E, 0xB8, 0xD8, 0xB8, 0x4A, 0x4E}

// The default Vial unlock combo (both Shifts + both Ctrl held) cannot work on
// this virtual matrix: all eight modifier keys are synthesized into one tail
// row (cols 4-11), so two of them can never occupy distinct matrix rows.
// VIAL_INSECURE in rules.mk skips the unlock combo entirely (recommended for
// this single-user converter device). The definitions below exist only to
// satisfy vial.c.
#define VIAL_UNLOCK_COMBO_ROWS { 7, 7 }
#define VIAL_UNLOCK_COMBO_COLS { 4, 5 }
