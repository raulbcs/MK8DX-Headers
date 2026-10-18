# Vt12cb2c8

Unnamed derived parameter-table record of Vt12cb108. No RTTI. Adds a
0x10-byte tail (+0x360..+0x36f) of extra parsed fields; all 7 inherited
slots are the shared base implementations; slot 0 is the parse override.

GOT cell convention: cell 0x1310710 holds vptr-0x10; installed vptr =
cell + 0x10.

## Init / sites

- Construction (in a byml-consuming loader function): `mov w21, #0x370;
  bl _Znwm` at 0x816d34 → C1 0x8144d0 (0x816d40) → vptr override (cell
  0x1310710) → zero +0x360 (`str xzr,[x22,#0x360]` and byte +0x365) →
  derived parse 0x816a74 (this, node) — which is also vtable slot 0.
  Size 0x370 EXACT.
- Parse override 0x816a74: calls base 0x8147d8 first, then parses:
  +0x360 u16 (key 0xedb0e2e, via 0x8d1d80), +0x362 byte (key 0xedb0e33),
  +0x2e2 u16 flag (key 0xf0b0d8d), +0x364 optional u32 (key 0xf0b0d86),
  +0x368 optional u32 (key 0xf0b0e2e), +0x36c (key 0xf0b0e2e, via
  0x8d1414).

## Member notes

- Base body 0x08..0x35f as documented in doc/game/Vt12cb108.md.
- The 0x365 byte store is part of zeroing the tail before parse.

## Slots (8)

+0x00 0x816a74 (parse override, see above), +0x08..+0x38 the seven
shared base slots 0x81517c / 0x8151a4 / 0x8151c0 / 0x8151e8 / 0x815204 /
0x815254 / 0x81525c (see doc/game/Vt12cb108.md). Unrecovered FUN_*.

## Construction / init order

1. `new 0x370` (0x816d34).
2. C1 0x8144d0 (base defaults, vptr 0x12cb108).
3. vptr override to 0x12cb2c8; zero +0x360..+0x36c region.
4. Parse 0x816a74 (base parse + extra tail keys).
