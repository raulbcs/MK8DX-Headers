# NatTraverser (nn::pia::nat::NatTraverser)

## Identity

- Assigned row 0x12dba80 is the TYPEINFO SLOT, not the vptr: [0x12dba80] =
  0x12dbab0 (reloc) = typeinfo record {0x10, name 0xf80840, base 0}. Name is
  exact: "N2nn3pia3nat12NatTraverserE". Root class (base record 0).
- Installed vptr = 0x12dba88 (row+8), 5 slots.
- GOT cell 0x1313208 holds addend 0x12dba78 = vt-0x10; code (C1 0x964b94 tail,
  ref 0x964bac) does `ldr cell; add #0x10; str [this]`.
- Extent 0xc8 LOWER BOUND: C1 0x964b94 (ends 0x964c70, interior of merged blob
  FUN_71009649c8) writes 0xc0; no allocation site for NatTraverser itself found.

## Slots (vptr 0x12dba88, 5 slots)

- slot 0 = 0x964c74 (D1: reinstalls vptr 0x12dba88; D1-deletes [this+0x70]
  member via its slot 0 then 0x568b64; ditto [this+0x78]; dtors 0x929ee0 at
  +0xa0/+0x80 and 0x92a014 at +0x34-ish strings; tail 0x92a014).
- slot 1 = 0x964d74 (D0: calls slot 0 body 0x964c74, then `operator delete`).
- slot 2 = 0x964e34 (method(this, x1, x2) using [this+8]; null-arg paths store
  result code 0x10000|0xc08 = 0x0c08_0000; on success 0x9a7c5c/0x96929c/
  0x9a7ccc/0x9a7ec0 chain writes u16 [this+0x58] and pointer [this+0x60]).
- slot 3 = 0x9651f4 (functions.csv-unrecovered).
- slot 4 = 0x965f2c (functions.csv-unrecovered).

## Member notes

- 0x28 — secondary vptr 0x12dbad0 (cell 0x1313210 + 0x10; 3-slot row
  0x964d2c/0x965f30/0x965f80, ti record 0x12dbae8 =
  "N2nn3pia6common15SimpleContainerINS_11InetAddressELi4EEE", base 0).
- 0x34..0x53 — C1 sub-init 0x929fd4 (same init used for pia string members).
- 0x70 — heap member: new 0x518, C1 0x967140.
- 0x78 — heap member: new 0x4a0, C1 0x968c40 = nn::pia::nat::NatPropertyDetecter
  (see doc/_nn/pia/nat/NatPropertyDetecter.md).
- 0x80 / 0xa0 — C1 sub-init 0x929ec0, D1 dtor 0x929ee0.

## Construction / init order

1. C1 0x964b94: vptr 0x12dba88 at [this] (cell 0x1313208, 0x964bc4); scalar
   zeros 0x10..0x30; secondary vptr 0x12dbad0 at 0x28 (cell 0x1313210).
2. 0x929fd4 sub-inits at 0x34/0x3c/0x44/0x4c; zeros 0x60..0x6a.
3. 0x929ec0 sub-inits at 0x80/0xa0; [0xc0] = 0.
4. new 0x518 + C1 0x967140 -> [this+0x70] (0x964c28..0x964c40);
   new 0x4a0 + C1 0x968c40 -> [this+0x78] (0x964c4c..0x964c64).
