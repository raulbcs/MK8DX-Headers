# nn::pia::local::LocalHostMigrationJob

## Identity

- vtable row 0x12e1880 (tsv row = typeinfo slot), vptr 0x12e1888 = row + 8, 12 slots.
  GOT cell 0x1313ff0 holds 0x12e1878 = vptr - 0x10 (offset-to-top row 0x12e1878 = 0,
  descriptor slot 0x12e1880 = 0x12e18f0); installed vptr = cell + 0x10.
- RTTI: descriptor 0x12e18f0 = {0x10, name 0xf83500, base 0x12f8d30, 0};
  name 0xf83500 = "N2nn3pia5local30LocalHostMigrationJobE"; base 0x12f8d30 =
  shared pia/nex job-base descriptor (same base as JoinSessionJob).
- Slots: 0 D1 0x9cfb3c, 1 D0 0x9cfb88, 2 0xb4a654, 3 0xb4a67c, 4 0x933314
  (shared pia-job cluster, identical to JoinSessionJob slots 2-4), 5 0x9d1278,
  6 0x9cfcfc, 7 0x9d012c, 8 0x9d01e0, 9 0x9d0a14, 10 0x9d0f30, 11 0x9d1024
  (slots 5-11 unrecovered).
- D1 0x9cfb3c: installs vptr (0x9cfb5c), destroys the +0x60 sub-object
  (0x929ee0 + 0x568b64), [this+0x78] = 0, tail 0xb4a62c (shared job-base D0).
  D0 0x9cfb88: same body then operator delete 0x60b470.
- extent 0x88 is a LOWER BOUND (max C1 store 0x80 + 8); no operator-new site
  for the object itself recovered (unverified tail).

## Member notes

- +0x58 = 0 (0x9cfaec); +0x60 sub-object: operator new(0x20) via 0x568aa0
  (0x9cfb18), ctor 0x929ec0 (0x9cfb28), ptr stored at 0x9cfb2c; +0x68 byte 0
  (0x9cfaf8); +0x70 = 0 and +0x78 = C1 x1 argument (stp 0x9cfafc); +0x80 = 0
  (0x9cfb08).
- [0x08,0x58) initialized by the shared base C1 0xb4a5e0 — unproven gap.
- LdnHostMigrationJob derives from this class (its C1 0x9cb954 calls 0x9cfad4).

## Construction / init order

1. C1 0x9cfad4: base C1 0xb4a5e0(this) (0x9cfae8).
2. +0x58 = 0 (0x9cfaec); +0x68 = 0 (0x9cfaf8); +0x70 = 0, +0x78 = x1 arg
   (0x9cfafc).
3. vptr 0x12e1888 -> [this] (0x9cfb04); +0x80 = 0 (0x9cfb08).
4. Sub-object at +0x60: new(0x20), ctor 0x929ec0, store (0x9cfb0c-0x9cfb2c).
