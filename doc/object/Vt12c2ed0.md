# object::Vt12c2ed0

PLACEHOLDER name (identity not proven). vptr 0x12c2ed0, 14 slots, no offset-to-top/typeinfo header (row starts directly at the vptr; game-side). GOT cell 0x130f640 holds 0x12c2ec0 = vptr-0x10; installed vptr = cell+0x10. Secondary interface of a 0x50-byte class whose primary vtable is 0x12c2f30 (installed vptr 0x12c2f40, cell 0x130f638, 10 slots). The primary vtable is a sibling target, documented here for context only.

size 0x50 — exact (operator new 0x50 at 0x790068 in factory FUN_7100790050, sole caller of C1 FUN_710078ef44; factory itself is only reached via a function pointer stored in vtable 0x12c2fd8 slot 0, reloc cell 0x12c2fe8).

## Member notes

- [this+0x00] vptr = 0x12c2f40 (primary).
- [this+0x14] u32 — state; secondary slot 0 returns `state == 2` (0x78D52C-0x78D538). Written by FUN_710078d4b4 (0x78D4F0: stores 1 after an init pass). Ctor does not initialize +0x08..+0x27 (unverified whether callers do).
- [this+0x28] u8 — bool flag, zeroed by ctor (0x78EF88).
- [this+0x30] vptr = 0x12c2ed0 (this interface), stored together with a zero qword at +0x38 (`stp x8, xzr`, 0x78EF74).
- [this+0x40] self pointer — ctor stores `this` (0x78EF84); intrusive-node pattern, unverified.
- [this+0x48] — `*(static loaded via GOT cell 0x12fc0e70)` (0x78EF78-0x78EF84); singleton/back-reference, target static unresolved (unverified).

Primary vtable 0x12c2f40 slots (10, 0x12C2F40-0x12C2F88): 0: 0x78D654 (return 0); 1: 0x78D65C (return null); 2: 0x78D664 (return -1); 3/4: NULL; 5: 0x78D54C (`ret`); 6: 0x78DA68; 7: 0x78D680 (`str x1, [x0, #8]` setter); 8: NULL; 9: 0x78D688.

## Construction / init order

- C1 FUN_710078ef44 (0x78EF44-0x78EF94): installs primary vptr at +0x00, secondary vptr + zero at +0x30/+0x38, self pointer at +0x40, static back-reference at +0x48, clears the +0x28 flag. Fields +0x08..+0x27 are not written by the ctor.
- Factory FUN_7100790050 (0x790050): `new(0x50)` then C1; returns the object.
- D1/D0 not located; the only `operator delete` reachable from this cluster is slot 6 of the secondary row (tail-jump to `_ZdlPv`).

Secondary vtable 0x12c2ed0 slots (14, 0x12C2ED0-0x12C2F38):

| slot | addr | target |
| --- | --- | --- |
| 0 | 0x78D514 | calls FUN_710078d9d8, returns `[this+0x14] == 2` |
| 1 | — | NULL |
| 2 | — | NULL |
| 3 | 0x78D574 | guarded static init (guard 0x12FC128, vptr source cell 0x12FADE0), returns `arg == static singleton` |
| 4 | 0x78D5E4 | same guard; returns the singleton pointer |
| 5 | 0x78D640 | `ret` |
| 6 | 0x78D644 | tail `b operator delete` (0x60B470) |
| 7 | 0x78D648 | `ret` |
| 8 | 0x78D64C | `ret` |
| 9 | 0x78D650 | `ret` |
| 10 | 0x78D554 | return 0 |
| 11 | 0x78D55C | return 0 |
| 12 | 0x78D564 | return 0 |
| 13 | 0x78D56C | return 0 |
