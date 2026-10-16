# KartBodyVt71

## Identity

Address-anchored name ("Vt71"): base of the kart body family — 665 vtables (71-101
slots) sharing PrePass20_7100197798 / GetCurrentSpeed_7100197c90 / CoinItemInteraction_71001981ec,
one per kart+driver combo (ctors SHARED, vtable passed as arg). Vtable .data 0x11bb5c0
(GOT cell 0x12fd6a8), ctor 0x7100019888 (Actor base 0x7b976c, member ctor 0x86838c at
+0x38), true size 0x208 (alloc 0x208 at 0x19d554); derived allocs 0x1f8..0x2b8. Slot facts:
0x18 re-init hook (0x7100198ac8) writes +0x38/+0x128 and clears +0x1a8; 0x80/0x88/0x90
PURE RET on base; 0x98 (0x7100199798) reads [+0x140]->[+8]; 0xa0 (0x7100199000) reads
bytes +0x166/+0x130/+0x40; 0x1c0 (0x710019b440) delegates [+0x140]->[+0x730] vt 0x18.
Thunk impls (0x710019xxxx band) touching: +0x128 low word =1.0f (0x7100012a44),
*(int*)+0x140 (0x71001994d8), counter ptr +0x1B0 / snap +0x1B8 (0x710019a388),
u16 ring +0x1C0/+0x1C8/+0x1CC/+0x1D0 (0x710019b7bc), flags +0x1D0/+0x1DE (0x710019b7f4/b80c).

## Member notes

Notes in field order; proven from the cited addresses.

- 0x38 — embedded member (ctor 0x86838c); the 0x140 sub-object read by slots 0x98/0x1c0 lives in here ([+0x730] delegate, [+0x738] ret)
- 0x128 — per-combo data/object: written by the construction block and rewritten by the re-init slot 0x18
- 0x130 — byte pair read by slot 0xa0
- 0x138
- 0x140 — sub-object read by slots 0x98/0x1c0 (delegation [+0x730] -> vcall 0x18, [+0x738])
- 0x148
- 0x150 — zeroed on ctor
- 0x158 — zeroed on ctor
- 0x160 — zeroed on ctor
- 0x164 — unproven padding
- 0x166 — flag read by slot 0xa0
- 0x167 — unproven padding
- 0x1a8 — cleared by the re-init slot 0x18
- 0x1b0 — to end (0x208)

> Naming: the 665 family members are per kart+driver combination variants (shared ctors, vtable passed as argument); semantic per-combo names need the combination dictionary.

## Construction / init order

In field/offset order (= binary init order within this header):
- 0x38 — embedded member (ctor 0x86838c); the 0x140 sub-object read by slots 0x98/0x1c0 lives in here ([+0x730] delegate, [+0x738] ret)
- 0x128 — per-combo data/object: written by the construction block and rewritten by the re-init slot 0x18
- 0x150 — zeroed on ctor
- 0x158 — zeroed on ctor
- 0x160 — zeroed on ctor
- 0x1a8 — cleared by the re-init slot 0x18
