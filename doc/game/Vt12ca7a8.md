# Vt12ca7a8

Unnamed derived class of Vt12c7de8 (Vt12c7cc0 family). No RTTI. Hierarchy:
root ctor 0x6155bc (vptr 0x12b0058) → base init 0x7d34d8 (vptr 0x12c7cc0)
→ base init 0x7d5164 (vptr 0x12c7de8) → vptr override to 0x12ca7a8.

GOT cell convention: cell 0x13104d8 holds vptr-0x10; installed vptr =
cell + 0x10.

## Init / sites

- No out-of-line C1. Construction sites in FUN_7100804db0 factory region
  read the GOT cell after calling base init 0x7d5164: 0x804e48 and
  0x805560 (each preceded by `bl 0x7d5164`; the allocation `new 0xe8` at
  0x804e20 / 0x805540 is shared with the base type).
- No field stores after the vptr override: size 0xe8 EXACT (allocation
  size, identical to Vt12c7de8).

## Member notes

- Field layout identical to Vt12c7de8 (0x08..0xe7): base block from
  0x7d34d8, derived fields 0xac..0xe4 (see doc/game/Vt12c7de8.md).
- Slot 0 here is the shared family D1 0x7d35f8 (reinstalls base vptr
  0x12c7cc0 via cell 0x130fff0, calls destroy tail 0x7d4b40, then root
  destroy 0x6156b4), unlike Vt12c7c70/12c7de8 whose slot 0 is the fmul
  dispatch 0x7c6e1c. Slot 1 is the deleting-dtor wrapper 0x807854
  (`bl 0x7d35f8; b operator delete`).

## Slots (8)

+0x00 0x7d35f8 (D1, shared), +0x08 0x807854 (D0 wrapper), +0x10 0x7d525c
(500B update, inherited), +0x18 0x7d5270 (float update, inherited),
+0x20 0x7d34c4 (inherited), +0x28 0x7d5440 (`ret`), +0x30 0x7d5200
(OVERRIDE: transforms both candidate points (+0xcc block vs arg via
+0xd8 matrix block) by weights from x1/x2 and returns the one with the
greater dot product; early-out `ret` when flag [this+0xe4]==0),
+0x38 0x7d5448 (returns this+0xcc, inherited). All unrecovered FUN_*.

## Construction / init order

1. `new 0xe8` (0x804e20 / 0x805540).
2. Base init 0x7d5164 (vptr 0x12c7de8; params + global copies; state=1).
3. Store vptr 0x12ca7a8 at +0x00; no further field writes.
