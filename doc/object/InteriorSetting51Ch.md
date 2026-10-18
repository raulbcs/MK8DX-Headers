# object::InteriorSetting51Ch

PROVISIONAL name taken from the Japanese UI string the factory stores at
[this+0x10]: 0xf07b74 "インテリア（5.1ch）". Member of the 5-variant
interior-preset family created by dispatcher 0x760b38 (jump table 0xf72fe8);
this is enum case 1 (factory fragment 0x760c3c-0x760d10). Sibling mappings:
case 0 -> 0x12c1ad0 (stereo, unmapped), 2 -> 0x12c1a90 (4.1ch),
3 -> 0x12c19d0 (square), 4 -> 0x12c1a10 (wide). No RTTI (header slots
0x12c1a40/0x12c1a48 = 0). GOT cell 0x130f190 holds vptr-0x10 (0x12c1a40);
installed vptr = cell+0x10. Size 0x40 EXACT (operator new 0x40 at 0x760c44).

## Vtable layout (primary 0x12c1a50, 6 slots, 0x12c1a50-0x12c1a78)

- slot 0 (0x00) 0x760ed4: trivial dtor fragment (`ret`), family-shared.
- slot 1 (0x08) 0x760e9c: deleting-dtor fragment, tail `b operator delete`
  (0x60b470); row-unique trampoline.
- slot 2 (0x10) 0x75174c: thunk `add x0, x0, #8; b 0x61c9bc` - forwards to the
  secondary base subobject at this+0x8 (vtable 0x11ad210 via GOT cell
  0x12fae28).
- slot 3 (0x18) 0x760ea0: returns 1.
- slot 4 (0x20) 0x760ea8: returns 1.
- slot 5 (0x28) 0x760eb0: returns 1.
  (Getter triple (1,1,1) - the only all-ones row of the family; semantics
  unverified.)

## Member notes

- [this+0x8] void* - secondary-base vptr (vtable 0x11ad210), installed during
  construction before the final primary store.
- [this+0x10] const char* - display name, 0xf07b74.
- [this+0x18..0x3f] float coefficients (see header). Identical word set to the
  4.1ch row 0x12c1a90 (both factory fragments share the 0x760cf0 tail);
  semantics unverified.

## Construction / init order

- Factory fragment 0x760c3c-0x760d10: new 0x40 (0x760c44) -> temporary family
  vptr (GOT cell 0x130f180, vtable 0x12c1b10, 0x760c50-0x760c88) -> name copy
  via 0x61c9bc (0x760c88) -> per-variant float stores (0x760cf0-0x760d0c) ->
  final primary vptr store (0x760d04, cell 0x130f190).
- Consumer: array builder 0x761020 (dispatcher call at 0x761084). Additional
  primary-vptr reloads (destruction path or re-reads) at 0x7c561c, 0x7c5a70,
  0x7cef18, 0x7cf00c, 0x7d3530, 0x88016c (unverified bodies).
