# recorder::ChannelVt12d1208 (0x12d1208)

PLACEHOLDER name. Binder-derived recorder channel.

- Identity: 35 slots (0x12d1208..0x12d1320). No RTTI. GOT cell 0x13111d0
  holds 0x12d11f8 (vt-0x10); vptr = cell+0x10. Single code site 0x889834.
- Ctor: FUN_7100889814(this, x1, w2) — calls recorderBinderCtor_71007aae24
  (0x889830), stores x1 at +0x278, zeroes +0x280, stores w2&1 at +0x281, then
  installs the vptr at [this] (0x889848-0x88984c).
- Factory: call site 0x8dad58 allocates `new 0x288` (via 0x60b234, aligned 8;
  0x8dad3c) and stores the result at [owner+0x208]; the enclosing factory
  function is unrecovered (address 0x8dad58 lies in a csv gap).
- Extent: 0x288 — factory allocation is exactly 0x288 and deepest store is
  +0x281.

## Member notes

- +0x278 void* — ctor arg; the slot10 helper (0x889860) reads [x8+0x120] from
  it and calls 0x79c910(ptr, 1) when non-null, then sets +0x280 = 1.
- +0x280 uint8 — cleared by ctor, set by the slot10 close helper; slot14
  variant 0x88989c does the same only when [+0x278]+0x120 is null-guarded.
- +0x281 uint8 — ctor arg w2 & 1, unverified semantics.
- Slots 0/1 = 0x3a8a0c/0x3a8a7c (shared Binder pair per doc/recorder/BinderVt.md,
  presumed D2/D1). Slots 2-8 = 0x88a874..0x88a8bc own block (csv U). Slot10 =
  0x889860 (close helper), slot14 = 0x88989c, slot19 = 0x8898d0 — all absent
  from functions.csv. Shared tail slot9 0x7ab904, slot11 0x7ac1d8,
  slots 20-24 (0x1acd4/0xa13d0/0x1acf4/0xa1404/0x7ac728), slots 33/34
  0x7acd90/0x7ac020.

## Construction / init order

1. Factory allocates 0x288 and passes (obj, arg, flags) to FUN_7100889814.
2. recorderBinderCtor_71007aae24 initializes the Binder head (see
   doc/recorder/BinderVt.md "Construction").
3. Ctor stores arg x1 at +0x278, zeroes +0x280, writes w2&1 to +0x281.
4. vptr 0x12d1208 installed at [this] (0x889848).
5. Factory stores the object at [owner+0x208] (0x8dad5c).
