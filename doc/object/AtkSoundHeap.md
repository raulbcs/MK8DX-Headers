# nn::atk::SoundHeap

## Identity

- Assigned row 0x12f1bf0; installed vptr = 0x12f1bf8.
- GOT cell 0x1314fb8 holds addend 0x12f1be8 = vptr-0x10; installed vptr =
  cell+0x10. Typeinfo pointer at vptr-8 = 0x12f1bf0 points to RTTI record
  0x12f1c20 "N2nn3atk9SoundHeapE" = nn::atk::SoundHeap (record base ptr
  0x12ae648); offset-to-top slot 0x12f1be8 = 0.
- 5 vtable slots at 0x12f1bf8: 0xa7d614 (FUN_7100a7d614, 64 B - D2: installs
  vptr, teardown 0xa7d654, finalizes list +0x28 via 0xa7dc2c, tail-calls
  nn::os::FinalizeMutex on +0x08), 0xa7d6d8 (FUN_7100a7d6d8, 72 B - D0
  deleting dtor: same teardown then `operator delete`), 0xa7d784 /
  0xa7d858 / 0xa7d8cc (unrecovered).
- Install sites: 0xa7d5e4 (ctor), 0xa7d620 (D2), 0xa7d6e8 (D0).

## Member notes

- Size: lower bound 0x40. Ctor is FUN_7100a7d5d4 (64 B); both observed
  constructions are base subobjects at offset 0 of derived classes whose
  ctors (callsites 0x7748c0 and 0x778190) continue with their own fields
  from +0x40 - no standalone allocation site; exact extent unverified.
- +0x08: nn::os::MutexType (InitializeMutex(this+8, 1, 0)).
- +0x28: intrusive list {head = 0, first = last = this+0x30} seeded at
  0xa7dc1c; torn down by 0xa7dc2c (walks [x0] chain).

## Construction / init order

1. Ctor FUN_7100a7d5d4: install vptr 0x12f1bf8 from cell 0x1314fb8.
2. nn::os::InitializeMutex(this+0x08, 1, 0).
3. Seed list at +0x28 (head null, first/last = this+0x30).
4. Derived ctors (0x7748c0: stores zero at +0x40, zeroes +0x48..) append
   their own fields from +0x40.
