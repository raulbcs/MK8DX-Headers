# RaceDirectorVt3240 (gear::RaceDirectorVt3240)

- PROVISIONAL vtable-anchored name (vptr written by the ctor from cell 0x12fb038; .data 0x1283240). Far-family director, 24 slots. Ctor 0x501c54, size 0x138 (alloc 0x398e24: new 0x138).

Base: RaceDirectorBase38 (ctor 0x7b976c).

Naming: consumer proven: ctor 0x501c54 is the mode-id-4 branch of the per-mode list-node dispatcher 0x398c00-0x398e98 (new 0x138 at 0x398e28, wired to mgr+0x178/+0x1b0 like RaceListItemE); the dispatcher never names it. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x38 — ctor zero; 0x3c unproven padding.
- 0x40/0x48 — u64 ctor zero.
- 0x50..0x7f — untouched by the ctor (unproven gap).
- 0x80/0x88/0x90/0x98/0xa0 — u64 ctor zero.
- 0xa8 — u32 ctor zero; 0xac — s32 = -1.
- 0xb0 — u64 ctor zero.
- 0xb8 — ptr = vtable cell 0x12fb038 (+0x10), vptr-shaped.
- 0xc0 — u64 ctor zero; 0xc8 — u8 = 0; 0xc9 unproven padding.
- 0xd0/0xd8/0xe0 — u64 ctor zero.
- 0xe8 — sub-object, 0x34 bytes (vptr from cell 0x12fd480, init 0x7c355c with 1.0f / -10.0f stack args).
- 0x11c — u64 ctor zero; 0x124 unproven gap.
- 0x128 — u32 = 12; 0x12c — u32 = 0; 0x130 — u16 = 0; 0x132 — u8 = 0; 0x133 unproven padding.
- 0x134 — s32 = -150.

## Construction / init order

1. Ctor 0x501c54; base ctor 0x7b976c (RaceDirectorBase38).
2. Zeros at 0x38/0x40/0x48/0x80/0x88/0x90/0x98/0xa0/0xa8/0xb0/0xc0/0xc8/0xd0/0xd8/0xe0/0x11c/0x12c/0x130/0x132.
3. 0xac = -1; 0xb8 = vtable cell 0x12fb038 (+0x10).
4. Sub-object at 0xe8: vptr from cell 0x12fd480, init 0x7c355c (1.0f / -10.0f stack args).
5. 0x128 = 12; 0x134 = -150.
6. Allocation 0x398e24 (new 0x138) inside the per-mode list-node dispatcher 0x398c00-0x398e98 (new at 0x398e28; wired to mgr+0x178/+0x1b0 like RaceListItemE).
