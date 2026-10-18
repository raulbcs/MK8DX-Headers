# nn::nex::PseudoGlobalVariable&lt;AccountManagementServiceDDLDeclarations&gt;

RTTI-confirmed: typeinfo 0x12e7880 -> mangled
`N2nn3nex20PseudoGlobalVariableINS0_39AccountManagementServiceDDLDeclarationsEEE`.
Global-settings holder for the account-management DDL declarations;
static instance storage at 0x13671f8, reached through GOT cell
0x1314d88. No standalone C1 was found - the instance is (re)initialized
in place.

- Vtable: vptr = 0x12e7838. GOT cell 0x1314b60 holds 0x12e7828 =
  vptr-0x10; every site does `ldr cell; add #0x10; str [this]`. Row:
  [0x12e7828] = 0 (offset-to-top), [0x12e7830] typeinfo slot ->
  0x12e7880.
- vptr sites: 0xa32a54 (slot +0x00 D1 body inside FUN_7100a32868),
  0xa427a4 (slot +0x08 D0 body, FUN_7100a42748), 0xa42d5c (re-init
  FUN_7100a42d40).

## Member notes

- Slots (9): +0x00 D1 0xa32a44, +0x08 D0 0xa42794 (calls member dtor,
  frees the list, `operator delete` 0x573f48 tail), +0x10 0xa4280c
  (268 B), +0x18 0xa42918 (144 B - destroys the 0x20-stride entry array
  at +0x10 virtually, then frees it via 0x5763ac and nulls +0x10),
  +0x20 0xa429a8 (532 B; reads byte +0x50), +0x28 0xa429d0 (stores x1
  at [x0+8]), +0x30 0xa429d8 (stores x1 at [x0+8]), +0x38 0xa429e0
  (pre-inc load [x0+0x40]).
- T = nn::nex::AccountManagementServiceDDLDeclarations (typeinfo
  0x12e7400, vptr 0x12e73e8 via GOT cell 0x1314d80), size 0x20 with its
  own vptr at T+0x00; init/copy helper 0xb4ae90(dst, 1).
- Size: lower bound 0x58 (two 0x20-byte T copies at +0x18/+0x38, byte
  read at +0x50); no allocation of the object itself was found, so the
  exact size is unverified.

## Construction / init order

1. FUN_7100a42d40 (re-init, 240 B): fetch instance 0x13671f8 from
   cell 0x1314d88, teardown helper 0x58c5a4(this), reinstall vptr at
   +0x00.
2. Init member T at +0x18 (helper 0xb4ae90, arg 1) after storing its
   vptr (cell 0x1314d80 + 0x10) at +0x18; same for the second T at
   +0x38.
3. Restore: [x+0x10] = 0, copy q-pairs +0x40/+0x48 -> +0x20/+0x28 and
   byte +0x50 -> +0x30 (saved -> current).
