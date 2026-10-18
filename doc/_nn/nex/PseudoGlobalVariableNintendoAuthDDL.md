# nn::nex::PseudoGlobalVariable<NintendoAuthenticationDDLDeclarations>

RTTI-confirmed: typeinfo record 0x12f9150 (row 0x12f9100 + 0x50), name
`N2nn3nex20PseudoGlobalVariableINS0_37NintendoAuthenticationDDLDeclarationsEEE`
= nn::nex::PseudoGlobalVariable<nn::nex::NintendoAuthenticationDDLDeclarations>.
Typeinfo base 0x128d6c0 = nn::nex::PseudoGlobalVariableRoot. The wrapped
type NintendoAuthenticationDDLDeclarations has its own typeinfo record at
0x12f90e0 (base 0x12f8da0 = DDLDeclarations), vtable row 0x12f90c0.

- Identity: static pseudo-global holding the Nintendo authentication
  DDL state; same family as PseudoGlobalVariableOnlineCoreDDL
  (vt 0x12f8e90).
- Vtable: vptr = 0x12f9108, typeinfo-pointer row variant (word at
  0x12f9100 = &typeinfo 0x12f9150). No .got cell; D1/D0 use .bss
  mirror cell 0x1316030 (RELATIVE reloc addend 0x12f90f8 =
  vptr-0x10), then add 0x10.
- D1 0xb4cc38: install vptr, unregister from PseudoGlobalVariableRoot
  global list (FUN_710058c4d8, head cell 0x130b940), run virtual
  [vptr+0x18], tail delete wrapper 0x58c5b8.
- D0 0xb4cd1c: install vptr, run virtual [vptr+0x18] with this, then
  run trivial-dtor stub 0xb4ba2c (`ret`) on this+0x18 and this+0x38
  (two embedded 0x20-stride subobjects), delete wrapper 0x58c5b8.

## Member notes

- Slots (8, all unrecovered in functions.csv): +0x00 D1 0xb4cc38,
  +0x08 D0 0xb4cd1c, +0x10 0xb4cd94, +0x18 0xb4cea0, +0x20 0xb4cf30,
  +0x28 0xb4cf58, +0x30 0xb4cf60, +0x38 0xb4cf68.
- Fields: vptr at +0x00; subobjects at +0x18 and +0x38 proven only as
  destructed regions (trivial dtor stub), contents unverified.
  Size >= 0x40; if the two subobjects are 0x20 each, size would be
  0x58 - unverified.

## Construction / init order

1. No standalone C1 found: vptr 0x12f9108 materialized only inside
   D1/D0. Instance init path unverified (static pseudo-global).
2. Destruction: D1 0xb4cc38 / D0 0xb4cd1c as above.
