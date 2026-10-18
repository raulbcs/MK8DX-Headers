# object::Vt12cb6e0

"MiiEngine" subsystem (identity from the name string 0xf0c064 passed to the
base ctor; the adjacent rodata holds "GSysMii"/"GSysMiiFaceOnly"). Derives from
Vt12c9268; layout identical to the base (0x200 bytes). Unlike CameraEngine /
SystemSubEngine there is no post-ctor vptr override: the runtime vptr IS
0x12cb6e0.

- vptr 0x12cb6e0 installed by the ctor FUN_7100820fa0 at +0x00
  (0x7100820fbc..0x7100820fcc; GOT cell 0x13107c0 holds 0x12cb6d0 = vt-0x10, so
  the installed vptr is cell+0x10), after base C1 FUN_71007f3ffc(this, parent,
  "MiiEngine") (0x7100820fb8) and +0x1f8 = 0 (0x7100820fc4).
- Extent 0x200: caller FUN_71003d6e20 allocates 0x200, align 8
  (allocFromHeapOrDefault 0x710060b234, 0x71003d6e30..0x71003d6e44) then calls
  the ctor (0x71003d6e50) and returns the object unmodified.
- Slot 23 FUN_7100820fdc is the node-append virtual: allocates a 0x880 node
  (operator new, align 8, 0x7100820ff4..0x7100820ffc), constructs it with
  FUN_710081eacc, links it into the +0x1b0 list, stores it at +0x1f8 and bumps
  the +0x1c0 count (0x7100820ffc..0x7100821060).
- Slot 1 FUN_7100821078 is the derived D2; slot 2/3 pair 0x71003f7b64 /
  0x71003f7c84 and the remaining slots are shared with the Vt12c9268 base table.

## Construction / init order

1. FUN_71003d6e20: allocFromHeapOrDefault(0x200, align 8) (0x71003d6e30).
2. Ctor FUN_7100820fa0: base C1 FUN_71007f3ffc with name "MiiEngine"
   (0x7100820fb8), then +0x1f8 = 0 and vptr 0x12cb6e0
   (0x7100820fc4..0x7100820fcc).
