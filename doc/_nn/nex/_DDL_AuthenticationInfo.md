# nn::nex::_DDL_AuthenticationInfo

RTTI-confirmed: typeinfo record 0x12f90a0 (row 0x12f9050 + 0x50), name
`N2nn3nex23_DDL_AuthenticationInfoE`. Typeinfo base 0x12e61b0 =
nn::nex::Data. Internal DDL (authentication / data-download layer)
record class.

- Vtable: vptr = 0x12f9058, typeinfo-pointer row variant (word at
  0x12f9050 = &typeinfo 0x12f90a0). GOT cell 0x1314e40 holds
  vptr-0x10 (addend 0x12f9048); sites do `ldr cell; add #0x10`.
- D1 0xa457e8 (slot +0x00; ICF twin body at 0xb4cc38-adjacent clones):
  install vptr 0x12f9058 at [this], install nn::nex::Data base vptr
  (runtime .bss cell 0x130b4a8 + 0x10) at [this+0x10], bl base D1
  FUN_71005790b4 on this+0x10, tail member-cleanup 0xa30458.
- D0 0xb4ccac (slot +0x08): same body, then bl 0xa30458 and tail
  operator delete 0x573f48.
- Consumers: FUN_7100b506b0 (refs 0xb506e4 / 0xb50758) — inspects a
  u32 status at +0x58 (== 2 branch) and scans 32 dword entries
  starting at +0xc4 plus u16 flags at +0xe8/+0xec/+0xf8.

## Member notes

- 0x00 vptr 0x12f9058; 0x10 nn::nex::Data base vptr (runtime cell
  0x130b4a8+0x10); 0x58 u32 status; 0xc4..0xe3 32 dwords scanned by
  the consumer; 0xe8/0xec/0xf8 u16 flags. Gaps unproven.
- Slots (8): +0x00 D1 0xa457e8, +0x08 D0 0xb4ccac, +0x10 0xb4cabc,
  +0x18 0xb4cb88, +0x20 0xb4cbb8, +0x28 0xb4cbec, +0x30
  FUN_7100b4cbcc (16 B), +0x38 FUN_7100b4cbdc (2036 B).

## Construction / init order

1. No standalone C1 site found (only D1/D0 reference GOT cell
   0x1314e40); construction path unverified.
2. Destruction: D1 0xa457e8 / D0 0xb4ccac as above.
