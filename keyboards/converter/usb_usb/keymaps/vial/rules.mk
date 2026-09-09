VIAL_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
# All eight modifiers live in row 14 of this virtual matrix, so Vial's default
# 4-key unlock combo (both Shifts + both Ctrl, which needs two distinct rows)
# can never be formed and could false-trigger on degenerate cells. Skip the
# unlock: Vial is always available on the web UI.
VIAL_INSECURE = yes
# Size: ATmega32u4 flash budget - see continuation notes
KEY_OVERRIDE_ENABLE = no
LAYER_LOCK_ENABLE = no
REPEAT_KEY_ENABLE = no
COMBO_ENABLE = no
QMK_SETTINGS = yes
# See config.h - one editable layer is the maximum that fits in 1KB EEPROM.
DYNAMIC_KEYMAP_LAYER_COUNT = 1
