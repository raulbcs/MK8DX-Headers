# KartParamCacheVt6e60

## Identity

KartParamCacheVt6e60 — address-anchored name (vptr 0x12b6e60, GOT cell
0x130e1f8; the cell holds vt-0x10, code stores cell+0x10 into [this] at
0x71006c0be0). Single-vptr param-cache variant; no secondary tables.

Size: NOT allocated standalone — constructed in place at outer+0x16a0 by the
big aggregator ctor 0x71006bb300 (member-ctor call at 0x71006bb354). The next
member of that aggregator starts at outer+0x1dd8 (ctor 0x71006e38e0 at
0x71006bb360), bounding this class to 0x738 (0x1dd8 − 0x16a0). C1 0x71006c0b68
proves writes only to 0x558 + member, so 0x738 is an upper bound, not a proven
exact size.

## Vtable (13 slots, row = installed vptr)

- slot 0x00 (0x6c0d44, 192 B) — D1 complete destructor (restores the class
  vptr at 0x6c0d58 before destroying).
- slot 0x08 (0x6c0e04, 36 B) — D0 deleting destructor.
- slot 0x10 (0x6c369c) and slot 0x30 (0x6c3124) — mid-function entries of
  0x71006c2d68 (2360 B; gap-split in file_list); slots 0x18/0x20/0x28
  (0x6c36a0/+4/+8) — tail stubs of the same body. Semantics unverified.
- slots 0x38..0x60 — unmapped thunks 0xeff188/0xeff19b/0xeff1ac/0xeff1c3/
  0xeff1d9 (veneer cluster; unverified).

Lazy-init usage cluster: the cell is re-read and the vptr reinstalled at
0x6b5ee8/0x6b5f20/0x6b6318 and 0x6ebce0-0x6ec778 (in-place re-initialization
of members of this type inside containers), mirroring the lazy-resolver
pattern of ParamChannelVt38f8.

## Member notes

Notes in field order; proven from C1 0x71006c0b68 (base stub 0x71006c6128,
0x6c0b88) unless cited.

- 0x248/0x250/0x258/0x268 — ctor zeros (0x6c0b8c-0x6c0bb0).
- 0x260 — 1.0f; 0x284 — 100.0f (0x6c0bc8/0x6c0bd4).
- 0x264 — flags; 0x30000 forced on at 0x6c0cc0.
- 0x270/0x278/0x280/0x288 — -1 fill (0x6c0cac-0x6c0cec).
- 0x298..0x2e4 — config pair block sourced from global [0x12fadb8]
  (0x6c0ca8-0x6c0d20).
- 0x2a4..0x2ac / 0x2d4..0x2e0 — triples seeded from globals [0x12fce50] /
  [0x12fce10] (0x6c0bd8-0x6c0c18).
- 0x2f0..0x310 — ctor zeros.
- 0x318 — channel-like member: vptr cell 0x12fada0, ctor 0x710061cc48, u32
  0x104 at 0x328 (0x6c0c38-0x6c0c4c); byte from [0x12fada8] copied to
  [vptr] (0x6c0c50-0x6c0c60).
- 0x430 — second member: vptr cell 0x130e200, u32 0x104 at 0x440
  (0x6c0c64-0x6c0c88).
- 0x548/0x550 — ctor zeros.
- 0x558 — member ctor 0x71006461e4 (0x6c0c90-0x6c0c9c).
- Region 0x558..0x738 — unverified (bounded by the aggregator layout).

> Naming: address-anchored; no ctor strings.

## Construction / init order

- Aggregator 0x71006bb300 places this object at outer+0x16a0 and calls C1
  0x71006c0b68 (0x71006bb354).
- C1 field order: base stub, zeros 0x248..0x268, vptr (0x6c0be0), config
  block 0x298..0x2e4, zeros 0x2f0..0x310, 0x318 member, 0x430 member, flags
  0x264/0x270..0x288, 0x548/0x550 zeros, 0x558 member.
