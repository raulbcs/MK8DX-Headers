# KartParamCacheVt2668

## Identity

KartParamCacheVt2668 — address-anchored name (vptr 0x12b2668,
GOT cell 0x130d980). Cluster variant, extent 0x168 (ctor 0x710064a708):
KartParamCacheEnv base (ctor 0x710064822c, extent 0x38), then
members: KartParamCacheMid2-shaped 0x48 member at 0x40 (ctor
0x710061cc48), KartParamCacheVt24c8-shaped 0x20 member at 0x88 (ctor
0x7100669954), KartParamCacheChanBase member at 0xa8 (ctor
0x7100662f30), another 0x48 Mid2-shaped member at 0xd8, zero qword at
0x120, KartParamCacheNodeBase member at 0x128 (ctor 0x710066a2a4),
zero w32 at 0x158 and zero qword at 0x160.

## Member notes

Notes in field order; proven from the cited addresses.

- 0x00
- 0x08 — KartParamCacheEnv base fields (ctor-zeroed)
- 0x38
- 0x40 — member, ctor 0x710061cc48 (Mid2-shaped, extent 0x48)
- 0x88 — member, ctor 0x7100669954 (Vt24c8-shaped, extent 0x20)
- 0xa8 — KartParamCacheChanBase member vptr (ctor 0x7100662f30)
- 0xb0 — ctor-written (ChanBase ctor writes w0)
- 0xb4 — unproven gap
- 0xd8 — member, ctor 0x710061cc48 (Mid2-shaped, extent 0x48)
- 0x120 — ctor zero
- 0x128 — member, ctor 0x710066a2a4 (KartParamCacheNodeBase)
- 0x148 — unproven gap
- 0x158 — ctor zero
- 0x15c — unproven gap
- 0x160 — ctor zero (0x168 total) Vtable slot 0 (0x10) vtable-init ctor stub : stores the class vtable pointer (global pointer at 0x710130848, +0x10) into *this. True extent 20 bytes.

> Naming: only ctor string is the debug icon 'Icon=CIRCLE_GREEN' (0xef90b0); no role evidence.

## Construction / init order

In field/offset order (= binary init order within this header):
- 0x08 — KartParamCacheEnv base fields (ctor-zeroed)
- 0x40 — member, ctor 0x710061cc48 (Mid2-shaped, extent 0x48)
- 0x88 — member, ctor 0x7100669954 (Vt24c8-shaped, extent 0x20)
- 0xa8 — KartParamCacheChanBase member vptr (ctor 0x7100662f30)
- 0xb0 — ctor-written (ChanBase ctor writes w0)
- 0xd8 — member, ctor 0x710061cc48 (Mid2-shaped, extent 0x48)
- 0x120 — ctor zero
- 0x128 — member, ctor 0x710066a2a4 (KartParamCacheNodeBase)
- 0x158 — ctor zero
- 0x160 — ctor zero (0x168 total) Vtable slot 0 (0x10) vtable-init ctor stub : stores the class vtable pointer (global pointer at 0x710130848, +0x10) into *this. True extent 20 bytes.
