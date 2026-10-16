# KartParamCacheProjShadow

## Identity

KartParamCacheProjShadow — named from ctor string evidence: ctor string tag 'aglprojsdw' + params bias_scale/anim_swing_cyc_x/scroll anim (0xf1dc97-0xf1ddb4) (was address-anchored KartParamCacheVt3f60) (vptr 0x12f3f60, cell 0x1315460, n=13, site 0xade4d0, ctor 0xade480).
Variant of the 0x63c6f8 param-cache cluster.

## Member notes

Notes in field order; proven from the cited addresses.

- 0x40 — unproven gap
- 0x384
- 0x386
- 0x387
- 0x388
- 0x389
- 0x38a — unproven gap
- 0x3c0
- 0x3c4 — ctor zero
- 0x3c8
- 0x3d0 — ctor zero
- 0x3d4 — unproven gap
- 0x3e8
- 0x3f0 — unproven gap
- 0x418 — ctor stores `this`
- 0x420
- 0x428 — unproven gap
- 0x438
- 0x43c
- 0x440
- 0x448 — unproven gap
- 0x458
- 0x45c
- 0x460
- 0x468 — unproven gap
- 0x478 — ctor zero
- 0x47c — unproven gap
- 0x480
- 0x488 — unproven gap
- 0x498 — ctor zero
- 0x49c — unproven gap
- 0x4a0
- 0x4a8 — unproven gap
- 0x4b8
- 0x4bc
- 0x4c0
- 0x4c8 — unproven gap
- 0x4d8
- 0x4dc
- 0x4e0
- 0x4e8 — unproven gap
- 0x4f8 — ctor zero
- 0x4fc — unproven gap
- 0x500
- 0x508 — unproven gap
- 0x518 — ctor zero
- 0x51c — unproven gap
- 0x520
- 0x528 — unproven gap
- 0x538 — ctor zero
- 0x539 — unproven gap
- 0x540 — ctor zero extent 0x541 (ctor 0x7100ADE480 stores reach 0x541) Vtable slots : - slot 0 (0x10) dtor, returns self (projShadowDtorSlot0_7100ade9a8): vptr from cell 0x7101315460+0x10, resets the nine member sub-vptrs at +0x420..+0x520 to [0x710130d918]+0x10 and +0x3e8 to [0x710130d920]+0x10, calls 0x710063a384(self) and 0x7100639f38(self+0x280), installs [0x710130d848]+0x10 as outer vptr. function size 0x8c bytes. - slot 1 (0x18) deleting dtor (projShadowDeletingDtorSlot1_7100adea34): same reset sequence, then operator delete(self). function size 0x80 bytes. - slot 5 (0x38) per-frame update (projShadowUpdateSlot5_7100adee10): recomputes shadow projection: k = rodata[0xed59c0]; +0x544 = *(+0x518)*k, +0x548 = *(+0x4f8)*k; bytes +0x387/+0x388/+0x389 := (*(+0x538) ? 1 : 7); word +0x390 exclusive rmw (clear/set 0x2, later clear 0x2 set 0x4); +0x384/+0x385 := 1, +0x386 := 1 or 2 by byte +0x540; +0x3d0 := 0; vptr cell *(0x12fbb00) dereferenced into +0x3c8 and the +0x3d4/+0x3dc pair; trig block with sinf/cosf(*(+0x518)) writing the tangent/bias terms +0x398..+0x3c4 and +0x3a4/+0x3b4 = *(+0x4d8)+0.5+... / *(+0x4dc)+0.5+... function size 0x1b8 bytes.

> KartParamCacheProjShadow — named from ctor string evidence: ctor string tag 'aglprojsdw' + params bias_scale/anim_swing_cyc_x/scroll anim (0xf1dc97-0xf1ddb4) (was address-anchored KartParamCacheVt3f60) (vptr 0x12f3f60, cell 0x1315460, n=13, site 0xade4d0, ctor 0xade480).

> Variant of the 0x63c6f8 param-cache cluster.

> Naming: factory/array structural variant (base-call chain + factory case id only, no per-class strings).

## Construction / init order

In field/offset order (= binary init order within this header):
- 0x3c4 — ctor zero
- 0x3d0 — ctor zero
- 0x418 — ctor stores `this`
- 0x478 — ctor zero
- 0x498 — ctor zero
- 0x4f8 — ctor zero
- 0x518 — ctor zero
- 0x538 — ctor zero
- 0x540 — ctor zero extent 0x541 (ctor 0x7100ADE480 stores reach 0x541) Vtable slots : - slot 0 (0x10) dtor, returns self (projShadowDtorSlot0_7100ade9a8): vptr from cell 0x7101315460+0x10, resets the nine member sub-vptrs at +0x420..+0x520 to [0x710130d918]+0x10 and +0x3e8 to [0x710130d920]+0x10, calls 0x710063a384(self) and 0x7100639f38(self+0x280), installs [0x710130d848]+0x10 as outer vptr. function size 0x8c bytes. - slot 1 (0x18) deleting dtor (projShadowDeletingDtorSlot1_7100adea34): same reset sequence, then operator delete(self). function size 0x80 bytes. - slot 5 (0x38) per-frame update (projShadowUpdateSlot5_7100adee10): recomputes shadow projection: k = rodata[0xed59c0]; +0x544 = *(+0x518)*k, +0x548 = *(+0x4f8)*k; bytes +0x387/+0x388/+0x389 := (*(+0x538) ? 1 : 7); word +0x390 exclusive rmw (clear/set 0x2, later clear 0x2 set 0x4); +0x384/+0x385 := 1, +0x386 := 1 or 2 by byte +0x540; +0x3d0 := 0; vptr cell *(0x12fbb00) dereferenced into +0x3c8 and the +0x3d4/+0x3dc pair; trig block with sinf/cosf(*(+0x518)) writing the tangent/bias terms +0x398..+0x3c4 and +0x3a4/+0x3b4 = *(+0x4d8)+0.5+... / *(+0x4dc)+0.5+... function size 0x1b8 bytes.
