# object::Vt12cc3a8

Placeholder name (identity not proven); behavior is an append-only write buffer. vptr 0x12cc3a8, 6 slots, typeinfo NULL (RTTI-less). GOT cell 0x13109a8 holds 0x12cc398 = vt-0x10 (installed vptr = cell+0x10).

## Member notes

- size 0x28, exact — operator new(0x28) at 0x834DE0; result stored to owner+0xA0 (0x834E00).
- Slot 3 (0x834A20): `set(x1, w2)` — [this+8]=x1, [this+0x10]=w2, [this+0x14]=0.
- Slot 4 (0x834A2C): `append(x1 data, w2 size)` returns bool — bounds [this+0x14]+size against [this+0x20] and [this+0x10]; memcpy into [this+0x18]+[this+0x14] (0x834A78-0x834AA4); one branch resets the write position to [this+0x20] (full) and returns 0, the other advances it and returns 1.
- Slot 5 (0x834A14): `setBuffer(x1, w2)` — [this+0x18]=x1, [this+0x20]=w2.
- Slots 0/2 = 0x83660C/0x836614 `ret`; slot 1 = 0x836610 deleting dtor (tail `b operator delete`, no field teardown).

## Construction / init order

- Constructed inline in the owner setup at 0x834DE0-0x834E00: zero [this+0x20], [this+0x10], [this+0x18], [this+8]; install vptr 0x12cc3a8 at [this]; store to owner+0xA0.
- A sibling 0x18-byte object with vptr from cell 0x13109b0 is created immediately after (owner+0xA8); that row is not in the assigned set.
