# object::Vt12ced30

PLACEHOLDER name (identity not proven). vptr 0x12ced30, 53 slots. GOT cell 0x1310e88 holds vptr-0x10 (cell+0x10 = installed vptr; the row address IS the vptr).

Known only as the direct base of Vt12ceb70: its C1 FUN_710085D484 is called solely from Vt12ceb70's C1 (0x85D3DC). Size cited as the derived allocation 0x680 (unproven standalone).

## Member notes

- [this+0x00] vptr 0x12ced30 (0x85D4B4).
- [this+0x60] u32 — receives C1 arg w2 (0x85D4B0; caller passes 2, unverified meaning).
- [this+0x70..0x7F] zeroed by C1 (0x85D4B8-0x85D4C4).
- [this+0x80] pointer to a `new` array of w20 (arg w1... actually caller-supplied count) elements of 0x130 bytes each (0x85D4CC-0x85D4E4); stored 0x85D4F4.
- Slots 0-2 = FUN_7100396F48, FUN_710039705C, FUN_7100397068 (shared with Vt12ceb70); differ from Vt12ceb70 only at slot 39 (0x85EA08 vs 0x85E9B0) and slot 52 (0x85ED40 vs 0x85EB2C).

## Construction / init order

- C1 = FUN_710085D484: base init FUN_710085EB3C (0x85D49C), [this+0x60] = w2, vptr, zero +0x70 block (0x85D494-0x85D4C4), then counted array alloc/init loop (0x85D4CC onward, element stride 0x130).
- Derived Vt12ceb70 C1 = FUN_710085D3C4 calls it with w1=1, w2=2 (0x85D3D0-0x85D3DC).
