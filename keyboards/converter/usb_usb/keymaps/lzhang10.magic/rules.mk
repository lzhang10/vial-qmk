VIA_ENABLE = yes
VIAL_ENABLE = yes
VIAL_INSECURE = yes
LTO_ENABLE = yes

# Feature matrix (each option verified one-by-one against the ATmega32u4
# 28672B flash budget; VIA+VIAL vendor interface costs ~5.3KB over plain QMK):
#   fits:  QMK_SETTINGS (+4916B), CAPS_WORD (+588B), LAYER_LOCK (+370B)
#   no fit: TAP_DANCE (+1790B), COMBO (+2266B), KEY_OVERRIDE (+1772B),
#           REPEAT_KEY (+1414B)
# LAYER_LOCK is off here to match the pre-VIA keymap; enabling it leaves
# only 224B free (28448/28672) instead of 594B.
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
QMK_SETTINGS = yes
TAP_DANCE_ENABLE = no
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = no
KEY_OVERRIDE_ENABLE = no
LAYER_LOCK_ENABLE = no
REPEAT_KEY_ENABLE = no

# Two Vial-editable layers (10x16 virtual matrix x 2B = 320B per layer;
# see config.h for the matrix shrink and the EEPROM budget).
DYNAMIC_KEYMAP_LAYER_COUNT = 2
