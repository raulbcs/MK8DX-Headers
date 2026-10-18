# object::ParamChannelVt3e58

## Identity

- vtable 0x12b3e58, 26 slots + 2 null tail, GOT cell 0x130db98 holds
  vptr-0x10 (0x12b3e48); code stores cell+0x10 into [this]. No
  offset-to-top/typeinfo words (vptr-0x10/vptr-8 read 0).
- Abstract sibling of ParamChannelVt3d78 in the KartParamCache cluster
  (ChanBase 0x12b3af0): slots 16/17 = return-1 stubs 0x647f30/0x647f38,
  slots 18-25 = pure-virtual sentinels 0xefa017/1e/25/2c (two groups).
- D1 0x666328 / D0 0x666374 (slots 0/1): destroy the two +0x18 members
  via empty stub 0x62fe44, re-install ChanBase vptr (cell 0x130d918).

## Member notes

- Extent 0x148 from the factory allocation `operator new(0x148, 8)` at
  0x667148 (factory-ctor 0x667120).
- Two {cell 0x12fd178+0x10, 0} pairs at +0x18/+0x20 (base tail) and
  +0x30/+0x38 (0x6671e8/0x6671f0); +0x20 -> this+0x50 (0x667264),
  +0x38 -> this+0xd0 (0x6672e4).
- Flags 0x28-0x2b and 0x40-0x43; +0x48 = 9, +0x4c = 7.
- memcpy(this+0x48, src+0x48, 0x100) from the factory's x1 argument
  (0x6672ec) - caller-supplied 0x100-byte region lands at +0x48..+0x147.
- Static blobs: memcpy(0x24) from cell 0x130dbb0 -> +0x50 (0x667210) and
  -> +0xd0 (0x66727c); floats 1.0f fill +0x74..+0xc8 and +0xf4..+0x148.
- Slots 2/3: 0x6663b4 / 0x666424; slot 4 = shared 0x664b18; slot 5/6:
  0x6664dc (756B) / 0x6667d0 (2336B); slots 7-12 = stubs 0x6670f8-0x667118;
  slot 13 = 0x664f68; slot 14 = 0x667120 (the factory); slot 15 = 0x667314;
  slots 16/17 = 0x647f30/0x647f38.

## Construction / init order

1. Factory-ctor 0x667120: `operator new(0x148, 8)` (0x667148).
2. ChanBase vptr at [this] (0x667188); +0x10 = 0; hash 0x62fd48 -> +0x08
   (0x6671a4); optional parse 0x66a2c0 (0x6671b4).
3. Class vptr 0x12b3e58 (cell 0x130db98+0x10) overrides [this]
   (0x6671dc).
4. Flag/pair/blob/float stores per Member notes; return this.
