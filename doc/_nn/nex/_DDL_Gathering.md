# nn::nex::_DDL_Gathering

RTTI-confirmed: typeinfo record 0x12f5850 = {0x10, name 0xf88800
(`N2nn3nex14_DDL_GatheringE`), base 0x128c3b0 = nn::nex::RootObject,
0x10}. Internal DDL class for the matchmake Gathering schema; sibling
names on the same rodata page: _DDL_DynamicGathering (0xf88880),
AnyGatheringAdapter (0xf88820), AnyObjectAdapter&lt;Gathering,String&gt;
(0xf88840).

- Vtable: vptr = 0x12f5810. GOT cell 0x1315778 holds 0x12f5800 =
  vptr-0x10 (offset-to-top at 0x12f5800 = 0; typeinfo slot at
  0x12f5808). The vt_ctors.tsv row address 0x12f5808 is the typeinfo
  slot, not slot 0.
- Slots (8): +0x00 0xb15534 and +0x08 0xb15558 (C2 variants: install
  vptr at +0x00 and the RootObject-family vptr from GOT cell 0x130b4a8
  at +0x38, then tail into 0x5790b4), +0x10 0xb14f64 (factory: allocates
  0x60 bytes via 0x573f04, inits a RootObject-family subobject at +0x38
  plus fields +0x08/+0x0c/+0x40/+0x50), +0x18 0xb14ff0, +0x20 0xb15020,
  +0x28 0xb14b00, +0x30 0xb15034, +0x38 0xb15044 (2716 B; contains
  further inline ctor variants installing sibling DDL vtables, e.g.
  cells 0x13157e0/0x13157e8, and a secondary vptr store at +0xa0).
- C2 sites: 0xb14e9c (FUN_7100b14e88) plus 8 inline sites inside the DDL
  interpreter FUN_7100b0fc90 (10 KB) and FUN_7100b15044.
- Size: lower bound 0x40 (member/subobject vptr store at +0x38); the
  +0xa0 store inside slot 0xb15044 belongs to an in-place product of a
  sibling DDL type and is not attributed here (unverified upper bound).

## Construction / init order

1. C2 (0xb15534/0xb14e88-style): vptr at +0x00.
2. RootObject-family vptr (cell 0x130b4a8+0x10) at +0x38.
3. Tail dispatch into the shared cleanup/init helper 0x5790b4.
