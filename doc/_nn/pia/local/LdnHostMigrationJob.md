# nn::pia::local::LdnHostMigrationJob

## Identity

- vtable row 0x12e11b0 (tsv row = typeinfo slot), vptr 0x12e11b8 = row + 8, 12 slots.
  GOT cell 0x1313e80 holds 0x12e11a8 = vptr - 0x10 (offset-to-top row 0x12e11a8 = 0,
  descriptor slot 0x12e11b0 = 0x12e1220); installed vptr = cell + 0x10.
- RTTI: descriptor 0x12e1220 = {0x10, name 0xf831f0, base 0x12e18f0, 0};
  name 0xf831f0 = "N2nn3pia5local19LdnHostMigrationJobE";
  base 0x12e18f0 = "N2nn3pia5local30LocalHostMigrationJobE".
- Slots: 0 D1 0x9cb9a0 (4-byte tail b 0x9cfb3c = LocalHostMigrationJob D1),
  1 D0 0x9cb9a4, 2 0xb4a654, 3 0xb4a67c, 4 0x933314 (shared pia-job cluster),
  5 0x9cbf20, 6 0x9cb9c8, 7 0x9cb9f0, 8 0x9cbac4 (`...WaitForCancel` clone),
  9 0x9cbbbc, 10 0x9cbc70, 11 0x9cbd30 (`...WaitForCancel` clone; slots 5-11
  unrecovered, RTTI symbol names from functions.csv only).
- extent 0xa8: max C1 store byte [0xa0] (0x9cb980); not operator-new proven
  (unverified tail).

## Member notes

- [0x08,0x88) = LocalHostMigrationJob base subobject (base C1 0x9cfad4, base
  extent lower bound 0x88) — unproven gap here.
- +0x88 = 100, +0x8c = 500 (stp 0x9cb968 — retry/timeout pair), +0x90 = 5
  (0x9cb98c), +0x98 = 0 (0x9cb97c), +0xa0 byte 0 (0x9cb980).

## Construction / init order

1. C1 0x9cb954: base C1 0x9cfad4(this) — LocalHostMigrationJob C1 (0x9cb964).
2. +0x88 = 100, +0x8c = 500 (0x9cb968); +0x98 = 0 (0x9cb97c); +0xa0 = 0
   (0x9cb980).
3. vptr 0x12e11b8 -> [this] (0x9cb984); +0x90 = 5 (0x9cb98c).
