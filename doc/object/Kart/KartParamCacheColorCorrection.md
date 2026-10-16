# KartParamCacheColorCorrection

## Identity

KartParamCacheColorCorrection — named from ctor string evidence: ctor string tag 'aglccr' + params hue/saturation/brightness/gamma/toycam_enable (EN/JP pairs at 0xef93f6-0xef94c4) (was address-anchored KartParamCacheVt30a8) (vptr
0x12b30a8, GOT cell 0x130da78). Largest KartParamCache variant:
ctor 0x710064fb3c built by the factory 0x710065efbc (alloc 0x1a30).
NOT a KartParamCacheMid derive — it goes straight over the
KartParamCache base: embedded member at 0x1d0 (vptr 0x12b26b0, a
small cluster vtable — secondary base), recorder channel-pair
members from 0x200 on (pair 0x7100662f30/0x7100662f70, names
0xef8f59/0xef8f60, cell 0x130d908), member writes up to 0x300+.

## Member notes

Notes in field order; proven from the cited addresses.

- 0x1d0 — secondary vptr (0x12b26b0 +0x10)
- 0x1d8 — secondary-base member body
- 0x200 — channel-pair member
- 0x220
- 0x228 — unproven gap
- 0x238 — ctor zero
- 0x23c — unproven gap
- 0x240
- 0x248 — unproven gap
- 0x258
- 0x25c — unproven gap
- 0x260
- 0x268 — unproven gap
- 0x278
- 0x27c — unproven gap
- 0x280
- 0x288 — unproven gap
- 0x298
- 0x29c — unproven gap
- 0x2a0
- 0x2a8 — unproven gap
- 0x2b8 — ctor zero
- 0x2b9 — unproven gap
- 0x2c0
- 0x2c8 — unproven gap
- 0x2d8 — ctor zero
- 0x2d9 — unproven gap
- 0x2e0
- 0x2e8 — unproven gap
- 0x2f8
- 0x2fc
- 0x300
- 0x304
- 0x308
- 0x310 — unproven gap
- 0x320
- 0x324
- 0x328
- 0x32c
- 0x330
- 0x338 — unproven gap
- 0x348
- 0x34c
- 0x350
- 0x354
- 0x358
- 0x360 — unproven gap
- 0x370
- 0x374
- 0x378
- 0x37c
- 0x380
- 0x388 — unproven gap
- 0x398
- 0x39c — unproven gap
- 0x3a0
- 0x3a8 — unproven gap
- 0x3b8
- 0x3bc — unproven gap
- 0x3c0
- 0x3c8 — unproven gap
- 0x3d8
- 0x3dc — unproven gap
- 0x3e0
- 0x3e8 — unproven gap
- 0x3f8
- 0x3fc — unproven gap
- 0x400
- 0x408 — unproven gap
- 0x418
- 0x41c
- 0x420
- 0x424
- 0x428 — unproven gap
- 0x430 — ctor zero
- 0x432 — unproven gap
- 0x43c — ctor zero
- 0x43d — unproven gap
- 0x4a8 — ctor zero
- 0x4b0 — unproven gap
- 0x16e0 — ctor zero
- 0x16e8 — ctor zero
- 0x16ec — unproven gap
- 0x16f0 — ctor zero
- 0x16f8 — ctor zero
- 0x16fc — unproven gap
- 0x1700 — ctor zero
- 0x1708 — ctor zero
- 0x170c — unproven gap
- 0x1a18
- 0x1a1c — unproven gap
- 0x1a20 — ctor zero
- 0x1a28 — ctor zero
- 0x1a2c — unproven gap (0x1a30 total)

> Naming: factory/array structural variant (base-call chain + factory case id only, no per-class strings).

## Construction / init order

In field/offset order (= binary init order within this header):
- 0x238 — ctor zero
- 0x2b8 — ctor zero
- 0x2d8 — ctor zero
- 0x430 — ctor zero
- 0x43c — ctor zero
- 0x4a8 — ctor zero
- 0x16e0 — ctor zero
- 0x16e8 — ctor zero
- 0x16f0 — ctor zero
- 0x16f8 — ctor zero
- 0x1700 — ctor zero
- 0x1708 — ctor zero
- 0x1a20 — ctor zero
- 0x1a28 — ctor zero
