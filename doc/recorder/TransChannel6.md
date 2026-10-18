# recorder::TransChannel6 (vtable 0x12c3ff0)

## Identity

Quantized "trans" recorder channel, token size 6. Created only by
recorderCreateRotTransChannels_71007ae16c when its kind argument (w2) is 0, allocating 0x288
bytes (`mov w0, #0x288` at 0x7ae27c) and installing vptr 0x12c3ff0 from GOT cell 0x130f918
(cell holds 0x12c3fe0 = vt-0x10; vptr = cell+0x10, single site 0x7ae2b0). 35 slots, no RTTI.
Sibling of TransChannel4 (0x12c4118, kind 1, token 4).

## Member notes

- 0x1c0 u32 = 12 — value count; matches the +0x110 writer slot recorderWrite3Ints_71007ae328.
- 0x1c4 u32 = 6 — token size in bytes; "RecorderMatrix33fComp6" at 0xf0a986 plausibly names the
  format; direct reference unverified.
- 0x1f0/0x1f4/0x1f8 float min/step/inv-step = 0.2 / 16.0 / 0.0625, written by the factory after
  the addChannel call (0x7ae2f8-0x7ae314, via `[parent+0x280]`).
- 0x278 zeroed (0x7ae2c0); 0x280 = factory arg x1 (owning ChannelSet, 0x7ae2d0).
- Slots: slot0 0x7ae75c / slot1 FUN_71007ae764 (U, 1484 B — dtor pair, split unverified).
  +0x140 FUN_71007b4764 (M), +0x150 FUN_71007b49fc (M), +0x170 FUN_71007b4ad8 (O), +0x190
  FUN_71007b42ec (M) — the trans read/write path shared with TransChannel4.

## Construction / init order

1. `operator new(0x288)` (0x7ae27c).
2. recorderBinderCtor_71007aae24 on the raw object (0x7ae284) — shared base init; inheritance
   unverified.
3. vptr = [0x130f918] + 0x10 stored at [this] (0x7ae2cc); numValues 12 at +0x1c0 (0x7ae2c8),
   token 6 at +0x1c4 (0x7ae2c4), zero at +0x278, owner at +0x280.
4. Registered via recorderAddChannel_71007ac0cc(parent, this, "trans" @0xf0a969) (0x7ae2f0);
   min/step/inv-step constants land at +0x1f0/+0x1f4/+0x1f8 afterwards.
