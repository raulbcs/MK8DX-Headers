# KartParamCacheMid2

## Identity

KartParamCacheMid2 — address-anchored name (vptr 0x12b4518,
GOT cell 0x130dc10, n=13). SECOND mid base of the cluster (used as base ctor by 0x12b3130,
0x12bb800, 0x12bd030, 0x12bd6f8). Ctor calls the KartParamCache base
(0x7100669954), builds a 0x68-byte member at 0x48 (ctor 0x710061cc48)
and another member at 0xb0, fields 0x50/0x58/0xa0/0xa8/0xb8/0x1c8.

## Member notes

Notes in field order; proven from the cited addresses.

- 0x40 — unproven gap
- 0x50
- 0x58
- 0x5c — unproven gap
- 0xa0
- 0xa4 — unproven gap
- 0xa8 — ctor zero
- 0xb0
- 0xb8
- 0xc0 — unproven gap
- 0x1c8 — ctor zero additional writes by ctor 0x7100668d40 extent 0x1d0 (ctor 0x7100668d40 stores reach 0x1d0 — resolves the old "true extent 20 bytes" conflict as a gap-split artifact) Vtable slot 0 (0x10) vtable-init ctor stub : stores the class vtable pointer (global pointer at 0x710130848, +0x10) into *this. True extent 20 bytes (file_list function-size field is a gap-split artifact).

> Naming: factory/array structural variant (base-call chain + factory case id only, no per-class strings).

## Construction / init order

In field/offset order (= binary init order within this header):
- 0xa8 — ctor zero
- 0x1c8 — ctor zero additional writes by ctor 0x7100668d40 extent 0x1d0 (ctor 0x7100668d40 stores reach 0x1d0 — resolves the old "true extent 20 bytes" conflict as a gap-split artifact) Vtable slot 0 (0x10) vtable-init ctor stub : stores the class vtable pointer (global pointer at 0x710130848, +0x10) into *this. True extent 20 bytes (file_list function-size field is a gap-split artifact).
