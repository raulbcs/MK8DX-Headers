# recorder::MatrixTransChannel6 (vtable 0x12d16a8)

## Identity

Quantized "trans" sub-channel (token size 6) of the recorder Matrix33f
decomposition path. 35 slots, no RTTI. Created only inside the matrix-channel
init 0x88ab18 (`new 0x288` at 0x88ae68, shared Binder head ctor 0x7aae24 at
0x88ae74, then vptr override at +0x00 from GOT cell 0x13112a0; the cell holds
0x12d1698 = vptr-0x10, so installed vptr = cell + 0x10 = 0x12d16a8) and
registered via recorderAddChannel_71007ac0cc(parent, ch, "trans") with the name
string at 0xf0a969 (call 0x88aebc).

Selected when the init's w21 selector is 0 (the Comp6 branch); the Comp4
sibling is MatrixTransChannel4 (0x12d17d0, w21 == 1). The paired "rot" channel
created just before is MatrixRotChannel4/6 (0x12d18f8 / 0x12d1a20, registered
under "rot" at 0xf0a965, call 0x88ae34). The parent object of the decomposition
is a stack-local channel whose ctor 0x7ae16c (= recorderCreateRotTransChannels,
see doc/recorder/RotChannel4.md) is re-vptr'd to row 0x12d1580 (cell
0x1311280) at 0x88ad68.

All slot addresses below are VMAs (functions.csv base 0x7100000000 must be
added); every slot is absent from functions.csv (unrecovered).

## Member notes

- 0x1c0 u32 = 12, 0x1c4 u32 = 6 (token size 6, Comp6 branch) - factory stores
  at 0x88ae94 / 0x88ae84 (0x88ae88: `orr w10, wzr, #0xc`).
- 0x1f0/0x1f4/0x1f8 float min/step/inv-step defaults written by the factory at
  0x88aed8 / 0x88aec8 / 0x88aecc: min = 0.2f (0x3e4cccd), step = 16.0f
  (0x41800000), inv-step = 0.0625f (0x3d800000).
- 0x278 zeroed at 0x88ae8c; 0x280 = factory arg (owning object, also stored to
  the parent at [x19+0x280], 0x88aea0). The +0x88 slot 0x88aef4 reads
  [this+0x280] and copies 3x u32 to [x1 + (s32)[this+0x1d4]].
- 0x288 = first qword stored by the factory (0x88ae9c, x20 = parent arg).

## Construction / init order

1. `ch = operator new(0x288)` (0x88ae68).
2. `recorderBinderCtor_71007aae24(ch)` (0x88ae74) - shared Binder head.
3. vptr override: `ch->mVtable = *(GOT cell 0x13112a0) + 0x10 = 0x12d16a8`
   (0x88ae7c/0x88ae98).
4. Field init: +0x278 = 0, +0x1c4 = 6, +0x1c0 = 12 (0x88ae8c..0x88ae94),
   +0x280 = owner arg, +0x288 = parent arg (0x88ae9c).
5. Owner registration: `recorderAddChannel_71007ac0cc(parent, ch, "trans")`
   (0x88aebc).
6. Post-init quantizer defaults: min/step/inv-step at 0x88aec0..0x88aee0.
