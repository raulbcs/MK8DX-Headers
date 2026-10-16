# KartParamCacheVolumeMask

## Identity

KartParamCacheVolumeMask — named from ctor string evidence: ctor string tag 'aglvolm' + param volume_mask (0xf1aa11-0xf01d00) (was address-anchored KartParamCacheVt2d18) (vptr 0x12f2d18, cell 0x1315208, n=14, site 0xa9cad8, ctor 0xa9ca94).
Variant of the 0x63c6f8 param-cache cluster.
Vtable slot facts :
slot 0 = complete dtor (nested pools 0x1b8/0xa80 freed) — entry
0x7100a9cc14, true size: 0x2c8; file_list size is a gap-split. Stamps
vptr 0x1315208(+0x10); frees the pooled array at +0x540 (count at -8,
stride 0x1b8): per element stamps 0x130d918(+0x10) at el-0x28..-0x188
(0x20 pitch, 11 slots) and 0x130d920(+0x10) at el-0x1b8, then delete[],
zero +0x540/+0x538. Frees *(+0x228) via delete[] (zero +0x228/+0x220).
Pool [+0x230] count / [+0x238] array (stride 0xa80, entries clamped to 0):
per entry frees inner arrays entry+0x10 and entry+0x208 (count at -8,
stride 0x1c8, 0x710063a384 at -0x48 / 0x7100639f38 at -0x118 per element)
plus entry+0x20 (plain delete[]), zeroing the pairs; then per 0xa80 entry
0x710063a384 at -0x48, 0x7100639f38 at -0x118/-0x2e8/-0x4b8/-0x6e8,
0x710063ed3c at -0x5d0, 0x710063a384 at -0x618; delete[] pool, zero
+0x238/+0x230. 0x7100654ae0 on +0x250; stamps 0x130d918(+0x10) into
+0x518/+0x4f8/+0x4d8/+0x4b8 and 0x130d920(+0x10) into +0x488; stamps
0x130d830(+0x10) into +0x250 with 0x7100654ae0/0x71006156b4; finally
stamps 0x130d848(+0x10) into +0x1d0 and self+0x0.

## Member notes

Notes in field order; proven from the cited addresses.

- 0x40 — unproven gap
- 0x1d0
- 0x1d8 — unproven gap
- 0x218
- 0x21c — ctor zero
- 0x21d
- 0x21e — unproven gap
- 0x220 — ctor zero
- 0x224 — unproven gap
- 0x228 — ctor zero
- 0x230 — ctor zero
- 0x234 — unproven gap
- 0x238 — ctor zero
- 0x240
- 0x244 — ctor zero
- 0x248 — ctor zero
- 0x249 — unproven gap
- 0x24c — ctor zero
- 0x24d
- 0x24e — ctor zero
- 0x250 — unproven gap
- 0x488
- 0x490 — unproven gap
- 0x4b8
- 0x4c0 — unproven gap
- 0x4d8
- 0x4e0 — unproven gap
- 0x4f8
- 0x500 — unproven gap
- 0x518
- 0x520 — unproven gap
- 0x538 — ctor zero
- 0x53c — unproven gap
- 0x540 — ctor zero extent 0x548 (ctor 0x7100A9CA94 stores reach 0x548)

> Naming: factory/array structural variant (base-call chain + factory case id only, no per-class strings).

## Construction / init order

In field/offset order (= binary init order within this header):
- 0x21c — ctor zero
- 0x220 — ctor zero
- 0x228 — ctor zero
- 0x230 — ctor zero
- 0x238 — ctor zero
- 0x244 — ctor zero
- 0x248 — ctor zero
- 0x24c — ctor zero
- 0x24e — ctor zero
- 0x538 — ctor zero
- 0x540 — ctor zero extent 0x548 (ctor 0x7100A9CA94 stores reach 0x548)
