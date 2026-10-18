# object::InteriorSettingSquare

PROVISIONAL name taken from the Japanese UI string the factory stores at
[this+0x10]: 0xf07b33 "インテリア（スクエア）" (Interior / Square). Member of a
5-variant interior-preset family created by the enum dispatcher 0x760b38
(w8 = [x0], jump table 0xf72fe8): case 0 -> 0x12c1ad0 (stereo, unmapped),
1 -> 0x12c1a50 (5.1ch), 2 -> 0x12c1a90 (4.1ch), 3 -> this (square),
4 -> 0x12c1a10 (wide). No RTTI (header slots 0x12c19c0/0x12c19c8 = 0).
GOT cell 0x130f1a0 holds vptr-0x10 (0x12c19c0); installed vptr = cell+0x10.
Size 0x40 EXACT (operator new 0x40 at 0x760d1c).

## Vtable layout (primary 0x12c19d0, 6 slots, 0x12c19d0-0x12c19f8)

- slot 0 (0x00) 0x760ed4: trivial dtor fragment (`ret`), shared by the family.
- slot 1 (0x08) 0x760e64: deleting-dtor fragment, tail `b operator delete`
  (0x60b470); row-unique trampoline.
- slot 2 (0x10) 0x75174c: thunk `add x0, x0, #8; b 0x61c9bc` - forwards to the
  secondary base subobject at this+0x8 (vtable 0x11ad210 via GOT cell
  0x12fae28; base stores are the 0x61c9bc copy helper).
- slot 3 (0x18) 0x760e68: returns 0.
- slot 4 (0x20) 0x760e70: returns 0.
- slot 5 (0x28) 0x760e78: returns 1.
  (Getter triple (0,0,1); row-unique flag set, semantics unverified. Other
  rows: stereo (0,0,0), 5.1ch (1,1,1), 4.1ch (0,1,1), wide (0,0,1).)

## Member notes

- [this+0x8] void* - secondary-base vptr (vtable 0x11ad210), installed during
  construction before the final primary store (0x760cd4 pattern).
- [this+0x10] const char* - display name, 0xf07b33.
- [this+0x18..0x3f] float coefficients written by the ctor with movz/movk
  constants (see header comments for the raw words). Semantics unverified;
  the equal-power-looking patterns (0x38e38e20, 0xaaaaaa80, 0xd5555540) occur
  across the family.

## Construction / init order

- Factory fragment 0x760d14-0x760da8 (tail-shared 0x760cf0-0x760e44):
  new 0x40 (0x760d1c) -> install temporary family vptr (GOT cell 0x130f180,
  vtable 0x12c1b10, 0x760d54-0x760d60) -> copy name/handle via 0x61c9bc
  (0x760d60) -> per-variant float stores (0x760d64-0x760da4) -> final primary
  vptr store (0x760da0, cell 0x130f1a0).
- Consumer: array builder 0x761020 calls the dispatcher 0x760b38 (0x761084)
  and stores the result into a slot array at [x20+0x10] (0x7610a0).
