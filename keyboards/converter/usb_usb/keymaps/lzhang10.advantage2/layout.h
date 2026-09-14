#ifndef LAYOUT_H_
#define LAYOUT_H_

// Ported from qmk_firmware converter/usb_usb/keymaps/lzhang10.advantage2/layout.h
// (lzhang): Kinesis Advantage 2 physical layout mapped onto the HID-keycode
// virtual matrix of the usb_usb converter.
//
// The matrix is 8 rows x 16 cols (see CONVERTER_TAIL_ROW in config.h):
//   rows 0-6: natural mapping, cell == HID usage byte (0x00-0x6F, incl. F13-F20)
//   row 7:    packed tail row: F21-F24 (reserved), then the eight modifier
//             usages 0xE0-0xE7, then invalid cells
// Only the LAYOUT_kinesis macro is kept; every cell is a named parameter.

/* Parameter names (position in the call, not the cell):
 * F-row:    LF0-LF8 = Esc,F1-F8    RF0-RF8 = F9-F12,Mute,Vol-,Vol+,(unused x2)
 * Num-row:  L00-L05 = EQL 1-5      R00-R05 = 6-9 0 MINS
 * Alpha:    L10-L15 = TAB Q W E R T   R10-R15 = Y U I O P LBRC RBRC BSLS
 *           L20-L25 = CAPS A S D F G  R20-R25 = H J K L SCLN QUOT
 *           L30-L35 = LSFT Z X C V B  R30-R35 = RSFT COMMA DOT SLSH ENT SPC
 * Misc:     L41-L44 = GRV BSLS(intl-\) LEFT RGHT  R41-R44 = UP DOWN LBRC RBRC
 *           LT1-LT6 = LCTL LALT HOME BSPC DEL END
 *           RT1-RT6 = RGUI RCTL PGUP PGDN ENT SPC
 * Reserved: F13-F24 (no physical keys; cells exist in the matrix for later use)
 */
#define LAYOUT_kinesis( \
    LF0, LF1, LF2, LF3, LF4, LF5, LF6, LF7, LF8, RF0, RF1, RF2, RF3, RF4, RF5, RF6, RF7, RF8, \
    L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35, R30, R31, R32, R33, R34, R35, \
    L41, L42, L43, L44, R41, R42, R43, R44, \
    LT1, LT2, LT3, LT4, LT5, LT6, RT1, RT2, RT3, RT4, RT5, RT6, \
    F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24) \
{ \
    { KC_NO, KC_NO, KC_NO, KC_NO, L21, L35, L33, L23,      /* 00-07 */ \
      L13, L24, L25, R20, R12, R21, R22, R23 },            /* 08-0F */ \
    { R31, R30, R13, R14, L11, L14, L22, L15,              /* 10-17 */ \
      R11, L34, L12, L32, R10, L31, L01, L02 },            /* 18-1F */ \
    { L03, L04, L05, R00, R01, R02, R03, R04,              /* 20-27 */ \
      RT5, LF0, LT4, L10, RT6, R05, L00, R43 },            /* 28-2F */ \
    { R44, R15, KC_NO, R24, R25, L41, R32, R33,            /* 30-37 */ \
      R34, L20, LF1, LF2, LF3, LF4, LF5, LF6 },            /* 38-3F */ \
    { LF7, LF8, RF0, RF1, RF2, RF3, RF4, RF5,              /* 40-47 */ \
      RF6, KC_NO, LT3, RT3, LT5, LT6, RT4, L44 },          /* 48-4F */ \
    { L43, R42, R41, KC_NO, KC_NO, KC_NO, KC_NO, L42,      /* 50-57 */ \
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, /* 58-5F */ \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /* 60-67 */ \
      F13, F14, F15, F16, F17, F18, F19, F20 },            /* 68-6F */ \
    { F21, F22, F23, F24, LT1, L30, LT2, KC_NO,            /* 70-77: tail row */ \
      RT2, R35, KC_NO, RT1, KC_NO, KC_NO, KC_NO, KC_NO }   /* 78-7F */ \
}

#endif // LAYOUT_H_
