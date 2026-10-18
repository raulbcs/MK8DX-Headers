# object::Vt12d6af0

PLACEHOLDER name (identity not proven). vptr 0x12d6af0, 44 primary slots, typeinfo NULL (game-side). GOT cell 0x1311fb0 holds 0x12d6ae0 = vt-0x10, so the row address is the installed vptr (cell+0x10).

Member of a five-class layout-control family (see doc/object/Vt12d64f0.md). Factory key tested at 0x8efae8-0x8efb58 against the constant at 0xf07219 ("TouchOff2" region of the layout-state string pool; exact full key unverified).

## Member notes

- [this+0x28] — pointer to the embedded sub-object at +0x70 (factory store 0x8ef974 via the common tail path).
- [this+0x70] — secondary vptr = 0x12d6af0+0x180; [this+0x78] — back-pointer to the enclosing object (0x8efc18 jumps into the shared store block at 0x8ef964-0x8ef974).
- Slots 2-40 shared with the siblings (0x7343a0/0x739xxx); per-class overrides at slots 0 (0x73b9b4), 1 (0x8f09e0), 13/14/16/20 (0x73bab0-0x73bba8), 24 (0x73bb7c), 27/28 (0x73bc1c/0x73bc2c), 31 (0x738dac), 32 (0x73ba98), 40 (0x73b9c0), 41-43 (0x8f0a98-0x8f0b78).
- Secondary table (0x12d6c70, 13 slots, extent 0x68): slot 0 = 0x8f0d3c, slot 1 = 0x8be97c, slots 2-12 shared (0x433740-0x4346c8).

## Construction / init order

- Factory branch 0x8efbe0-0x8efc20: operator-new 0xf8 (0x8efbe0-0x8efbe8), base ctor FUN_7100738d68(this) (0x8efbf8), base primary vptr from GOT cell 0x130eb70 into [this] (0x8efbfc-0x8efc10), sub-object ctor 0x8f1328(this+0x70) (0x8efc14), then derived vptr 0x12d6af0 and the shared secondary/back-pointer/[this+0x28] stores (0x8efc1c-0x8ef974).
- Common tail 0x8ef97c-0x8ef998: 0x8bddf4(subobject, x21), then this->slot 31 (0xf8) with (x20, x21).
- Extent 0xf8 is the exact operator-new size of the factory branch (size 0xf8).
