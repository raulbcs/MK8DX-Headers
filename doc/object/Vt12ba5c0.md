# object::Vt12ba5c0

Secondary interface table (13 slots, offset-to-top -0x248, typeinfo row 0) of
a KartParamCache-family aggregate constructed in place as the member at
Vt12b6af8+0x1dd8 (see doc/object/Vt12b6af8.md). PLACEHOLDER name.

## Identity

- GOT cell 0x130e3d8 holds 0x12ba558 (ot row of the PRIMARY table). The C1
  computes both vptrs from that one cell: `add #0x10` -> primary 0x12ba568
  installed at [this], `add #0x68` -> secondary 0x12ba5c0 installed at
  [this+0x248]. The pair-install runs in the C1 FUN_71006e38e0
  (0x6e3940-0x6e3964) and mirrored in D1 FUN_71006e3c0c (0x6e3c24-0x6e3c40).
- No RTTI name. Slots 2-12 are the shared paramCache cluster
  (0x63c6f8/0x63c700/0x63c704/0x63c70c-gap/0x63c710
  paramCacheSharedTypeIdEquals/0x63c724/0x63c728/0x669208/0x66979c/0x6697f8/
  0x63c72c) recurring across the 0x12b1/0x12ba paramCache interface tables.
- Slot 0 = D1-thunk 0x6e3e3c (`sub x0,#0x248; b 0x6e3c0c`), slot 1 = D0-thunk
  0x6e3e68 (same adjustment + operator delete 0x60b470); both target the
  primary D1 0x6e3c0c. Primary table 0x12ba568 has 9 slots: 0x6e3c0c (D1),
  0x6e3e44 (D0), 0x6c369c, 0x6c36a0, 0x6e6644, 0x6e719c, 0x6e8600, 0x6e88dc,
  0x6e88e0 (all unrecovered in functions.csv).

## Member notes

- C1 FUN_71006e38e0 (812 B, 0x6e38e0-0x6e3c0c): base ctor 0x6c6128 first;
  member ctor 0x668d40(this+0x248, {vptr cell 0x12fae28+0x10, rodata string
  0xf02889}, 0) at 0x6e3928 before the secondary vptr is adjusted.
- Owned buffers freed by D1: [this+0x560] ptr (0x6e3c30), [this+0x1be8] ptr
  (0x6e3c54), [this+0x19e8] virtual-destroy (0x6e3c68), [this+0x1bc8]
  0x8d0-stride element array with per-element vptrs from cells 0x130d830 /
  0x130d918 (0x6e3c80-0x6e3d04), [this+0x1bd8] 0x68-stride element array
  (0x6e3d10-0x6e3d40).
- Size 0x1bf0: the object occupies Vt12b6af8+0x1dd8..+0x39c8; the next member
  ctor (FUN_71006e22b4) starts at owner+0x39c8 (0x6bb364-0x6bb36c).
- Deepest C1 field store: +0x1be8 (0x6e3bf0).

## Construction / init order

1. Owner ctor FUN_71006bb300 calls FUN_71006e38e0(this+0x1dd8) at 0x6bb360.
2. Base ctor 0x6c6128 (0x6e38fc); member 0x668d40 at +0x248 (0x6e3928).
3. Secondary vptr 0x12ba5c0 at +0x248 and primary 0x12ba568 at +0 (0x6e3960/
   0x6e3964); then zero-fill +0x418..+0x440, member ctors 0x66a2a4/0x662f30
   out to +0x1b80, counters +0x1bc0..+0x1be8 zeroed.
4. Post-ctor population of the arrays happens in the owner's init
   (FUN_71006bb300 body after 0x6bb360).
