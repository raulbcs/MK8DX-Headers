# gsys::Layer3D

- fn row at 0x12b5fb8 (34 slots). GOT cell 0x130def0 holds 0x12b5fa8 =
  row-0x10; sites 0x69d78c (C1), 0x69d9d4 (D2), 0x69da24 (D1). The ctor
  0x710069d770 is already named `gsys::Layer3D` in config/functions.csv.
- Identity: render layer owned by `RenderLayerManager::LayerHeap`
  (0x71003ca1b4); the manager's debug-name machinery references
  "3D Main | Sub0" (0xee63f2) for this family.

## Member notes

| Offset | Field | Evidence |
|---|---|---|
| 0x00 | vptr | 0x12b5fb8 |
| 0x08..0x101f | base class body | base ctor 0x69cae4; not yet mapped (unverified) |
| 0x1020 | zeroed u64 | ctor 0x69d790 |
| 0x1028 | embedded object, vptr 0x12b4780 | ctor 0x69d7d4, then 0x6155bc(this+0x1028) at 0x69d7a4 (before vptr store) |
| 0x1048 | embedded object, vptr 0x11ad210 | ctor 0x69d7e4 |
| 0x1050 | string ptr 0xed6af8 | ctor 0x69d7c4 |
| 0x1058/0x105c/0x1060 | 0 / -100 / 1 | ctor 0x69d7e0/0x69d7f4/0x69d7cc |
| 0x106c | self pointer | ctor 0x69d810 |
| 0x1088/0x1089 | 0xff / 0 | ctor 0x69d7e8/0x69d7f0 |

Slots are 0x69cxxx-0x69dxxx functions (mostly unrecovered); slots 20-22 are
out-of-line 4-12 B thunks (0x3c9244/0x3c9248/0x3c924c) and slots 23-33 are
tiny string-returning thunks in the 0xefe39c cluster (unverified contents).

## Construction / init order

- RenderLayerManager::LayerHeap allocates: `operator new(0x1090)`
  (0x3ca260, allocator 0x60b234), C1 0x69d770 at 0x3ca278, then registers the
  layer via 0x678120 with the manager singleton (cell 0x12fb5e0).
- C1: base ctor 0x69cae4, vptr install, member inits listed above.
- D1 0x69da10 → D2 0x69d9c0 (both re-install vptr; D1 delegates to base
  teardown and frees).
