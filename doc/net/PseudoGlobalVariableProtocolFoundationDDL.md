# PseudoGlobalVariableProtocolFoundationDDL

## Identity

- RTTI name (nex typeinfo descriptor 0x12e6990, string at .rodata 0xf85cf0): `nn::nex::PseudoGlobalVariable<nn::nex::ProtocolFoundationDDLDeclarations>`, base descriptor 0x128d6c0 = `nn::nex::PseudoGlobalVariableRoot`.
- Vtable row 0x12e6940 (typeinfo slot), installed vptr 0x12e6948. GOT cell 0x13149c8 holds vptr-0x10; sites 0xa2c46c (D2) and 0xa31d30/0xa32580 (init sequence).
- 8 slots: D1 0xa2c458 / D0 clone 0xa31d1c, init callback 0xa31d94, helpers 0xa31ea0 / 0xa31f30 / 0xa31f58 / 0xa31f60 / 0xa31f68. All unresolved in functions.csv.

## Member notes

- +0x00 vptr (0x12e6948).
- +0x08..0x17 unverified; global-tree node fields — unverified.
- +0x18 member, 0x20 bytes, C1 0xb4ae90.
- +0x38 member, 0x20 bytes, same class.

## Construction / init order

Static instance reached via GOT cell (series around 0x1314b08+; exact cell unverified). Shared init routine as the other PseudoGlobalVariable instantiations: vptr at +0x00, member C1 0xb4ae90 at +0x18, member vptr + C1 at +0x38, flag copy +0x50 -> +0x30, global-tree registration via cell 0x130b940, then slot-2 init virtual through [vptr+0x10] gated on version cell 0x1314188 >= 2 (site 0xa32580).

Size 0x58 (member-boundary; member2 at +0x38, size 0x20).
