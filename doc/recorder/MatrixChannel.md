# recorder::MatrixChannel (vtable 0x12c4538)

## Identity

Quantized recorder channel created in bulk by ICF-folded ctor FUN_71007b100c (11 call sites; installs base vptr 0x12c4788 from cell 0x130fb08, copies 4 param ptrs, zeros tail — allocation happens in the callers): a loop at 0x7b1280-0x7b1324
allocates `operator new(0x298)` per channel index and installs vptr 0x12c4538 from GOT cell
0x130fb20 (cell holds 0x12c4528 = vt-0x10; vptr = cell+0x10, single site 0x7b1284). Loop count =
`[owner+0x288]` (int, checked >= 1 at 0x7b1274). 35 slots, no RTTI. Same family as the
rot/trans channels of recorder::ChannelSet (vtable layout identical through the shared tail).

## Member notes

- 0x1c0/0x1c4: single u64 store 0x700000007 | 0x10 << 0 (0x7b12e0) → +0x1c0 = 0x10,
  +0x1c4 = 7. Under the QuantChannel layout (doc/recorder/QuantChannel.md) these are numValues
  and token size in bytes; the token reading is unverified for this class (7 is outside the
  documented 1/4/6 set).
- 0x278 = owner (the x19 setup object); 0x280 = [owner+0x278] — a cross-link to the owner's
  first channel, both stored at 0x7b12c0/0x7b12c8.
- 0x288 u32 = channel index (loop counter w23); 0x28c u8 = 0; 0x290/0x294 float = 0.1f each
  (thresholds, purpose unverified).
- Slots: slot0 0x7b24f4 / slot1 FUN_71007b25c0 (W — dtor pair, split unverified); slot2
  FUN_71007b261c (W, 316 B). Write path slots +0x190 FUN_71007b0178 (W, 1224 B), +0x1c0
  FUN_71007b0640 (W, 1072 B) — larger than the rot/trans writers, consistent with the
  16-value payload.

## Construction / init order (per element, loop 0x7b12a8-0x7b131c)

1. `operator new(0x298)` (0x7b12ac).
2. recorderBinderCtor_71007aae24 on the raw object (0x7b12b8) — shared base init; inheritance
   unverified.
3. vptr = [0x130fb20] + 0x10 stored at [this] (0x7b12bc); owner/peer/index/flags/threshold
   stores at 0x7b12c0-0x7b12e0.
4. Element pointer stored into the owner's channel array `[owner+0x2b8] + idx*8`
   (0x7b12e4-0x7b12f8; array base + count live at owner +0x2b8/+0x2b0).
5. recorderAddChannel_71007ac0cc(owner, this, NULL) registers it (0x7b1314).
