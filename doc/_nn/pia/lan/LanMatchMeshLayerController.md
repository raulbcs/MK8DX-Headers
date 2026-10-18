# LanMatchMeshLayerController (nn::pia::lan::LanMatchMeshLayerController)

- vt row 0x12dcfd0 is the typeinfo slot; real vptr 0x12dcfd8 (vptr-8 ->
  typeinfo 0x12dd090, "N2nn3pia3lan27LanMatchMeshLayerControllerE"). GOT cell
  0x13135c8 holds addend 0x12dcfc8 = vptr-0x10; the ctor does `cell + 0x10`.
- Size 0x2b8, proven by the nothrow-new factory 0x710096d6bc
  (`operator new(0x2b8)` -> C1 0x7100977e2c).

## Identity

pia LAN mesh-layer controller; same base chain as the inet variant:
nn::pia::session::MeshLayerController (base C1 0x710098b06c, vptr 0x12ddfe0,
second unnamed vptr 0x12d7ec8 at +0x08).

## Slots

Primary vtable 0x12dcfd8, 23 slots:
- slot 0 = 0x7100977e60 (`ret` — inherited no-op slot).
- slot 1 = 0x7100977e64 (tail-call operator delete only).
- slot 2 = 0x7100977e68 (D1 deleting dtor, 0x530 bytes; reads settings at
  +0x10/+0x98/+0x120/+0x1a8, stores 0x554 at +0x25c, zeroes the +0x24 entry
  table, then D2 0x710098b7d8/delete).
- slots 10/11 = 0x710097840c/97841c, slot 12 = 0x71009784b8, slot 14 =
  0x7100978544, slot 19/20 = 0x710098b7d8/98b7dc (D2/D0 pair shared with the
  session base), rest unrecovered FUN_* / base-inherited.

## Construction / init order

C1 0x7100977e2c: base C1 0x710098b06c -> vptr 0x12dcfd8 at [this] ->
[this+0x2a8] = 0. No further member init (object size 0x2b8).
