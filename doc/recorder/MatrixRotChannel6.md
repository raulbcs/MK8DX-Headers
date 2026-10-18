# recorder::MatrixRotChannel6 (vtable 0x12d1a20)

## Identity

Quantized "rot" sub-channel (token size 6) of the recorder Matrix33f
decomposition path. 35 slots, no RTTI. Created only inside the matrix-channel
init 0x88ab18 (`new 0x290` at 0x88ad88, Binder head ctor 0x7aae24 at 0x88ad94,
vptr override at +0x00 from GOT cell 0x1311288; cell holds 0x12d1a10 =
vptr-0x10, installed vptr = cell + 0x10 = 0x12d1a20) and registered via
recorderAddChannel_71007ac0cc(parent, ch, "rot"), name string 0xf0a965
(call 0x88ae34).

Selected when the init's w22 selector is 0 (Comp6 branch); the Comp4 sibling
is MatrixRotChannel4 (0x12d18f8, w22 == 1). Parent context documented in
doc/recorder/MatrixTransChannel6.md.

## Member notes

- 0x1c0 u32 = 36 (0x24), 0x1c4 u32 = 6 - factory stores 0x88ae0c / 0x88adb0.
- 0x1f0 = 0xc28f3cf5 (~-70.97f); 0x1f4/0x1f8 from literals 0xed6858 / 0xed6854
  (0x88adac / 0x88ada4) - different literal pair than the Comp4 sibling.
- 0x278/0x280 zeroed; 0x288 = owner arg (stored to the parent group at
  [x19+0x278], 0x88ae14).
- +0x88 slot 0x88af9c copies 6x u32 from [this+0x288] to
  [x1 + (s32)[this+0x1d4]].
- All slot addresses are VMAs; every slot absent from functions.csv.

## Construction / init order

1. `ch = operator new(0x290)` (0x88ad88).
2. `recorderBinderCtor_71007aae24(ch)` (0x88ad94).
3. vptr override from GOT cell 0x1311288 (+0x10) = 0x12d1a20 (0x88ada0/0x88ae10).
4. Field init: +0x1c4 = 6, +0x1c0 = 36, quantizer floats, +0x278/0x280 = 0,
   +0x288 = owner arg (0x88adb0..0x88ae14).
5. `recorderAddChannel_71007ac0cc(parent, ch, "rot")` (0x88ae34).
