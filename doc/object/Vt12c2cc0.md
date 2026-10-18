# Vt12c2cc0

## Identity

- PLACEHOLDER name (identity not proven). GOT cell 0x130f620 holds
  vt-0x10 (0x12c2cb0); installed primary vptr = cell+0x10 = **0x12c2cc0**,
  secondary vptr = cell+0x98 = **0x12c2d48** at this+0x08.
- Primary row 0x12c2cb0: offset-to-top 0, typeinfo 0, 15 slots
  (0x78d0a0..0x78ca28). Secondary group starts at 0x12c2d38
  (offset-to-top -8): slot 0 = 0x78bfd8, slot 1 = 0x78c004, slot 2 =
  0x78cba0, slots 3/4 = 0x5f0484/0x5f0494 — ICF-thin clones.
- Multiple inheritance: the +0x08 slot first receives 0x12c2de8 from the
  base ctor 0x5ef030 (GOT cell 0x130f618 → 0x12c2dd8, vptr 0x12c2de8, a
  separate class), then C1 overwrites it with the derived secondary
  0x12c2d48 (0x78bcb8..0x78bddc).

## Member notes

- Size 0x3c0 from the unique allocation: lazy singleton `new` 0x3c0
  (align 8) at 0x7757b4, C1 call at 0x7757c8, cached at [mgr+0x38] with
  guard flag [mgr+0x6b].
- +0x2C8 null; +0x2D0..0x308 zeroed by C1 (0x78bcf4..0x78bd14), including
  halfword +0x2F8 which is later replaced by a `new` 0x268 sub-object
  (ctor 0x773a64, stored at 0x78bda0).
- +0x310 member ctor 0x628628 (0x78bd1c).
- +0x350 byte zero; +0x358 member whose vptr comes from GOT cell
  0x12fada0 (+0x10); +0x360 = this+0x36C; +0x368 = 0x20; +0x398..0x3B8
  zeroed; +0x3A0 byte zero.
- D-tors: slot 2 = FUN_710078bdb0 (0x78bdb0, reinstalls both derived
  vptrs then runs member teardown); slots 0/1 = 0x78d0a0/0x78d16c (ICF
  clones); slot 3-5 = 0x78bf04+0xdc/0x128/0x12c (thin clones incl. the
  secondary-group deleting-dtor target).

## Construction / init order

1. Owner at 0x7757b4: `operator new(0x3c0, 8)`.
2. C1 FUN_710078bcb8: install provisional base vptr at +0x00, run base
   ctor 0x5ef030 for the +0x08 secondary base, zero +0x2C8..0x308,
   member ctor 0x628628 for +0x310.
3. Overwrite +0x00/+0x08 with derived pair 0x12c2cc0/0x12c2d48 (0x78bd18).
4. +0x358 member init, 0x61cc48 call, byte from GOT 0x12fada8 copied to
   [this+0x360] target, zero +0x398..0x3B8, `new` 0x268 sub-object into
   +0x2F8.
