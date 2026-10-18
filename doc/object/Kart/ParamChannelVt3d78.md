# object::ParamChannelVt3d78

## Identity

- vtable 0x12b3d78, 26 slots + 2 null tail, GOT cell 0x130db78 holds
  vptr-0x10 (0x12b3d68); code stores cell+0x10 into [this]. No
  offset-to-top/typeinfo words (vptr-0x10 and vptr-8 read 0).
- Abstract channel of the KartParamCache cluster (ChanBase 0x12b3af0):
  slots 16/17 are return-1 stubs (0x647f30/0x647f38) and slots 18-25 are
  pure-virtual sentinels (0xefa017/0xefa01e/0xefa025/0xefa02c, two groups
  of four).
- D1 0x665400 / D0 0x665440 (slots 0/1): both re-install the ChanBase
  vptr (cell 0x130d918 + 0x10) after "destroying" the +0x18 member via
  the empty stub 0x62fe44 (trivial dtor).

## Member notes

- Extent 0xb0 from the factory allocation `operator new(0xb0, 8)` at
  0x6661ac (factory-ctor 0x666190, which is also slot 14 of the vtable).
- +0x18/+0x20 (base tail region): stp of [cell 0x12fd178]+0x10 and 0 at
  0x666240; +0x20 later overwritten with this+0x38 (0x6662b4).
- +0x38..+0x5b: memcpy(0x24) from static blob cell 0x130db90 (0x666258).
- +0x5c..+0xaf: 21 floats, all 0x3f800000 (0x66625c-0x666298).
- Slots 2/3: 0x665474 (reads vtbl slot 0x38 twice), 0x6654e4; slot 4 = shared
  0x664b18 (892B, shared by Vt3d78/3e58/3f38); slot 5/6: 0x66558c (756B),
  0x665880 (2272B); slots 7-12 are 8-byte stubs (`add x0,x0,0x30; ret`,
  `mov w0,#0x80; ret`, 0x666160-0x666188); slot 13 = 0x664f68; slot 14 =
  0x666190 (the factory); slot 15 = 0x6662d8; slots 16/17 = 0x647f30/0x647f38.
- A 0x100-strided container loop installs this class's vptr into inline
  subobjects at [container+0xb90+0x100*k] (0x678c40-0x678c68, big cache
  container ctor).

## Construction / init order

1. Factory-ctor 0x666190: `operator new(0xb0, 8)` (0x6661ac).
2. ChanBase vptr (cell 0x130d918+0x10) stored at [this] (0x6661ec);
   +0x10 = 0; param-id hash via 0x62fd48 -> +0x08 (0x666208).
3. Optional source parse 0x66a2c0 when x2 != 0 (0x666218).
4. Class vptr 0x12b3d78 (cell 0x130db78+0x10) overrides [this]
   (0x66623c); +0x18/+0x20 pair stored (0x666240).
5. memcpy 0x24 blob -> +0x38; flags 0x28-0x2b, +0x30 = 9, +0x34 = 7;
   21 x 1.0f -> +0x5c..+0xaf; return this (0x6662c0).
