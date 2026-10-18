# object::Vt12cf5b0

Sibling of the Vt12ce1c8 family (same factory block; the concrete row shape
matches the Vt12ceb08 54-slot clone family).

- Identity: no RTTI. Primary row 0x12cf5b0: 8 slots 0x861b80/0x861c34/
  0x861ce8/0x861d74/0x861e2c/0x8621b8/0x861ed4/0x861ed8; never installed
  (no GOT cell, no code reference).
- Stub row 0x12cf600 (GOT cell 0x1310ee0 holds vt-0x10; vptr = cell+0x10):
  1 slot 0x8621bc; lazy guards at 0x861a74/0x861b38 install the stateless
  singleton (this == vptr) under guard 0x1310ef8 (cell addresses unverified).
- Concrete row 0x12cf618 (GOT cell 0x1310f08; vptr = cell+0x10): 54 slots,
  0x12cf618..0x12cf7c8. First slots 0x55ae80 then ICF-clone stubs 0xbbdc,
  0xbbe4, ... (functions.csv U). Installed into [this] by ctor FUN_71008622f8
  (csv FUN_71008622f8, size 0x54; the entry is a mid-function clone of the
  0x412-byte FUN_710086215c) at 0x862324.

## Member notes

- Only the vptr is proven; the remaining 0x630 bytes are ctor-managed
  (unproven). The clone family suggests the same list/queue layout as
  Vt12ce1c8/Vt12ceb08, but no field stores were traced for this ctor.

## Construction / init order

1. Shared factory: `new` 0x638 via FUN_710060afec (0x383780..0x383788);
   result stored at [parent+0x258] (0x383790).
2. Ctor FUN_71008622f8 installs vptr 0x12cf618 (0x862324).
