# object::NexNatRelayInterface

RTTI-CONFIRMED: nn::pia::inet::NexNatRelayInterface. The vtable row carries a
typeinfo pointer at vptr-8 (0x12d9ae8 -> record 0x12d9b70, name string
"N2nn3pia4inet20NexNatRelayInterfaceE" at 0xf7e6e0); GOT cell 0x13128e8 holds
0x12d9ae0 (row-0x10), installed vptr = cell+0x10 = 0x12d9af0.

NOTE: tools/vt_ctors.tsv lists this vtable as "0x12d9ae8" — that address is
the typeinfo slot (vptr-8), not the fn row.

## Identity

- Concrete impl: `memalloc(0x1d8)` in nn::pia::inet::NexNatRelay's C1
  (0x92cda8, alloc size 0x1d8, zero-filled loop 0x92cdbc), stored at
  NexNatRelay+0x60; C1 = 0x92f400 installs vptr 0x12d9af0 at [this+0x28].
- 16 slots ending 0x12d9b68 (slot 15 0x92f694); typeinfo record 0x12d9b70
  follows immediately.

## Member notes

- Object is zero-filled by the allocator loop before C1 runs.
- [this+0x28] vptr; [this+0x30] zero (C1 0x92f444 `stp x8, xzr`).
- [this+0x58] — embedded nn::pia::local::LocalAddress, C1 0x929fd4 (0x92f44c);
  same base ctor used by nn::pia::local::LdnConnectionStatus (see
  doc/object/Vt12e1018 if present on main).
- [this+0x60/0x68/0x70/0x78] — zeroed scalars; [this+0x7C] = 0x40 (0x92f480).
- [this+0x80..] — init continues at 0x92f464-0x92f4bc (members via 0x56810c /
  0x568118, array via [this+0xB0] table walk); layout beyond 0x80 unproven.

Slots: slot 2 0x92f1b8 (12 B), slot 4 0x930ecc, slot 6 0x92f1cc, slot 9
0x92f290 (368 B), slot 11 0x92f350; slots 0 (0x9ea9bc), 1 (0x930ea8), 3
(0x92f1c4), 5 (0x930ed0), 7 (0x930ed4), 8 (0x92f224), 10 (0x92f2f0), 12
(0x930ed8), 13 (0x92f3e8), 14 (0x92f694) are unrecovered in functions.csv.

## Construction / init order

- Heap zero (0x92cdbc) -> C1 0x92f400: vptr @+0x28 (0x92f434) -> zero +0x30,
  +0x38..+0x47 -> LocalAddress C1 @+0x58 (0x92f44c) -> zero +0x60..+0x7b ->
  0x40 @+0x7C -> remaining member init (0x92f464+).
- Extent 0x1D8 proven by the alloc size at 0x92cda8.
