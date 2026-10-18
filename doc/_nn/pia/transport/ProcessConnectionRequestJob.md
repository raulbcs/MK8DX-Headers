# nn::pia::transport::ProcessConnectionRequestJob

## Identity

- vtable row 0x12deec8 (tsv row = typeinfo slot), vptr 0x12deed0 = row + 8,
  6 slots. GOT cell 0x1313b68 holds 0x12deec0 = vptr - 0x10 (offset-to-top
  0x12deec0 = 0, typeinfo slot 0x12deec8 = 0x12def00); installed vptr =
  cell + 0x10.
- RTTI: typeinfo 0x12def00 = {0x10, name 0xf821f0, base 0x12f8d30}; name =
  "N2nn3pia9transport27ProcessConnectionRequestJobE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x9a7000, 1 D0 0x9a7068, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5 `ret` 0x9a79c4 (bare `ret`).
- D1 0x9a7000 / D0 0x9a7068: re-install vptr, destroy the +0x78 heap
  sub-object — if its [sub+0] state == 1 run 0x929f78(sub) first, then
  0x929ee0(sub), free 0x568b64(sub), null [this+0x78]; tail 0xb4a62c
  (D0 then adds operator delete 0x60b470).
- extent 0x88 EXACT: operator new 0x88 at 0x9b17c4 (factory caller
  0x9b17d8, stored at [owner+0x60]), sole site found.

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58: ptr, zeroed by C1.
- +0x60 u32 = 10000 (timeout/budget).
- +0x64: 8 bytes zeroed (stur xzr, [x19, #0x64]).
- +0x70: ptr stored by member fn 0x9a70d8 (Process(body): takes a handler
  object, calls its vtable slot +0x10 with flag 0x8000000, runs 0x929f00
  on the +0x78 sub-object, inspects [handler+0x30] == 3).
- +0x78: separately allocated 0x20-byte sub-object (alloc 0x568aa0 at
  0x9a6fd8, ctor 0x929ec0 at 0x9a6fe8).

## Construction / init order

1. C1 0x9a6f9c: base C1 0xb4a5e0(this) (0x9a6fac).
2. [this+0x58] = 0 (0x9a6fb8).
3. vptr 0x12deed0 -> [this] (0x9a6fc0, cell 0x1313b68 + 0x10).
4. [this+0x60] = 10000 (0x9a6fc8).
5. sub = alloc 0x20 (0x9a6fd8); 0x929ec0(sub) (0x9a6fe8); sub -> [this+0x78]
   (0x9a6fec).
6. [this+0x64] = 0 (0x9a6ff0).
