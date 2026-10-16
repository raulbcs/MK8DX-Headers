# RaceDirector (gear::RaceDirector)

- vtable .data 0x11b2f28 (GOT cell 0x12fbc58); concrete size 0x90 — the 0x6f244 factory news[] it directly.

RaceDirector walks an element array every frame (calc) and tears it down (exit). The element count/array live at 0x38/0x40; the race checkers and the lap rank checker are installed at 0x50/0x58.

Slot facts (vtable 0x11b2f28, default impls shared by derived directors):
- slot 0xa8 is a no-op returning void; slot 0xc0 returns the 32-bit word at *sCell12fbc10 (isolated singleton pointer cell, .orig_bss_iso; no writer for the cell in this binary — derived directors override it with getters of their own 0xB8-0xC4 config words); slot 0xc8 returns 0.
- Slots 0xa8/0xc0/0xc8 are not declared in the header.
- Signatures match the 4.0.0 binary. Slots 0x00/0x08 return bool / const sead::RuntimeTypeInfo::Interface*.

Slots beyond Actor's vtable; each stage of enter/calc/exit fires a pre/post hook pair. slot70/78/A0/A8 are still unnamed.

## Fields

- 0x38 mActorCount — Actor element count for calc/exit/enter (ctor: 3 after the child array allocation succeeds).
- 0x3C — unproven gap.
- 0x40 mActors — Actor array walked by calc/exit/enter (ctor allocs 0x18 = 3 slots, 0x4d818-0x4d830).
- 0x48 — unproven padding.
- 0x4C mInsertCursor4C — child insertion cursor: ctor registers each created child at mActors[cursor] and increments (0x4d8e8-0x4d9b8).
- 0x50 mRaceCheckerBase — ctor arg x1 (0x4d808).
- 0x58 mLapRankChecker.
- 0x60 mSubActor60 — new(0xB0), ctor 0x7100066448 (gear/Race/RaceDirectorSubActor60.hpp, vtable 0x11b41c8), registered as child.
- 0x68 mSubActor68 — new(0x1C8), ctor 0x71000490fc (vtable [0x12fbc00]+0x10; u16 +0x40 and byte +0x42 zeroed), registered.
- 0x70 mSubActor70 — new(0x160), ctor 0x710005c7f0 (vtable [0x12fbdb0]+0x10; bytes +0x41/+0x42 zeroed), registered.
- 0x78 — gap: ctor writes nothing here.
- 0x80 mConfig80 — new(0x2C), ctor 0x71000585e8: five u32s + flag byte copied from the default block [0x12fb168].
- 0x88 mConfig88 — second 0x2C config object, same ctor 0x71000585e8.

Class ends at 0x90: derived RaceDirectorVt2 is 0xA0 with fields only at 0x90-0x9F (allocation proof 0x710006f108).

## Construction / init order

Ctor entry address not separately labeled; the following store/allocation sequence is proven, in binary order:

1. ctor arg x1 -> mRaceCheckerBase (0x50) at 0x4d808.
2. mActors (0x40) allocation: 0x18 = 3 slots, 0x4d818-0x4d830; mActorCount (0x38) = 3 after it succeeds.
3. Child registration loop through mInsertCursor4C (0x4C): 0x4d8e8-0x4d9b8.
4. mSubActor60 (0x60): new(0xB0), ctor 0x7100066448, registered as child.
5. mSubActor68 (0x68): new(0x1C8), ctor 0x71000490fc, registered.
6. mSubActor70 (0x70): new(0x160), ctor 0x710005c7f0, registered.
7. mConfig80 (0x80): new(0x2C), ctor 0x71000585e8 (copy from default block [0x12fb168]).
8. mConfig88 (0x88): second 0x2C config object, same ctor 0x71000585e8.
