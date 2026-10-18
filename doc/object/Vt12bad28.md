# object::Vt12bad28

PLACEHOLDER name. Derived flavour of Vt12b69c8: identical 0x318 layout
with no own fields; only the destructor pair and the final slot differ.

- Identity: vptr = 0x12bad28; [vptr-0x10]/[vptr-8] = 0. GOT cell
  0x130e440 holds 0x12bad18 = vt-0x10; the factory installs it after the
  base C1 has run.
- Size proof: factory FUN_71006f786c (0x6f786c-0x6f7978) requests
  0x318 bytes via 0x6ad048 (arg w3 = 0x318), constructs the Vt12b69c8
  base (bl 0x6b5e2c at 0x6f7914), installs this vptr (0x6f7918-0x6f7938),
  calls helper 0x6ad110 and virtual slot 0x58 (slot11 parse); returns
  null on failure — single construction site (0x6ad00c is a caller of
  the factory itself).
- One-time guard: 0x6f7880-0x6f78cc initializes a global (guard
  0x12fb130, vptr cell 0x12fb138 -> instance 0x12fb140) with a
  __cxa_guard pair — framework-side singleton used for the slot0 vcall
  that gates construction.

## Member notes

- Slots: +0x00 D1 0x6f95c8 (tail of FUN_71006f9140, 1232 B; re-installs
  this vptr at 0x6f95cc before member teardown), +0x08 D0 0x6f95dc
  (re-install at 0x6f95ec then delete), +0x10..+0x60 shared verbatim
  with Vt12b69c8 (0x6b5f80, 0x6b6c50, 0x6b609c, 0x6b60bc, 0x6b6c58,
  0x6b6c78, 0x6b68f0, 0x6b68b8, 0x6b6ca4, 0x6b612c, 0x6b676c),
  +0x68 slot13 override 0x6f9500 (tail of FUN_71006f786c region:
  dispatches through a context vtable group at cell 0x130e448 + index*0x10
  after computing flags from [+0x20]->0x1610/0x24 and arg halfword
  [+0x36] — a parameterized variant of the base slot13 0x6b69ec).
- D1/D0 constructors listed in vt_ctors.tsv at sites 0x6f95cc/0x6f95ec
  are the in-destructor vptr re-installs (destruction numbering).

## Construction / init order

1. Factory 0x6f786c: guard-protected global init, slot0 vcall on the
   source's +0x08 object, 0x318-byte allocation (0x6ad048).
2. Base C1 FUN_71006b5e2c, then vptr 0x12bad28, then 0x6ad110 and
   slot11 (0x6b612c) parse with the factory's x2/x4 args.
