# KartParamCacheVt3598

## Identity

KartParamCacheVt3598 — address-anchored name (vptr 0x12b3598,
GOT cell 0x130db00). Derived KartParamCacheMid variant built by the
factory 0x710065efbc (case w1=1, inline extension of the mid ctor);
size 0x150 (factory alloc).

## Member notes

Notes in field order; proven from the cited addresses.

- 0x110 — channel-pair member (ctor pair 0x7100662f30/0x7100662f70, cell 0x130d9b8)
- 0x128 — factory zero
- 0x12c — unproven padding
- 0x130 — channel-pair member (names 0xef9d06/0xef9d13) (0x150 total) Vtable slots : - slot 12 (0x70): shifts the u32 pair at arg+4/arg+8 left by *(int*)(self+0x148) and stores back the smaller of the shifted value and the original element (arg+0xc participates as the bound for the arg+8 element). function size 0x30 bytes (file_list size is a gap-split artifact). Slot-0/slot-14 bodies shared with the Vt3508 family are recorded in KartParamCacheVt3508.hpp.

> Naming: factory/array structural variant (base-call chain + factory case id only, no per-class strings).

## Construction / init order

In field/offset order (= binary init order within this header):
- 0x110 — channel-pair member (ctor pair 0x7100662f30/0x7100662f70, cell 0x130d9b8)
