# object::Vt12b9fc0

PLACEHOLDER name (identity not proven). vptr 0x12b9fc0, 8 slots, typeinfo NULL (game-side). GOT cell 0x130e2a8 holds vt-0x10; installed vptr = cell + 0x10.

## Member notes

- size 0x300 — EXACT: aggregate member at +0x3cd0 (0x6bb378 in ctor 0x6bb300) with the next member at +0x3fd0; C1 stores run through +0x2f8+8.
- Base Vt12b6f58 at +0x00..+0x248 (base C2 0x6c6128 at 0x6d9a70).
- [this+0x250] — subobject initialized by 0x66a2a4 (0x6d9a74-0x6d9a78); immediately afterwards C1 overwrites [this+0x248] with the SECONDARY base vptr = GOT cell 0x130e2a8 value + 0x60, i.e. vtable row 0x12ba010 (0x6d9a7c-0x6d9a9c). The +0x248 subobject is therefore a polymorphic base of a base (MI); its row 0x12ba010 is not part of this batch.
- [this+0x278] — 0x58-byte block memset to 0 (0x6d9a8c-0x6d9aa0).
- [this+0x2d0] = 1.0f; [this+0x2d8] = 0; [this+0x2f0]/[this+0x2f8] = 0.
- D1 (slot 0, 0x6d9ac4) re-installs primary vptr (cell+0x10) and secondary row at +0x248 first, then virtually destroys [this+0x280] (slot-1 blr), [this+0x2f0], [this+0x2f8] (slot-1 blr) and nulls them.

## Construction / init order

- C1 = 0x6d9a60 (inlined at 0x6bb378 inside aggregate ctor 0x6bb300): base 0x6c6128 → subobject +0x250 (0x66a2a4) → secondary vptr +0x248 (row 0x12ba010) + primary vptr overwrite → memset +0x278 (0x58) → float/pointer defaults.
- Slots: 0 = D1 0x6d9ac4; 1 = 0x6d9c90 (unrecovered, absent from functions.csv); 2 = 0x6dad98; 3 = 0x6db000; 4 = shared ret stub 0x6c36a4; 5 = 0x6dc390; 6 = 0x6dc784; 7 = 0x6dc838 (unrecovered).
