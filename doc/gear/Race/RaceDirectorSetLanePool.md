# RaceDirectorSetLanePool (gear::RaceDirectorSetLanePool)

- PROVISIONAL vtable-anchored name. Per-lane entry-pool manager of RaceDirectorPlayerSet: ctor 0x71000702e0 (Actor base), primary vtable 0x11b4980 (GOT 0x12fc010), secondary at +0x38 (0x11b4a00, GOT 0x12fc018). Size 0xA8 (factory alloc 0x6f380).

Holds three 0x30 entry pools; entries are {fn, ctx} callback pairs filled from GOT code cells (0x704a4/0x704b0/0x70508/0x705a4). Config (qword+2 dwords) copied from the rodata default [0xf57b7c] (dword +8 = -1 at +0x94).

Naming: entry-pool manager: {fn,ctx} callbacks from GOT code cells and rodata default [0xf57b7c]; behavior mapped, name not. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x38-0x3F — unproven padding.
- 0x40 — ctor sets 3 (pool count base); 0x41/0x42 — ctor zero; 0x43 unproven padding.
- 0x44 — ctor zero.
- 0x48 — self pointer.
- 0x50/0x58/0x60 — alloc(0x30) entry pools.
- 0x68 — ctor zero.
- 0x70 — ctor arg x1 (owner).
- 0x78 — unproven padding.
- 0x88 — *(u64*)[0xf57b7c]; 0x90 — *(u32*)([0xf57b7c]+8); 0x94 — ctor -1.
- 0x98 — ctor zero; 0x9C — ctor zero; 0xA0-0xA7 — unproven padding.

## Construction / init order

1. Ctor 0x71000702e0 with the Actor base; primary vtable 0x11b4980, secondary vptr at +0x38 (0x11b4a00).
2. 0x40 = 3; zeros at 0x41/0x42/0x44/0x68/0x98/0x9C.
3. Self pointer at 0x48; three alloc(0x30) entry pools at 0x50/0x58/0x60, filled with {fn, ctx} pairs from GOT code cells 0x704a4/0x704b0/0x70508/0x705a4.
4. Owner (arg x1) at 0x70.
5. Config copied from rodata default [0xf57b7c]: 0x88 = *(u64*), 0x90 = *(u32*)(+8); 0x94 = -1.
6. Factory allocation 0x6f380 (0xA8); stored at RaceDirectorPlayerSet+0xB0.
