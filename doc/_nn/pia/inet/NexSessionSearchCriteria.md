# NexSessionSearchCriteria (nn::pia::inet::NexSessionSearchCriteria)

## Identity

- Assigned row 0x12da340 is the TYPEINFO SLOT, not the vptr: [0x12da340] =
  0x12da370 (reloc) = typeinfo record {0x10, name 0xf7e9a0, base 0x12de790}.
  Name is exact: "N2nn3pia4inet22NexSessionSearchCriteriaE". Base record
  0x12de790 = "N2nn3pia7session21SessionSearchCriteriaE" (root, base 0).
- Installed vptr = 0x12da348 (row+8), 5 slots.
- GOT cell 0x1312970 holds addend 0x12da338 = vt-0x10; code (C1 0x933694 at
  0x9336b0) does `ldr cell; add #0x10; str [this]`.
- Extent 0xd1c LOWER BOUND: C1 0x933694 (FUN_7100933694, 0x933694..0x93b28)
  writes fields through 0xd18; no allocation site found (always constructed
  into owner subobjects at owner+0x630 and owner+0x1350, callers 0x912cf0 /
  0x912cfc / 0x92ea50 / 0x92ea60).

## Slots (vptr 0x12da348, 5 slots)

- slot 0 = 0x933b28 (D1: reinstalls vptr 0x12da348, dtor 0x92a014 on this+0xa0c,
  tail 0x99d2b0 = base SessionSearchCriteria D2).
- slot 1 = 0x933b60 (D0: same as D1 then `operator delete` 0x60b470).
- slot 2 = 0x933d94 (error-code setter: stores 0x0c07_0000-style code 0x10000|0xc07
  via [x8]; result-code path).
- slot 3 = 0x933ba0 (540 B, functions.csv-unrecovered).
- slot 4 = 0x9351a0 (312 B, functions.csv-unrecovered; preceded by 12 B
  O-function 0x935194).

## Member notes

- 0x9e0 — secondary vptr of nn::pia::common::FixedString<2> (row 0x12d96e8,
  cell 0x1312848); FixedString derives from nn::pia::common::String.
- 0xa28 / 0xa68 / 0xaa8 / 0xb18 — four nn::pia::common::FixedString<8> objects
  (row 0x12d9748, cell 0x1312858); self-pointer members at 0xa30/0xa70/0xab0
  point to internal buffers 0xa44/0xa84/0xac4.
- 0x9ca/0x9cb — C1 sets 1 (flags); 0xa18..0xa1e set 0xffff; 0xa20/0xa21 set 1.
- 0xa38 / 0xa78 — C1 sets 0x20 (capacities).
- 0xd18 — last field written by C1; layout beyond 0xb18 unverified.

## Construction / init order

1. C1 0x933694: base C1 0x99d294 (SessionSearchCriteria), then vptr 0x12da348
   at [this] (cell 0x1312970 + 0x10, 0x9336d8).
2. FixedString<2> vptr at 0x9e0 (cell 0x1312848, 0x9336f0); buffer pointer
   0x9e8 -> 0x9fc.
3. Four FixedString<8> vptrs at 0xa28/0xa68/0xaa8/0xb18 (cell 0x1312858,
   0x93375c..0x933784) with buffer self-pointers.
4. Scalar zero/0xffff/0x20 field init through 0xd18; sub-init 0x929fd4 calls at
   0x933bec..0x933bfc region; dtor path frees this+0xa0c via 0x92a014.
