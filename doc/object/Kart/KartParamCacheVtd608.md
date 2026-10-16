# KartParamCacheVtd608

## Identity

KartParamCacheVtd608 — address-anchored name (vptr 0x12bd608,
GOT cell 0x130e8a8). Named node-group container of the c63c6f8
cluster (n=9). Ctor 0x71007284f0 (second variant 0x710072875c):
KartParamCache base (0x7100669954), then:
+0x48 node member (ctor 0x710066a2a4, vptr cell 0x130d988), 0x30
+0x78 channel pair (0x7100662f30+0x662f70; vptr cell 0x130daa8 =
ParamChannelVt32b8 type; fn cell 0x12fae28), 0x20
+0x90 u32 zero
+0x98 named-string member (ctor 0x710061cc48 w=8, vptr cell
0x12fb790; SSO buffer at +0xac, name copied by inline
strlen/memcpy), 0x20
+0xb8 second channel pair (same init; vptr cell 0x12fb798), 0x20
+0xd0 u32 zero
+0xd8 node (ctor 0x7100728074, Vt5b0 class), 0xd0
+0x1a8 node (ctor 0x7100727a60, Vt500 class), 0xb8
+0x260 node (ctor 0x7100727d54, Vt558 class), extent unmapped
then four 0x7100669a10(this, member, name) registrations with
rodata names 0xf05cf/0xf05d9/0xf05de/0xf05ee. The 0x72875c variant
touches 0x1f0/0x238/0x250/0x25c/0x310 -> extent >= 0x318.

## Member notes

Notes in field order; proven from the cited addresses.

- 0x48 — 0x30 (same node type as Mid 0x68)
- 0x78 — unproven padding
- 0x78 — channel pair (0x20)
- 0x90 — ctor zero
- 0x98 — named-string member (ptr @0x98 = this+0xac SSO buf)
- 0xb8 — second channel pair (0x20)
- 0xd0 — ctor zero
- 0xd8 — node (ctor 0x7100728074)
- 0x1a8 — Vt500 node (ctor 0x7100727a60; padded extent; variant zeroes 0x1f0 rel)
- 0x260 — Vt558 node (ctor 0x7100727d54; padded extent; variant touches 0x310 rel) (extent >= 0x318, tail unmapped) dtor: fn size 0x204.

> Naming: factory/array structural variant (base-call chain + factory case id only, no per-class strings).

## Construction / init order

In field/offset order (= binary init order within this header):
- 0x90 — ctor zero
- 0xd0 — ctor zero
- 0xd8 — node (ctor 0x7100728074)
- 0x1a8 — Vt500 node (ctor 0x7100727a60; padded extent; variant zeroes 0x1f0 rel)
- 0x260 — Vt558 node (ctor 0x7100727d54; padded extent; variant touches 0x310 rel) (extent >= 0x318, tail unmapped) dtor: fn size 0x204.
