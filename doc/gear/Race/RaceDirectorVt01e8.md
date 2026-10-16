# RaceDirectorVt01e8 (gear::RaceDirectorVt01e8)

- PROVISIONAL vtable-anchored name (vptr 0x12601e8, GOT cell 0x1307588). Far-family singleton: ctor 0x71003995d4 (cxa_guard getter in the same init region) runs ctor 0x71007b976c (RaceDirectorBase38) then its own fields. Extent 0x62 mapped; concrete size 0x68 (rounded to the 8-byte vptr alignment).

Naming: sole getter caller is the per-mode list-node dispatcher 0x398c00-0x398e98 (wired like RaceListItemE: +0x18 self, +0x28 &mgr+0x178, +0x30 [mgr+0x1a8]); the dispatcher never names it. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x38 — ctor zero; 0x3c unproven padding.
- 0x40/0x48 — ctor zero.
- 0x50 — ctor sets 4; 0x54 unproven padding.
- 0x58 — ctor zero.
- 0x60 — ctor sets 1; 0x61 — ctor zero.
- 0x62 — tail padding (extent 0x62). Total 0x68, binary extent 0x62.

## Construction / init order

1. Ctor 0x71003995d4 runs base ctor 0x71007b976c (RaceDirectorBase38).
2. Zeros at 0x38/0x40/0x48/0x58/0x61; 0x50 = 4; 0x60 = 1.

Sole getter caller: the per-mode list-node dispatcher 0x398c00-0x398e98 (wired like RaceListItemE: +0x18 self, +0x28 &mgr+0x178, +0x30 [mgr+0x1a8]).
