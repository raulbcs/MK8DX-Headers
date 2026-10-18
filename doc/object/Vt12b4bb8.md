# object::Vt12b4bb8

PLACEHOLDER name (theme unproven). vptr 0x12b4bb8, n=46, single vptr at offset +0x00. GOT cell 0x130dd00 -> 0x12b4ba8; code stores cell+0x10 (0x12b4bb8) into [this]. Sibling ARRAY-ELEMENT class of Vt12b4a38: allocated in the same factory, element size 0x248, vtable slots immediately following Vt12b4a38's cluster (0x682db0 onward).

Slots: 0x682db0, 0x682ed0 (dtor pair), 0x682f2c, 0x6832c8-0x683df0 cluster, interleaved 0x67ea88-0x67ff2c (46 total, all U).

Member notes (from the array-element init at 0x67b364-0x67b3b8): operator new[](0x248) at 0x67b378; vptr at element+0x00 (0x67b3a0); memset(element+8, 0, 0x240) (0x67b380-0x67b38c); member ctor 0x6461e4 on element+0x40 (0x67b39c/0x67b3a4); element+0x220 = 0 (0x67b3b4); stored into a manager array at [x21+0x30] (0x67b3b8) - the parallel slot to Vt12b4a38's [x21+0x28].

## Construction / init order

- Per element, same loop as Vt12b4a38: operator new[](0x248) at 0x67b378, memset +8 (0x240), vptr 0x12b4bb8 at +0x00 at 0x67b3a0, member ctor 0x6461e4 on +0x40, +0x220 = 0, stored to [manager+0x30].
- Destruction: slot +0x08 (0x682ed0).
