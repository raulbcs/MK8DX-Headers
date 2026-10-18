# object::Vt12d3cc8

PLACEHOLDER name (identity not proven). vptr 0x12d3cc8, 25 rows total: primary 8 slots (0x12d3cc8..0x12d3d08), MI secondary 0x12d3d18 (2 slots), then an embedded member primary 0x12d3d38 (16 rows, cell 0x1311640, not assigned here). Typeinfo NULL. GOT cell 0x1311948 holds vt-0x10.

Size 0x2d0 PROVEN: heap factory 0x8a583c (slot7 of Vt12d3c78) does `mov w0,#0x2d0; bl operator new` (0x8a5848) then installs this vtable pair — same layout as Vt12d3408.

## Member notes

- Slots are ICF-style clones sharing the Vt12d3408 bodies (stub-director pattern): slot0 0x8a5884 = D1 clone (re-installs vptr pair at [x0], singleton-compares against cell 0x1311958, then tail-calls 0x3d8f64); slot1 0x8a5908; slot2 0x8a5964 = in-place init clone (installs 0x12d3cc8/0x12d3d18 at [x0]/[x0+0x20], calls member init 0x3d87c8, tails into D2 0x896cd4); slot3 0x8a59a0 = deleting clone (init + D2 + operator delete); slot4/5 0x3d89ac/0x3d89b4, slot6 0x3d973c (shared with Vt12d3408); slot7 0x8a59e4 (tail of FUN_71008a5964, forwards to 0x3d8718). Secondary slots: 0x8a5a08, 0x8a5a48 (same clone bodies, this-0x20 thunks).
- [this+0x40] vptr 0x12d3d38 — embedded member primary (ot row 0 at 0x12d3d28); rows 0x12d3d38..0x12d3d78 end in 0x8a5cd8 (tail of FUN_71008a5bdc).
- MI secondary at [this+0x20] = 0x12d3d18; offset-to-top -0x20 at 0x12d3d08.
- D2 shared with the base family: 0x896cd4 (Vt12d3408 slot2). Member init shared: 0x3d87c8 (interior of FUN_71003d8718).
- FUN_71008a9990 (slot15, size 0x4074) is the big consumer/updater; it constructs a Vt12d3d90 stack record (see Vt12d3d90.md) via cell 0x1311960.

## Construction / init order

- No out-of-line C1. Heap factory 0x8a583c (Vt12d3c78 slot7): new(0x2d0), C1 0x896ba4 (base-family init), byte 0x2c8 zeroed, then vptr pair swapped to 0x12d3cc8 (cell 0x1311948+0x10) / 0x12d3d18 (cell+0x60) at 0x8a5864-0x8a5870.
- In-place variant: slot2 clone 0x8a5964 on existing storage.
- Destruction: slot0/1/3 clones (D1/D2/deleting), all sharing the base D2.
