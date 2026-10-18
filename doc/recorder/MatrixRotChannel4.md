# recorder::MatrixRotChannel4 (vtable 0x12d18f8)

## Identity

Quantized "rot" sub-channel (token size 4) of the recorder Matrix33f
decomposition path. 35 slots, no RTTI. Created only inside the matrix-channel
init 0x88ab18 (`new 0x290` at 0x88adb8, Binder head ctor 0x7aae24 at 0x88adc4,
vptr override at +0x00 from GOT cell 0x1311290; cell holds 0x12d18e8 =
vptr-0x10, installed vptr = cell + 0x10 = 0x12d18f8) and registered via
recorderAddChannel_71007ac0cc(parent, ch, "rot"), name string 0xf0a965
(call 0x88ae34).

Selected when the init's w22 selector is 1 (Comp4 branch, 4-byte tokens); the
Comp6 sibling is MatrixRotChannel6 (0x12d1a20, w22 == 0). The parent context
(stack-local parent re-vptr'd to 0x12d1580) is documented in
doc/recorder/MatrixTransChannel6.md.

## Member notes

- 0x1c0 u32 = 36 (0x24), 0x1c4 u32 = 4 - factory stores 0x88ae0c / 0x88ade0;
  matches the RotChannel4 value-count convention (9x u32 writers).
- 0x1f0 u32 = 0xc28f3cf5 (~-70.97f) at 0x88aeec..0x88aef4; 0x1f4/0x1f8 loaded
  from literals 0xed6860 / 0xed685c (0x88addc / 0x88add4).
- 0x278/0x280 zeroed (0x88adfc/0x88ae08); 0x288 = factory arg x20 (owner,
  stored to the parent group at [x19+0x278], 0x88ae14).
- +0x88 slot 0x88af44 copies 6x u32 from [this+0x288]; slots 26/27
  (0x7adbec/0x7adca4) match the rot write-path pair documented in
  doc/recorder/RotChannel4.md (+0x190/+0x1a0 there).
- All slot addresses are VMAs; every slot absent from functions.csv.

## Construction / init order

1. `ch = operator new(0x290)` (0x88adb8).
2. `recorderBinderCtor_71007aae24(ch)` (0x88adc4).
3. vptr override from GOT cell 0x1311290 (+0x10) = 0x12d18f8 (0x88add0/0x88ae10).
4. Field init: +0x1c4 = 4, +0x1c0 = 36, +0x278/0x280 = 0, +0x1f0..+0x1f8
   quantizer floats, +0x288 = owner arg (0x88ade0..0x88ae14).
5. Owner registration: `recorderAddChannel_71007ac0cc(parent, ch, "rot")`
   (0x88ae34).
