# recorder::TransChannel4 (vtable 0x12c4118)

## Identity

Quantized "trans" recorder channel, token size 4. Created only by
recorderCreateRotTransChannels_71007ae16c when its kind argument (w2) is 1, allocating 0x288
bytes (`mov w0, #0x288` at 0x7ae29c) and installing vptr 0x12c4118 from GOT cell 0x130f910
(cell holds 0x12c4108 = vt-0x10; vptr = cell+0x10, single site 0x7ae28c). 35 slots, no RTTI.
Sibling of TransChannel6 (0x12c3ff0, kind 0, token 6).

## Member notes

- 0x1c0 u32 = 12 — value count; matches the +0x110 writer slot recorderWrite3Ints_71007ae350.
- 0x1c4 u32 = 4 — token size in bytes; "RecorderMatrix33fComp4" at 0xf0a96f plausibly names the
  format; direct reference unverified.
- 0x1f0/0x1f4/0x1f8 float min/step/inv-step = 0.2 / 16.0 / 0.0625, written by the factory after
  the addChannel call (0x7ae2f8-0x7ae314, via `[parent+0x280]`).
- 0x278 zeroed (0x7ae2c0); 0x280 = factory arg x1 (owning ChannelSet, 0x7ae2d0).
- Slots: slot0 0x7ae8b4 / slot1 FUN_71007ae9d4 (U — dtor pair, split unverified). +0x150
  FUN_71007b45a4 (M), +0x170 FUN_71007b462c (O), +0x190 FUN_71007b42ec (M) — read/write path
  shared with TransChannel6.

## Construction / init order

Identical to TransChannel6 (same code block, kind = 1):
1. `operator new(0x288)` (0x7ae29c).
2. recorderBinderCtor_71007aae24 on the raw object (0x7ae2a4) — shared base init; inheritance
   unverified.
3. vptr = [0x130f910] + 0x10 stored at [this] (0x7ae2cc); numValues 12, token 4, zero at
   +0x278, owner at +0x280.
4. recorderAddChannel_71007ac0cc(parent, this, "trans" @0xf0a969) (0x7ae2f0), then the
   min/step/inv-step constants at +0x1f0/+0x1f4/+0x1f8.
