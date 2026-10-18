# nn::pia::session::RandomMatchmakeJob

Identity: vtable word 0x12de300; typeinfo pointer there targets 0x12de3a0 =
{0x10, "N2nn3pia7session18RandomMatchmakeJobE"}. GOT cell 0x1313988 holds
vptr-0x10 (0x12de2f8 = offset-to-top 0), installed vptr **0x12de308**. Slots
0x12de308..0x12de368: 12 populated entries plus a null entry at 0x12de358
(role unverified). The words at 0x12de3c0+ belong to the neighbouring
nn::pia::session::RelayRouteManageJob group (typeinfo 0x12de400, name
0xf81d30), not to this class.

## Member notes

- Slots: 0x99582c (D1), 0x995870 (D0), 0xb4a654 / 0xb4a67c / 0x933314 (shared
  pia-job stubs), 0x996bdc, 0x996b38, 0x953688 (shared with the inet twin
  NexMatchRandomMatchmakeJob), 0x996be0, 0x979444 (ret stub), null, 0x996b34,
  0x996ab8 (shared with the inet twin).
- Ctor FUN_71009957dc: job-base ctor 0xb4a5e0 (0x9957ec); zero +0x68/+0x6c and
  the +0x58 pair; vptr 0x12de308 (0x99580c); sub-object ctors 0x9b1fe8 at
  +0x80 (0x995810) and 0x929ec0 at +0xf8 (0x995818); +0x118 = 0 (0x99581c).
- D1 0x99582c / D0 0x995870 tear down the +0xf8 / +0x80 sub-objects in
  reverse order, then base D1 0xb4a62c.
- Derived classes: nn::pia::lan::LanMatchRandomMatchmakeJob (ctor 0x97854c,
  continues at +0x120, total alloc 0x158) and a second derived ctor
  FUN_7100951714 (writes +0x120/+0x130). The base portion therefore ends at
  exactly 0x120.

## Construction / init order

1. No direct factory found (both callers are derived ctors constructing the
   base in place). Size 0x120 is proven by the derived sub-object boundary
   (LanMatchRandomMatchmakeJob alloc 0x158 at 0x96d224).
2. Ctor: 0xb4a5e0, field zeroes, sub-object ctors at +0x80 and +0xf8, +0x118
   = 0, vptr 0x12de308.
