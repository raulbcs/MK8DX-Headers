# RaceDirectorVtaac0 (gear::RaceDirectorVtaac0)

PROVISIONAL vtable-anchored name. vptr 0x12caac0, GOT cell 0x1310578; cell convention: cell holds vt-0x10 (0x12caab0), installed vptr = cell + 0x10. Typeinfo NULL, offset-to-top 0. Size 0x68 (operator new 0x68 in own C1 0x809af8 @0x809b08).

Derived from RaceDirectorVtac30 (ctor 0x809af8 calls base C1 0x80a514 then overwrites [this] with cell 0x1310578+0x10 — far-family fold; no new members).

## Member notes

- Layout identical to base (0x68): Actor/RaceDirectorBase38 fields to 0x37, 0x38/0x40/0x48 zeros, param ptr 0x50, 0x58 zero, byte 0x60 = 0xff.
- Slot overrides vs base: slot 0 (0x80a154) and slot 1 (0x80a1d8) — class dtor pair (absent from functions.csv); slot 3 (0x80a234) replaces base 0x80b0fc. Slots 2/4-19 shared with the base table (gear::Actor D1 thunk, prepareOuter, FUN_71001b5ca0/d0c/dcc/e30, sead::FixedSizeJQ::begin-shaped stub 0x1cbc, FUN_710080ad64/0x8080ada4/0x8080ade0).

## Construction / init order

Factory C1 0x809af8 (called via GOT cell 0x1310570 — the cell pair 0x1310570/0x1310578 holds factory + vtable row):
1. `new 0x68` (0x60afec) with x1 = param.
2. Base C1 0x80a514 (RaceDirectorVtac30).
3. [this] = cell 0x1310578 + 0x10.
4. Tail: bl 0x80a730 (returns bool in w0); factory returns the object or nullptr (`csel x0, x20, xzr, ne` @0x809b3c) — guarded try-create.

Sole caller context: guarded-singleton manager at 0x8099xx (cxa_guard cell 0x12fdf48); its alternate branch (0x809adc-0x809ae4) returns an array element `[mgr+8][idx] + 8` when the guard-holder is already live — i.e. the class instances populate a manager-owned array of 0x10-byte records.
