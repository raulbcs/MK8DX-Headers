# NexNatRelay (nn::pia::inet::NexNatRelay)

- vptr 0x12d9a08 installed from GOT cell 0x13128e0 (RELATIVE addend 0x12d99f8 =
  vt-0x10; code does `cell+0x10`). The vt_ctors.tsv row 0x12d9a00 is the
  typeinfo slot, not the vptr. Typeinfo 0x12d9ba0 (si), name string
  0xf7e710 "N2nn3pia4inet11NexNatRelayE", base NatRelayInterface (0x12d9b88).
- Size 0xcc0, proven by the allocation site 0x710092cdfc
  (`0x568aa0(0xcc0, heap)` followed by ctor 0x710092f400) in the manager
  factory around 0x710092ce00, which stores the object at [mgr+0x88].

## Identity

NAT-relay worker for the pia inet stack. Secondary base
NexNatRelayInterface (typeinfo 0x12d9b70, name 0xf7e6e0) is materialized at
[this+0x28] with vptr 0x12d9af0 (cell 0x13128e8 + 0x10); its base is
typeinfo 0x12e41d0 (unverified name).

## Slots

Primary vtable 0x12d9a08, 27 slots (all FUN_* / unrecovered):
slot 0 = 0x710092f69c (D2: tears down the +0x08 intrusive list, members
0x10/0x18/0x20/0x48/0x50, list at +0x80, base at +0x28), slot 1 = 0x710092f8a4
(D0: D2 + operator delete). Secondary vtable 0x12d9af0, 15 slots, slot 0 =
0x71009ea9bc.

## Member notes

- 0x08/0x10/0x18/0x20 — heap blocks new'd by the ctor (0x18/0x70/0x90/0xc0).
- 0x28 — NexNatRelayInterface subobject (vptr 0x12d9af0).
- 0x38/0x40 — {this, [this+0x20]} pair (ctor 0x710092f630).
- 0x48 — new 0xc0 (init 0x7100a2bf88); 0x50 — new 0x48 member (vptr from
  runtime cell 0x130b4a8, -1 word at +0x44).
- 0x58 — third base subobject (ctor 0x7100929fd4, dtor 0x710092a014).
- 0x80..0x8f — sync pair zeroed then initialized via 0x710056810c.
- 0xac — zero; used as a sign-extended addend on entry pointers.
- 0xb0 — set to this+0xbc; 0xb8 = 0x40.
- 0xbc..0xc8b — 63 entries of 0x30 bytes zeroed by the ctor loop
  0x710092f4a8..0x710092f4d4 (stride constant 0xbd0/0x30 = 63).

## Construction / init order

1. Factory 0x710092ce00 news 0xcc0 (0x710092cdfc) and calls C2 0x710092f400.
2. C2 installs vptr 0x12d9a08 at [this], runs base ctor 0x71009ea9a8(+0x28),
   installs secondary vptr 0x12d9af0 at +0x28, runs base ctor
   0x7100929fd4(+0x58).
3. Allocates members (+0x08/+0x10/+0x18/+0x20/+0x48/+0x50), zeroes and inits
   the sync pair (+0x80), zeroes the state block 0x98..0xc4, zero-fills all 63
   entries at 0xbc.
4. D2 0x710092f69c / D0 0x710092f8a4 run the teardown in reverse.
