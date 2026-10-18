# recorder::RotChannel4 (vtable 0x12c4240)

## Identity

Quantized "rot" recorder channel of the ghost/replay recorder framework, token size 4. Created
only by recorderCreateRotTransChannels_71007ae16c when its kind argument (w3) is 0, allocating
0x290 bytes (`mov w0, #0x290` at 0x7ae1b8) and installing vptr 0x12c4240 from GOT cell
0x130f900 (cell holds 0x12c4230 = vt-0x10; vptr = cell+0x10, single site 0x7ae1d0). 35 slots,
no RTTI. Sibling of RotChannel6 (0x12c4368, kind 1, token 6).

## Member notes

- 0x1c0 u32 = 36 — value count; matches the +0x110 writer slot recorderWrite9Ints_71007ae378
  (9 consecutive u32 stores, 36 bytes).
- 0x1c4 u32 = 4 — token size in bytes (QuantChannel layout, doc/recorder/QuantChannel.md). The
  string "RecorderMatrix33fComp4" at 0xf0a96f plausibly names this format; direct reference
  unverified.
- 0x1f0/-0x1f4/+0x1f8 float min/step/inv-step: min = -70.0f (0x7ae21c-0x7ae230), step and
  inv-step loaded from literals at 0xed685c / 0xed6854.
- 0x1fc u8 zeroed by caller 0x3ad6ec (channel-specific post-init).
- 0x278/0x280 zeroed by the factory (0x7ae228, 0x7ae23c); 0x288 = factory arg x1 (the owning
  ChannelSet).
- Slots: slot0 0x7aeabc / slot1 0x7aeb40 (dtor pair, unverified split). +0x110
  recorderWrite9Ints_71007ae378. +0x150 FUN_71007b45a4 (M), +0x170 FUN_71007b462c (O),
  +0x190 FUN_71007adbec (U) / +0x1a0 FUN_71007adca4 (U) — the rot write path, W-rated twins
  0x7adeac/0x7adf64 sit in RotChannel6.

## Construction / init order

1. `operator new(0x290)` (0x7ae1b8).
2. recorderBinderCtor_71007aae24 on the raw object (0x7ae1c4) — shared base init with the
   recorder::Binder layout; formal inheritance unverified.
3. vptr = [0x130f900] + 0x10 stored at [this] (0x7ae244); numValues 36 at +0x1c0 (0x7ae240),
   token 4 at +0x1c4 (0x7ae218), min/step/inv-step at +0x1f0/+0x1f4/+0x1f8, owner at +0x288.
4. Registered via recorderAddChannel_71007ac0cc(parent, this, "rot" @0xf0a965) (0x7ae268).
