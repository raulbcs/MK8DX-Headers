# nn::pia::session::BrowseMatchmakeJob

Identity: typeinfo-row vtable, assigned address 0x12dd630 (= typeinfo slot,
vptr-8); installed vptr **0x12dd638**. GOT cell 0x1313678 holds vptr-0x10
(0x12dd628 = offset-to-top 0). Typeinfo data 0x12dd680, name
"N2nn3pia7session18BrowseMatchmakeJobE" (name ptr 0xf811a0). 7 slots
(0x12dd638..0x12dd668). Base of the LocalMatchBrowseMatchmakeJob /
LanMatchBrowseMatchmakeJob / NexMatchBrowseMatchmakeJob family.

## Member notes

- Slots: 0x97dc8c (D1, `b 0xb4a62c`), 0x97dc90 (D0), 0xb4a654 / 0xb4a67c /
  0x933314 (shared pia-job stubs, inherited), 0x97ddbc (`ret` stub), 0x97dd84.
  All unrecovered in functions.csv.
- [this+0x08..0x57] — job-base subobject built by base C1 0xb4a5e0 (base D1
  0xb4a62c); LocalMatchBrowseMatchmakeJob.md identifies the base as
  nn::pia::common::StepSequenceJob (unverified here).
- [this+0x58] void* — zeroed by C2 0x97dc58 (0x97dc74); released via the
  vtable-call + `str xzr` pattern at 0x97dd94-0x97ddac.

## Construction / init order

1. C2 FUN_710097dc58 (0x97dc58..0x97dc88): base C1 0xb4a5e0 first (0x97dc68),
   then [this+0x58] = 0 (0x97dc74), then vptr 0x12dd638 = cell 0x1313678 +
   0x10 (0x97dc6c-0x97dc7c).
2. Derived wrappers re-install their own vptr after this C2, e.g.
   LocalMatchBrowseMatchmakeJob ctor 0x93bbc0 (installs cell 0x1312b98 vptr
   and inits a member at +0x60 via 0x929ec0).
3. No factory allocation found for the bare base; extent 0x60 is a lower
   bound from the +0x58 field store (derived layouts start at +0x60).
