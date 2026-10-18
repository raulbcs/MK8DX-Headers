# PanePic1

## Identity

- vtable 0x12bffc0, 29 slots, GOT cell 0x130ed28 holds vt-0x10 (0x12bffb0);
  installed vptr = cell+0x10 = 0x12bffc0.
- Created by the pane-tag factory dispatcher at 0x7430bc: tag "pic1"
  (w2 == 0x31636970, checked at 0x743100) requires string "FrameBufferUse"
  (0xf07567) in the pane resource, then allocates 0x130 (align 0x10) and
  calls ctor 0x744f40 (0x7431e8..0x74320c).
- Base class: PaneBase (vptr 0x12c0298, C1 0x745624) called first at
  0x744f58; derived vptr re-installed at 0x744f70.

## Member notes

- +0x108: agl::TextureData, allocated with new 0x250 (align 8) at
  0x744f90..0x744fa0, constructed by 0x74b5e0 (config/functions.csv name
  "agl::TextureData"), tail call 0x74b6d8 (0x744fc8). Freed by D1 0x744fcc
  via its [vt+8] entry.
- +0x118: s64, initialized to -1 (0x744f64..0x744f68).
- +0x120: u32, initialized to 0 (0x744f7c).
- Slot 20 (0x745064): guard on [arg1+0x100]; drives 0x74b830 / 0x74bc3c on
  the +0x108 texture data, then tail 0x5a44c0 (shared).
- Dtor triple: D1 0x744fcc, D0 0x745014 (both re-install vptr, destroy the
  +0x108 texture, then chain PaneBase D1 0x5a3e18); slot 2 0x74510c
  (guard/getter pattern).

## Construction / init order

1. Factory 0x7430bc: "pic1" tag + "FrameBufferUse" string; aligned_alloc
   (0x130, align 0x10) at 0x7431f0.
2. C1 0x744f40: base PaneBase ctor 0x745624 (0x744f58); derived vptr
   0x12bffc0 at +0x00 (0x744f70); +0x118 = -1; +0x120 = 0; call 0x738a20
   (0x744f88); agl::TextureData new 0x250 + ctor 0x74b5e0 stored at +0x108;
   tail 0x74b6d8 with [arg4+0x20] (0x744fac..0x744fc8).
