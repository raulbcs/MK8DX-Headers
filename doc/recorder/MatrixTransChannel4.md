# recorder::MatrixTransChannel4 (vtable 0x12d17d0)

## Identity

Quantized "trans" sub-channel (token size 4) of the recorder Matrix33f
decomposition path. 35 slots, no RTTI. Created only inside the matrix-channel
init 0x88ab18 (`new 0x288` at 0x88ae44, Binder head ctor 0x7aae24 at 0x88ae50,
vptr override at +0x00 from GOT cell 0x1311298; cell holds 0x12d17c0 =
vptr-0x10, installed vptr = cell + 0x10 = 0x12d17d0) and registered via
recorderAddChannel_71007ac0cc(parent, ch, "trans"), name string 0xf0a969
(call 0x88aebc).

Selected when the init's w21 selector is 1 (Comp4 branch); Comp6 sibling is
MatrixTransChannel6 (0x12d16a8). Same factory and parent context as documented
in doc/recorder/MatrixTransChannel6.md.

## Member notes

- 0x1c0 u32 = 12, 0x1c4 u32 = 4 (token size 4) - stores at 0x88ae90/0x88ae88
  and 0x88ae60 (Comp4 branch).
- 0x1f0/0x1f4/0x1f8 quantizer defaults identical to the Comp6 sibling
  (0x88aed8/0x88aec8/0x88aecc).
- 0x278 zeroed; 0x280 = owner arg; 0x288 = parent arg (0x88ae8c..0x88ae9c).
- +0x88 slot 0x88af1c reads [this+0x280]; slots 20-23 (0x1acd4/0x7b45a4/
  0x1acf4/0x7b462c) match the RotChannel4/6 override set documented in
  doc/recorder/RotChannel4.md.
- All slot addresses are VMAs; every slot absent from functions.csv.

## Construction / init order

1. `ch = operator new(0x288)` (0x88ae44).
2. `recorderBinderCtor_71007aae24(ch)` (0x88ae50).
3. vptr override from GOT cell 0x1311298 (+0x10) = 0x12d17d0 (0x88ae58/0x88ae98).
4. Field init: +0x278 = 0, +0x1c4 = 4, +0x1c0 = 12, +0x280 = owner,
   +0x288 = parent arg (0x88ae60..0x88ae9c).
5. `recorderAddChannel_71007ac0cc(parent, ch, "trans")` (0x88aebc).
6. Quantizer defaults min/step/inv-step (0x88aec0..0x88aee0).
