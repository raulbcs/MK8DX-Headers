# LanSessionSearchCriteria (nn::pia::lan::LanSessionSearchCriteria)

## Identity

- Assigned row 0x12dc970 is the TYPEINFO SLOT, not the vptr: [0x12dc970] =
  0x12dc9a0 (reloc) = typeinfo record {0x10, name 0xf80d70, base 0x12de790}.
  Name is exact: "N2nn3pia3lan24LanSessionSearchCriteriaE". Base record
  0x12de790 = "N2nn3pia7session21SessionSearchCriteriaE" (root).
- Installed vptr = 0x12dc978 (row+8), 5 slots.
- GOT cell 0x13133e8 holds addend 0x12dc968 = vt-0x10; code (C1 0x973a74 at
  0x973a8c) does `ldr cell; add #0x10; str [this]`.
- Extent 0x258 LOWER BOUND: C1 0x973a74 (ends 0x973b94, interior of merged blob
  FUN_7100972b54) writes 0x254; no allocation site found.

## Slots (vptr 0x12dc978, 5 slots)

- slot 0 = 0x973b98 (D1: 4-byte tail `b 0x99d2b0` = base SessionSearchCriteria
  D2).
- slot 1 = 0x973b9c (D0: base D2 then `operator delete` 0x60b470).
- slot 2 = 0x99d2e4 (error-code setter: stores 0x10000|0xc08 = 0x0c08_0000 via
  [x8]).
- slot 3 = 0x973bc0 (functions.csv-unrecovered).
- slot 4 = 0x9748f4 (functions.csv-unrecovered).

## Member notes

- 0x0c — C1 sets 100.
- 0x14 — C1 zero pair; 0x1c/0x6c/0x15c/0x1ac — four 0x50-byte blocks memset
  to 0 (0x973ad0/0x973b30/0x973b50/0x973b70).
- 0x200..0x253 — zeroed flag/counter block (individual stores
  0x973b20..0x973b84; split unverified).
- 0x24a..0x251 — C1 sets 0xffff; 0x252/0x253 — C1 sets 1; 0x254 — C1 zero.

## Construction / init order

1. C1 0x973a74: base C1 0x99d294 (SessionSearchCriteria) first (0x973a84).
2. vptr 0x12dc978 at [this] (cell 0x13133e8 + 0x10, 0x973ac8).
3. Scalar init (0x0c = 100, 0xffff block, 1-flag bytes), four memsets, and the
   0x200..0x254 zero block.
