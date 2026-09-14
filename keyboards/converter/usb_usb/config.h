/*
Copyright 2017 Balz Guenat <balz.guenat@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


/* size of virtual matrix
 *
 * Board default: full 16 * 16 (matrix cell == HID usage byte).
 *
 * Vial keymaps override MATRIX_ROWS per keymap (the keymap's config.h is
 * force-included after this file in every TU) to shrink the matrix and fit
 * more dynamic layers into the 1KB EEPROM; the last row is then a packed
 * tail row supplied via CONVERTER_TAIL_ROW. See custom_matrix.cpp and
 * keymaps/lzhang10.advantage2/config.h for details.
 */
#define MATRIX_ROWS 16
#define MATRIX_COLS 16

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
