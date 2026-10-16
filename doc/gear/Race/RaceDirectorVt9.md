# RaceDirectorVt9 (RaceDirector-family director)

Overrides prepare/enter (slots 0x20/0x28) while keeping the shared calc/render/exit/isDirector/accept hooks — missed by the strict family signature, caught by the loose scan. Vtable .data 0x11b93f8 (GOT cell 0x12fcf40), ctor 0x7100107c3c, 0x228 bytes (allocation 0x398a9c: operator new[](0x228, nothrow)), spawned by the race job manager like RaceDirectorVt8 (count +0x1c0, list slot +0x250, owner back-ptrs +0x18/+0x28/+0x30).

## Fields

- 0x38 — zeroed on ctor; 0x3c unproven padding.
- 0x40/0x48/0x60/0x68 — zeroed on ctor.
- 0x50 — channel cell 0x12fcf48 (vptr, +0x10); 0x58 — cell 0x12fcf50.
- 0x70 — memset region start; ctor sets it.
- 0x78 — owned node set by the ctor.
- 0x80 — unproven padding.
- 0x88 — node array mNodes[12], 0x10 bytes each (init 0x60b930).
- 0x148 — unproven padding; 0x150-0x1bb — memset tail.
- 0x1bc — zeroed on ctor (str = 32-bit); 0x1c0 unproven padding.
- 0x1c4 — zeroed on ctor; 0x1c8/0x1cc unproven padding.
- 0x1d0 — member sub-object (ctor 0x628628), 0x40 bytes.
- 0x210/0x218 — zeroed on ctor.
- 0x220 — zeroed on ctor; 0x221 unproven padding.

## Construction / init order

1. Ctor 0x7100107c3c (allocation 0x398a9c: operator new[](0x228, nothrow)).
2. 0x38 = 0 (u32); 0x40/0x48/0x68 = 0; channel cells 0x50/0x58 (GOT 0x12fcf48/0x12fcf50 +0x10).
3. memset(this+0x70, 0, 0x14a) → 0x70..0x1ba.
4. Pointer set at 0x78.
5. Node array init (0x60b930, 0x10 bytes each) at 0x88..0x148.
6. Zeros at 0x1bc/0x1c4.
7. KartDirector-family member ctor 0x628628 on the sub-object at 0x1d0.
8. Zeros 0x210/0x218; byte 0x220 = 0.
