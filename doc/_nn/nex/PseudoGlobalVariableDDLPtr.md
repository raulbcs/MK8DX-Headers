# nn::nex::PseudoGlobalVariable<DDLDeclarations*>

RTTI-confirmed: typeinfo record 0x12f8fc0, name
`N2nn3nex20PseudoGlobalVariableIPNS0_15DDLDeclarationsEEE` =
nn::nex::PseudoGlobalVariable<nn::nex::DDLDeclarations*>.
Typeinfo base 0x128d6c0 = nn::nex::PseudoGlobalVariableRoot.

- Identity: static pseudo-global holding a pointer to the parsed
  DDLDeclarations tree; same family as PseudoGlobalVariableOnlineCoreDDL
  (vt 0x12f8e90). Direct base DDLDeclarations typeinfo record 0x12f8da0
  sits one block below.
- Vtable: vptr = 0x12f8f78, typeinfo-pointer row variant (word at
  0x12f8f70 = &typeinfo 0x12f8fc0). No .got cell; D1/D0 use .bss mirror
  cell 0x1315fb0 (RELATIVE reloc addend 0x12f8f68 = vptr-0x10), then
  add 0x10.
- D1 0xb4ae40: install vptr, unregister from PseudoGlobalVariableRoot
  global list (FUN_710058c4d8, head cell 0x130b940), run virtual
  [vptr+0x18], tail delete wrapper 0x58c5b8.

## Member notes

- Slots (8, all unrecovered in functions.csv): +0x00 D1 0xb4ae40,
  +0x08 D0 0xb4c17c, +0x10 0xb4c1d4, +0x18 0xb4c248, +0x20
  FUN_7100b4c294 (2360 B, largest slot of the batch), +0x28 0xb4c2a4,
  +0x30 0xb4c2ac, +0x38 0xb4c2b4.
- Fields: vptr only proven for this instantiation; family ctor
  0xb4ae90 (sibling vptr 0x12f8d58) writes u32 +0x08, u8 +0x0c,
  ptr +0x10, bool +0x18 -> size 0x20 family-wide; per-instance layout
  unverified.

## Construction / init order

1. No standalone C1 found: vptr 0x12f8f78 materialized only inside
   D1/D0. Instance init path unverified (static pseudo-global).
2. Destruction: D1 0xb4ae40; D0 0xb4c17c same body + operator delete
   0x573f48.
