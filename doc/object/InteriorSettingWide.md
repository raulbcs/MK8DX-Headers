# object::InteriorSettingWide

PROVISIONAL name taken from the Japanese UI string the factory stores at
[this+0x10]: 0xf07b55 "インテリア（ワイド）" (Interior / Wide). Member of the
5-variant interior-preset family created by dispatcher 0x760b38 (jump table
0xf72fe8); this is enum case 4 (factory fragment 0x760dac-0x760e44). Sibling
mappings: case 0 -> 0x12c1ad0 (stereo, unmapped), 1 -> 0x12c1a50 (5.1ch),
2 -> 0x12c1a90 (4.1ch), 3 -> 0x12c19d0 (square). No RTTI (header slots
0x12c1a00/0x12c1a08 = 0). GOT cell 0x130f1a8 holds vptr-0x10 (0x12c1a00);
installed vptr = cell+0x10. Size 0x40 EXACT (operator new 0x40 at 0x760db4).

## Vtable layout (primary 0x12c1a10, 6 slots, 0x12c1a10-0x12c1a38)

- slot 0 (0x00) 0x760ed4: trivial dtor fragment (`ret`), family-shared.
- slot 1 (0x08) 0x760e80: deleting-dtor fragment, tail `b operator delete`
  (0x60b470); row-unique trampoline.
- slot 2 (0x10) 0x75174c: thunk `add x0, x0, #8; b 0x61c9bc` - forwards to the
  secondary base subobject at this+0x8 (vtable 0x11ad210 via GOT cell
  0x12fae28).
- slot 3 (0x18) 0x760e84: returns 0.
- slot 4 (0x20) 0x760e8c: returns 0.
- slot 5 (0x28) 0x760e94: returns 1.
  (Getter triple (0,0,1) - identical to the square row 0x12c19d0; semantics
  unverified.)

## Member notes

- [this+0x8] void* - secondary-base vptr (vtable 0x11ad210), installed during
  construction before the final primary store.
- [this+0x10] const char* - display name, 0xf07b55.
- [this+0x18..0x3f] float coefficients from movz/movk constants (see header
  comments); semantics unverified.

## Construction / init order

- Factory fragment 0x760dac-0x760e40: new 0x40 (0x760db4) -> temporary family
  vptr (GOT cell 0x130f180, vtable 0x12c1b10, 0x760dc8-0x760df4) -> name copy
  via 0x61c9bc (0x760df8) -> per-variant float stores (0x760e04-0x760e40) ->
  final primary vptr store (0x760e14, cell 0x130f1a8).
- Consumer: array builder 0x761020 (dispatcher call at 0x761084).
