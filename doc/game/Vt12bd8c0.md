# Vt12bd8c0 (placeholder name)

## Identity

- Assigned row 0x12bd8c0 = 6 slots, offset-to-top -0x30 at 0x12bd8b0,
  typeinfo NULL at 0x12bd8b8. It is the SECONDARY vptr (installed at
  [this+0x30]) of the class with primary vptr 0x12bd7b0 (row
  0x12bd7a0, off/ti 0).
- GOT convention: NO reloc targets this table. Cell 0x130e8e0 (plain
  .got data, no RELA) holds 0x12bd7a0 = primary row; code adds 0x10
  (primary vptr) or 0x120 (this secondary vptr 0x12bd8c0).
- Base class of the Vt12bda10 class (cell 0x130e8e8): its C2 0x72c35c
  calls this C2 0x72b980 (0x72c37c) and then overwrites the vptr pair.
  This class also exists standalone (its own factory does NOT
  overwrite).

## Member notes

- Slots (vptr+0x00..+0x28): D1 0x72be04, D0 0x72bedc, then the shared
  thunks 0x648094 / 0x6480a0 / 0x6480a8 / 0x6480b4.
- D1 0x72be04: restores primary vptr (cell 0x130e8e0 +0x10) at
  [this-0x30] and secondary vptr 0x12bd8c0 at [this], re-installs the
  ChanBase vptr 0x12b3af0 (cell 0x130d918 +0x10) at
  [this+0xf8..+0x270 step 0x20/0x28 pattern (0x118, 0x138, 0x158,
  0x180, 0x1a0, 0x1c8, 0x1f0, 0x210, 0x230, 0x250, 0x270)], then
  tail-calls 0x6472c8 (dtor continuation).
- D0 0x72bedc: same vptr restores, framed variant (bl 0x6472c8 at
  0x72bec8); ChanBase re-installs at owner-relative +0x128..+0x2a0.
- size 0x2c0 EXACT: factory 0x72e35c (`mov w0,#0x2c0` 0x72e36c,
  `operator new(0x2c0, 8)` 0x60b234 at 0x72e378, C2 0x72b980 at
  0x72e380).

## Construction / init order

- C2 0x72b980 (0x72b980-0x72bdb0): bl 0x646dac (base-of-base init),
  zero u32 [this+0x120] (0x72b9a0), installs vptrs cell 0x130e8e0
  +0x10 / +0x120 (0x72b9b4/0x72b9c0), then constructs channel-pair
  members with 0x662f30/0x662f70 (name string 0xf06a2d, fn cell
  0x12fae28 +0x10, owner back-ptr).
