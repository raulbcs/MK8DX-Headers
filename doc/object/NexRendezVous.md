# nn::nex::RendezVous

## Identity

- Assigned row 0x12e6f50; installed vptr = 0x12e6f58.
- GOT cell 0x1314d40 holds addend 0x12e6f48 = vptr-8; installed vptr =
  cell+0x10. Typeinfo pointer at vptr-8 = 0x12e6f50 points to RTTI record
  0x12e7730 "N2nn3nex10RendezVousE" = nn::nex::RendezVous; record base ptr
  0x12e7480 = "N2nn3nex15BackEndServicesE" (offset-to-top slot 0x12e6f48 = 0).
- 5 vtable slots at 0x12e6f58: 0xa359b8 (880 B; FUN_7100a359b8; installs base
  vptr 0x12e6b78 from GOT cell 0x1314bd0 first - destructor family, role
  unverified), 0xa3ecfc (FUN_7100a3eccc cluster; calls init FUN_7100a35698
  then reinstalls own vptr, site 0xa3ece4), 0xa369b0 / 0xa376ac / 0xa37780
  (unrecovered; the last two are shared with the NgsFacade row 0x12e79e8 and
  are inherited BackEndServices virtuals).
- Install sites: 0xa3ece4 (cell 0x1314d40), 0xa359c8 (cell 0x1314bd0 ->
  base vptr 0x12e6b78).

## Member notes

- Size: lower bound 0x1b0 - init FUN_7100a35698 stores up to [x+0x1ac] and
  initializes heap subobjects at +0xd0 (0xe bytes) and +0xd8 (0x64 bytes)
  allocated via 0x573f04. No complete-object heap allocation observed (the
  class lives as base of NgsFacade, whose factory allocates 0x270); exact
  extent unverified.
- +0x10/+0x18: flag and byte zeroed by init; +0x28: stlr sync word set to 1.
- +0x40: intrusive list self-linked {+0x40,+0x48} = this+0x40.
- +0xb8: 30000 (timeout), written by init.
- +0x20: vptr+0x10 from cells 0x130b618 / 0x130b740 (two-phase).

## Construction / init order

1. Init FUN_7100a35698 (368 B): zero +0x10/+0x18, seed +0x20 cell vptr,
   stlr 1 at +0x28, zero +0x30..+0xb0, init list +0x40, write 30000 at
   +0xb8, zero +0xc0..+0x1af.
2. Allocate subobjects: 0xe bytes at +0xd0, 0x64 bytes at
   +0xd8 (both via 0x573f04, then configured via 0xa28d3c/0xa2a6b8).
3. Wrapper 0xa3ecfc (slot +0x08): calls init, then installs vptr 0x12e6f58
   from cell 0x1314d40 (site 0xa3ece4).
4. Derived nn::nex::NgsFacade ctor FUN_7100a42e30 calls this wrapper as
   base initialization.
