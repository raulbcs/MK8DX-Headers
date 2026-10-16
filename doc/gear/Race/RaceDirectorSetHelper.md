# RaceDirectorSetHelper (gear::RaceDirectorSetHelper)

- PROVISIONAL vtable-anchored name. 0x40-byte helper bound to RaceDirectorPlayerSet: ctor 0x71000689c8 (minimal base 0x7c2920), vtable 0x11b4408 (GOT 0x12fbf40). Stored at set+0x50.

Naming: 0x40 helper ctor 0x689c8 off minimal base 0x7c2920, stored at set+0x50; no binary name. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x00 — vtable.
- 0x08/0x0C — ctor zero.
- 0x10/0x18 — ctor zero.
- 0x20 — ctor arg x1 (the PlayerSet).
- 0x28/0x30/0x38 — ctor zero; 0x34 unproven padding.

## Construction / init order

1. Ctor 0x71000689c8 (minimal base 0x7c2920); vtable 0x11b4408.
2. Zeros at 0x08/0x0C/0x10/0x18/0x28/0x30/0x38; owner (arg x1) at +0x20. Store reach 0x3c.
3. Stored at RaceDirectorPlayerSet+0x50 (new(0x40)).
