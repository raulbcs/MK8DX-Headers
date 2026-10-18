# object::DynamicCaptureUseName

Name-keyed settings node created by the string-dispatch factory
FUN_71007430bc when the key equals "DynamicCaptureUseName"
(rodata 0xf0713c; sibling branches create nodes for other keys, e.g.
0xf070524 with size 0x360 / ctor FUN_7100741460, and a default branch with
size 0x140 / ctor FUN_7100746cd0).

- Identity: no RTTI. GOT cell 0x130ece0 holds 0x12bfb60 (vt-0x10); the
  installed vptr is cell+0x10 = 0x12bfb70. Offset-to-top (0x12bfb60) and
  typeinfo (0x12bfb68) are both 0.
- Base class vtable row 0x12bfa80 (GOT cell 0x130ecd8, vptr 0x12bfa80),
  whose base ctor chain reaches vptr 0x12c0298 (cell 0x130ed60).
- Extent: factory FUN_71007430bc allocates 0x120 via FUN_71005a095c
  (aligned alloc, align 0x10) at 0x7433b4..0x7433bc, then calls ctor
  FUN_7100741bc8 (0x7433d8).

## Member notes

- +0x00 vptr 0x12bfb70 (0x741bf0); +0x08..0x107 managed by base ctor
  FUN_7100745624 (0x741bd8), which forwards to FUN_71005a3c78 with a config
  cell (0x1306ff0 double-deref, field +0x48) — contents unproven.
- +0x108 pointer (delegate/handler), ctor zeroes (0x741be4); installed by
  setter FUN_7100741c00 (str x1,[x0,#0x108]; strb w2,[x0,#0x110]).
- +0x110 u8 flag, ctor zeroes (0x741be8); set together with +0x108.
- Method FUN_7100741c0c: if [+0x108] is set, calls FUN_7100741ab8 with
  ([handler+0x20]+0x28, this, arg, [this+0x110]) before tail-calling the
  base implementation FUN_71005a40ac — i.e. optional delegation hook.
  Its slot placement is unverified (not present in rows 0x12bfa80 /
  0x12bfb70).
- Slots (row 0x12bfb70 vs base row 0x12bfa80): overrides at 0-5, 8-11
  (slot 2 = 4-byte stub FUN_7100741cf4); slots 6, 7 and 12+ are shared
  with the base (0x5a2ccc, 0x5a2ce8, 0x5a2d10, 0x5a2d9c, 0x5a2dac,
  0x5a2e84, 0x5a35d0, 0x5a361c). Slot 0 override FUN_71005a3e18 (20 B).

## Construction / init order

1. Container virtual (slot +0xc0, see 0x743008) reaches factory
   FUN_71007430bc with a name key.
2. Key == "DynamicCaptureUseName": FUN_71005a095c(0x120, 0x10)
   (0x7433b4..0x7433bc).
3. Ctor FUN_7100741bc8: base ctor FUN_7100745624 (0x741bd8); zeroes +0x108
   and +0x110 (0x741be4/0x741be8); vptr 0x12bfb70 at +0x00 (0x741bf0).
