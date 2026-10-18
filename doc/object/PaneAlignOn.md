# PaneAlignOn

## Identity

- vtable 0x12bf7b0, 28 slots, GOT cell 0x130ecc0 holds vt-0x10 (0x12bf7a0);
  installed vptr = cell+0x10.
- Factory: pane-tag dispatcher 0x7430bc branch at 0x743488 requires string
  "AlignOn" (0xf0742a) in the pane resource; allocates 0xf0 (align 0x10) and
  calls ctor 0x73ed4c (0x74349c..0x7434bc).
- Base ctor 0x5a22e4 (920 B shared C1 of the 0x12acf98 base table) called at
  0x73ed68 before the derived stores.

## Member notes

- +0xdc: u32 zeroed (0x73ed74); +0xe2: bool zeroed (0x73ed78); +0xe0: u16
  set to 0x100 (0x73ed8c..0x73ed94).
- After the stores the ctor looks up "AlignOn" (0xf0742a) via 0x5a37fc and,
  on success, byte-compares two 0x100000-sized buffers (0x73eda0..0x73ee04,
  terminator 0xee047f / zero cell 0x12fade8) - unverified semantics
  (resource-vs-reference comparison).
- Slots 0/1/2: D1 0x73ef14, D0 0x73ef18, slot 2 0x73f874 (all unrecovered in
  functions.csv except 0x73ef3c = slot 20, FUN_710073ef3c).
- Slots 6-27 are the shared 0x5a2xxx cluster (base-family thunks).

## Construction / init order

1. Factory 0x743488: "AlignOn" string check; aligned_alloc(0xf0, align 0x10)
   at 0x74349c.
2. C1 0x73ed4c: base ctor 0x5a22e4 (0x73ed68); vptr 0x12bf7b0 at +0x00
   (0x73ed80..0x73ed88); field stores listed above; "AlignOn" lookup +
   buffer comparison (0x73ed80..0x73eeac).
