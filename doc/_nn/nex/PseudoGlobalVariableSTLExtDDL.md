# nn::nex::PseudoGlobalVariable<STLExtDDLDeclarations>

RTTI-confirmed: typeinfo record 0x12f8f50, name
`N2nn3nex20PseudoGlobalVariableINS0_21STLExtDDLDeclarationsEEE` =
nn::nex::PseudoGlobalVariable<nn::nex::STLExtDDLDeclarations>.
Typeinfo base 0x128d6c0 = nn::nex::PseudoGlobalVariableRoot.

- Identity: static pseudo-global holding the STL-extension DDL
  declaration state; same family as
  PseudoGlobalVariableOnlineCoreDDL (vt 0x12f8e90).
- Vtable: vptr = 0x12f8f08, typeinfo-pointer row variant (word at
  0x12f8f00 = &typeinfo 0x12f8f50). No .got cell; D1/D0 use .bss
  mirror cell 0x1315fa8 (RELATIVE reloc addend 0x12f8ef8 =
  vptr-0x10), then add 0x10.
- D1 0xb4adf0: install vptr, unregister from PseudoGlobalVariableRoot
  global list (FUN_710058c4d8, head cell 0x130b940), run virtual
  [vptr+0x18], tail delete wrapper 0x58c5b8.

## Member notes

- Slots (8, all unrecovered in functions.csv): +0x00 D1 0xb4adf0,
  +0x08 D0 0xb4bfdc, +0x10 0xb4c034, +0x18 0xb4c0bc, +0x20
  FUN_7100b4c108 (396 B, only resolved slot in the batch), +0x28
  0xb4c118, +0x30 0xb4c120, +0x38 0xb4c128.
- Fields: vptr only proven for this instantiation; family ctor
  0xb4ae90 (sibling vptr 0x12f8d58) writes u32 +0x08, u8 +0x0c,
  ptr +0x10, bool +0x18 -> size 0x20 family-wide; per-instance
  layout unverified.

## Construction / init order

1. No standalone C1 found: vptr 0x12f8f08 is materialized only inside
   D1/D0. Instance init path unverified (static pseudo-global,
   guarded-static init presumed).
2. Destruction: D1 0xb4adf0; D0 0xb4bfdc same body + operator delete
   0x573f48.
