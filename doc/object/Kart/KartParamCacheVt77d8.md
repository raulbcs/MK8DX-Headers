# KartParamCacheVt77d8

## Identity

KartParamCacheVt77d8 — address-anchored name (vptr 0x12b77d8, GOT cell
0x130e238; the cell holds vt-0x10, code stores cell+0x10 into [this] at
0x71006cb098; second install site 0x71006cc3a4 = D1 slot 0).

Size 0xb060 proven by the member slot in factory 0x717900: operator
new(0x5bc10) at 0x710071790c builds a huge aggregator; this class is the
member at outer+0x4d8 (C1 call 0x7100717954) and the next member starts at
outer+0xb538 (ctor 0x7100719f3c at 0x7100717964) → 0xb538 − 0x4d8 = 0xb060.

## Vtable (13 slots, row = installed vptr)

- slot 0x00 (0x6cc394, 1340 B) — D1 complete destructor (restores the class
  vptr at 0x6cc3a4).
- slot 0x08 (0x6cc8d0, 104 B) — D0 deleting destructor.
- slot 0x10 (0x6cbc74, 88 B) and slot 0x20 (0x6cbccc, 108 B) and slot 0x28
  (0x6cbd38, 452 B) — own overrides (semantics unverified).
- slot 0x18/0x38/0x40/0x60 — shared `ret` stubs (0x63c700/0x63c724/0x63c728/
  0x63c72c).
- slot 0x30 (0x63c710, paramCacheSharedTypeIdEquals) — shared ID compare.
- slots 0x48/0x50/0x58 — shared record trio (0x669208 agl::Debug::xml loader,
  0x66979c, 0x6697f8).

## Member notes

Notes in field order; proven from C1 0x71006cb040 (base Mid2 ctor 0x7100668d40
at 0x6cb088) unless cited.

- 0x1d0 — member ctor 0x710066a2a4 (0x6cb0a4).
- 0x200 — member ctor 0x7100669954, vptr cell 0x130e240; u8 @0x248 zeroed
  (0x6cb0a8-0x6cb0c8).
- 0x250 — member ctor 0x71006cb614 (0x6cb0cc); interior unproven.
- 0x9b50..0xa550 — ring of 32 entries, stride 0x50, built by the ctor loop
  0x6cb11c-0x6cb158 (ctor pair 0x7100662f30 + 0x710061cc48; vptr cells
  0x130d910 / 0x130d9a0-0x9a8 / 0x12fb728; a config byte from [0x12fada8]
  copied into each entry).
- 0xa550 / 0xa6b0 / 0xa810 / 0xa970 / 0xaad0 / 0xac30 / 0xad90 / 0xaef0 —
  eight members, stride 0x160, ctor 0x71006cabb0 (0x6cb164-0x6cb1f8).
- 0xb050 — -1; 0xb054 — 1; 0xb058 — 0 (0x6cb208-0x6cb228).
- 0x6cb22c — call 0x710071b5e4(this, 0, [cell 0x130d800]+0x70).
- Registration/name-table calls 0x7100669a10 and 0x7100669c4 with strings
  0xf01023 / 0xf0102b / 0xf01036 / 0xf0104b (0x6cb248-0x6cb2b4).

> Naming: address-anchored; no ctor strings.

## Construction / init order

- Factory 0x717900: operator new(0x5bc10) (0x71790c), member ctor 0x710071830c
  at +0x0 (0x71793c), then this class at +0x4d8 via C1 0x71006cb040
  (0x717954); afterwards +0xb538 (0x719f3c) and +0xb550 (0x6fe734), fields
  +0xbc00/+0xbc08 zeroed.
- C1 field order: base 0x7100668d40, name 0xf01023, vptr (0x6cb098), 0x1d0,
  0x200, 0x250 members, ring 0x9b50 (32 × 0x50), eight 0x160 members, tail
  flags, aggregator call, registrations.
