# RaceListItemF (gear::RaceListItemF)

- PROVISIONAL vtable-anchored name ("F"). Manager list item of the far race family (same wiring pattern as D/E; base chain 0x7d5450, NOT Actor). Vtable 0x11b8ab8 (GOT 0x12fcca8). Ctor 0x71000c9e04; size 0x198, proven by the allocation site 0x71003de7c4. Note: its typeinfo cell is unreliable (points at unrelated code).

Naming: same wiring pattern, base chain 0x7d5450; typeinfo cell unreliable (points at unrelated code); no name. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x00 — vtable ptr.
- 0x08-0x183 — unproven padding.
- 0x184/0x188/0x194 — ctor zero.
- 0x190 — ctor sets 0x21C.
- 0x18C — unproven gap.

## Construction / init order

1. Allocation 0x71003de7c4 (0x198).
2. Ctor 0x71000c9e04 (base chain 0x7d5450 = RaceDirectorVt7e38); vtable 0x11b8ab8.
3. Zeros at 0x184/0x188/0x194; 0x190 = 0x21C.
