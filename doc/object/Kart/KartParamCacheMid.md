# KartParamCacheMid

## Identity

KartParamCacheMid — address-anchored name (vptr 0x12b3478,
GOT cell 0x130daf0, n=11). Mid base of the big KartParamCache
variants: ctor 0x710065ede8 calls the KartParamCache ctor
(0x7100669954), builds an embedded member at 0x68 (ctor 0x710066a2a4)
and THREE 0x20-byte recorder channel-pair members at 0xb0/0xd0/0xf0
(ctor pair 0x7100662f30 + 0x7100662f70; fn cell 0x12fae28; rodata
names 0xef8f59/0xef8f60, 0xef9c27, 0xef9c2e; cells 0x130d908/
0x130daa0), then -1 at 0x108 and init 0x7100669a10(this, w1=param).
Extent 0x110. The factory 0x710065efbc (jump table on w0, 0..6)
allocates the derived sizes over this ctor; no standalone
construction site is known.

## Member notes

Notes in field order; proven from the cited addresses.

- 0x40 — unproven padding
- 0x48 — ctor zero
- 0x50 — ctor zero
- 0x58 — ctor stores this; 0x60 zero
- 0x60
- 0x68 — embedded member (ctor 0x710066a2a4)
- 0x98 — ctor zero
- 0xa0 — ctor zero
- 0xa8 — ctor arg w1
- 0xac — ctor: (w1<<8)+0x100+(w2+1)
- 0xb0 — channel-pair member (cells 0x130d908; ctor zeroes a flag byte at 0xc8 = chan+0x18 — the +0x18 field here is a byte, NOT the float seen in the KartParamCacheFilterAA instances)
- 0xd0 — channel-pair member (flag byte at 0xe8)
- 0xf0 — channel-pair member (to 0x108)
- 0x108 — ctor sets -1
- 0x10C — unproven gap (0x110 total) Vtable slot 0 (0x10) vtable-init ctor stub : no base call; fans cell 0x710130d918(+0x10) vptr into 0xb0/0xd0/0xf0, cell 0x710130d920(+0x10) into 0x68, cell 0x710130d848(+0x10) into +0x0. function size 0x3c bytes (file_list function-size field is a gap-split artifact).

> Naming: factory/array structural variant (base-call chain + factory case id only, no per-class strings).

## Construction / init order

In field/offset order (= binary init order within this header):
- 0x48 — ctor zero
- 0x50 — ctor zero
- 0x58 — ctor stores this; 0x60 zero
- 0x68 — embedded member (ctor 0x710066a2a4)
- 0x98 — ctor zero
- 0xa0 — ctor zero
- 0xa8 — ctor arg w1
- 0xac — ctor: (w1<<8)+0x100+(w2+1)
- 0xb0 — channel-pair member (cells 0x130d908; ctor zeroes a flag byte at 0xc8 = chan+0x18 — the +0x18 field here is a byte, NOT the float seen in the KartParamCacheFilterAA instances)
- 0x108 — ctor sets -1
- 0x10C — unproven gap (0x110 total) Vtable slot 0 (0x10) vtable-init ctor stub : no base call; fans cell 0x710130d918(+0x10) vptr into 0xb0/0xd0/0xf0, cell 0x710130d920(+0x10) into 0x68, cell 0x710130d848(+0x10) into +0x0. function size 0x3c bytes (file_list function-size field is a gap-split artifact).
