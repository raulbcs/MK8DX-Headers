# KartParamCacheVtba248

## Identity

KartParamCacheVtba248 — address-anchored name (vptr 0x12ba248). NOT a primary
row: 0x12ba248 is the SECONDARY interface vtable (13 slots) installed at
[this+0x248]; the primary vtable is 0x12ba1f0. Both come from one cell:
0x130e330 holds 0x12ba1e0; code stores cell+0x10 (0x12ba1f0) at [this] and
cell+0x68 (0x12ba248) at [this+0x248] (sites 0x6dd1ec-0x6dd20c; other install
sites 0x6dac94, 0x6db36c, 0x6dd8f0, 0x7243a4, and the element loop at
0xaa54fc-0xaa5674).

Size: NOT allocated standalone — constructed in place at outer+0x4d00 by the
big aggregator ctor 0x71006bb300 (member-ctor call 0x71006bb390 to C1
0x71006dd190). The next member of that aggregator starts at outer+0x54b8
(ctor 0x7100730fc8 at 0x71006bb39c), bounding this class to 0x7b8
(0x54b8 − 0x4d00). C1 writes reach 0x7a0, consistent with the bound; 0x7b8 is
an upper bound, not a proven exact size.

## Secondary vtable (row 0x12ba248)

- slot 0x00 (0x6ddaac, 8 B) — dtor thunk: `sub x0, x0, #0x248` then tail-call
  0x6dd8d8 (468 B D1 body).
- slot 0x08 (0x6ddad8) — deleting-dtor thunk (adjust −0x248; nearby 0x6ddab4
  calls 0x6dd8d8 then operator delete 0x60b470). Thunk body unverified
  (gap-merged with 0x6ddaac in file_list).
- slots 0x10..0x60 — shared interface band: 0x63c6f8 (ret 1), 0x63c700 (ret),
  0x63c704 (ret 1), slot 0x28 = 0x6e0280 (mid-entry of 0x71006e0248, 112 B;
  own override, semantics unverified), 0x63c710 (paramCacheSharedTypeIdEquals)
  at 0x30, 0x63c724/0x63c728 (ret), 0x669208 (agl::Debug::xml loader),
  0x66979c, 0x6697f8 (record-apply pair), 0x63c72c (ret).

## Member notes

Notes in field order; proven from C1 0x71006dd190 (base stub 0x71006c6128,
name 0xf028cf at 0x6dd1d8) unless cited.

- 0x00 — primary vptr 0x12ba1f0.
- 0x248 — secondary vptr 0x12ba248.
- 0x418..0x438 — ctor zeros (0x6dd1e8-0x6dd21c).
- 0x488 — member init entered at 0x6dd214 (flags 0x2/0x40 written; interior
  unproven).
- 0x590 / 0x610 / 0x690 / 0x710 — ctor-assigned words (0x6dd87c-0x6dd894).
- 0x698 — member ptr (0x6dd784).
- 0x718 / 0x738 — channel-pair members (ctor pair 0x7100662f30/0x7100662f70,
  0x6dd7a4-0x6dd810) with counts at 0x730/0x750.
- 0x758..0x798 — zeros/ptrs (0x6dd81c-0x6dd870).
- 0x7a0 — ctor value (0x6dd864).
- Region 0x7a4..0x7b8 — unverified (bounded by the aggregator layout).
- Array-element usage: the 0xaa54fc-0xaa5674 cluster installs this secondary
  vptr into array elements at element+0x08 (via `stur x11, [x9, #-0x4a]` at
  0x6dacb8 with element base +0x52) — secondary-interface embedding, unverified
  details.

> Naming: address-anchored; no ctor strings.

## Construction / init order

- Aggregator 0x71006bb300 places this object at outer+0x4d00 and calls C1
  0x71006dd190 (0x71006bb390).
- C1 field order: base stub 0x6dd1b4, name/string setup, both vptrs
  (0x6dd204/0x6dd20c), zeros 0x418..0x438, 0x488 member, mid-body members,
  channel pairs 0x718/0x738, tail fields to 0x7a0.
