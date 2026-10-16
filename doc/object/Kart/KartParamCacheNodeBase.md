# KartParamCacheNodeBase

## Identity

KartParamCacheNodeBase — address-anchored name (vptr 0x12b2198,
GOT cell 0x130d920). Base of the linked-node member class: ctor 0x710066a2a4 (stores
x1 into [this+0x10] and into [[this]]-style head, u32 @0x18). The
embedders overwrite the vptr with KartParamCacheNode (0x12b26b0).

## Member notes

Notes in field order; proven from the cited addresses.

- 0x00
- 0x08 — unproven padding
- 0x10 — ctor stores x1 (node link)
- 0x18
- 0x1c — unproven padding (0x20 total) extent 0x20 (prior survey: 0x20 total (ctor 0x710066a2a4 stores reach 0x30))

> Naming: factory/array structural variant (base-call chain + factory case id only, no per-class strings).

## Construction / init order

In field/offset order (= binary init order within this header):
- 0x10 — ctor stores x1 (node link)
- 0x1c — unproven padding (0x20 total) extent 0x20 (prior survey: 0x20 total (ctor 0x710066a2a4 stores reach 0x30))
