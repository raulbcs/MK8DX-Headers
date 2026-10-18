# LanInputStream (nn::pia::lan::LanInputStream)

- Typeinfo slot 0x12de190 -> typeinfo 0x12de220, name string 0xf81990
  "N2nn3pia3lan14LanInputStreamE". Primary vptr 0x12de198; GOT cell 0x13138f8
  holds 0x12de188 (vt-0x10, RELATIVE reloc).
- Size unverified; 0xf8 is a lower bound (final memset covers 0xd5..0xf4).

## Identity

nn::pia::lan input-stream base; no factory allocates it directly. Three
derived ctors call its C2 and re-install their own vptrs: 0x7100938bc0
(runtime cell 0x1312ab8, secondary vptr at +0x130), 0x710096e154 and
0x71009c42f4.

## Slots

17 slots (0x12de198..0x12de218): slot 0 = 0x710099007c, slot 1 =
0x7100990080, slots 2-4 = shared base wrappers 0x7100b4a654 /
0x7100b4a67c / 0x7100933314, slot 5 = 0x7100991d48, slot 6 =
0x71009903bc, slot 7 = 0 (unrelocated), slot 8 = 0x7100991d4c, slot 9 =
0x710096f8a4, slots 10/11 = 0 (unrelocated), slot 12 = 0x7100991144,
slot 13 = 0x71009910d8, slot 14 = 0x710099034c, slot 15 = 0x710099150c,
slot 16 = 0x7100991d54.

## Member notes

- 0x08..0x27 — common nn base inited by 0x7100567cb8 (unproven); 0x28 —
  base subobject vptr 0x12db168 (base ctor 0x7100b4a5e0).
- 0x60 — u32 = 0x2710 (10000, likely a buffer/time constant).
- 0x9c — memset(w1=0/arg, 0x20) → 0x9c..0xbb; 0x100 — memset 0x20 →
  0x100..0x11f wait: this store is add x0,x19,#0x100 — beyond the 0xf5
  bound; it belongs to the derived record? No: same this. Treat 0x98 arg
  word, +0xd0 u16, +0xd2 u8, +0xd4 bool, +0xd5 memset 0x20 as proven
  tail; the +0x100 memset suggests size >= 0x120 in some inlined variant
  (unverified — kept out of the struct).
- Derived secondary vptr at +0x130 (ctor 0x7100938bc0) proves derived
  objects reach 0x138; base/object split unproven.

## Construction / init order

1. C2 0x710098ffbc: base ctor 0x7100b4a5e0 (runs 0x7100567cb8 first),
   m68/m70 = 0, m78 = 0, m80 = 0, m58 = 0, m60 = 0x2710, vptr 0x12de198
   at [this], m84/m87 u16 = 0, memset(0x9c, arg2=0/arg, 0x20), m98 = arg
   w20, m8c = w20, m90 = 0, +0xd0 u16 = 0, +0xd2 u8 = 0, bool +0xd4 =
   (platform == 2 via global 0x1312748), memset(+0x100, 0, 0x20),
   memset(+0xd5, w20, 0x20).
2. Derived ctors (0x7100938bc0 / 0x710096e154 / 0x71009c42f4) call C2 then
   re-install their own primary vptr.
