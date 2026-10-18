# object::Vt12dac30

PLACEHOLDER name. nn::pia-region job object, sibling of Vt12da130/Vt12da460.
vptr 0x12dac38, 9 slots, no RTTI (row 0x12dac30 is the typeinfo slot). GOT cell
0x1312b98 holds 0x12dac28 = vt-0x8, so the installed vptr is cell+0x10.

- Slots (vptr-relative): 0 = D1 0x93bc00 (vptr at [this], member dtor 0x929ee0
  at +0x60, base dtor tail 0x97dc8c); 1 = D0 0x93bc34 (same + `operator
  delete`); 2 = 0xb4a654 (lock-ish helper, clears flag [this+0x48]); 3 =
  0xb4a67c (flag +0x48 polling loop with jump-table dispatch through the
  +0x30/+0x38 pair); 4 = 0x933314 `ret` stub; 5 = 0x93c588; 6 = 0x93c538; 7 =
  0x93bc70; 8 = 0x93c388 (slots 5-8 unrecovered in functions.csv).
- Slots 2-4 are shared verbatim with Vt12da130 and Vt12da460 (ICF trio).

## Member notes

- +0x60: 0x929ec0-class member (0x20 bytes: ptr pair +0x8/+0x10, flag byte
  +0x18) - the same member class placed at +0x138 in Vt12da460.
- [this+0x80] ptr null, [this+0x88] u32 zeroed by the C1 (0x93bbec..0x93bbf0).
- Base region 0x00..0x60 initialized by the base member ctor 0x97dc58 (C1
  entry 0x93bbd0).

## Construction / init order

- C1 0x93bbcc: `bl 0x97dc58` (base member ctor) -> install vptr 0x12dac38 ->
  0x929ec0 at +0x60 -> [+0x80] = 0 -> [+0x88] = 0 (0x93bbcc..0x93bbfc).
- The only vptr-materializing sites are the C1/D1/D0 trio (0x93bbd8/0x93bc10/
  0x93bc44); no direct `bl` caller of the C1 and no data relocation to it was
  found - construction site unverified.
- Extent 0x90 (lower bound): deepest field store is the u32 at +0x88; exact
  size unverified.
