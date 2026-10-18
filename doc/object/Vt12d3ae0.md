# object::Vt12d3ae0

PLACEHOLDER name (identity not proven). vptr 0x12d3ae0, 10 slots, typeinfo NULL (game-side; row 0x12d3ae0 has no offset-to-top/typeinfo header — the row itself is the installed vptr). GOT cell 0x1311860 holds 0x12d3ae0-0x10; init stores cell+0x10 into [sub+0].

One of six sibling keyed-entry classes (Vt12d3900, Vt12d3960, Vt12d3a80, Vt12d39c0, Vt12d3a20, Vt12d3ae0) that appear as in-place-constructed member subobjects of a 0xC78-size base object; the base is initialized by FUN_71008a12f0 (0x8a12f0-0x8a1e98), which FUN_71003d8718 (0x3d8718) calls 14 times as the base-subobject ctor of 14 heap objects of size 0xD68 (operator new 0xD68 at 0x3d9e38). This class occupies subobject region [0x7a0, 0xc78) of the base (vptr store at base+0x7a0); region size 0x4d8.

## Member notes

All offsets are relative to the subobject this.

- [this+0x08]/[this+0x0C] u32 — key pair; rewritten by the shared reset helper 0x8a5d5c and compared by slot 3 Equals.
- [this+0x10] ptr — release handle; disposed via a vtable slot-0x20 call in 0x8a5d5c.
- [this+0x25] u8 — flag guarding the virtual dispose in 0x8a5d5c.

Slots (from row 0x12d3ae0): slot0 0x8a36f0 release (installs a base-family vptr from GOT cell 0x13082d8, tail-calls reset 0x8a5d5c); slot1 0x8a334c release + operator delete 0x60b470; slot2 0x8a3380 returns (key != -1); slot3 0x8a3390 Equals (x1 key pair vs +0x08/+0x0C); slot4 0x8a33d0 copies a guarded static pair (guard 0x1311878, value 0x1311880); slot5 0x8a02e4 registry lookup (global base 0x8bd358 + table 0x5060, 0xC-stride, caches result at +0xA0, writes id to +0x90); slot6 0x8a0650; slot7 0x3ddda4 returns 1; slot8 0x8a6b48; slot9 0x8a06ec. Slots 6/8/9 unresolved — addresses only.

## Construction / init order

- No standalone C1 found; the class is default-constructed inline inside FUN_71008a12f0 at 0x8a1950 (vptr from cell 0x1311860, members zeroed, embedded member constructed via 0x61cc48 at sub+0xA8; subobject runs to the base tail (size 0x4D8 is a lower bound if the base has trailing members)).
- Destruction path not observed standalone; slot0/slot1 release entries (unverified whether callers use slot1 to free pooled clones).
