# nn::nex::PseudoGlobalVariable<unsigned int>

RTTI-confirmed: typeinfo record 0x12f9030, name
`N2nn3nex20PseudoGlobalVariableIjEE` =
nn::nex::PseudoGlobalVariable<unsigned int>.
Typeinfo base 0x128d6c0 = nn::nex::PseudoGlobalVariableRoot.

- Identity: static pseudo-global counter/flag (u32 payload); same
  family as PseudoGlobalVariableOnlineCoreDDL (vt 0x12f8e90).
- Vtable: vptr = 0x12f8fe8, typeinfo-pointer row variant (word at
  0x12f8fe0 = &typeinfo 0x12f9030). No .got cell; D1/D0 use .bss
  mirror cell 0x1315fb8 (RELATIVE reloc addend 0x12f8fd8 =
  vptr-0x10), then add 0x10.
- D1 0xb4aebc: install vptr, unregister from PseudoGlobalVariableRoot
  global list (FUN_710058c4d8, head cell 0x130b940), run virtual
  [vptr+0x18], tail delete wrapper 0x58c5b8.

## Member notes

- Slots (8, all unrecovered in functions.csv): +0x00 D1 0xb4aebc,
  +0x08 D0 0xb4c304, +0x10 0xb4c35c, +0x18 0xb4c3e4, +0x20 0xb4c430,
  +0x28 0xb4c440, +0x30 0xb4c448, +0x38 0xb4c450.
- Fields: vptr only proven for this instantiation. The sibling family
  ctor 0xb4ae90 (vptr 0x12f8d58, u32 payload variant) writes u32
  +0x08, u8 +0x0c, ptr +0x10, bool +0x18 -> size 0x20; per-instance
  layout unverified.

## Construction / init order

1. No standalone C1 for vptr 0x12f8fe8; family ctor pattern is
   0xb4ae90 (adrp 0x1314ac8 + 0x10 = sibling vptr 0x12f8d58; strb arg
   to +0x18, zero u32 +0x08, u8 +0x0c, xzr +0x10). Instance init
   path for this vptr unverified (static pseudo-global).
2. Destruction: D1 0xb4aebc; D0 0xb4c304 same body + operator delete
   0x573f48.
