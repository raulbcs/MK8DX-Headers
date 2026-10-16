# KartParamCacheChan

## Identity

KartParamCacheChan — address-anchored name (vptr 0x12b21e0,
GOT cell 0x130d908). The recorder channel-pair member embedded at 0xb0/0xd0/0xf0 of
KartParamCacheMid, 0x110/0x130 of the 0x150 variants and 0x200 of
KartParamCacheColorCorrection: ctor pair 0x7100662f30 (base) + 0x7100662f70 (name/fn fill:
fn cell 0x12fae28, rodata name, owner back-ptr).

## Member notes

Notes in field order; proven from the cited addresses.

- 0x18 — filled by the 0x7100662f70 init extent 0x20 (true extent per prior survey (0x18 base + 0x8 tail)) Vtable slot 0 (0x10) vtable-init ctor stub : stores the class vtable pointer (global pointer at 0x710130918, +0x10) into *this. True extent 20 bytes.

> Naming: factory/array structural variant (base-call chain + factory case id only, no per-class strings).

## Construction / init order

In field/offset order (= binary init order within this header):
- 0x18 — filled by the 0x7100662f70 init extent 0x20 (true extent per prior survey (0x18 base + 0x8 tail)) Vtable slot 0 (0x10) vtable-init ctor stub : stores the class vtable pointer (global pointer at 0x710130918, +0x10) into *this. True extent 20 bytes.
