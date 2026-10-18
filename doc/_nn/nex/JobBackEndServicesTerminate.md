# nn::nex::JobBackEndServicesTerminate

## Identity

- RTTI-confirmed: typeinfo slot 0x12e6db0, typeinfo struct 0x12e7680, name
  "N2nn3nex27JobBackEndServicesTerminateE". Installed vptr = 0x12e6dc0
  (assigned slot + 8); offset-to-top 0 at 0x12e6db0. GOT cell 0x1314bf0 holds
  0x12e6db0 (vptr-0x10); installed vptr = cell + 0x10.
- 13 slots (0x12e6dc0..0x12e6e20): slot0 = D1 0xa3d3e0 (0x34 B, csv
  FUN_7100a3d3e0), slot1 = D0 0xa3d414 (0x34 B + tail operator delete
  0x588bd0), slots 2..12 are the shared nn::nex job block 0x5917a0 / 0x58ff6c /
  0x5917ac / 0x590148 / 0x59014c / 0x5917b0 / 0x5917cc / 0x58b7d8 / 0x5917d4 /
  0x5917d8 / 0x59189c.
- Correction over the previous header: the previously cited "ctor 0xa20128 /
  site 0xa20164" never touches GOT cell 0x1314bf0 (FUN_7100a20128 is an
  unrelated 700 B method); the real construction is the inlined factory
  FUN_7100a37050 below.

## Member notes

- Size 0x140 PROVEN: FUN_7100a37050 news 0x140 via 0x573f04 (0xa371b0..0xa371b8).
- 0x08..0xa0: nn::nex::ForcedCriticalSection base region (shared job base
  init 0x588b04(this, 2, scratch) at 0xa371d4; secondary vptr at +0x78).
- +0xb0..+0x13f: member subobject torn down by D1 0xa3d3e0
  (`str x8,[x0],#0xb0` vptr re-install + member dtor 0x585ae0).

## Construction / init order

1. Factory FUN_7100a37050 (0x368; reached via bl 0xa35ab0 / tail-branches
   0xa35dc0 and 0xa3704c in FUN_7100a359b8): alloc 0x140 (0xa371b0), null
   check, id load from [x19+0xb0]+0x18, base init 0x588b04 (0xa371d4), vptr
   store at 0xa371d8..0xa371e4.

Size 0x140 proven by the factory allocation.
