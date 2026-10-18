# nn::nex::qProtectedList<StationURL>

## Identity

- Assigned row 0x12e4e40; installed vptr = 0x12e4e48.
- GOT cell 0x1314570 holds addend 0x12e4e38 = vptr-0x10; installed vptr =
  cell+0x10. Typeinfo pointer at vptr-8 = 0x12e4e40 points to RTTI record
  0x12e4e28 (offset-to-top slot 0x12e4e38 = 0); name data
  "N2nn3nex14qProtectedListINS0_10StationURLEEE".
- 8 vtable slots at 0x12e4e48: 0x9f4640 (D2, FUN_71009f4544 cluster),
  0xa1b8dc (D1, FUN_7100a1b844), 0xa1b934 (310 B), 0xa1b9bc (118 B),
  0xa1ba08 (516 B), 0xa1ba18, 0xa1ba20, 0xa1ba28 (micro-slots).
- Install sites: 0x9f4650 (D2), 0x9f7520 (static init), 0xa1b8ec (D1).

## Member notes

- Size: lower bound 0x28. The static singleton lives at .bss 0x13616c0;
  init stores zero at +0x10 and the rodata sentinel 0xed6af8 at +0x18 and
  +0x20 (list begin/end markers). No heap allocation observed - exact
  extent unverified.

## Construction / init order

1. Static init stub (0x9f74d0 cluster, instance from .bss 0x13616c0): take
   the global-tree lock (0x58c5a4).
2. Zero +0x10; install vptr 0x12e4e48 from cell 0x1314570
   (0x9f751c..0x9f752c).
3. Store sentinel pair {0xed6af8, 0xed6af8} at +0x18/+0x20 (0x9f7538).
4. Register the instance into the nex instance __tree (root 0x130b940,
   balance 0x58c448) and fire the devirtualized init callback slot 2 when
   the engine phase counter >= 2.
5. Destruction: D1 0xa1b8dc / D2 0x9f4640 reinstall the vptr from cell
   0x1314570 and reverse the registration.
