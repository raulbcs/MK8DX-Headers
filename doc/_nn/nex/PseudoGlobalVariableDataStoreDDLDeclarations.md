# nn::nex::PseudoGlobalVariable<DataStoreDDLDeclarations>

RTTI-confirmed: typeinfo 0x12f8550 -> mangled
`N2nn3nex20PseudoGlobalVariableINS0_24DataStoreDDLDeclarationsEEE`. Static
pseudo-global singleton for the DataStoreDDLDeclarations DDL table. Instance
lives in .bss at 0x1368390 (GOT instance cell 0x1315e50); no allocation of
the object itself was found.

## Identity

- Vtable: vptr = 0x12f8508. GOT cell 0x1315d88 holds 0x12f84f8 = vptr-0x10;
  every site does `ldr cell; add #0x10`. Row layout: [0x12f84f8] = 0
  (offset-to-top), [0x12f8500] = typeinfo slot -> record 0x12f8550
  ({0x10, name, base = PseudoGlobalVariableRoot 0x128d6c0, 0}).
- Value type: two DataStoreDDLDeclarations subobjects at +0x18 and +0x38
  (0x20 bytes each: vptr, two qwords, u8 flag at +0x18 of the subobject).
  Their vtable 0x12f7148 (typeinfo 0x12f7160) derives from
  nn::nex::DDLDeclarations; GOT cell 0x1315e38 holds its vptr-0x10. Init
  syncs second -> first (qwords +0x40/+0x48 -> +0x20/+0x28, u8 +0x50 ->
  +0x30).

## Member notes

- Slots (8): +0x00 D1 0xb312c8 (FUN_7100b312c8, 116 B; installs vptr, runs
  virtual +0x10, unlinks from registry tree, delete wrapper), +0x08 D0
  0xb3fdbc (FUN_7100b3fdbc, 116 B; D1 body then `operator delete`). Slots
  2-7 unrecovered: 0xb3fe34, 0xb3ff40, 0xb3ffd0, 0xb3fff8, 0xb40000,
  0xb40008.
- Size: 0x58 exact (base 0x18 + 2 x 0x20 value subobjects; max init store
  u8 at +0x50). Adjacent .bss singletons are spaced 0x58, consistent
  (unverified).

## Construction / init order

In-place init FUN_7100b4076c (static initializer; the object is never
allocated). Same shape as the other DDL-declaration pseudo-globals:

1. Registry tree node prep via helper 0x58c5a4(this).
2. vptr installed at +0x00 from GOT cell 0x1315d88 (+0x10).
3. Value C1 helper 0xb4ae90(this+0x18, 1); secondary vptr written to +0x18,
   then 0xb4ae90(this+0x38, 1) and secondary vptr written to +0x38.
4. Defaults written into the second subobject (+0x40/+0x48/flag +0x50),
   then copied into the first (+0x20/+0x28/flag +0x30); +0x10 zeroed.
5. Registered in the global pseudo-global tree:
   0x58c448(root cell 0x130b940, this), then __tree_balance_after_insert
   0x58c5a4.
6. If the global counter at cell 0x1314188 dereferences to >= 2, virtual
   slot2 (+0x10) is invoked on the instance.
7. Cleanup registration: helper 0x19c(D1 0xb312c8, instance, __dso_handle
   0x12fc140) - atexit-style destroy on shutdown (unverified identity of
   helper 0x19c).
