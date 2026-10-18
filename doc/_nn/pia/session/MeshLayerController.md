# nn::pia::session::MeshLayerController

Identity: typeinfo-row vtable, assigned address 0x12ddfd8 (= typeinfo slot,
vptr-8); installed vptr **0x12ddfe0**. GOT cell 0x13138a8 holds vptr-0x10
(0x12ddfd0 = offset-to-top 0). Typeinfo data 0x12de098, name
"N2nn3pia7session19MeshLayerControllerE", base typeinfo 0x12f8d30
("N2nn3pia6common15StepSequenceJobE"). 23 slots (0x12ddfe0..0x12de090).

## Member notes

- Multiple inheritance: secondary vptr **0x12d7ec8** at [this+0x08] (GOT
  cell 0x13123d8 holds 0x12d7ec8-0x10; the 0x12d7ec8 row is a 10-slot
  no-RTTI member table, slots 6/7/9 null). Copies of 0x12d7ec8 also at
  +0x90, +0x118, +0x1a0 — each 0x88-stride unit's entry+0x78 subobject
  vptr (4th unit's copy not observed; unverified).
- [this+0x18..0x237] — 4 units, heads at +0x18/+0xa0/+0x128/+0x1b0,
  stride 0x88. Each: head u32 = 0x50 (80), element pointer at +0x10-like
  slot (+0x10/+0x98/+0x120/+0x1a8) pointing to the entry array at
  +0x24/+0xac/+0x134/+0x1bc, 27 x 3-byte elements zeroed by C2 loops
  (`cmp #0x51`), 0xff sentinel at +0x78 of each unit region.
- [this+0x238..0x2a7] — tail member region: [+0x240] u8 = 1, in-place
  member ctor 0x929fc4 at +0x248, memsets +0x24c (0x10) and +0x260 (0x20),
  strh [+0x280], zero qwords at +0x238/+0x288/+0x290/+0x298/+0x2a0.
- Slots 10/11: constant-0 getters; slot12: constant-1 getter; slot7 `ret`.

## Construction / init order

1. C2 FUN_710098b06c (0x98b06c..0x98b39c, size 0x334): vptr pair
   ([+0x0] = cell 0x13138a8 + 0x10, [+0x8] = cell 0x13123d8 + 0x10),
   then per-unit init loops described above (arrays zeroed twice by the
   compiler-duplicated zero-init path), tail member region, last store
   [+0x2a0] qword = 0.
2. Derived factory FUN at 0x9c410c: operator-new 0x2b0 (`mov w0, #0x2b0`),
   C2, then overrides vptr with cell 0x1313db8 + 0x10 and stores a global
   at [+0x2a8] — proving base extent 0x2a8. Second derived site at
   0x94eb7c (new 0x1958, aggregates it as a member).
