# object::RaceCheckerVt2

Checker-family sibling of RaceKartChecker: vtable .data 0x12d0d18 (GOT cell 0x1311118), ctor 0x7100881bb0. Direct construction sites allocate 0x118 bytes (operator new[](0x118, nothrow) at 0x3a206c and 0x3a2088; five further ctor wrappers receive pre-allocated this), call the RaceKartChecker ctor 0x710087ffd0 first, then swap the vptr.

Custom-RTTI id 10 (getTypeId10_7100881868, `mov w0,#0xa; ret`) is UNIQUE to this vtable — a distinct concrete type.

Ctor field writes: 0xb8 = 0x71135d94c (rw-data buffer cell), 0xc8-0xd8 and 0x10c/0x110 zeroed. The family method at 0x881c00 (calls enter body 0x8802f4, reads flag 0x99) then invokes vtable slots 0xd8 and 0x110 and reads fields 0xc0/0xd8/0x110.

## Construction / init order

1. Allocation 0x3a206c / 0x3a2088: operator new[](0x118, nothrow); five further ctor wrappers receive pre-allocated this.
2. RaceKartChecker ctor 0x710087ffd0 runs first.
3. Ctor 0x7100881bb0: vptr swap to 0x12d0d18; 0xb8 = 0x71135d94c; zero 0xc8-0xd8, 0x10c/0x110.
