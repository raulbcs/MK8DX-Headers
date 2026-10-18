# object::JobDataStoreGetRating

RTTI-CONFIRMED: nn::nex::JobDataStoreGetRating. Typeinfo record 0x12f7380
(name at 0x12f7388's target); typeinfo pointer at vptr-8 = 0x12f6cd8 —
tools/vt_ctors.tsv's "0x12f6cd8" is the typeinfo slot. Installed vptr =
0x12f6ce0 (GOT cell 0x1315980 holds 0x12f6cd0 = row-0x10; sites add +0x10).

## Identity

- Factory (inside the nex JobDataStore workflow function):
  `operator new(0x1e0)` at 0xb1ac54, base C1 0x588b04(this, 2, &out), then
  field zero-fill and vptr 0x12f6ce0 -> [this] (0xb1ac98).
- vptr installed at three sites: 0xb1ac70 (C1), 0xb1aef8 (second C1 clone)
  and 0xb27e34 (inside slot-0 function 0xb27e20 — vptr reinstall, dtor/clone
  path).

## Member notes

- [this+0xA0] u32 zero; [this+0xA8..0xFF] zeroed qwords (0xb1ac7c-0xb1aca8).
- [this+0x100] — member initialized by FUN_7100a2bf88 (0xb1acac, arg 0);
  occupies through +0x1d7 (next proven write is +0x1d8).
- [this+0x1D8] — trailing zero qword (0xb1acb0).
- Virtual dispatch seen through slot 13 (`ldr x8,[this]; ldr x9,[x8,#0x68];
  blr` at 0xb1acb4-0xb1acd8) with 5 args — the job's execute entry.
- Slots: slot 0 0xb27e20 (304 B, D0-like), slot 1 0xb27f50 (36 B, D2-like),
  slot 2 0x5917a0, slot 3 0x58ff6c, slot 4 0x5917ac, slot 5 0x590148, slot 13
  0xb27f74 (508 B), slot 14 0xb28344 (484 B); slots 6-12 (0x59014c, 0x5917b0,
  0x5917cc, 0x58b7d8, 0x5917d4, 0x5917d8, 0x59189c) unrecovered.

## Construction / init order

- new 0x1e0 -> base C1 0x588b04 -> zero +0xA0..0xFF -> vptr -> member C1
  0xa2bf88 at +0x100 -> zero +0x1D8.
- Extent 0x1E0 proven by the alloc size at 0xb1ac54.
