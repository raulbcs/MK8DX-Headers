# object::Vt12ca0b0 (PROVISIONAL)

25-slot vtable at 0x12ca0b0: base class of the heap worker nodes that the
named-subsystem engine family (`Vt12c9268`, 0x200 bytes) chains into its
intrusive list (+0x1b0/+0x1b8 head/tail, +0x1c0 count, +0x240 tail pointer).
Derives from Vt12c93a8 (its ctor 0x7f9ffc calls the Vt12c93a8 ctor 0x7b976c
first) and carries two secondary interface vptrs.

- vptr convention: GOT cell 0x1310408 holds 0x12ca0a0 (vt-0x10); installed
  vptr = cell+0x10 = **0x12ca0b0**. Offset-to-top 0 at 0x12ca0a0, typeinfo
  NULL at 0x12ca0a8 — no RTTI.
- Secondary vptrs: +0x50 = 0x12ca188 (cell 0x1310410 + 0x10; single slot
  0x7fa6cc; offset-to-top 0 / typeinfo NULL at 0x12ca178/0x12ca180) and
  +0x68 = 0x12ca1a0 (cell 0x1310420 + 0x10; slots 0x7fa6d8/0x7fa708).
- Size: operator new(0x88) + memset at the only found site FUN_7100398bd0
  (caller of ctor 0x7f9ffc), which then stores the manager at +0x18, another
  pointer at +0x28 and overrides [this] with a derived vptr (cell
  0x1307550+0x10) — so 0x88 is the derived node size too.
- Slots (from 0x12ca0b0): slot0 0x11047c, slot1 0x110484, slot2 0x1104e0,
  slot3 0x7fa6a8, slot4 0x110508, slot5 0x110574, slot6 0x7fa6a4, slot7
  0x1105d4, slot8 0x11063c, slot9 0x110698, slot10 0x1106a0, slot11 0x1cbc
  (clone-tail), slot12 0x7b97a8 (clone-tail), slot13 0x110788, slot14 =
  0x7fa3cc (only slot with a mapped name, FUN_71007fa3cc), slots 15-23 =
  0x11078c/0x110790/0x110794/0x110798/0x11079c/0x1107a0/0x1107a4/0x1107a8/
  0x1107ac (stub run, unrecovered), slot24 = NULL (0x12ca170). The function
  stored at +0x78 (cell 0x1310418 + 0x10 = 0x7fa08c) and the dtor-like
  0x7fa07c nearby are unverified.

## Construction / init order

1. Caller (0x398bcc..0x398bfc, engine FUN_7100398xxx): operator new(0x88),
   memset 0, bump engine +0x1c0 count, link engine +0x240.
2. Base ctor 0x7b976c (Vt12c93a8 region: vptr + zero +0x08..+0x37).
3. Derived ctor FUN_71007f9ffc: +0x38 w = 0, +0x40 = 0, main vptr = cell
   0x1310408 + 0x10, +0x48 = 0, +0x50 pair = (0x12ca188, 0x11ad210), +0x60 =
   0xed6af8, +0x68 = 0x12ca1a0, +0x70 = this, +0x78 = 0x7fa08c, +0x80 = 0
   (0x7f9ffc..0x7fa078).
4. Caller: +0x18 = self, +0x28 = engine pointer, final derived-vptr override
   (0x398c04..0x398c1c).
