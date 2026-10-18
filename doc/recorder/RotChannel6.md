# recorder::RotChannel6 (vtable 0x12c4368)

## Identity

Quantized "rot" recorder channel, token size 6. Created only by
recorderCreateRotTransChannels_71007ae16c when its kind argument (w3) is 1, allocating 0x290
bytes (`mov w0, #0x290` at 0x7ae1ec) and installing vptr 0x12c4368 from GOT cell 0x130f908
(cell holds 0x12c4358 = vt-0x10; vptr = cell+0x10, single site 0x7ae200). 35 slots, no RTTI.
Sibling of RotChannel4 (0x12c4240, kind 0, token 4).

## Member notes

- 0x1c0 u32 = 36 — value count (same writer shape as RotChannel4; the +0x110 slot
  FUN_71007ae3d0, U, 88 B, mirrors recorderWrite9Ints_71007ae378).
- 0x1c4 u32 = 6 — token size in bytes; "RecorderMatrix33fComp6" at 0xf0a986 plausibly names the
  format; direct reference unverified.
- 0x1f0/-0x1f4/+0x1f8 float min/step/inv-step: min = -70.0f, step literal at 0xed6858, inv-step
  at 0xed6854.
- 0x278/0x280 zeroed (0x7ae228, 0x7ae23c); 0x288 = factory arg x1 (owning ChannelSet).
- Slots: slot0 0x7aec58 / slot1 0x7aed30 (W, 5192 B — dtor pair, the second entry unusually
  large; split unverified). +0x150 FUN_71007b46a4 (M), +0x170 FUN_71007b4714 (O), +0x190
  FUN_71007adeac (W) / +0x1a0 FUN_71007adf64 (W) — rot write path; +0x1d0 FUN_71007ae74c (U).

## Construction / init order

1. `operator new(0x290)` (0x7ae1ec).
2. recorderBinderCtor_71007aae24 on the raw object (0x7ae1f4) — shared base init; inheritance
   unverified.
3. vptr = [0x130f908] + 0x10 stored at [this] (0x7ae244); numValues 36, token 6,
   min/step/inv-step, owner — same store block as RotChannel4 (0x7ae214-0x7ae24c).
4. Registered via recorderAddChannel_71007ac0cc(parent, this, "rot" @0xf0a965) (0x7ae268).
