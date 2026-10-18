# NexMatchMeshLayerController (nn::pia::inet::NexMatchMeshLayerController)

- vt row 0x12db1a8 in vt_ctors.tsv is the typeinfo slot; real vptr 0x12db1b0
  (vptr-8 = 0x12db1a8 -> typeinfo 0x12db290, name string
  "N2nn3pia4inet27NexMatchMeshLayerControllerE"). GOT cell 0x1313070 holds
  RELATIVE addend 0x12db1a0 = vptr-0x10; every site does `cell + 0x10`.
- Size 0x2e0, proven by the nothrow-new factory 0x7100932184
  (`operator new(0x2e0)` -> C1 0x710094eb7c).

## Identity

pia inet mesh-layer controller. Derives from
nn::pia::session::MeshLayerController (base C1 0x710098b06c, base vptr
0x12ddfe0 via cell 0x13138a8) whose layout occupies 0x00..~0xb0; the base
also installs a second, unnamed vptr 0x12d7ec8 at +0x08 (cell 0x13123d8).

## Slots

Primary vtable 0x12db1b0, 23 slots:
- slot 0 = 0x710094ebd4 (D1 deleting dtor: reloads cell 0x1313070, destroys
  the +0x2d8 subobject via its own vtable, operator delete 0x7100568b64).
- slot 1 = 0x710094ec24 (D2 complete dtor, same body minus delete).
- slot 2 = 0x710094eca0 (0x6b4 bytes, largest override; unrecovered).
- slots 3..22 unrecovered FUN_*; shared session-base slots
  0x7100951678/9516a0/9516c0/9516e0/9516f4/9516fc/951704/95170c/951714 at
  slots 8/9/13/15..22 are base-inherited.
Secondary thunk tables follow at vptr+0xc0 (typeinfo row 0x12db2b0, fns
0x7100950594/95073c/950e78) and vptr+0xe0 (offset-to-top 0x10 group).

## Construction / init order

C1 0x710094eb7c:
1. base C1 0x710098b06c (installs both base vptrs, zeroes entry table).
2. vptr 0x12db1b0 at [this].
3. [this+0x2a8] = 0.
4. manager handle via 0x7100563b70; `operator new(0x1958)`; subobject ctor
   0x7100950408; result stored at [this+0x2d8].
