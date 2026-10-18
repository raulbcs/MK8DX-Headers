# recorder::ChannelVt12d0f70 (0x12d0f70)

PLACEHOLDER name. Binder-family recorder channel built inline by
FUN_7100883158 (948 B, unrecovered) — it has no dedicated constructor.

- Identity: 80 slots (0x12d0f70..0x12d12f8 incl. two MI secondary sections).
  No RTTI (offset-to-top/typeinfo 0). GOT cell 0x1311138 holds 0x12d0f60
  (vt-0x10); vptr = cell+0x10. Single code site: adrp/ldr at 0x8832d4 inside
  FUN_7100883158, vptr stored to [obj] at 0x8833a8 / 0x8833e4.
- Construction: FUN_7100883158 `new`s each object, calls
  recorderBinderCtor_71007aae24, stores the vptr manually, sets
  +0x278 = descriptor pointer into its array at [x19+0x48] (entries used at
  +0x18/+0x1a/+0x28), sets +0x1c0 from a constant table pointer, then
  registers via recorderAddChannel_71007ac0cc (name string 0xf0ccf0). A third
  variant in the same loop installs the SDK-region table 0x11fa5d0
  (cell 0x1301478) instead — unverified whether that row is a game vtable.
- Extent: deepest store is +0x278; Binder head is 0x288, so size 0x288.
  No allocation beyond Binder fields observed.

## Member notes

- 0x278 void* — per-channel descriptor pointer (data, offset within the
  caller's array varies: +0x18/+0x1a/+0x28), unverified format.
- Slots 0-8 (0x8859fc..0x885bc0) and 16-19/25 (0x885bcc..0x885c04) are this
  class's own block; slots 0/1 (0x8859fc/0x885b1c) are the presumed D2/D1
  pair, both absent from functions.csv (unrecovered).
- Shared channel tail: slot9 0x7ab904, slot10 0x7abca8, slot11 0x7ac1d8,
  slot12 0x1ac84, slots 20-23 (0x1acd4/0xa13d0/0x1acf4/0xa1404),
  slot24 0x7ac728, slots 33/34 0x7acd90/0x7ac020 — same set as
  doc/recorder/BinderVt.md.
- Slots 37-80 form a second section (zeros at slots 35/36, 51/52, 71-76 as
  MI separators): own block 0x888xxx/0x889xxx plus repeats of the shared tail
  (0x7b97xx, 0x7a26c) — secondary-interface tables, unverified mapping.

## Construction / init order

1. FUN_7100883158 allocates the object (operator new, 0x8833b4 region).
2. recorderBinderCtor_71007aae24 initializes the Binder head (0x88338c).
3. vptr 0x12d0f70 stored at [obj] (0x8833a8; second instance 0x8833e4).
4. +0x278 = descriptor pointer, +0x1c0 = table pointer (0x8833a0/0x8833a4).
5. recorderAddChannel_71007ac0cc registers the channel (0x8833ac/0x8833f0).
