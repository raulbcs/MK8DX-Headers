# object::KartParamCacheVt2cc8

KartParamCacheVt2cc8 — KartParamCache-family node, size-derived placeholder name.
vptr 0x12b6fa8, GOT cell 0x130e220 holds 0x12b6f98 = vt-0x10; installed vptr =
cell+0x10 = 0x12b6fa8 (C1 0x6c6550). Kart-param family evidence: slots 6-8 are the
shared paramNode stubs 0x647f60/0x647f68/0x647f6c and slot3 0x647f48.

Size 0x2cc8: outer aggregate C1 0x6cb614 constructs elements of exactly 0x2cc8
stride at +0x0/+0x2cc8/+0x5990/+0x8658/+0xb320/+0xdfe8/+0x10cb0/+0x13978/... with
this C1 (0x6cb624-0x6cb7f0). D1 stores reach 0x2ca8.

## Member notes

Notes in field order; proven from the cited addresses; unverified marked "unverified".

- 0x00 — vptr 0x12b6fa8 (0x6c658c-0x6c6590).
- 0x08..0x38 — member band built by 0x66a2a4 (this+0x30) and 0x64897c (this+0x60)
  (0x6c6574-0x6c659c); exact member sizes unverified.
- 0x488 — 50 x 0x20 member objects, each vptr cell 0x130d908+0x10, C1 0x662f30
  (loop 0x6c65b8-0x6c65d8).
- 0xac8 — second 50 x 0x20 member array, same vptr (loop 0x6c65e0-0x6c6604).
- 0x1108 — member C1 0x64bd90 (0x6c6610); 0x1118-0x1128 zeroed; 0x1130 vptr
  cell 0x12fada0 → later 0x12fdb0 (0x6c6644/0x6c6678); 0x1138 self ptr; 0x1140
  = 0x40; 0x1144 u16.
- 0x1188 — -1 (0x6c6684); 0x1198 — vptr cell 0x130d9b8+0x10, member C1 0x662f30;
  repeats at 0x11b8/0x11d8/0x11f8/0x1218/0x1238/... (0x6c668c-0x6c6708).
- 0x11a0..0x2cc8 — unverified member band (C1 body continues to 0x6cb614); the D1
  0x6cbf0c re-stamps the shared base-cluster vptr (cell 0x130d918+0x10) at
  0x2aa8-0x2ca8.

Slots: slot0 0x6cbf0c (D1, 1120 B), slot1 0x6cc36c (D0, 40 B, tail operator delete),
slot2 0x6ca368 (568 B), slot3 0x647f48 (paramNodeSharedNopSlot5), slot4 0x6ca340
(40 B), slot5 0x6ca5a0 (1512 B), slot6 0x647f60 (ret-1), slot7 0x647f68 (nop),
slot8 0x647f6c (paramNodeSharedTypeIdEquals). Slots 9+ read into non-code data —
vtable has 9 slots.

## Construction / init order

1. Outer aggregate C1 0x6cb614 calls this C1 0x6c6550 per 0x2cc8 element.
2. C1 0x6c6550: base/member C1 0x66a2a4, vptr store (0x6c658c), member arrays at
   0x488/0xac8, 0x64bd90 member, string-flag member (delimiter byte from cell
   0x12fada8, 0x6c6668), then the 0x1198+ member series, ending 0x6cb614.
3. Destruction: D1 0x6cbf0c re-stamps vptr and the base-cluster member vptrs;
   D0 0x6cc36c tail-calls operator delete.
