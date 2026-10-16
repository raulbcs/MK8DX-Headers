# KartParamCacheLightMap

## Identity

KartParamCacheLightMap — named from ctor string evidence: ctor string tag 'agllmap' (0xefa640) (was address-anchored KartParamCacheVt48f8) (vptr 0x12b48f8, cell 0x130dce0, n=13, site 0x67885c, ctor 0x678808).
Variant of the 0x63c6f8 param-cache cluster.

## Member notes

Notes in field order; proven from the cited addresses.

- 0x40 — unproven gap
- 0x1d0 — ctor zero
- 0x1d4 — unproven gap
- 0x1e8 — ctor zero
- 0x1f0 — unproven gap
- 0x200 — ctor zero
- 0x204
- 0x208 — ctor zero
- 0x210 — ctor zero
- 0x214 — unproven gap
- 0x218 — ctor zero
- 0x220 — ctor zero
- 0x224 — unproven gap
- 0x570 — ctor zero
- 0x578 — ctor zero
- 0x57c — unproven gap
- 0x580 — ctor zero
- 0x588 — ctor zero
- 0x58c — unproven gap
- 0x8d8 — ctor zero
- 0x8e0 — ctor zero
- 0x8e4 — unproven gap
- 0x8e8 — ctor zero
- 0x8f0 — ctor zero extent 0x8f4 (ctor 0x7100678808 stores reach 0x8f4) Vtable slots : - slot 0 (+0x10) dtor/reset (lightMapDtorResetSlot0_7100678b78): runs 0x71006373a4 (cold fragment) on the +0x33e8 block, frees the pooled array at +0x1d8 (stride 0xad8, 0x7100695e90 element dtor), clears +0x1e0 via 0x710060b984, re-inits the +0x3408 container, and runs a 32-iteration pass (offsets 0x2000 down to 0x100, step 0x100) resetting each node (+0xb90 vptr, +0xb40 vptr) through 0x710062fe44; re-stamps the +0x8d8..+0x2d8 blocks and the +0x0 vptr. function size 0x17c bytes. - slot 5 (0x38) release tiles (lightMapSlot5ReleaseTilesAndSetFlag_710067ab40): ORs byte +0x3401 with 0x28; for each of *(u32*)(+0x1d0) entries calls 0x7100699b44 on successive pointers from +0x1d8 (stride 0xad8); tail-calls 0x710067a474(self). function size 0x5c bytes.

> KartParamCacheLightMap — named from ctor string evidence: ctor string tag 'agllmap' (0xefa640) (was address-anchored KartParamCacheVt48f8) (vptr 0x12b48f8, cell 0x130dce0, n=13, site 0x67885c, ctor 0x678808).

> Variant of the 0x63c6f8 param-cache cluster.

> Naming: factory/array structural variant (base-call chain + factory case id only, no per-class strings).

## Construction / init order

In field/offset order (= binary init order within this header):
- 0x1d0 — ctor zero
- 0x1e8 — ctor zero
- 0x200 — ctor zero
- 0x208 — ctor zero
- 0x210 — ctor zero
- 0x218 — ctor zero
- 0x220 — ctor zero
- 0x570 — ctor zero
- 0x578 — ctor zero
- 0x580 — ctor zero
- 0x588 — ctor zero
- 0x8d8 — ctor zero
- 0x8e0 — ctor zero
- 0x8e8 — ctor zero
- 0x8f0 — ctor zero extent 0x8f4 (ctor 0x7100678808 stores reach 0x8f4) Vtable slots : - slot 0 (+0x10) dtor/reset (lightMapDtorResetSlot0_7100678b78): runs 0x71006373a4 (cold fragment) on the +0x33e8 block, frees the pooled array at +0x1d8 (stride 0xad8, 0x7100695e90 element dtor), clears +0x1e0 via 0x710060b984, re-inits the +0x3408 container, and runs a 32-iteration pass (offsets 0x2000 down to 0x100, step 0x100) resetting each node (+0xb90 vptr, +0xb40 vptr) through 0x710062fe44; re-stamps the +0x8d8..+0x2d8 blocks and the +0x0 vptr. function size 0x17c bytes. - slot 5 (0x38) release tiles (lightMapSlot5ReleaseTilesAndSetFlag_710067ab40): ORs byte +0x3401 with 0x28; for each of *(u32*)(+0x1d0) entries calls 0x7100699b44 on successive pointers from +0x1d8 (stride 0xad8); tail-calls 0x710067a474(self). function size 0x5c bytes.
