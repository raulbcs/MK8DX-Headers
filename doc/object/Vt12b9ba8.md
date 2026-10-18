# object::Vt12b9ba8

PLACEHOLDER name. agl/gl resource-handler object keyed by the file extension
string "txt" family. Two factory blocks share this vtable: variant A id
0x2d (45), variant B id 0x30 (48).

- Identity: created only inline inside FUN_71006ceab0:
  - variant A: block 0x6d0c38-0x6d0d6e, alloc 0x160 via
    allocFromHeapOrDefault_710060b234, registered into array [mgr+0x258]
    (count [mgr+0x250]).
  - variant B: block 0x6d0fac-0x6d1070, alloc 0x160, registered into array
    [mgr+0x288] (count [mgr+0x280]).
- vtable convention: row = 0x12b9b98, typeinfo slot 0x12b9ba0, installed
  vptr = 0x12b9ba8 (slot 0 = 0x6d9164). Materialized by adrp 0x12b9000 +
  add 0xb98 + 0x10; no GOT cell.
- Base pattern: the base-class row is loaded from GOT cell 0x130e268
  (rela addend 0x12b9c58) and stored at +0x00 first ([cell]+0x10 =
  0x12b9c68), then replaced by the final derived vptr 0x12b9ba8. 0x12b9c68
  therefore names the base class of this pair.
- 21 primary slots (0xa8): slot 0/1 dtor pair 0x6d9164 / 0x6d916c
  (unrecovered); shared tail 0x6d738c/0x6d704c..0x6d7394; class-specific
  0x6d9164..0x6d94b8. A secondary group repeats at +0x128
  (0x6d738c..0x6d7394+), zero gap 0xb0-0x120 — MI/RTTI-carrying tail,
  unverified.
- Embedded members at +0x40, +0x98, +0xf8: base vptr [0x12fada0]+0x10 =
  0x11ad0f8, each overridden to [0x12fadb0]+0x10 = 0x11ad158 after
  FUN_710061cc48 ctor; payload byte at +0x54 / +0xac / +0x10c.
- +0xf0 and +0x150 set to -1; +0x154 = 8; +0x158 = 0 (variant B).

## Member notes

- +0x10 u32 id (0x2d / 0x30); +0x18 entry = x25 + 0x2d0/0x300 clamped by
  count (csel); +0x20/+0x28 self pointers; +0x30/+0x38 zero.
- Members: guard/ptr/byte pattern identical to Vt12b9a28's members
  (guards 0x40 at +0x50 and +0x108, 0x100 at +0xa8).
- Variant B additionally stores a byte at +0xc (block 0x6d0fxx) before the
  shared init — variant-specific field, unproven.

## Construction / init order

1. allocFromHeapOrDefault_710060b234(0x160, heap, align 8).
2. Base-row vptr 0x12b9c68 at +0x00, manager +0x08, id +0x10, entry +0x18,
   self ptrs, zero +0x30/+0x38 (base ctor inlined).
3. Members A/B/C at +0x40/+0x98/+0xf8: vptr 0x11ad0f8, guard, ptr, ctor
   FUN_710061cc48, payload byte, override vptr 0x11ad158.
4. -1 at +0xf0 and +0x150; 8 at +0x154; 0 byte at +0x158 (B).
5. Derived vptr 0x12b9ba8 at +0x00 (0x6d0d34-0x6d0d44); registered into
   the manager array.
