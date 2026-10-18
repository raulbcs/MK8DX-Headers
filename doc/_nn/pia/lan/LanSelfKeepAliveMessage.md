# nn::pia::lan::LanSelfKeepAliveMessage

Identity: typeinfo-row vtable, assigned address 0x12dd520 (= typeinfo slot,
vptr-8); installed vptr **0x12dd528**. GOT cell 0x1313670 holds vptr-0x10
(0x12dd518 = offset-to-top 0). Typeinfo data 0x12dd610, name
"N2nn3pia3lan23LanSelfKeepAliveMessageE", base typeinfo 0x12dd570
("N2nn3pia3lan10LanMessageE"). 6 slots (0x12dd528..0x12dd550).

## Member notes

- Slots 0/4 0x97da50/0x97da48: `ret` stubs (slot0 shared with base
  LanMessage row 0x12dd3e8). Slot1 0x97da44: returns 0xc (message size).
- Slot2 0x97d910: serialize-style builder; payload pointer arrives in x8,
  builds with constant 0xc0710000. Unverified semantics.
- Slot3 0x97d96c: byte-loop parser over x1. Unverified semantics.
- Slot5 0x97cf70: destructor-path — re-installs the base LanMessage vptr
  via GOT cell 0x1313650 (= 0x12dd3e8-0x10).
- [this+0x8] u32 — C2 zeroes it, then sets 7.
- [this+0xc..0x16] — 0xb-byte buffer zeroed by C2 memset.

## Construction / init order

1. C2 FUN_710097d8b8 (0x97d8b8..0x97d90c): inlined base init — [this+8]=0,
   vptr 0x12dd3e8 = cell 0x1313650 + 0x10, memset(this+0xc, 0, 0xb);
   then vptr 0x12dd528 = cell 0x1313670 + 0x10, [this+8] = 7.
2. Both call sites (0x970800, 0x971988) construct in-place on the stack;
   no operator-new factory found. Extent 0x18 is a lower bound from the
   +0x16 last store.
