# Vt12bc2f8 (placeholder name)

## Identity

- Assigned row 0x12bc2f8 = 6 slots, offset-to-top -0x30 at 0x12bc2e8,
  typeinfo NULL at 0x12bc2f0. It is the SECONDARY vptr (installed at
  [this+0x30]) of ParamMultiChanVtc200 (primary 0x12bc200, row
  0x12bc1f0; doc/object/Kart/ParamMultiChanVtc200.md).
- GOT convention: NO reloc targets this table. Cell 0x130e650 (plain
  .got data, no RELA entry) holds 0x12bc1f0 = primary row; code adds
  0x10 (primary vptr 0x12bc200) or 0x108 (this secondary vptr
  0x12bc2f8).
- The final class is the DERIVED type whose C2 is 0x7119fc: it
  constructs the ParamMultiChanVtc200 base part (cell 0x130e650 site
  0x711a20/24) and then continues into 0x711db4 which overwrites the
  vptrs with the derived pair (cell 0x130e658: +0x10 / +0x108 =
  0x12bc468 / 0x12bc560). No factory leaves the base vptrs installed,
  so 0x12bc200/0x12bc2f8 are construction-phase base subobject tables.

## Member notes

- Slots (vptr+0x00..+0x28): D1 0x712468, D0 0x7125b0, then the shared
  thunks 0x648094 / 0x6480a0 / 0x6480a8 / 0x6480b4 (identical bodies
  across the whole 0x12bc hook-band cluster; see doc/game/Vt12bc1c0.md).
- D1 0x712468: restores primary vptr 0x12bc200 at [this-0x30] and the
  secondary vptr 0x12bc2f8 at [this], re-installs the ChanBase vptr
  0x12b3af0 (cell 0x130d918 +0x10) at [this+0x248..+0x448 step 0x20]
  and at +0x4a0..+0x5a0 step 0x20, then tail-calls 0x73305c.
- D0 0x7125b0: same vptr restores; ChanBase re-installs extended to
  [this+0x4a8..+0x5d0].
- size 0x5f0 EXACT: factory 0x712c60 (`mov w0,#0x5f0` at 0x712c54,
  `operator new(0x5f0, 8)` 0x60b234 at 0x712c60, C2 0x7119fc at
  0x712c68); second factory 0x712c44 same size/C2. This also firms up
  the "EXTENT APPROXIMATE" in doc/object/Kart/ParamMultiChanVtc200.md.

## Construction / init order

- Base C2 = 0x7119fc: installs the ParamMultiChanVtc200 vptrs
  (cell 0x130e650 +0x10 / +0x108) and constructs the channel-pair
  members with 0x662f30/0x662f70 (in-place sites incl. 0x711a24);
  then 0x711db4 runs the derived continuation (vptr overwrite to
  0x12bc468/0x12bc560, cell 0x130e658) — see doc/game/Vt12bc560.md.
- Destruction order: D1 0x712468 → derived D1 0x713478 (restores this
  base's secondary vptr 0x12bc2f8 with the derived ChanBase offsets).
