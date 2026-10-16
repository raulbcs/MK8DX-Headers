# KartParamCache

## Identity

KartParamCache — address-anchored name (slot-5 evidence: shared ret
stub 0x7100638e3c is named KartParamCache_vt5). Base of the ~41-vtable param-cache cluster
(vtables 0x12b1xxx-0x12f4xxx, n=9..16, sharing the slot block
0x10-0x40; per-class variance is in slots 0x0/0x8 and the tail).

Vtable 0x12b1c30 (n=9, GOT cell 0x130d848 — raw qword, NO reloc: the
cluster cells are plain .got data read by adrp+ldr). Ctor 0x7100669954,
extent 0x40: vptr, zeros 0x10-0x27, param id @0x28 (returned by
0x7100663050 on the global [0x12fc190]), zeros 0x30-0x3f. 86 direct
construction/reference sites — the cluster's dominant class; also used
as the BASE the array factories call before overwriting the vptr with
a derived one (e.g. KartParamCacheVt24c8, stride-0x58 arrays).

## Member notes

Notes in field order; proven from the cited addresses.

- 0x00
- 0x08 — unproven padding
- 0x10 — ctor zero
- 0x18 — ctor zero
- 0x20 — ctor zero
- 0x28 — ctor: 0x7100663050([global 0x12fc190]) = slot-0x18 vcall on the dictionary object + hash 0x710062fd48 (named-parameter id). Shared Equals 0x710063c710 compares this u32 vs the other object's (paramCacheSharedTypeIdEquals)
- 0x2c — unproven padding
- 0x30 — ctor zero
- 0x38 — ctor zero (0x40 total)

> Naming: factory/array structural variant (base-call chain + factory case id only, no per-class strings).

## Construction / init order

In field/offset order (= binary init order within this header):
- 0x10 — ctor zero
- 0x18 — ctor zero
- 0x20 — ctor zero
- 0x28 — ctor: 0x7100663050([global 0x12fc190]) = slot-0x18 vcall on the dictionary object + hash 0x710062fd48 (named-parameter id). Shared Equals 0x710063c710 compares this u32 vs the other object's (paramCacheSharedTypeIdEquals)
- 0x30 — ctor zero
- 0x38 — ctor zero (0x40 total)
