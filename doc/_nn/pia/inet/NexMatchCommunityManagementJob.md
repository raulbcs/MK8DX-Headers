# NexMatchCommunityManagementJob (nn::pia::inet::NexMatchCommunityManagementJob)

## Identity

- NAME CORRECTION (2026-10-17, worktree vt-map/19c): previously documented as
  "NexFacade". The typeinfo record 0x12dad80 name reference 0xf7f0f0 points at
  the EXACT START of the pool string "N2nn3pia4inet30NexMatchCommunityManagementJobE"
  (pool = table of 4-byte self-relative offsets followed by strings; there is no
  0x10-byte pool header and the string does not land inside any NexFacade text).
  The real nn::pia::inet::NexFacade is vptr 0x12d9808 (doc/_nn/pia/inet/NexFacade.md).
- vt_ctors.tsv row 0x12dad10 is the typeinfo slot, not the vptr. Layout:
  [0x12dad08] = offset-to-top 0, [0x12dad10] = typeinfo record 0x12dad80,
  vptr 0x12dad18 = row start (13 slots).
- GOT cell 0x1312c00 holds addend 0x12dad08 = vt-0x10; code (0x93c8f0) does
  `ldr cell; add #0x10; str [this]`.
- Typeinfo record 0x12dad80 = {0x10, 0xf7f0f0, base 0x12dd8e0}; base chain
  (0x12dd8e0 → 0x12f8d30) matches the nex-DDL job registry family, consistent
  with the NexMatchCommunityManagementJob identity.

## Slots (vptr 0x12dad18, 13 slots)

- slot 0 = 0x93c914 (tail `b 0x97dff8` — shared D2).
- slot 1 = 0x93c918 (D0: calls 0x97dff8, no operator delete in the tail).
- slots 2..12 = 0xb4a654 (40 B), 0xb4a67c (108 B), 0x933314, 0x93dd44,
  0x93dd20, 0x93c93c, 0x93d0dc, 0x93d358, 0x93d5d4, 0x93d850, 0x93dab8 — all
  functions.csv-unrecovered.

## Member notes

- 0x00..0x60 — base subobject: base C1 0x97dfc0 installs base vptr 0x12dd878
  (cell 0x1313690 + 0x10), zeroes [this+0x58], tail-calls 0x929ec0 with
  this+0x60; base D0 0x97dff8 re-installs the base vptr, advances x0 by 0x60
  and calls 0x929ee0 — so the base part is 0x60 bytes.
- 0x88 — word 0; 0x90/0x98 — zeroed pair; 0xa0 — byte 1 (ctor 0x93c8d4).

## Construction / init order

1. In-place construction inside FUN_7100931598 (call 0x931d7c `bl 0x93c8d4`).
2. Ctor 0x93c8d4: base C1 0x97dfc0 (base vptr 0x12dd878, +0x58 zero, tail
   0x929ec0 at this+0x60), then [this+0x88] = 0, [this+0x90]/[this+0x98] = 0,
   vptr 0x12dad18 at [this] (0x93c8fc), byte [this+0xa0] = 1.
