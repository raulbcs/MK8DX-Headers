# nn::nex::PseudoGlobalVariableU8

RTTI-confirmed: typeinfo 0x12e50e0 -> mangled
`N2nn3nex20PseudoGlobalVariableIhEE` =
nn::nex::PseudoGlobalVariable<unsigned char>. Sorted intrusive
container: nodes linked by +0x00/+0x08 pointers with a signed 16-bit
sort key at node+0x28; the erase routine walks the chain, unlinks a
node, decrements the owner count at +0x10 and frees the node.

- Identity: FUN_7100a1d260 (336 B, called from 0xa0a078 in a lookup
  wrapper that reads a u16 key at +0x70 of the caller's record) - key
  comparison is `sub / sxth / cmp #0` over node+0x28 vs the argument key.
- Vtable: vptr = 0x12e5098. GOT cell 0x1314608 holds 0x12e5088 =
  vptr-0x10. Row: [0x12e5088] = 0 (offset-to-top), [0x12e5090] typeinfo
  slot -> 0x12e50e0.
- Sites: 0x9f77b4 (in-place init inside global-table init
  FUN_71009f7434), 0xa025d4 (slot0/D1 body), 0xa1d368 (slot1/D0 body).

## Member notes

- Slots (8): +0x00 D1 0xa025c4 (tail of FUN_7100a023c4; installs vptr,
  runs virtual +0x18, delete wrapper 0x58c5b8), +0x08 D0 0xa1d358 (D1
  body then `operator delete` 0x573f48), +0x10 0xa1d3b0 (140 B),
  +0x18..+0x38 slots 3-7 all 0xa1d43c (200 B, shared stub).
- Node layout (from 0xa1d260): +0x00 / +0x08 links, +0x10 owner backref,
  +0x28 s16 sort key.
- Size: lower bound 0x18 (count field end 0x18); unproven.

## Construction / init order

1. In-place inside FUN_71009f7434 (global table init): vptr installed
   (site 0x9f77b4), helper 0x58c448(global cell 0x130b940, this), then
   virtual slot +0x18.
