# SimpleContainer<InetAddress, 4> (nn::pia::common::SimpleContainer<nn::pia::common::InetAddress, 4>)

## Identity

- Assigned row 0x12dbb00 is the TYPEINFO SLOT, not the vptr: [0x12dbb00] =
  0x12dbb68 (reloc) = typeinfo record {0x10, name 0xf80860, base 0}. Name is
  exact: "N2nn3pia6common15SimpleContainerINS1_11InetAddressELi4EEE".
  Root class (base record 0).
- Installed vptr = 0x12dbb08 (row+8). Row is irregular: slots at +0x00..+0x28,
  zero words at +0x30..+0x40 and +0x50, slot at +0x48 (0x966b70) and +0x58
  (0x9662bc) — effective span 0x60.
- GOT cell 0x1313240 holds addend 0x12dbaf8 = vt-0x10; code (C1 0x96606c at
  0x966080) does `ldr cell; add #0x10; str [this]`.
- Extent 0x3ec LOWER BOUND from C1 0x96606c writes (max 0x3e8 + 4). This C1 is
  shared/merged with NatDetectionJob: see Construction below.

## Slots (vptr 0x12dbb08)

- slot 0 = 0x96616c (D2: dtor of the base part; used as shared base D2 by
  NatPropertyDetecter and NatDetectionJob dtor chains).
- slot 1 = 0x9661b8 (D0: slot 0 body then `operator delete`).
- slot 2 = 0x96620c, slot 3 = 0x9662e0, slot 4 = 0x966830
  (functions.csv-unrecovered).
- +0x48 = 0x966b70 (functions.csv-unrecovered), +0x58 = 0x9662bc (4 B, tail
  into a shared thunk; unverified).
- Slots +0x30..+0x40 and +0x50 are null — unverified whether genuinely empty or
  the row is a partial view.

## Member notes

- 0x08 — sub-init 0xb49bb8; 0x1c/0x24 — sub-init 0x929fd4.
- 0x60/0x68 — 0x56810c-style inits; 0x70/0x78 zeroed later; 0x88 zeroed
  (0x966ba0) — writes at 0x60..0x88 happen in the post-stage function 0x966b84,
  so their attribution to this base vs NatDetectionJob is unverified.
- 0x80 — entry array, 0x28-byte entries walked 0..0x2f8 by C1 loop
  (0x966108..0x966134), count from i32 0x7c.
- 0x3b0..0x3e8 — trailing zeroed fields of C1 0x96606c.

## Construction / init order

1. C1 0x96606c (NatDetectionJob C1 with inlined base ctor; also called as base
   C1 from NatPropertyDetecter C1 0x968c40): installs vptr 0x12dbb08 at [this]
   (cell 0x1313240, 0x966090).
2. Base field init: 0xb49bb8 at +8, 0x929fd4 at +0x1c/+0x24, zeros 0x2c..0x58,
   0x56810c inits at 0x60/0x68, entry-array loop to 0x378, zeros 0x3b0..0x3e8.
3. Tail 0x966b84 (0x966168): calls 0xb4a5e0, zeros 0x70/0x78/0x88/0x60 and
   REINSTALLS [this] with the NatDetectionJob vptr 0x12dbb88 (cell 0x1313248 +
   0x10; ti record 0x12dbbc0, base 0x12f8d30). 0x12dbb08 therefore also serves
   as the base-stage row inside NatDetectionJob construction.
