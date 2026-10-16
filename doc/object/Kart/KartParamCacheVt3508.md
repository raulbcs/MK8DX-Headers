# KartParamCacheVt3508

## Identity

KartParamCacheVt3508 — address-anchored name (vptr 0x12b3508,
GOT cell 0x130daf8). Derived KartParamCacheMid variant built by the
factory 0x710065efbc (case w1=0, inline extension of the mid ctor);
size 0x150 (factory alloc).

## Member notes

Notes in field order; proven from the cited addresses.

- 0x110 — channel-pair member (ctor pair 0x7100662f30/0x7100662f70, cell 0x130d9b8)
- 0x128 — factory zero
- 0x12c — unproven padding
- 0x130 — channel-pair member (names 0xef9d06/0xef9d13) (0x150 total) Vtable slots : - slot 0 (0x10) vtable-init ctor stub, no base call (vt3508InitVt_710065f584): fans cell 0x710130d918(+0x10) vptr into 0xb0/0xd0/0xf0/0x110/0x130, cell 0x710130d920(+0x10) into 0x68, cell 0x710130d848(+0x10) into +0x0. The bodies in vt3598InitVt_710065faac and vt3868InitVt_71006612dc are byte-identical (same offsets), i.e. the whole 0x150-family shares this vptr layout. True extent 0x44 (file_list function-size field is a gap-split artifact). - slot 11 (0x68) mode dispatch (kartParamCacheVt3508DispatchMode_710065f5cc): when +0x148 == 3 the mode arg becomes 1, when == 4 it becomes 2; in both cases 0x710065f638(self,a,b,mode) runs once then again with mode 2; otherwise a single call with the unchanged mode. function size 0x6c bytes. - slot 12 (0x70) shift counts (vt3508ShiftCountsByShift_710065fa2c): replaces the u32 pair at arg+4/arg+8 with max(1, value >> *(int*)(self+0x148)) (arithmetic shift). function size 0x30 bytes. - slot 14 (0x80) register name (vt3508InitSlot14_710065fa6c; identical body in vt3598InitSlot14_710065ffac): builds a stack {vptr from cell 0x71012fae28+0x10, name 0x710ef9d38} pair and calls 0x7100664e94(self+0x110, a2, &local). True extent 0x34.

> Naming: factory/array structural variant (base-call chain + factory case id only, no per-class strings).

## Construction / init order

In field/offset order (= binary init order within this header):
- 0x110 — channel-pair member (ctor pair 0x7100662f30/0x7100662f70, cell 0x130d9b8)
- 0x130 — channel-pair member (names 0xef9d06/0xef9d13) (0x150 total) Vtable slots : - slot 0 (0x10) vtable-init ctor stub, no base call (vt3508InitVt_710065f584): fans cell 0x710130d918(+0x10) vptr into 0xb0/0xd0/0xf0/0x110/0x130, cell 0x710130d920(+0x10) into 0x68, cell 0x710130d848(+0x10) into +0x0. The bodies in vt3598InitVt_710065faac and vt3868InitVt_71006612dc are byte-identical (same offsets), i.e. the whole 0x150-family shares this vptr layout. True extent 0x44 (file_list function-size field is a gap-split artifact). - slot 11 (0x68) mode dispatch (kartParamCacheVt3508DispatchMode_710065f5cc): when +0x148 == 3 the mode arg becomes 1, when == 4 it becomes 2; in both cases 0x710065f638(self,a,b,mode) runs once then again with mode 2; otherwise a single call with the unchanged mode. function size 0x6c bytes. - slot 12 (0x70) shift counts (vt3508ShiftCountsByShift_710065fa2c): replaces the u32 pair at arg+4/arg+8 with max(1, value >> *(int*)(self+0x148)) (arithmetic shift). function size 0x30 bytes. - slot 14 (0x80) register name (vt3508InitSlot14_710065fa6c; identical body in vt3598InitSlot14_710065ffac): builds a stack {vptr from cell 0x71012fae28+0x10, name 0x710ef9d38} pair and calls 0x7100664e94(self+0x110, a2, &local). True extent 0x34.
