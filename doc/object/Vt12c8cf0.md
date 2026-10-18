# object::Vt12c8cf0

PLACEHOLDER name (identity not proven). Minimal Vt12c8698 derivative. vptr
0x12c8cf0, 11 slots, typeinfo NULL. GOT cell 0x13101b8 holds vt-0x10;
installed vptr = cell + 0x10.

## Member notes

- Size proven: `operator new(0x78)` at 0xcc858-0xcc868 (orr w0, #0x78), ctor
  FUN_71007e9adc at 0xcc868; cached at [mgr+0x138] (selector array, 8-entry
  stride like siblings).
- Only [this+0x70] = 0 beyond the base layout (0x7e9af8).
- Slot 1 = 0x7e9b10 (`ret` — override stub). Slot 2 = 0x7e9b14: large frame
  fn loading floats from [[this+8]+0x98+0xb0] and constants -5/-2/-3, calling
  0x7e1d3c — vector math helper (unverified).
- Slots 4/5 = 0x7e9b14-region neighbors: slot4 0x7e9b14 (fn above), slot5
  0x7e9fc0 (unrecovered); slot7 0x7e9fcc, slot8 0x7e9fd4 (unrecovered).

## Construction / init order

- C1 = FUN_71007e9adc: base ctor 0x7e0848 (0x7e9aec), then vptr cell
  0x13101b8 (+0x10) stored at 0x7e9b00.
- Slot 0 = 0xd1198 (`ret`, family D1); slot 3 = 0x7e2384, slot 6 = 0xd11a8
  (family forwarder), slot 9 = 0xd11c4 (ret 0), slot 10 = 0x7e092c (family
  vec3 getter).
