# nn::nex::PseudoGlobalVariable<MatchMakingServiceDDLDeclarations>

RTTI-confirmed: typeinfo 0x12f5b20 -> mangled
`N2nn3nex20PseudoGlobalVariableINS0_33MatchMakingServiceDDLDeclarationsEEE`.
Static pseudo-global singleton for the MatchMakingServiceDDLDeclarations DDL
table. Instance lives in .bss at 0x1368270 (GOT instance cell 0x1315868); no
allocation of the object itself was found.

## Identity

- Vtable: vptr = 0x12f5ad8. GOT cell 0x1315848 holds 0x12f5ac8 = vptr-0x10;
  every site does `ldr cell; add #0x10`. Row layout: [0x12f5ac8] = 0
  (offset-to-top), [0x12f5ad0] = typeinfo slot -> record 0x12f5b20
  ({0x10, name, base = PseudoGlobalVariableRoot 0x128d6c0, 0}).
- Value type: two MatchMakingServiceDDLDeclarations subobjects at +0x18 and
  +0x38 (0x20 bytes each: vptr, two qwords, u8 flag at +0x18 of the
  subobject). Their vtable 0x12f59b8 (typeinfo 0x12f59d0) derives from
  nn::nex::DDLDeclarations; GOT cell 0x1315850 holds its vptr-0x10. Init
  syncs second -> first (qwords +0x40/+0x48 -> +0x20/+0x28, u8 +0x50 ->
  +0x30).

## Member notes

- Slots (8): +0x00 D1 0xb154c0 (installs vptr, runs virtual +0x10, unlinks
  from registry tree, delete wrapper), +0x08 D0 0xb158cc (D1 body then
  `operator delete`). Slots 2-7 unrecovered: 0xb15944, 0xb15a50, 0xb15ae0
  (FUN_7100b15ae0, 796 B), 0xb15b08, 0xb15b10, 0xb15b18.
- Size: 0x58 exact (base 0x18 + 2 x 0x20 value subobjects; max init store
  u8 at +0x50). Adjacent .bss singletons are spaced 0x58, consistent
  (unverified).

## Construction / init order

In-place init FUN_7100b15ba4 (static initializer; the object is never
allocated):

1. Registry tree node prep via helper 0x58c5a4(this).
2. vptr installed at +0x00 from GOT cell 0x1315848 (+0x10).
3. Value C1 helper 0xb4ae90(this+0x18, 1); secondary vptr written to +0x18,
   then 0xb4ae90(this+0x38, 1) and secondary vptr written to +0x38.
4. Defaults written into the second subobject (+0x40/+0x48/flag +0x50),
   then copied into the first (+0x20/+0x28/flag +0x30); +0x10 zeroed.
5. Registered in the global pseudo-global tree:
   0x58c448(root cell 0x130b940, this), then __tree_balance_after_insert
   0x58c5a4.
6. If the global counter at cell 0x1314188 dereferences to >= 2, virtual
   slot2 (+0x10) is invoked on the instance.
7. Cleanup registration: helper 0x19c(D1 0xb154c0, instance, __dso_handle
   0x12fc140) - atexit-style destroy on shutdown (unverified identity of
   helper 0x19c).
