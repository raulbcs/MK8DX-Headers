# gsys::SystemTask

- Identity: C1 0x7136f4 is already named `gsys::SystemTask` in
  config/functions.csv (the class registers named child tasks
  "gsys::SystemTask" 0xf046a0, "::PreCalc" 0xf046b1, "::PostCalc"
  0xf046cb, "::DrawTV" 0xf046e6, "PostDraw(DRC)" 0xf0491c).
- vptr 0x12bc5c0; GOT cell 0x130e680 holds 0x12bc5b0 = vt-0x10.
- Size 0x6d8: proven by the guarded singleton factory at 0x3c71f8
  (`mov w0, #0x6d8; _Znwm; C1` at 0x3c7204..0x3c7214). The factory also
  writes profile flag words (0x400/0x180/0x40/0x100/0xc0000) into the
  global 0x133f8b8 after construction.
- Member functions recovered: `preCalc_` 0x713b84, `calcFrame` 0x71411c
  (both named in functions.csv; also stored as raw fn ptrs in cells
  0x130e698/0x130e6a0/0x130e6a8 next to the family's vptr cells).

## Member notes

| Offset | Field | Evidence |
|---|---|---|
| 0x00 | vptr | C1 0x713738 |
| 0xd0 | u8 flag | C1 0x71373c |
| 0xd8 | sub-object (C 0x7139c4, vptr 0x12bc5a0) | C1 0x713730..0x713740 |
| 0x488 | secondary vptr (cell 0x130e678) | C1 0x71375c |
| 0x490 | 0xb5-byte param block copied from arg+8 | memcpy 0x713760 |
| 0x548 | const 0xfff6c900 | C1 0x71377c |
| 0x574/0x57c/0x5b8/0x5bc/0x5c0/0x6c8/0x6cc | float 1.0f | C1 0x713770..0x7137b8, 0x7137f0/0x7137f8 |
| 0x5b0 | vptr 0x12bc6a8 (cell 0x130e688) | C1 0x7137ac |
| 0x5c8 | heap ptr, freed by D1 | D1 0x714e90..0x714ea4 |
| 0x5d0 | sub-object (C 0x63194c) | C1 0x7137c0 |
| 0x6a8/0x6a9 | bytes = 4 | C1 0x7137dc/0x7137e0 |
| 0x6b0 | vptr (cell 0x130d6f0) | C1 0x7137fc |
| 0x6b8 | two packed 1.0f floats | C1 0x7137ec |
| 0x130/0x1c8 (inside 0xd8 sub) | node pairs set by C1 (0x713820, 0x713864: `stp x21, this`) | intrusive list links |

The C1 inlines the named-task registration: repeated
`stp vptr, stringptr; bl 0x61c9bc` blocks at 0x713848, 0x713884, 0x7138b4,
... attach children named from 0xf04xxx strings; child nodes live at
+0x120/+0x170/+0x1b8/+0x208/+0x250 ... (init pairs at 0x71381c, 0x713864,
0x7138a8).

Slots: slot0 0x714e74 (D1, size 2664, deletes +0x5c8 then chains through
the 0x12fa0e68 global dtor block), slot1 0x714fac (unrecovered, D0),
slot2 0x716bb0, slot3 0x716c7c, slot4-7 unrecovered, slot9 0x611acc,
slot11 0x715aac, slot20 0x716af8, rest unrecovered or tiny ICF clones.
Secondary vptrs installed at 0x488/0x5b0/0x6b0 belong to the family cells
0x12bc590/0x12bc698/0x12bc6b8.

## Construction / init order

- Factory 0x3c71f8 (guarded init on 0x1308080-family guard): `new 0x6d8`,
  then C1 with (this, stack args at sp).
- C1 order: base-ish init `bl 0x612bb8` (0x713720), vptr store (0x713738),
  +0xd8 sub-object C (0x713740), +0x488 vptr + 0xb5-byte memcpy into 0x490
  (0x71375c..0x713760), scalar/pointer zeroing + 1.0f defaults
  (0x713774..0x7137c0), +0x5d0 sub-object C (0x7137c0), list-node pairs at
  +0x130/+0x1c8/+0x260 (0x713820, 0x713864, 0x7138a8), named-task
  registrations via 0x61c9bc (0x713848 onward). C1 ends 0x714118.
