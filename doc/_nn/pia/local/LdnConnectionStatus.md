# nn::pia::local::LdnConnectionStatus

## Identity

RTTI-confirmed: compact typeinfo record at 0x12e10d0 = {0x10, name 0xf83140 = "N2nn3pia5local19LdnConnectionStatusE"}. Primary vtable row: offset-to-top 0 at 0x12e1008, typeinfo slot 0x12e1010, vptr 0x12e1018. GOT cell 0x1313d48 holds 0x12e1008 (vt-0x10 convention; installed vptr = cell+0x10). 23 slots (0x12e1018-0x12e10c8).

Size 0x4a0 — operator new 0x4a0 at 0x9beee0 in the lazy-singleton factory (0x9beeac). Cross-checked by slot2's memset(this+0x18, 0, 0x480) + s32 store at +0x498.

Base class: nn::pia::local::LocalAddress (compact ti record at 0x12e0560 = {0x10, name 0xf82e60}; GOT cell 0x1313d40 holds its row 0x12e04a0; vptr 0x12e04b0). An embedded LocalAddress lives at this+0xc (its ctor 0x929fd4 is called with this+0xc; slot20 returns this+0xc; deleting dtors re-install the LocalAddress vptr with post-increment #0xc then tail-call 0x92a014).

## Member notes

- +0x00 vptr (0x12e1018).
- +0x08 u16 — cleared by slot2; slot19 (0x9c2920) = `ldrh w0, [x0, #0x8]`.
- +0x0c embedded LocalAddress (size unverified; derived dtor steps over exactly 0xc).
- +0x18..0x498 entry array: 18 entries x 0x40 bytes. Slot4 (0x9cb6a0) = `sxtw x8, w1; x8 = x0 + (x8<<6); ldrb w0, [x8, #0x8b]` — flag byte at entry+0x73.
- +0x498 s32 — init -1 by slot2; slot21 (0x9c2930) copies [x0+0x14] to [x8] (unverified semantics — reads +0x14, not +0x498).
- +0x49c padding to size 0x4a0 (unproven).

Slot map (vptr 0x12e1018; all slot bodies unrecovered in functions.csv, identified by disasm only):
- slot0 0x9c28d8 = D1, slot1 0x9cb66c = D0 (dtor pair; D1 re-installs LocalAddress vptr, tail-calls 0x92a014; D0 then operator delete 0x60b470).
- slot2 0x9cb48c = reset: calls 0x9c28c0, clears u16 @+0x8, memset(this+0x18, 0x480), [this+0x498] = -1.
- slot3 0x9cb4c8; slot4 0x9cb6a0 = flag getter (above).
- slots5-18 0x9cb6b0..0x9cb668 (unverified, real bodies in the 0x9cb3f8-0x9cabe0 cluster).
- slot19 0x9c2920 (u16 @+0x8), slot20 0x9c2928 (returns this+0xc), slot21 0x9c2930.

## Construction / init order

Lazy singleton factory pattern (three instances, stored at parent+0x1b8/+0x1c0/+0x1c8; sites 0x9beee0-0x9bef34, 0x9bef48-0x9befa0, 0x9befb4-0x9bf00c):

1. If the cached pointer is null: `operator new(0x4a0)` (0x568aa0).
2. Install LocalAddress vptr (GOT cell 0x1313d40, +0x10) at [this].
3. Call LocalAddress ctor 0x929fd4 with this+0xc (embedded base).
4. Zero u32 at this+0x14; call slot2 (0x9cb48c) via the LocalAddress vtable with this.
5. Override [this] with the LdnConnectionStatus vptr (GOT cell 0x1313d48, +0x10).
6. Call slot3-row entry [row+0x20] = 0x9cb48c (same reset fn) via blr with this.
7. Store the pointer into the parent slot.
