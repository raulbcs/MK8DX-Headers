# object::Vt12d6ce8

PLACEHOLDER name (identity not proven). vptr 0x12d6ce8, 44 primary slots, typeinfo NULL (game-side). GOT cell 0x1311fb8 holds 0x12d6cd8 = vt-0x10, so the row address is the installed vptr (cell+0x10).

Member of a five-class layout-control family (see doc/object/Vt12d64f0.md). Factory key tested at 0x8efb24-0x8efb54 against the constant at 0xf07226 ("TouchDecide2" region of the layout-state string pool; exact full key unverified).

## Member notes

- [this+0x70] u8 zeroed, [this+0x71] u8 set to 1, [this+0x78] NULL — direct factory stores unique to this branch (0x8efc4c-0x8efc60).
- [this+0x28] — pointer to the embedded sub-object at +0x80 (store 0x8efc74).
- [this+0x80] — secondary vptr = 0x12d6ce8+0x180; [this+0x88] — back-pointer to the enclosing object (stp 0x8efc84).
- Slots 2-40 shared with the siblings (0x7343a0/0x739xxx); per-class overrides at slots 0 (0x74aa2c), 1 (0x8f0d84), 19 (0x74ab20), 23 (0x74aaac), 31 (0x74aa38), 41-43 (0x8f0e3c-0x8f0f1c).
- Secondary table (0x12d6e68, 13 slots, extent 0x68): slot 0 = 0x8f10e0, slot 1 = 0x8be97c, slots 2-12 shared (0x433740-0x4346c8).

## Construction / init order

- Factory branch 0x8efc24-0x8efc8c: operator-new 0x108 (0x8efc24-0x8efc2c), base ctor FUN_7100738d68(this) (0x8efc3c), base primary vptr from GOT cell 0x130eb78 into [this] (0x8efc40-0x8efc64), +0x70/+0x71/+0x78 stores, sub-object ctor 0x8f1328(this+0x80) (0x8efc68), then derived vptr 0x12d6ce8 and the secondary/back-pointer/[this+0x28] stores (0x8efc6c-0x8efc84).
- Common tail 0x8ef97c-0x8ef998 (via 0x8efc8c): 0x8bddf4(subobject, x21), then this->slot 31 (0xf8) with (x20, x21).
- Extent 0x108 is the exact operator-new size of the factory branch (size 0x108).
