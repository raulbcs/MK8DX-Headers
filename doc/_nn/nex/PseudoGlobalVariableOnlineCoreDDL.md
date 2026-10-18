# nn::nex::PseudoGlobalVariable<OnlineCoreDDLDeclarations>

RTTI-confirmed: typeinfo record 0x12f8ee0 (row 0x12f8e90 + 0x50), name
`N2nn3nex20PseudoGlobalVariableINS0_25OnlineCoreDDLDeclarationsEEE` =
nn::nex::PseudoGlobalVariable<nn::nex::OnlineCoreDDLDeclarations>.
Typeinfo base 0x128d6c0 = nn::nex::PseudoGlobalVariableRoot (itself under
nn::nex::RootObject 0x128c3b0).

- Identity: static pseudo-global holding the OnlineCore DDL declaration
  state; sibling of PseudoGlobalVariableU16/U8/StreamSettings (batch 27c).
- Vtable: vptr = 0x12f8e98. Row layout here is the typeinfo-pointer
  variant: word at 0x12f8e90 points at the typeinfo record (0x12f8ee0 =
  {0x10, name, base PseudoGlobalVariableRoot, 0}), installed vptr is
  row+8. No .got cell; the D1/D0 bodies load .bss mirror cell 0x1315fa0
  (load-time RELATIVE reloc, addend 0x12f8e88 = vptr-0x10) and add 0x10.
- D1 0xb4ad9c: install vptr, unregister from the PseudoGlobalVariableRoot
  global list (FUN_710058c4d8 with head cell 0x130b940), run virtual
  [vptr+0x18], tail delete wrapper 0x58c5b8.
- D0 0xb4bd08: same body, then bl 0x58c5b8 and tail operator delete
  0x573f48.

## Member notes

- Slots (8, all unrecovered in functions.csv): +0x00 D1 0xb4ad9c,
  +0x08 D0 0xb4bd08, +0x10 0xb4bd60, +0x18 0xb4be88 (virtual also run
  by D1 before delete), +0x20 0xb4bf18, +0x28 0xb4bf40, +0x30 0xb4bf48,
  +0x38 0xb4bf50.
- Fields: only the vptr is proven for this instantiation. The shared
  family C1 0xb4ae90 (sibling vptr 0x12f8d58) stores u32 +0x08, u8
  +0x0c, ptr +0x10, bool +0x18 -> size 0x20 family-wide; per-instance
  layout unverified.

## Construction / init order

1. No standalone C1 found for this instantiation: no site materializes
   vptr 0x12f8e98 outside D1/D0 (no .got cell, no adrp/add site in
   /tmp/full.asm). Instances are static pseudo-globals (companion
   instance cells 0x1368c40 area are zero-initialized RELATIVE relocs);
   init path unverified - likely the shared family C1 run from a
   guarded static initializer.
2. Destruction: D1 0xb4ad9c / D0 0xb4bd08 as above.
