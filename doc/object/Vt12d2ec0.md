# object::Vt12d2ec0

'Gear/' resource category entry (name derived from the path literal; class name unproven).
vptr 0x12d2ec0, 10 slots, typeinfo NULL (game-side). GOT cell 0x1311648 holds 0x12d2eb0
(vtable row − 0x10); installed vptr = row start 0x12d2ec0. Row header words at −0x10/−0x8 are 0.

## Member notes

- Embedded in-place at singleton+0x4b88 by FUN_71008911a0 (vptr store 0x89137c→0x891378 cell
  load). Next sibling entry (Vt12d2f78) starts at +0x4be8 → entry size 0x60.
- +0x30 = "Gear/" (0xf0cf27), +0x40 = ".bfres" (0xee0c9e); +0x28/+0x38 = the same x21 pointer
  (a manager/global captured earlier in FUN_71008911a0); +0x48 = 2; +0x50..+0x5f = 0.
- Sibling classes, same shape and stride: Vt12d2f78 ("Screw/", +0x4be8), Vt12d3030 ("Light/",
  +0x4c48), plus Vt12d3e20 at +0x4ca8 (not mapped here). All are category entries of one entry
  array inside the same manager (fields span beyond +0x4d84).
- No dedicated C1/D1 located; construction is inlined field stores. The two small tables at
  0x12d2f20 {0x895d60, 0x895d74} and 0x12d2f50 {0x895d5c, 0x895d38, 0x8a7cd0} sit between this
  row and Vt12d2f78 but have no vptr stores — separate unnamed tables (unverified).

Slot table (all `U` quality):
0x00 0x895d48, 0x08 0x895ca0, 0x10 0x895cd4, 0x18 0x895d0c, 0x20 0x895d30, 0x28 0x8a8cfc,
0x30 0x8a8e58, 0x38 0x895d38, 0x40 0x8a7cd0, 0x48 0x895d40.

## Construction / init order

- FUN_71008911a0 initializes the containing manager (10 KB of stores, fields up to +0x4d84+):
  entry vptr from GOT cell 0x1311648 (0x891370–0x89137c), then "Gear/" (0x891324–0x89132c),
  x21 pointer pair, ".bfres" (0x891330–0x891344), 2 (0x891338/0x89134c), and the zero tail
  (0x891360–0x891384). No ctor call — plain vptr + field stores.
