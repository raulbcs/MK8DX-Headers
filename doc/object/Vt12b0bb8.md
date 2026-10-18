# object::Vt12b0bb8

PLACEHOLDER name (identity not proven; no RTTI — offset-to-top and typeinfo slots both 0). Plain vptr row at 0x12b0bb8; GOT cell 0x130d470 holds vt-0x10 (0x12b0ba8). 20 slots (vt+0x00..vt+0x128). Derived from Vt12b0b18: shares the base tail (slots 3/4/5/6/10/12/13/14/15 identical) and its object is finalized by installing this vptr and storing a delegate at +0xf8.

Size: unverified lower bound 0x100 (the +0xf8 field store in 0x629270); no allocation site proves the exact size. The base class is 0xf8 (alloc at 0x62918c).

## Member notes

- [this+0x08..0xf7] — Vt12b0b18 base layout (see doc/object/Vt12b0b18.md).
- [this+0xf8] void* — delegate target captured by override-ctor 0x629270 (its x2); slot16 dispatches through it: 0x6292ec loads [this+0xf8], reads [[target]] slot0 and tail-calls it with (target, this, arg).

Slot map (unrecovered in functions.csv): slot0 D1 0x6292c4 (tail-call base dtor 0x628dfc), slot1 D0 0x6292c8 (base dtor then operator delete 0x60b470); slot2 0x3dcf30; slots3/4/5/6/10/12/13/14/15 identical to Vt12b0b18 (0x629434, 0x629464, 0x3dcf3c, 0x628f3c, 0x6294cc, 0x628ff0, 0x3dcf54, 0x3dcf5c, 0x62942c); slot7 0x629480, slot8 0x628f8c, slot9 0x3dcf44, slot11 0x628fd0 (derived-only overrides), slot16 0x6292ec (delegate dispatcher), slot17 0x628fc8.

## Construction / init order

- Override-ctor 0x629270 (a virtual entry that finalizes construction): forwards the variadic argument list to base implementation 0x628a54, then stores x2 at [this+0xf8] and installs this vtable (cell 0x130d470). This is the "derived engine node overrides vptr" pattern — no separate C1 was found.
- The only external GOT-cell user is 0xab0970 (ldr cell 0x130d470); base-cell users: 0x648aec/0x648db4 and 0xa9c844.
- D1/D0 delegate to base dtor 0x628dfc.
