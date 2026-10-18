# object::Vt12d3de0

PLACEHOLDER name (identity not proven). vptr 0x12d3de0, GOT cell 0x1311968
holds vt-0x10 (addend 0x12d3dd0); installed vptr = cell+0x10. The only site
that materializes the vptr is FUN_71008ab2ec at 0x8ab37c..0x8ab39c - there is
no out-of-line C1; the object is a stack record (sp+0x68 in that frame).

## Identity

- Stack-by-value record of 0x54 proven bytes, constructed on top of the
  0x12b0538 family base: base ctor 0x6155bc runs first (0x8ab330, x0 =
  sp+0x68, installing the base vptr from cell 0x130d388 = 0x12b0528), then
  the derived vptr 0x12d3de0 overwrites [this] (0x8ab39c).
- After construction the record is paired with a 0x40-byte descriptor
  (sp+0x28: {ptr, u32, u32, self-ptr, vptr-ish, cell ptr, data ptr}) and both
  are handed to the guard-protected singleton at 0x12fc0368 via 0x6243b0
  (0x8ab3f4..0x8ab404; guard cells 0x12fd360/0x12fd370).
- D2 = 0x6237f4 (slot 0), called directly on the record at 0x8ab4b0: it
  re-installs the base vptr (cell 0x130d388+0x10) and unregisters the record
  from the singleton container (0x623da8, head/tail fixup via [mgr+0x58]).

## Member notes

- +0x20/+0x28: zeroed (0x8ab390).
- +0x30: intrusive self pointer = record address (0x8ab32c, stored 0x8ab3c4).
- +0x38: zeroed (0x8ab32c).
- +0x40: secondary vptr = [cell 0x12fa0e28]+0x10 (0x8ab3a0..0x8ab3b4); the
  cell's runtime value could not be resolved from .rela.dyn - unverified.
- +0x48: pointer value of GOT cell 0x12fb0728 (0x8ab374..0x8ab3b4) - also
  unverified; both cells are in the runtime-relocated GOT range.
- +0x50: u32 = 0x20 (0x8ab350..0x8ab354).
- Vtable row: 20 code slots up to +0x98 (slot 19 = 0x8aeec4), then unrelated
  .data at +0xa0 (0x135de90...). Slots 0-19 are all unrecovered in
  functions.csv except slot 0 (D2 0x6237f4); slot 1 = 0x8aeb00 (D1 candidate,
  unverified).

## Construction / init order

1. Base ctor 0x6155bc on the stack record (0x8ab330) - installs vptr from
   cell 0x130d388+0x10; fields it writes beyond +0x54 are unverified, so the
   cited size 0x54 is a lower bound.
2. FUN_71008ab2ec derived stores: zeros +0x20..+0x2f (0x8ab390), self +0x30
   and zero +0x38 (0x8ab32c/0x8ab3c4), secondary vptr +0x40 (0x8ab3a0),
   cell pointer +0x48 (0x8ab3b4), u32 0x20 +0x50 (0x8ab354).
3. Derived vptr 0x12d3de0 installed at +0x00 (0x8ab39c).
4. Descriptor at sp+0x28 filled and both passed to singleton 0x12fc0368
   through 0x6243b0 (0x8ab3f4..0x8ab404).
