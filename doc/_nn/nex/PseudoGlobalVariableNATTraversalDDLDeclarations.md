# nn::nex::PseudoGlobalVariable<NATTraversalDDLDeclarations>

RTTI-confirmed: typeinfo 0x12f60b0 -> mangled
`N2nn3nex20PseudoGlobalVariableINS0_27NATTraversalDDLDeclarationsEEE`.
Static pseudo-global singleton for the NATTraversalDDLDeclarations DDL table.
Instance lives in .bss at 0x13682c8 (GOT instance cell 0x13158e0); no
allocation of the object itself was found.

## Identity

- Vtable: vptr = 0x12f6068. GOT cell 0x13158c0 holds 0x12f6058 = vptr-0x10;
  every site does `ldr cell; add #0x10`. Row layout: [0x12f6058] = 0
  (offset-to-top), [0x12f6060] = typeinfo slot -> record 0x12f60b0
  ({0x10, name, base = PseudoGlobalVariableRoot 0x128d6c0, 0}).
- Value type: two NATTraversalDDLDeclarations subobjects at +0x18 and +0x38
  (0x20 bytes each: vptr, two qwords, u8 flag at +0x18 of the subobject).
  Their vtable 0x12f5fe8 (typeinfo 0x12f6000) derives from
  nn::nex::DDLDeclarations; GOT cell 0x13158d8 holds its vptr-0x10. Init
  syncs second -> first (qwords +0x40/+0x48 -> +0x20/+0x28, u8 +0x50 ->
  +0x30).

## Member notes

- Slots (8): +0x00 D1 0xb169dc (FUN_7100b169dc, 116 B; installs vptr, runs
  virtual +0x10, unlinks from registry tree, delete wrapper), +0x08 D0
  0xb17bfc (FUN_7100b17bfc, 116 B; D1 body then `operator delete`). Slots
  2-7 unrecovered: 0xb17c74, 0xb17d80, 0xb17e10 (FUN_7100b17e10, 1020 B),
  0xb17e38, 0xb17e40, 0xb17e48.
- Size: 0x58 exact (base 0x18 + 2 x 0x20 value subobjects; max init store
  u8 at +0x50). Adjacent .bss singletons are spaced 0x58, consistent
  (unverified).

## Construction / init order

In-place init FUN_7100b17ed4 (static initializer; the object is never
allocated):

1. Registry tree node prep via helper 0x58c5a4(this).
2. vptr installed at +0x00 from GOT cell 0x13158c0 (+0x10).
3. Value C1 helper 0xb4ae90(this+0x18, 1); secondary vptr written to +0x18,
   then 0xb4ae90(this+0x38, 1) and secondary vptr written to +0x38.
4. Defaults written into the second subobject (+0x40/+0x48/flag +0x50),
   then copied into the first (+0x20/+0x28/flag +0x30); +0x10 zeroed.
5. Registered in the global pseudo-global tree:
   0x58c448(root cell 0x130b940, this), then __tree_balance_after_insert
   0x58c5a4.
6. If the global counter at cell 0x1314188 dereferences to >= 2, virtual
   slot2 (+0x10) is invoked on the instance.
7. Cleanup registration: helper 0x19c(D1 0xb169dc, instance, __dso_handle
   0x12fc140) - atexit-style destroy on shutdown (unverified identity of
   helper 0x19c).
