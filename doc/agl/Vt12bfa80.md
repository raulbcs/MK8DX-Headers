# agl::Vt12bfa80

PLACEHOLDER name. vptr 0x12bfa80, 28 slots (dtor pair 0x7415fc/0x741664 + 26 virtuals), single vptr at +0x00, secondary vptr at +0x108. GOT cell 0x130ecd8 -> 0x12bfa70; ctors/D0 store cell+0x10 into [this].

Layout-pane-family class created by factory 0x7430bc: allocated `new 0x360` at 0x743378 on the FourCC "n1pa" branch when the "CaptureOn" lookup fails and a follow-up lookup of "DynamicCaptureOn" (string 0xf07524) on [arg+0x60] succeeds (C1 0x741460 called at 0x743398). Extent 0x360 is the operator-new size.

Slots: dtor pair 0x7415fc (D1) / 0x741664 (D0); overrides vs the family-A shared base rows at +0xa0 (0x7416d4) and +0xa8 (0x7417bc); slots +0x18..+0xd8 shared with Vt12c01a8/Vt12c0390/Vt12c0618. All slot targets unrecovered in config/functions.csv.

Note: the factory tail (0x7432dc) invokes vtable slot at vptr+0xe0 (slot 28) on some products of this factory; in this table that word is 0 — the call site targets the longer "t1xt"-family tables, not this class.

## Construction / init order

- C1 0x741460 (called with this, x1, arg struct x2): base member ctor 0x5a22e4 (family-A base, size 0xe0, vptr from cell 0x130c948+0x10).
- +0xe0/+0xe8 = this+0xe0 (empty list), byte +0xf0 = 0, +0xf8/+0x100 = 0.
- Secondary vptr +0x108 = cell 0x1308f98+0x10 = 0x1266110 (MI secondary base); +0x110 = -1; +0x118 = 0; +0x120 = 0.
- Member ctor 0x63ecbc on this+0x128; member ctor 0x63f778 on this+0x190.
- Shared tail 0x7414d8: sets bit0 of [arg+0x58], builds a heap object via 0x73fe20 (stored +0xf8), compares the arg name against "DynamicCaptureOn"/"DynamicCaptureUseName" strings (0xf07524/0xf0749e); unverified beyond this.
- D0 0x741664: operator delete on +0xf8, virtual dtor call on +0x100, member dtors 0x639f38(this+0x240) and 0x63ed3c(this+0x128), then base D0. ICF-folded sibling D0 at 0x741678.
