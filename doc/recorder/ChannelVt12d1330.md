# recorder::ChannelVt12d1330 (0x12d1208's sibling, 0x12d1330)

PLACEHOLDER name. Binder-derived recorder channel, sibling of
recorder::ChannelVt12d1208 (same ctor shape, different overrides).

- Identity: 35 slots (0x12d1330..0x12d1448). No RTTI. GOT cell 0x13111d8
  holds 0x12d1320 (vt-0x10); vptr = cell+0x10. Single code site 0x889928.
- Ctor: FUN_7100889910(this, x1 src) — calls recorderBinderCtor_71007aae24
  (0x889924), installs vptr 0x12d1330 at [this] (0x889930), copies
  [src+8] -> +0x280, zeroes +0x288, copies [src+0] -> +0x278, and writes
  +0x1c0 = 4 / +0x1c4 = 8 (constant pair 0x8_00000004 at 0x88994c).
- Factory: call site 0x8d9574 allocates `new 0x290` (0x8d9560), passes a
  stack-built 2-pointer arg {x20, [x20+0x20]}; enclosing factory unrecovered.
- Extent: 0x290 — factory allocation is exactly 0x290 and deepest store is
  +0x288.

## Member notes

- +0x1c0 = 36-style pair like RotChannel4/6 (+0x1c0 numValues, +0x1c4 token);
  here 4 values of token 8 — cf. "RecorderMatrix33fComp*" naming in
  doc/recorder/RotChannel4.md, link unverified.
- slot10 = 0x889964: stores -1 into +0x288.
- slot17 = 0x889970: reads [this+0x1d4] index (Binder head write index),
  writes u32 from [[this+0x280]+9] and float from [[this+0x280]+0xc]
  (ucvtf of the raw value) into out[idx], out[idx]+4.
- slot19 = 0x889998, slot21 = 0x889c0c, slot23 = 0x889c50, slot25 = 0x8899fc,
  slot28 = 0x889bd8: own block, absent from functions.csv (unrecovered).
- Slots 0/1 = 0x3a8a0c/0x3a8a7c shared Binder pair; slots 2-8 =
  0x88a8d8..0x88a920 (csv U); slot16/18 = 0x88a92c/0x88a934; slot26/27 =
  0x88a93c/0x88a940. Shared tail identical to ChannelVt12d1208.

## Construction / init order

1. Factory builds the 2-pointer arg and allocates 0x290.
2. recorderBinderCtor_71007aae24 initializes the Binder head.
3. vptr 0x12d1330 installed at [this] (0x889930).
4. +0x280 = [src+8], +0x278 = [src], +0x288 = 0, +0x1c0/+0x1c4 = 4/8.
