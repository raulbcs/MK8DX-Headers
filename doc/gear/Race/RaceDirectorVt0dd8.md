# RaceDirectorVt0dd8 (gear::RaceDirectorVt0dd8)

Derived of RaceDirectorVt8: ctor 0x3a16a8 calls 0x87d9b8 then swaps the vptr to 0x1260dd8. Same 0x168 size (alloc 0x398964 feeds the derived ctor; the derived ctor adds no fields).

## Construction / init order

1. Allocation 0x398964 (operator new[](0x168, nothrow)).
2. Ctor 0x3a16a8 calls 0x87d9b8 (RaceDirectorVt8 ctor), then swaps the vptr to 0x1260dd8.
