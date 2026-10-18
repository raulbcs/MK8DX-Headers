# PseudoGlobalVariableNintendoProtocolFoundationDDL

## Identity

- RTTI name (nex typeinfo descriptor 0x12e6920, string at .rodata 0xf85c90): `nn::nex::PseudoGlobalVariable<nn::nex::NintendoProtocolFoundationDDLDeclarations>`, base descriptor 0x128d6c0 = `nn::nex::PseudoGlobalVariableRoot`.
- Vtable row 0x12e68d0 (typeinfo slot), installed vptr 0x12e68d8. GOT cell 0x13149a0 holds vptr-0x10; sites 0xa2accc (D2) and 0xa31940/0xa324d8 (init sequence).
- 8 slots: D1 0xa2acb8 / D0 clone 0xa3192c, init callback 0xa319a4, helpers 0xa31ab0 / 0xa31b40 / 0xa31b68 / 0xa31b70 / 0xa31b78. All unresolved in functions.csv. Same 0x70-stride sibling family shape.

## Member notes

- +0x00 vptr (0x12e68d8).
- +0x08..0x17 unverified; global-tree node fields — unverified.
- +0x18 member, 0x20 bytes, C1 0xb4ae90.
- +0x38 member, 0x20 bytes, same class (mirrors the AuthenticationFoundation/HealthService instantiations of the same shared init routine).

## Construction / init order

Static instance reached via GOT cell (next in the 0x1314af8/0x1314b08 series; exact cell unverified). Init runs in the same shared routine as the siblings: vptr at +0x00, member C1 0xb4ae90 at +0x18, member vptr + C1 at +0x38, flag copy +0x50 -> +0x30, global-tree registration via cell 0x130b940, then slot-2 init virtual through [vptr+0x10] gated on version cell 0x1314188 >= 2 (site 0xa324d8).

Size 0x58 (member-boundary; member2 at +0x38, size 0x20).
