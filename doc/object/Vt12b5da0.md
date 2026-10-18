# object::Vt12b5da0

PLACEHOLDER name. KartParamCacheGroup-derived cache variant; allocated only as
array elements.

- Identity: ctor 0x6958c8 (D1 0x695e90, D0 0x696090). First action is
  `bl 0x64a708` = the KartParamCacheGroupVt2520 ctor (see
  doc/object/Kart/KartParamCacheGroupVt2520.md), then zeroes 0x168-0x183 and
  installs vptrs.
- vtable convention: GOT cell 0x130de98, rela addend 0x12b5d90 = vt-0x10;
  installed primary vptr = cell+0x10 = 0x12b5da0 (row 0x12b5da0, offset-to-top
  0, typeinfo 0).
- Materialization: the ONLY ctor caller is 0x6794c4, an array loop:
  `operator new[](n*0xad8+8)` (0x60b3fc), element stride 0xad8, ctor per
  element; array ptr stored at [mgr+0x1d8], count at [mgr+0x1d0].
- Primary slots (11, 0x58): slot0/1 dtor pair 0x695e90 / 0x696090;
  0x64aa3c (0x2088, shared with family), kartParamCacheEnvCleanup_7100648414,
  0x6999b4, 0x699b8c, 0x64b718, 0x64b850, 0x699f68, 0x69977c, 0x699bf0.
- Secondary group (MI): D1 stores cell+0x78 = 0x12b5e08 at [this+0x38]
  (offset-to-top -0x38, slots 0x64b7b4/0x64b8ec) and cell+0x98 = **0x12b5e28**
  at [this+0x40] (offset-to-top -0x40; 9 slots: 0x696088 dtor thunk
  `sub x0,#0x40`, 0x6960b4 D0 thunk, 0x699998, 0x63c700, 0x699a74, 0x699bbc,
  0x63c710 paramCacheSharedTypeIdEquals, 0x699f60, 0x63c728).

## Construction / init order

1. 0x6958c8: `bl 0x64a708` (KartParamCacheGroup base ctor).
2. Zero 0x168/0x170, w 0x178, x 0x180.
3. Install primary vptr 0x12b5da0 at [this]; secondaries 0x12b5e08 at +0x38,
   0x12b5e28 at +0x40.
4. Member ctor 0x645410 at this+0x188.
5. Member ctor 0x643fa0 at this+0x350.
6. Flag/record writes: byte 0x4d0=6, bytes 0x4d4/0x4d5/0x4d8/0x4db=0xff/0,
   float -1.0f at 0x520, record region 0x4d9-0x649+ (unverified layout).
- D1 0x695e90 reads [this+0x7e0] and walks entries with stride 0x170
  (element count at entry[-1]).
- size 0xad8 (proven: operator-new[] element stride at 0x6794a0).
