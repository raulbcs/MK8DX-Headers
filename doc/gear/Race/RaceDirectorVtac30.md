# RaceDirectorVtac30 (gear::RaceDirectorVtac30)

PROVISIONAL vtable-anchored name. vptr 0x12cac30, GOT cell 0x13105b8; cell convention: cell holds vt-0x10 (0x12cac20), installed vptr = cell + 0x10. Typeinfo NULL, offset-to-top 0. Size 0x68 (inferred: sole allocation site is derived RaceDirectorVtaac0's `new 0x68`; own ctor stores reach 0x60).

Far-family: ctor calls 0x7b976c (RaceDirectorBase38, which zeroes 0x10..0x37); slot 2 is the gear::Actor D1 thunk 0x7b978c and slot 12 is gear::Actor::prepareOuter (0x7b97a8), so the hierarchy above RaceDirectorBase38 bottoms out in gear::Actor.

Base of RaceDirectorVtaac0 (vptr 0x12caac0): the derived C1 0x809af8 calls this ctor then overwrites [this] with its own row — same far-family fold pattern as Vt12d5060.

## Member notes

- 0x38 — ctor zero; 0x40/0x48 — ctor zeros (`stp xzr,xzr,[x20,#0x40]`).
- 0x50 — ctor arg1 (x19, pointer parameter); 0x58 — zero.
- 0x60 — byte 0xff.
- Slots 0/1 (0x1b5c18/0x1b5c20) and slot 3 (0x80b0fc) are the class-specific overrides (slot0/1 dtor pair, absent from functions.csv); slots 4-15 shared with the derived table (FUN_71001b5ca0, FUN_71001b5d0c, FUN_71001b5dcc, FUN_71001b5e30, sead::FixedSizeJQ::begin-shaped stub at 0x1cbc, prepareOuter, FUN_710080ad64, FUN_710080ada4).

## Construction / init order

Ctor 0x80a514 (this, param):
1. Base 0x7b976c (RaceDirectorBase38).
2. [0x38]=0; [0x40..0x4f]=0.
3. vptr = cell 0x13105b8 + 0x10 → 0x12cac30.
4. [0x50]=param, [0x58]=0, [0x60]=0xff.

Sole vtable-cell user is the ctor itself (0x80a538). The derived pair is created by the guarded-singleton manager function at 0x8099xx (GOT cell 0x1310570 holds the derived factory 0x809af8; cell 0x1310578 holds the derived row), whose other branch materializes objects from a manager array.
