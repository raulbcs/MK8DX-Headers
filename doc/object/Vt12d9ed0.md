# object::Vt12d9ed0

PLACEHOLDER name. Element-array manager for 0x270-byte nn::pia elements
(Vt12d9f50). vptr 0x12d9ed8, 9 slots, no RTTI (row 0x12d9ed0 is the typeinfo
slot). GOT cell 0x1312930 holds 0x12d9ec8 = vt-0x8, so the installed vptr is
cell+0x10.

- Slots (vptr-relative): 0 = D1 0x932498 (reinstalls vptr, virtual-deletes each
  element via element-table slot 0, frees the array 0x568bb0 + 0x568b64);
  1 = D0 0x932538 (same then `operator delete`); 2/3 = 0x9325d0/0x9325d8 get
  [this+0x10] (array base); 4/5 = 0x9325e0/0x9325e0-clones return
  base + cursor([this+0x8], u16) * 8; 6 = 0x932600 get u16 [this+0x8]; 7 =
  0x932608 get u16 [this+0xa] (count); 8 = 0x932610 release/reset (virtual slot
  0 per element up to count, zeroes cursor/count/array).
- This is the "manager owning the element array" already described from the
  element side in doc/object/Vt12da1a0.md / Vt12d9f50.md (count at +0xa, array
  at +0x10, factory loop 0x7100932418..0x7100932484).

## Member notes

- C1 0x932390(this, u16 count): zeroes [this+0x8], stores count at [this+0xa],
  installs the vptr, allocates count*8 via 0x568aa0, zeroes it, then loops
  allocating 0x270 per element (0x932428..0x932464), memset + element init
  0x933318 + element vptr overwrite 0x12d9f58 (cell 0x1312938), storing each
  pointer into [this+0x10] array.

## Construction / init order

- The only vptr-materializing sites in the binary are the C1/D1/D0 trio
  themselves (cells 0x1312930 read at 0x93239c/0x9324ac/0x93254c). No direct
  `bl` caller of C1 0x932390 and no data relocation to it was found — the
  construction site is unverified (likely an ICF-merged clone or an inlined
  parent path).
- Extent 0x18 from the deepest field store (array pointer at +0x10).
