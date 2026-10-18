# PseudoGlobalVariableSecureConnectionServiceDDL

## Identity

- RTTI name (nex typeinfo descriptor 0x12e6a00, string at .rodata 0xf85d40): `nn::nex::PseudoGlobalVariable<nn::nex::SecureConnectionServiceDDLDeclarations>`, base descriptor 0x128d6c0 = `nn::nex::PseudoGlobalVariableRoot`.
- Vtable row 0x12e69b0 (typeinfo slot), installed vptr 0x12e69b8. GOT cell 0x1314a38 holds vptr-0x10; sites 0xa2df10 (D2) and 0xa32008/0xa32628 (init sequence).
- 8 slots: D1 0xa2defc / D0 clone 0xa31ff4, init callback 0xa3206c, helpers 0xa32178 / 0xa32208 / 0xa32230 / 0xa32238 / 0xa32240. All unresolved in functions.csv. Last of the five 0x70-stride PseudoGlobalVariable siblings (0x12e67f8 / 0x12e6868 / 0x12e68d8 / 0x12e6948 / 0x12e69b8).

## Member notes

- +0x00 vptr (0x12e69b8).
- +0x08..0x17 unverified; global-tree node fields — unverified.
- +0x18 member, 0x20 bytes, C1 0xb4ae90.
- +0x38 member, 0x20 bytes, same class.

## Construction / init order

Static instance reached via GOT cell (series around 0x1314b08+; exact cell unverified). Shared init routine as the other PseudoGlobalVariable instantiations: vptr at +0x00, member C1 0xb4ae90 at +0x18, member vptr + C1 at +0x38, flag copy +0x50 -> +0x30, global-tree registration via cell 0x130b940, then slot-2 init virtual through [vptr+0x10] gated on version cell 0x1314188 >= 2 (site 0xa32628).

Size 0x58 (member-boundary; member2 at +0x38, size 0x20).
