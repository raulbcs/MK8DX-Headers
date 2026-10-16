# RaceDirectorVt10 (RaceDirector-family director)

Overrides prepare/enter (slots 0x20-0x30 range) while keeping the shared calc/render/exit/isDirector/accept hooks. Vtable .data 0x12d08a8 (GOT cell 0x1311070), ctor 0x7100878ecc, 0x238 bytes (allocation 0x8bc884: operator new[](0x238, nothrow); back-ptr at +0x18 stored by the creator in the 0x8bcxxx race region).

## Fields

- 0x38 — zeroed on ctor; 0x3c unproven padding.
- 0x40/0x48/0x50/0x58 — zeroed on ctor.
- 0x60 — 0x10-stride init block (0x60b918), 0x30 bytes.
- 0x90 — zeroed on ctor; 0x94 unproven padding.
- 0x9c/0xa4/0xac — -1 on ctor; 0xa0/0xa8 unproven padding.
- 0xb0 — unproven padding.
- 0x114 — 0 on ctor; 0x115 — 1 on ctor; 0x116 unproven padding.
- 0x118-0x120 — zeros on ctor.
- 0x124 — to end (0x238), unproven.

The 0x60..0x124 interior is structured (two 0x10-stride init blocks) but only the scalar writes above are ctor-proven.

## Construction / init order

1. Ctor 0x7100878ecc (allocation 0x8bc884: operator new[](0x238, nothrow); back-ptr at +0x18 stored by the creator in the 0x8bcxxx race region).
2. 0x38 = 0 (u32); 0x40/0x48/0x50/0x58 = 0.
3. Block inits via 0x60b918(x0, 0x10, x0+0x10) at 0x50 and 0xe8.
4. 0x90 = 0; -1 words at 0x9c/0xa4/0xac; bytes 0x114 = 0 / 0x115 = 1; zeros 0x118-0x120.
