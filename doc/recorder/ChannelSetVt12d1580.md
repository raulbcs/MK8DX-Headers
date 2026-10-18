# recorder::ChannelSetVt12d1580 (0x12d1580)

ChannelSet derivative — the "second" rot/trans channel set built by the kart
recorder setup path (distinct from recorder::ChannelSet 0x12c3ec8).

- Identity: 35 slots (0x12d1580..0x12d1698). No RTTI. GOT cell 0x1311280
  holds 0x12d1570 (vt-0x10); vptr = cell+0x10. Single code site 0x88ad68.
- Ctor: recorderCreateRotChannel_710088ad40(this, binder x1, kindTrans w2,
  kindRot w3) (csv W, 436 B). It first runs the ChannelSet base ctor
  recorderCreateRotTransChannels_71007ae16c(this, null, w2, w3) (vptr
  0x12c3ec8 + default children), then overrides the vptr with 0x12d1580.
- When binder (x1) is non-null it REPLACES the rot child: `new 0x290`
  (0x88ad88/0x88adb8), recorderBinderCtor_71007aae24, vptr from GOT cell
  0x1311290 (kindRot 0 → 0x12d18f8) or 0x1311288 (kindRot 1 → 0x12d1a20),
  token 4/6 at +0x1c4, numValues 36, min 0x1f0 = 0xc28f3cf5 (-70.0f),
  owner binder at +0x288, stored at [this+0x278]; likewise the trans child
  (`new 0x288`, cells 0x13112a0/0x1311298 → vptr 0x12d16a8 / 0x12d17d0) at
  [this+0x280]. Children are registered with recorderAddChannel_71007ac0cc
  ("rot" 0xf0a965 / "trans" 0xf0a969).
- Callers (all `new 0x288` then call): FUN_71001f12e8 (0x1f1368),
  FUN_7100252f54 (0x252ffc), recorderSetupKartChannels_71003aef8c (0x3af09c).
- Extent: 0x288 — all three factory allocations are exactly 0x288; deepest
  store is +0x280.

## Member notes

- +0x278/+0x280 — rot/trans children, same slots as the ChannelSet base; when
  binder arg is null the base-class children (RotChannel4/6, TransChannel4/6)
  remain in place.
- The child vtable rows 0x12d1698 / 0x12d17c0 / 0x12d18e8 / 0x12d1a10 (vptrs
  +0x10) are the sibling variant set of RotChannel4/6 + TransChannel4/6 for
  this set; not yet mapped (separate headers).
- slot2 = FUN_710088b26c (csv U, 616 B); slots 3-8 = 0x88b278..0x88b2b4
  (unrecovered). slot0/1 = 0x7aee48/0x7aef14 — the ChannelSet dtor pair (see
  doc/recorder/ChannelSet.md). Shared tail identical to ChannelSet (0x7ab904,
  0x7abca8, 0x7ac1d8, +0x80..+0xb0 accessor run, 0x7ac728, 0x7acd90,
  0x7ac020).

## Construction / init order

1. Factory allocates 0x288.
2. recorderCreateRotTransChannels_71007ae16c builds the ChannelSet base
   (default children per its kind args; see doc/recorder/ChannelSet.md).
3. vptr 0x12d1580 stored at [this] (0x88ad74).
4. If binder non-null: replacement rot/trans children are allocated, head-
   initialized, vptr'd from the 0x12d16xx/0x12d1axx family, defaulted, and
   stored at +0x278/+0x280.
