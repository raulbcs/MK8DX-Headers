# object::Vt12c2de8

PLACEHOLDER name. Primary-base vtable of a multiple-inheritance complete
class; the only code reference to its GOT cell is C-variant
FUN_710078bcb8 (0x78bcb8-0x78bdb0, sole caller 0x7757c8), which first
installs this vptr and later overwrites the two header words with the
final vptrs. Extent is a LOWER BOUND (no operator-new found).

- Identity: vptr = 0x12c2de8; [vptr-0x10]/[vptr-8] = 0. GOT cell
  0x130f618 holds 0x12c2dd8 = vt-0x10 (single reloc, single code site
  0x78bcc8).
- Final complete-object vptrs (installed 0x78bd18 via stp): primary
  0x12c2cc0 (cell 0x130f620, addend 0x12c2cb0 = vt-0x10; 14 slots
  0x78d0a0..0x78ca28) stored at [this], and secondary 0x12c2d48 (same
  group, +0x98 past the primary cell — secondary row after an 8-byte
  offset-to-top/typeinfo gap at +0x88/+0x90) stored at [this+8].
- Extent: deepest store in the C-variant is [x19+0x3b8]; size >= 0x3c0,
  unverified beyond that.

## Member notes

- This table's slots (14): +0x00 0x78d574 (92 B region: guard singleton
  0x12fc120/0x12fc128/0x12fc130, compares arg x1 against the global
  instance — identity check), +0x08 D0 0x78d5e4 (92 B deleting dtor),
  +0x10 0x78d640 (4 B `ret`), +0x18..+0x68 0x78d644/48/4c/50/54/55c/564/
  56c/654/65c/664 (unrecovered 8-byte stub region immediately after).
- Member at +0x08: constructed by 0x5ef030 (120 B, x0 = this+8); by the
  end of the C-variant [this+8] holds the MI secondary vptr.
- Member at +0x310: constructed by 0x628628 (x0 = this+0x310).
- Member at +0x358/+0x360: vptr/data pair; C1 writes vptr cell 0x130fda0
  then replaces it with cell 0x130f728+0x10 and stores a global byte
  ([0x12fada8]) through the data pointer.
- C1 allocates a 0x268-byte object (operator new 0x60afec at 0x78bd94 +
  C1 0x773a64) into [this+0x2f8].

## Construction / init order

1. FUN_710078bcb8: this-vptr 0x12c2de8; sub-object ctor 0x5ef030 at
   +0x08; zero stores 0x2c8..0x308; 0x628628 at +0x310; 0x350..0x36c
   member/cursor init; 0x61cc48 + global byte via +0x360; +0x398..+0x3b8
   zeroed; 0x268-byte allocation into +0x2f8.
2. Final vptr pair (primary 0x12c2cc0 / secondary 0x12c2d48) stored at
   +0x00/+0x08 (0x78bd18) by the same C-variant.
