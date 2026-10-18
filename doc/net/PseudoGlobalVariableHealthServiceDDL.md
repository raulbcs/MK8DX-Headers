# PseudoGlobalVariableHealthServiceDDL

## Identity

- RTTI name (nex typeinfo descriptor 0x12e68b0, string at .rodata 0xf85c40): `nn::nex::PseudoGlobalVariable<nn::nex::HealthServiceDDLDeclarations>`, base descriptor 0x128d6c0 = `nn::nex::PseudoGlobalVariableRoot`.
- Vtable row 0x12e6860 (typeinfo slot), installed vptr 0x12e6868. GOT cell 0x1314940 holds vptr-0x10 (same convention as PseudoGlobalVariableAuthFoundationDDL; verified via the D2 body pattern).
- 8 slots: D1 0xa29070 / D0 clone 0xa31654, init callback 0xa316cc, helpers 0xa317d8 / 0xa31868 / 0xa31890 / 0xa31898 / 0xa318a0. All unresolved in functions.csv. Sibling of the AuthenticationFoundation instantiations — same vtable shape (dtor pair + init + 5 helpers) at a fixed 0x70 vtable stride.

## Member notes

- +0x00 vptr (0x12e6868).
- +0x08..0x17 unverified; global-tree node fields (registration via balance insert 0x58c4d8, cell 0x130b940) — unverified.
- +0x18 member, 0x20 bytes, C1 0xb4ae90; vptr = *(GOT 0x1314ad0)+0x10 (stored at 0xa3241c region).
- +0x38 member, 0x20 bytes, same class.

## Construction / init order

Static instance reached via GOT cell 0x1314b08. Init sequence at 0xa323ec-0xa324xx (same routine that builds the AuthenticationFoundation instantiation, immediately after it): store vptr at +0x00, member C1 0xb4ae90 on +0x18, place member2 vptr at +0x38 and run its C1, copy flag byte +0x50 -> +0x30, register into the global tree, then invoke the slot-2 init virtual through [vptr+0x10] gated on version cell 0x1314188 >= 2.

Size 0x58 (member-boundary; member2 at +0x38, size 0x20).
