# nn::pia::lan::LanProtocol

## Identity

RTTI-confirmed: compact typeinfo record at 0x12dc7a0 = {0x10, name 0xf80d00 = "N2nn3pia3lan11LanProtocolE"}. Primary vtable row: offset-to-top 0 at 0x12dc718, typeinfo slot 0x12dc720, vptr 0x12dc728. GOT cell 0x13133b8 holds 0x12dc718 (vt-0x10 convention; installed vptr = cell+0x10). 13 slots (0x12dc728-0x12dc788); value 0xc000 at row+0x68 belongs to the next record, not a slot.

size 0x12a0 — LOWER BOUND: max field store xzr at +0x1298 (0x96fa88). No operator-new for the object itself: it is constructed in place at lanmanager-singleton+0x10 (singleton via GOT cell 0x13125e0); the surrounding factory region is 0x12f0 (helper 0x9a7c5c called with x0 = this, w1 = 0x12f0, site 0x96cd18-0x96cd28).

Base call at ctor head: 0x9a79c8 (0x96f9e4). Slots shared with the pia vtable cluster: slot2 0x971934, slot3 0x97219c, slot5 0x96fd2c, slot7 0x96fdd0, slot8 0x9700a0, slot10 0x9721a4, slot11 0x96fbe4, slot12 0x96fcb4 (unrecovered in functions.csv).

## Member notes

- +0x00 vptr (0x12dc728).
- +0x28 u8 init 0; +0x2c/+0x30 s32 pair init 0 (stp wzr,wzr); +0x34 u32 init 0; +0x38 u8 init 0; +0x50 u8 init 0; +0x68 u64 init 0.
- +0x648 u8 init 0; +0xc28 u32 init 0x320 (=800, 0x96fa08-0x96fa0c).
- +0x1210 u64 pointer (x20 = this+0x1210, filled at 0x96fba0); +0x1220 u16 init 0; +0x1208 u64 init 0 (0x96fa48); +0x1248/+0x1270/+0x1298 u64 init 0.
- ctor also memsets a region (memset@plt at 0x96fa40) and calls slot-row helpers 0x92a1e0/0x92a20c/0x929ec0/0x929fc4 (unverified semantics).

Slot map (vptr 0x12dc728):
- slot0 0x96faf0 = D1, slot1 0x96fbc0 = D0 (dtor pair; site 0x96fb00 in slot0 re-installs vptr, unverified), slot2 0x971934.
- slot4 0x9a7a2c (functions.csv, 8 B), slot6 0x9a7a3c, slot9 0x9a7a4c — tiny recovered stubs.
- remaining slots unrecovered (see above).

## Construction / init order

Factory at 0x96cce8 (site 0x96cd28):

1. Load singleton via cell 0x13125e0; if already initialized (byte [inst+0x38]) skip.
2. this = singleton+0x10; call 0x9a7c5c(this, 0x12f0).
3. Call ctor 0x96f9d4(this): base 0x9a79c8; clear +0x28/+0x2c..+0x34/+0x38/+0x50/+0x68; install vptr 0x12dc728; store 0x320 at +0xc28; zero +0x648, +0x1208; init helpers 0x92a1e0/0x92a20c; memset; zero +0x1220/+0x1248/+0x1270/+0x1298; fill pointer this+0x1210.
4. Pass this and the 0x9a7c5c result to 0x9a7ccc (w2 = 0x4400).
