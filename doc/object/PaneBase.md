# PaneBase

## Identity

- vtable 0x12c0298, 29 slots, GOT cell 0x130ed60 holds vt-0x10 (0x12c0288);
  installed vptr = cell+0x10.
- The only vptr-install site is the C1 0x745624 itself (0x745664..0x745670):
  the ctor is the tail of the family alloc helper. Factory: pane-tag
  dispatcher 0x7430bc fall-through at 0x7434c4 allocates 0x110 (align 0x10)
  and calls 0x745624 (0x7434c4..0x7434e8). This branch is the dispatcher's
  default (no pane-tag/attribute match).
- Base ctor chain: 0x5a3c78 (huge, 0x745660); slots 3-28 are the shared
  0x5a2xxx/0x5a3xxx cluster also present in PanePic1/PaneMassDrawOn.

## Member notes

- Extent 0x110 from the factory allocation; no owned field stores in the
  ctor body (everything below +0x08 is initialized by 0x5a3c78) - unproven.
- Dtor triple: D1 0x5a3e18 (shared; installs base-family vptr from cell
  0x130c980 then tails 0x5a22e0), D0 0x745680, slot 2 0x7456a4 (delete).
- Slots 0/1/2: 0x5a3e18 / 0x745680 / 0x7456a4; all other slots resolve to
  FUN_71005a**** (unrecovered shared cluster).

## Construction / init order

1. Factory 0x7434c4: aligned_alloc(0x110, align 0x10).
2. C1 0x745624: call 0x5a3c78 with (this, 0, [mgr+0x48], args 1..3) where
   mgr = [[0x1306ff0]] (0x745630..0x745660); vptr 0x12c0298 stored at +0x00
   (0x74566c..0x745670).
3. Derived panes (PanePic1 0x744f40, PaneMassDrawOn 0x743c38) call 0x745624
   as their base ctor and then overwrite the vptr.
