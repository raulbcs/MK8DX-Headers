# nn::nex::LogicalClockTmpl<int, unsigned short, short>

## Identity

- Assigned row 0x12e4d50; installed vptr = 0x12e4d58.
- GOT cell 0x1314438 holds addend 0x12e4d48 = vptr-0x10; installed vptr =
  cell+0x10. Typeinfo pointer at vptr-8 = 0x12e4d50 points to RTTI record
  0x12e4d38 (offset-to-top slot 0x12e4d48 = 0); name data
  "N2nn3nex16LogicalClockTmplItsEE" =
  nn::nex::LogicalClockTmpl<int, unsigned short, short>.
- 8 vtable slots at 0x12e4d58: 0x9e9de4 (D2, FUN_71009e9bf0 cluster),
  0xa1b3c0 (D1, FUN_7100a1b27c), 0xa1b418 (274 B), 0xa1b488 (790 B),
  0xa1b4d4, 0xa1b4e4, 0xa1b4ec, 0xa1b4f4 (micro-slots).
- Install sites: 0x9e9df4 (D2), 0x9f7458 (static init), 0xa1b3d0 (D1).

## Member notes

- Size: lower bound 0x20 from static init stores ([x+0x10] = 0,
  halfword [x+0x18] = 0). The instance is a static global whose pointer
  comes from GOT cell 0x1314440; no heap allocation observed - exact
  extent unverified.

## Construction / init order

1. Static init stub at 0x9f7434 (guarded by cell 0x1314188): loads instance
   ptr from cell 0x1314440, takes the global-tree lock (0x58c5a4).
2. Zero +0x10 and halfword +0x18; install vptr 0x12e4d58 from cell
   0x1314438 (0x9f7458..0x9f7468).
3. Register instance into the nex instance __tree (root 0x130b940,
   balance 0x58c448) and fire the devirtualized init callback slot 2 when
   the engine phase counter (cell 0x1314188 target) >= 2.
4. Destruction: D1 0xa1b3c0 / D2 0x9e9de4 reinstall the vptr from cell
   0x1314438 and reverse the registration.
