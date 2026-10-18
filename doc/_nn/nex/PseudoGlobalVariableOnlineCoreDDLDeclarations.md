# nn::nex::PseudoGlobalVariable<OnlineCoreDDLDeclarations>

RTTI-confirmed: typeinfo 0x12f8e70 -> mangled
`N2nn3nex20PseudoGlobalVariableINS0_25OnlineCoreDDLDeclarationsEEE`. Static
pseudo-global singleton for the OnlineCoreDDLDeclarations DDL table.
Instance lives in .bss at 0x1368b90 (GOT instance cell 0x1315fd8); no
allocation of the object itself was found.

## Identity

- Vtable: vptr = 0x12f8e28. GOT cell 0x1315f98 holds 0x12f8e18 = vptr-0x10;
  every site does `ldr cell; add #0x10`. Row layout: [0x12f8e18] = 0
  (offset-to-top), [0x12f8e20] = typeinfo slot -> record 0x12f8e70
  ({0x10, name, base = PseudoGlobalVariableRoot 0x128d6c0, 0}).
- Value type: two value subobjects at +0x18 and +0x38 (0x20 bytes each).
  Unlike the other DDL-declaration pseudo-globals, both subobject vptrs are
  the base-class STLExtDDLDeclarations vtable 0x12f8de8 (typeinfo 0x12f8e00,
  derives from nn::nex::DDLDeclarations); GOT cell 0x1315fc8 holds its
  vptr-0x10. Init does NOT call the value C1 helper 0xb4ae90 - it writes
  the defaults directly (zeros, flags at +0x30/+0x50 = 1).

## Member notes

- Slots (8): +0x00 D1 0xb4ad48 (installs vptr, runs virtual +0x10, unlinks
  from registry tree, delete wrapper), +0x08 D0 0xb4ba34 (D1 body then
  `operator delete`). Slots 2-7 unrecovered: 0xb4ba8c, 0xb4bbb4, 0xb4bc44,
  0xb4bc6c, 0xb4bc74, 0xb4bc7c.
- Size: 0x58 exact (base 0x18 + 2 x 0x20 value subobjects; max init store
  u8 at +0x50). Adjacent .bss singletons are spaced 0x58 (0x1368b90 ->
  0x1368be8), consistent (unverified).

## Construction / init order

In-place init FUN_7100b4c4a4 (static initializer; the object is never
allocated):

1. Registry tree node prep via helper 0x58c5a4(this).
2. STLExt vptr written to +0x18; +0x10, +0x20, +0x28, +0x40, +0x44, +0x48
   zeroed; flags +0x30 and +0x50 set to 1; second subobject vptr written to
   +0x38 (GOT cell 0x1315fc8 +0x10).
3. vptr installed at +0x00 from GOT cell 0x1315f98 (+0x10).
4. Registered in the global pseudo-global tree:
   0x58c448(root cell 0x130b940, this), then __tree_balance_after_insert
   0x58c5a4.
5. If the global counter at cell 0x1314188 dereferences to >= 2, virtual
   slot2 (+0x10) is invoked on the instance.
6. Cleanup registration: helper 0x19c(D1 0xb4ad48, instance, __dso_handle
   0x12fc140) - atexit-style destroy on shutdown (unverified identity of
   helper 0x19c).
