# nn::nex::NgsFacade

## Identity

- Assigned row 0x12e79e0; installed vptr = 0x12e79e8.
- GOT cell 0x1314da0 holds addend 0x12e79d8 = vptr-8; installed vptr =
  cell+0x10. Typeinfo pointer at vptr-8 = 0x12e79e0 points to RTTI record
  0x12e7d20 "N2nn3nex9NgsFacadeE" = nn::nex::NgsFacade; record base ptr
  0x12e7730 = nn::nex::RendezVous (offset-to-top slot 0x12e79d8 = 0).
- 5 vtable slots at 0x12e79e8: 0xa430b0 (704 B, FUN_7100a430b0; reinstalls
  own vptr 0x12e79e8 at site 0xa430c4 - dtor-family/reset, role unverified),
  0xa4334c (unrecovered), 0xa369b0 / 0xa376ac / 0xa37780 (unrecovered,
  inherited RendezVous/BackEndServices virtuals).
- Install sites: 0xa42e5c (ctor), 0xa430c4 (slot +0x00).

## Member notes

- Size 0x270 - factory at 0x916624: `mov w0, #0x270; bl 0x573f04; bl
  FUN_7100a42e30`; result stored at [parent+0x20]. Second factory call at
  0x9169b8 (same shape).
- 0x00..0x1b7: RendezVous base portion (see doc/object/NexRendezVous.md).
- +0x1d8: constant 0xc800000000 written by ctor.
- +0x1e0: initialized via 0x5788e0 with (this+0x1e0, sp{0x10001}); trailing
  +0x1f8/+0x1fc/+0x1fe counters zeroed.
- +0x208..+0x258: three cell/pointer triplets installed by ctor (helpers
  0x578f98); +0x268: heap object of 0xa8 bytes (0x573f04 at 0xa42fb4),
  initialized via 0xa28aa4/0x5783d4 and linked with this at +0x1d0.

## Construction / init order

1. Ctor FUN_7100a42e30 (640 B) calls RendezVous wrapper 0xa3eccc
   (base init + base vptr install).
2. Zero +0x1b8/+0x1c8, store 0xc800000000 at +0x1d8.
3. Install vptr 0x12e79e8 from cell 0x1314da0 (site 0xa42e5c).
4. Init semaphore at +0x1e0 (0x5788e0), zero +0x1f8..+0x200.
5. Install triplets at +0x208/+0x218..+0x258 (0x578f98).
6. Allocate 0xa8-byte object, init, store at +0x268; link list node at
   +0x1d0.
