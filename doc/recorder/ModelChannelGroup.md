# recorder::ModelChannelGroup (vtable 0x12d1b48)

## Identity

Per-model recorder channel group: a 0x298-byte Binder-head object that holds up
to four pre-built channel pointers and conditionally spawns additional
sub-channels at construction. 35 slots, no RTTI.

Ctor 0x88b76c: calls the shared Binder head ctor 0x7aae24, then overrides the
primary vptr at +0x00 from GOT cell 0x1311398 (cell holds 0x12d1b38 =
vptr-0x10; installed vptr = cell + 0x10 = 0x12d1b48), copies the four
param pointers [x1+0x00/0x08/0x10/0x18] to +0x278/+0x280/+0x288/+0x290, then
per enable flags:
- byte +0x296 != 0: calls 0x7ab40c(this, 0)
- byte +0x294 != 0: calls 0x7ab1b8(this, 0) then `new 0x288` + Binder head +
  vptr override from cell 0x13113a0 (row 0x12d1d98, unassigned) and registers
  it nameless via recorderAddChannel_71007ac0cc(this, ch, 0) (0x88b828)
- byte +0x291 != 0: `new 0x288`, vptr from cell 0x13113a8 (row 0x12d1eb0),
  quantizer floats at +0x1f0 (0x3c23d70a ~ 0.01), +0x1f4 = 0x3c800000,
  +0x1f8 = 0x42800000; registered nameless (0x88b894)
- byte +0x292 != 0: `new 0x290` with either cell 0x13113b0 (row 0x12d2238,
  token 6) or cell 0x13113b8 (row 0x12d2110, token 4) per byte +0x295;
  registered nameless (0x88b95c)
- byte +0x293 != 0: `new 0x288`, vptr from cell 0x13113c0 (row 0x12d1fe8),
  token 6 (0x88b9b0)
- if [this+0x280] != 0: builds a stack param from [this+0x280], +0x288/+0x28c
  and byte +0x290, then `new 0x2e0` + folded ctor 0x7b100c + vptr override to
  0x12d1c70 (= ModelMatrixChannel, see below) and registers it nameless
  (0x88ba14).

External factories: 0x88e23c (`mov w0, #0x298` at 0x88e250, ctor call
0x88e260) and the actor-side site at 0x3567dc..0x3567e8 (stores the rodata
string "TS_PrisonSwitch" @0xee35b8 into the fresh object at +0x208 before/after
the ctor call - caller-side field, not part of this class's ctor).

All slot addresses are VMAs (add 0x7100000000); every slot is absent from
functions.csv (unrecovered).

## Member notes

- +0x278/+0x280/+0x288: channel pointers from the init param; +0x280 gates the
  ModelMatrixChannel child. +0x290 holds the param qword [x1+0x18] whose bytes
  +0x291..+0x296 double as the six enable flags consumed by the ctor (unverified
  split between pointer/value semantics).
- Slots 16-19 use the recorderChannelFlag0/recorderNoop set shared with
  ChannelSet (doc/recorder/ChannelSet.md); slots 9-11 are the shared Binder
  interface trio.
- +0x60 slot 0x88ba2c reads [this+0x278] (first channel pointer).

## Construction / init order

1. Caller: `ch = operator new(0x298)` (0x88e254 or 0x3567dc).
2. `recorderBinderCtor_71007aae24(ch)` then vptr override from GOT cell
   0x1311398 (+0x10) = 0x12d1b48 (ctor 0x88b76c, 0x88b788/0x88b798).
3. Copy param pointers to +0x278..+0x290 (0x88b79c..0x88b7b8).
4. Conditional sub-channel creation per flags +0x291..+0x296 (0x88b7bc..),
   each child Binder-headed, vptr-overridden and registered nameless.
5. Conditional ModelMatrixChannel (0x2e0) child when +0x280 != 0 (0x88b9b4..).
