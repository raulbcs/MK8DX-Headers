# NatPropertyDetecter (nn::pia::nat::NatPropertyDetecter)

## Identity

- vt_ctors.tsv row 0x12dbdb0 is the TYPEINFO SLOT, not the vptr: [0x12dbdb0]
  = 0x12dbe20 (reloc) = typeinfo record {0x10, name 0xf80a00, base 0}. Name is
  exact: "N2nn3pia3nat19NatPropertyDetecterE". Root class (base record 0).
- Installed vptr = 0x12dbdb8 (row+8), 12 slots.
- GOT cell 0x13132a8 holds addend 0x12dbda8 = vt-0x8; code (ctor 0x968c58)
  does `ldr cell; add #0x10; str [this]`.
- Size 0x4a0 PROVEN: allocation site 0x964c4c (`mov w0, #0x4a0; bl 0x568aa0`),
  then ctor 0x968c40 (0x964c60); result stored to owner [x19+0x78] (0x964c64).
  A sibling allocation (new 0x518 → C1 0x967140) sits at [x19+0x70].
- Base vtable: vptr 0x12dbb08 (cell 0x1313240 + 0x10; typeinfo slot 0x12dbb00);
  base part spans +0x00..+0x3f7 (base D2 0x96616c advances to this+0x3f8).

## Slots (vptr 0x12dbdb8, 12 slots)

- slot 0 = 0x968c74 (D1, tail `b 0x96616c` — shared base D2).
- slot 1 = 0x968c78 (D0: calls 0x96616c, then `operator delete`).
- slot 2 = 0x968c9c (probe: builds a result via 0x5674d0, calls 0x567ea0 on
  this+0x3f8; on the 0x96620c / 0x966be8 fallback path stores 0x10000|0xc08
  (= 0x0c010000) as error code; writes the block pointer to [this+0x498]).
- slot 3 = 0x968d54 (cursor/region walk over [this+0x498] and this+0x3f8).
- slots 4..11 = 0x966830, 0x968db8, 0x968f1c, 0x968f9c, 0x968f44, 0x968db0,
  0x9662bc, 0x9662c8 — functions.csv-unrecovered.

## Member notes

- 0x00 — primary vptr 0x12dbdb8.
- 0x08..0x3f7 — base subobject (base C1 0x96606c: base vptr 0x12dbb08 at
  [this], sub-init 0xb49bb8 at this+8, further init at this+0x1c); unproven.
- 0x498 — pointer, ctor 0 (0x968c5c); used as a block pointer by slot 2.

## Construction / init order

1. Owner init 0x964c44: alloc 0x4a0 (0x568aa0), C1 0x968c40, store to
   [x19+0x78].
2. Ctor 0x968c40: base C1 0x96606c (base vptr 0x12dbb08, 0xb49bb8 at this+8,
   init at this+0x1c), [this+0x498] = 0, vptr 0x12dbdb8 at [this] (cell
   0x13132a8).
