# object::Vt12da0b0

PLACEHOLDER name. Element-array manager for 0x688-byte nn::pia elements,
structurally the u32-wide sibling of Vt12d9ed0. vptr 0x12da0b8, 9 slots, no
RTTI (row 0x12da0b0 is the typeinfo slot). GOT cell 0x1312940 holds
0x12da0a8 = vt-0x8, so the installed vptr is cell+0x10.

- Slots (vptr-relative): 0 = D1 0x9327a8 (reinstalls vptr, virtual-deletes each
  element via element-table slot 0, frees array 0x568bb0 + 0x568b64); 1 = D0
  0x932840 (same then `operator delete`); 2/3 = 0x9328d0/0x9328d8 get
  [this+0x10] (array base); 4/5 = 0x9328e0/0x9328f0 return base +
  cursor([this+0x8], u32) * 8; 6 = 0x932900 get u32 [this+0x8]; 7 = 0x932908
  get u32 [this+0xc] (count); 8 = 0x932910 broadcast (calls element-table
  slot 16, vtable+0x80, per element, then zeroes cursor/count/array).
- Element init in C1: 0x93b60c then an immediate virtual call to element-table
  slot 16 (0x932764..0x932770) - the element table row is 0x12da3e0 (cell
  0x13129b0 holds 0x12da3d8 = vt-0x8, vptr 0x12da3e8).

## Construction / init order

- C1 0x9326b8(this, u8 count): stores count at [this+0xc], installs the vptr,
  allocates count*8 via 0x568aa0, zeroes it, then loops allocating 0x688 per
  element and initializing it (0x932748..0x932784); tail-calls its own slot 8
  ([vptr+0x40] = 0x932908) as the reset pass (0x93278c..0x9327a4).
- The only vptr-materializing sites are the C1/D1/D0 trio (0x9326c4/0x9327bc/
  0x932854); no direct `bl` caller of the C1 and no data relocation to it was
  found - construction site unverified.
- Extent 0x18 from the deepest field store (array pointer at +0x10).
