# object::ParamChannelVt3f38

## Identity

- vtable 0x12b3f38, 26 slots + 2 null tail, GOT cell 0x130dbb8 holds
  vptr-0x10 (0x12b3f28); code stores cell+0x10 into [this]. No
  offset-to-top/typeinfo words (vptr-0x10/vptr-8 read 0).
- Abstract sibling of ParamChannelVt3d78/3e58 in the KartParamCache
  cluster (ChanBase 0x12b3af0): slots 16/17 = return-1 stubs
  0x647f30/0x647f38, slots 18-25 = pure-virtual sentinels
  0xefa017/1e/25/2c (two groups of four).
- D1 0x667398 / D0 0x6673f4 (slots 0/1): destroy three +0x18 members
  (+0x18/+0x30/+0x48) via empty stub 0x62fe44, re-install ChanBase vptr.

## Member notes

- Extent 0x278 from the factory allocation `operator new(0x278, 8)` at
  0x6681f8 (factory-ctor 0x6681d8).
- Four {cell 0x12fd178+0x10, 0} pairs at +0x18 (base tail), +0x30, +0x48,
  +0x60 (0x6682c0-0x6682e4); flag triples at 0x40-0x43, 0x58-0x5b,
  0x70-0x73 (byte 4 then two zeroed bytes each, 0x668290-0x6682d8).
- Loop (4 iterations, 0x6682e8-0x668354): memcpy(0x24) from static blob
  cell 0x130da80 -> group+0x08 (group base = this+0x78+0x80*i); 21
  1.0f floats -> group+0x2c..+0x7c; per-iteration the +0x20 record
  pointer / flags of the i-th chan subobject are refreshed.
- Final memcpy(this+0x78, arg+0x78, 0x200) from the factory's saved x2
  region (0x668358-0x668368) - caller-supplied data covers the whole
  group array.
- Slots 2/3: 0x667444 / 0x6674b4; slot 4 = shared 0x664b18; slot 5/6:
  0x66758c (756B) / 0x667880 (2336B); slots 7-12 = stubs 0x6681a8-0x6681c8;
  slot 13 = 0x664f68; slot 14 = 0x6681d0; slot 15 = 0x668390; slots 16/17 =
  0x647f30/0x647f38.

## Construction / init order

1. Factory-ctor 0x6681d8: `operator new(0x278, 8)` (0x6681f8).
2. ChanBase vptr at [this] (0x668238); +0x10 = 0; hash 0x62fd48 -> +0x08
   (0x668254); optional parse 0x66a2c0 (0x668264).
3. Class vptr 0x12b3f38 (cell 0x130dbb8+0x10) overrides [this]
   (0x6682bc).
4. Four chan pairs + flag triples; 4x0x80 group loop with blob memcpy
   and float fill; caller 0x200-byte memcpy over +0x78..+0x278; return
   this (0x66836c).
