# object::Vt12cf2c8

Sibling of the Vt12ceb08 family (same 0x412-byte init-clone shape).

- Identity: no RTTI. Primary row 0x12cf2c8: 8 slots 0x86096c/0x860a20/
  0x860ad4/0x860b60/0x860c18/0x860f88/0x860c98/0x860c9c; never installed
  (no GOT cell, no code reference).
- Stub row 0x12cf318 (GOT cell 0x1310ea8 holds vt-0x10; vptr = cell+0x10):
  1 slot 0x860f8c; lazy guards at 0x860860/0x860924 install the stateless
  singleton (this == vptr) under guard 0x1310eb0 (cell addresses unverified).
- Concrete row 0x12cf330 (GOT cell 0x1310ed0; vptr = cell+0x10): 44 slots,
  0x12cf330..0x12cf490, same slot count as the Vt12ceff8 concrete row.
  Installed into [this] by init entry 0x8610c8 (0x8610e4).

## Member notes

- Only the vptr is proven; remaining 0x58 bytes are init-managed padding
  (unproven). No field stores were traced beyond the vptr in the factory
  window.

## Construction / init order

1. Shared factory: `new` 0x60 via FUN_710060afec (0x383634..0x38363c);
   result stored at [parent+0x248] (0x38364c).
2. Init entry 0x8610c8 (inside FUN_7100860f2c, csv size 0x412): installs
   vptr 0x12cf330 (0x8610e4).
