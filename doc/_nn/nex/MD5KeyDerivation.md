# nn::nex::MD5KeyDerivation

RTTI-confirmed: typeinfo 0x12e63c0 -> mangled `N2nn3nex16MD5KeyDerivationE`
= nn::nex::MD5KeyDerivation. Small refcount-style member object;
constructed inline at singleton+0x10 (singleton storage at 0x13671a0,
created by static init function FUN_7100a322cc).

- Identity: slot2 (0xa29b98, 100 B) is a combiner: loads virtual slots
  +0x18 and +0x20 from its own vtable and calls them in sequence with a
  stack temporary, then destroys the temporary via 0x58bc04.
- Vtable: vptr = 0x12e5be0. GOT cell 0x1314b18 holds 0x12e5bd0 =
  vptr-0x10; site 0xa3249c adds 0x10 and stores at [member+0x00].
  Row: [0x12e5bd0] = 0 (offset-to-top), [0x12e5bd8] typeinfo slot ->
  0x12e63c0.
- Site: 0xa3249c (inline member init in FUN_7100a322cc).

## Member notes

- Slots (8): +0x00 D1 0xa29b90 (tail of FUN_7100a29a94), +0x08 D0
  0xa29b94 (same function, +4), +0x10 0xa29b98 (100 B combiner),
  +0x18 0xa29bfc (88 B), +0x20..+0x38 slots 4-7 all 0xa29c54 (948 B,
  shared).
- Init (0xa324a4): stores 0x0000000100000001 at +0x08 (two u32 1s) and
  1 at +0x10.
- Size: lower bound 0x18; unproven (no allocation of this object).

## Construction / init order

1. Member position inside singleton at 0x13671a0 (+0x10), storage
   provided by the singleton's static storage.
2. Inline init in FUN_7100a322cc: vptr installed at +0x00 (site
   0xa3249c), counters 1/1 at +0x08/+0x10.
