# LocalMatchMeshLayerController (nn::pia::local::LocalMatchMeshLayerController)

- vt row 0x12e1cd0 is the typeinfo slot; real vptr 0x12e1cd8 (vptr-8 ->
  typeinfo 0x12e1d90, "N2nn3pia5local29LocalMatchMeshLayerControllerE"). GOT
  cell 0x1313db8 holds addend 0x12e1cc8 = vptr-0x10.
- Size 0x2b0, proven by the nothrow-new factory 0x71009c410c
  (`operator new(0x2b0)` -> inlined C1).

## Identity

pia local-wireless mesh-layer controller; same base chain as the inet/lan
variants: nn::pia::session::MeshLayerController (base C1 0x710098b06c, vptr
0x12ddfe0, second unnamed vptr 0x12d7ec8 at +0x08).

## Slots

Primary vtable 0x12e1cd8, 23 slots, all inherited from the session base
(0x7100951678/9516a0/9516c0/9516e0/9516f4/9516fc/951704/95170c/951714 etc.);
slot 0 = 0x710098b868 (base D1) and slot 12 = 0x710098b880 (base override) —
no local-class overrides in the primary table. Secondary thunk groups at
vptr+0xc0 (0x71009d2e14/9d2e18) and vptr+0xf0 (typeinfo-row group,
0x71009d3198/9d3190). Neighbor helpers at 0x71009c41a8+ are memcpy-based
entry copies (set [x19+9]=0x14 flag after a 0x10-byte copy) and
`stp vptr, xzr, [x0]` init thunks on cell 0x1313db8.

## Construction / init order

Factory 0x71009c410c (inlined C1):
1. `operator new(0x2b0)` (nothrow; null-check).
2. base C1 0x710098b06c.
3. vptr 0x12e1cd8 at [this].
4. [this+0x2a8] = manager pointer loaded from cell 0x1312638.
