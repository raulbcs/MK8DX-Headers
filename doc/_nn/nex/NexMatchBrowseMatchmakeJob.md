# nex::NexMatchBrowseMatchmakeJob

Name from row content: slot +0x08 is 0x93b7ac, named `NexMatchBrowseMatchmakeJob::WaitFindSessionByOwner` in functions.csv (8-byte thunk). Vtable anomaly: GOT cell 0x1312b90 holds 0x12daaa0 and every installation site computes cell+0x10 = 0x12daab0, so the installed vptr is 0x12daab0 - 0x10 below the assigned address. With that base, slot 0 = 0x93b6c0 (re-vptr + tail `operator delete`, i.e. a deleting dtor) while the complete-dtor-shaped 0x93b6ac (re-vptr, plain ret) sits at vptr-8 (0x12daaa8); the D1/D2 slot placement is unverified. 17 slots (+0x00..+0x80), typeinfo NULL.

## Member notes

- +0x00: primary vptr (0x12daab0).
- +0x08: qword from ctor arg (unverified - the sole ctor call passes x1 = alloc result of FUN_7100563b70).
- +0x10: ptr array base (factory stores one entry per job: `str x21,[x8,w22,uxtw#3]`, count at manager+0xc).
- +0x40: secondary vptr = cell 0x1312b88+0x10 (row 0x12dabc8, vptr 0x12dabd8; slots 0x9118d8, 0x93b9d4, 0x92a7e8, 0x93b778, 0x92adac, 0x93b9d8).
- +0x48: pointer, set to this+0x5c by the ctor (cursor into the zeroed region).
- +0x50: u32 = 0x400 (capacity of the 0x400-byte region zeroed at +0x5c..+0x45c); +0x54/+0x58: zeroed u32 pair.
- +0x5c..+0x45c: 0x400-byte table, zero-initialized in a 4-byte-stride loop; element header bytes at +0x5d/+0x5f cleared per entry.
- +0x668/+0x678: two member sub-objects sharing vptr = cell 0x1312968+0x10 (row 0x12da308, vptr 0x12da318); +0x670..+0x681 u16 fields zeroed; +0x682: u32 zeroed.
- slot +0x78 (0x93b6d4) is a bulk reset zeroing +0x8..+0x680 (unverified fully); slot +0x80 (0x93b7b4) is invoked by the ctor tail and immediately after construction by the factory.

## Construction / init order

- Ctor FUN_710093b60c(this) (416 bytes, 0x93b60c-0x93b7ac): installs secondary vptr at +0x40, zeroes +0x58, installs primary vptr, +0x50 = 0x400, zeroes the 0x400-byte region (+0x5c cursor init at +0x48), zeroes the +0x54..+0x682 block, installs the two +0x668/+0x678 member vptrs, then tail-jumps slot +0x80.
- Sibling ctors 0x93b6ac (re-vptr) and 0x93b6c0 (re-vptr + delete) serve as dtor pair.
- Factory loop at 0x932748-0x932788: for i < [manager+0xc]: alloc = FUN_7100568aa0(0x688, FUN_7100563b70(...)); ctor(alloc); alloc->slot+0x80(); store into [manager->0x10][i].
