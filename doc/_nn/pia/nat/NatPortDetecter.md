# nn::pia::nat::NatPortDetecter

## Identity

RTTI-confirmed: compact typeinfo record at 0x12dbc50 = {0x10, name 0xf808e0 = "N2nn3pia3nat15NatPortDetecterE"}. Primary vtable row: offset-to-top 0 at 0x12dbbd8, typeinfo slot 0x12dbbe0, vptr 0x12dbbe8. GOT cell 0x1313280 holds 0x12dbbd8 (vt-0x10 convention; installed vptr = cell+0x10). 13 slots (0x12dbbe8-0x12dbc48).

size 0x518 — operator new 0x518 (0x568aa0, w0 = 0x518) at 0x964c28 in the nat manager ctor; base-object ctor 0x967140 (C2) is called on the result (site 0x964c3c) and the pointer stored at manager+0x70. Only C2 is constructed here; C1 0x967184 (vtable slot0) has no direct call site.

Base: nn::pia::nat::NatDetecter (compact ti record 0x12dbb68, name 0xf808a0; base ctor 0x96606c called from C2 head 0x967150). Sibling descriptor NatDetectionJob at 0x12dbbc0 (name 0xf808c0), NatProbe at 0x12dbc90 (name 0xf80900). The C2 installs vptr 0x12dbbe8 at [this] (site 0x967158), then constructs the two members and clears +0x510.

## Member notes

- +0x00 vptr (0x12dbbe8).
- +0x08..+0x498 NatDetecter base region: base ctor 0x96606c stores to +0x2c/+0x40/+0x48/+0x50/+0x58 and step-writes through +0x68/+0x70 with helper 0x56810c; full layout unproven.
- +0x498 and +0x4D0 — two 0x38-byte member objects, ctor 0x9b38b8 / member dtor 0x9b3a40 (called twice each by the dtor pair).
- +0x510 u64 — init 0 (xzr, 0x967174).
- slot4 0x966830 reads [this+0x18], [this+0x58]->[+8] and s32 [this+0x7c] (unverified semantics, 112 B).

Slot map (vptr 0x12dbbe8):
- slot0 0x967184 = D1, slot1 0x9671c4 = D0 (dtor pair; both re-install vptr, destroy the two 0x38 members via 0x9b3a40; D0 additionally calls base D1 0x96616c).
- slot2 0x96720c (calls alloc-time helper 0x5674d0), slot4 0x966830 (functions.csv, 112 B).
- remaining slots 0x967184/0x9671c4/0x96720c/0x96734c/... unrecovered in functions.csv.

## Construction / init order

Factory inside the nat manager ctor (0x964c28-0x964c40):

1. `operator new(0x518)` (0x568aa0), null-checked.
2. Call C2 0x967140(this): tail-base ctor 0x96606c; install vptr 0x12dbbe8 (cell 0x1313280 +0x10); ctor 0x9b38b8 on this+0x498 and this+0x4d0; xzr at +0x510.
3. Store pointer at manager+0x70.
