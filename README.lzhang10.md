# cheapino

```
qmk compile -kb cheapino -km vial
```

Then press and hold RESET, then BOOT, then release RESET then BOOT.

copy cheapino_vial.uf2 to the device then eject the volume.

## Num word (number layer mode)

The vial keymap builds with `NUM_WORD_ENABLE` (set in
`keyboards/cheapino/keymaps/vial/rules.mk`). It turns a `TG: Layer n` key into a
Caps-Word style number layer mode. Assign one key to `TG: Layer n` in the VIAL
web UI. No keymap code change is needed.

Behavior:

- Tap the assigned key: the mode arms, layer n turns on and stays on. The
  standard `TG` toggle action does not fire (both press and release are
  consumed by the feature).
- While armed, keep-set keys keep the mode on: `0`-`9`, numpad `P0`-`P9`,
  `-`, `+`, `.`. They type from layer n.
- Layer keys (`MO`, `TO`, `TT`, `OSL`, `DF`, PDF) do not affect the mode.
  One-shot layer keys keep their standard behavior.
- `TG(m)` re-targets the mode to layer m while armed.
- Any other key disarms the mode, turns layer n off, and types itself on the
  previous layer. Note: the trigger key reads its keycode from layer n while
  armed. If it is `KC_NO` (or any non-keep key) on layer n, pressing it
  disarms. Bind `TG(n)` to it on layer n as well if you want a re-target
  instead.
- 5 seconds of idle disarms the mode. Configurable with
  `NUM_WORD_IDLE_TIMEOUT` (ms).

Implementation (board-agnostic, mirrors the Caps Word structure):

- `quantum/num_word.c` / `num_word.h` — mode state, arm/disarm, idle timeout
  task (runs in the housekeeping loop).
- `quantum/process_keycode/process_num_word.c` / `.h` — process_keycode
  handler. Intercepts `TG(n)` before action processing and consumes press and
  release so the stock toggle never fires. A release that fell through would
  be re-derived as `TG` by `process_action_record()` and execute the stock
  toggle, fighting the mode.
- Wiring: `builddefs/generic_features.mk` (`NUM_WORD` in `GENERIC_FEATURES`),
  `builddefs/show_options.mk`, `quantum/quantum.c` (process chain),
  `quantum/keyboard.c` (task).

Behavior change on cheapino: `TG(n)` no longer acts as a true layer toggle.
It arms the num word mode. Other keymaps are unaffected (flag unset).
