# PanePan1

## Identity

- vtable 0x12bf990, 28 slots + a second table at 0x12bfa80 (cells 0x130ecd0
  region; cell holds vt-0x10, installed vptr = cell+0x10).
- Factory: pane-tag dispatcher 0x7430bc: tag "pan1" (w2 == 0x316e6170,
  checked at 0x743188) requires string 0xf0747f ("CaptureOn") in the pane
  resource, then allocates 0x360 (align 0x10) and calls ctor 0x73fc50
  (0x743198..0x7431cc).
- Base ctor 0x5a22e4 called at 0x73fc64 before the derived stores.

## Member notes

- +0xda: u16 init 0x100 (0x73fc6c..0x73fc78); +0xe0/+0xe8: +0xe0 heap block
  freed with operator delete, +0xe8 child destroyed via its [vt+8] entry by
  D1 0x740864.
- +0xf0: pair {vptr cell 0x1308f98+0x10, -1} stored by 0x73fca0 (shared
  cell, also used by PanePic1/PaneMassDrawOn at +0x108).
- +0x110: subobject ctor 0x63ecbc (0x73fca4); +0x178: subobject ctor
  0x63f778 (0x73fca8); D1 tears down +0x348 via 0x6373a4, +0x108 (dtor at
  +0xb0 then delete), +0x228 via 0x639f38, +0x110 via 0x63ed3c.
- +0x348/+0x350/+0x358 zeroed by the ctor (0x73fcb0..0x73fcbc); ctor tails
  into 0x73fcd0 which parses [arg3+0x20] (0x73fcc0).
- Dtor triple: D1 0x740864, D0 0x7408f4 (wraps D1 + delete), slot 2 0x74130c
  (FUN_710074130c, unrecovered). Slots 20/21 = 0x740918 / 0x740a3c
  (FUN_7100740a3c), rest shared 0x5a2xxx cluster.

## Construction / init order

1. Factory 0x743198: "pan1" tag + "CaptureOn" string; aligned_alloc(0x360,
   align 0x10) at 0x7431b4.
2. C1 0x73fc50: base ctor 0x5a22e4 (0x73fc64); vptr 0x12bf990 at +0x00
   (0x73fc8c..0x73fc90); zero/init stores 0xe0..0x108 and 0x348..0x358;
   +0xf0 pair store; subobject ctors 0x63ecbc (+0x110) and 0x63f778
   (+0x178); tail 0x73fcd0 with [arg3+0x20].
