# PseudoGlobalVariableAuthFoundationDDL

## Identity

- RTTI name (nex typeinfo descriptor 0x12e6840, string at .rodata 0xf85bf0): `nn::nex::PseudoGlobalVariable<nn::nex::AuthenticationFoundationDDLDeclarations>`, base descriptor 0x128d6c0 = `nn::nex::PseudoGlobalVariableRoot`.
- Vtable row 0x12e67f0 (typeinfo slot), installed vptr 0x12e67f8. GOT cell 0x1314928 holds vptr-0x10 (verified: D2 0xa27da0 does `ldr x8,[0x1314928]; add x8,x8,#0x10; str x8,[this]`).
- 8 slots: D1 0xa27da0 / D0 clone 0xa3137c (identical bodies: install vptr, destroy members at +0x18/+0x38 via 0xb4ba2c, tail into free 0x573f48), init callback 0xa313f4 (invoked as [vptr+0x10] after registration, gated by the nnSdk version cell 0x1314188 >= 2), helpers 0xa31500 / 0xa31590 / 0xa315b8 / 0xa315c0 / 0xa315c8 (last three 8 bytes apart, stub-like). All slots unresolved in functions.csv.

## Member notes

- +0x00 vptr (0x12e67f8).
- +0x08..0x17 unverified; the instance is registered into a global tree (balance insert 0x58c4d8 with the instance itself as node, cell 0x130b940), so tree-node fields likely live here — unverified.
- +0x18 member, 0x20 bytes, C1 0xb4ae90(x0=member, w1=1); vptr = *(GOT 0x1314ac0)+0x10.
- +0x38 member, 0x20 bytes, same class (vptr stored explicitly at 0xa3237c, C1 0xb4ae90 at 0xa32380).

## Construction / init order

No allocating factory; the instance is a static whose address reaches the init sequence via GOT cell 0x1314af8 (function-local-static style). Init at 0xa3233c-0xa323a8: copy member bytes, store vptr at +0x00, place member vptrs at +0x18/+0x38, run member C1 0xb4ae90 on both (+0x18 at 0xa32364, +0x38 at 0xa32380), copy the flag byte +0x50 -> +0x30, then register into the global tree (0x58c448 via cell 0x130b940) and finally call the slot-2 init virtual through [vptr+0x10] when the runtime version cell 0x1314188 >= 2 (0xa323b8-0xa323cc).

Size 0x58: member2 ends at +0x58; no stores beyond +0x50 observed (member-boundary proven by the member2 placement at +0x38, size 0x20).
