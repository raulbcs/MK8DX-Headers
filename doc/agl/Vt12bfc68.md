# agl::Vt12bfc68

PLACEHOLDER name. vptr 0x12bfc68, 28 slots, single vptr at +0x00. GOT cell 0x130ece8 -> 0x12bfc58; C1 stores cell+0x10 into [this].

Layout-pane-family class created by factory 0x7430bc: allocated `new 0x150` at 0x743338 as the fallback of the "DynamicCaptureUseName" (string 0xf0713c) branch (C1 0x741e08 called at 0x74335c). Extent 0x150 is the operator-new size.

Slots: slot +0x00 = 0x5a7934 (deleting dtor, shared), slot +0x08 = 0x741f10 (D0); overrides vs the family-B shared rows at +0xa0 (0x741e4c, consumes fields +0x138/+0x140) and +0xb0 (0x741ea8). Slots +0x18..+0xd8 shared with Vt12c00b8 (base rows differ from the Vt12bfa80/Vt12c01a8 family). All slot targets unrecovered in config/functions.csv.

## Construction / init order

- C1 0x741e08: family-B base ctor 0x746cd0 (forwards to 0x5a7384; base vptr from cell 0x130edc8), then vptr = cell 0x130ece8+0x10.
- +0x138 = 0; byte +0x140 = 0. Setter helper 0x741e40 stores (ptr, bool) into +0x138/+0x140.
- D0 0x741f10: family-B D0.
