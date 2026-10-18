# Vt12bda10 (placeholder name)

## Identity

- Assigned row 0x12bda10 = 6 slots, offset-to-top -0x30 at 0x12bda00,
  typeinfo NULL at 0x12bda08. It is the SECONDARY vptr (installed at
  [this+0x30]) of the class with primary vptr 0x12bd900 (row
  0x12bd8f0, off/ti 0).
- GOT convention: NO reloc targets this table. Cell 0x130e8e8 (plain
  .got data, no RELA) holds 0x12bd8f0 = primary row; code adds 0x10
  (primary vptr) or 0x120 (this secondary vptr 0x12bda10).
- Derives from the Vt12bd8c0 class (cell 0x130e8e0): C2 0x72c35c calls
  the base C2 0x72b980 (0x72c37c), then overwrites both vptrs with
  this class's pair (cell 0x130e8e8: +0x10 at [this] 0x72c3b0, +0x120
  at [this+0x30] 0x72c3a0).

## Member notes

- Slots (vptr+0x00..+0x28): D1 0x72c844, D0 0x72c974, then the shared
  thunks 0x648094 / 0x6480a0 / 0x6480a8 / 0x6480b4.
- D1 0x72c844: demotes the vptrs to the BASE family (cell 0x130e8e0:
  +0x10 at [this-0x30], +0x120 = 0x12bd8c0 at [this]), re-installs the
  ChanBase vptr 0x12b3af0 (cell 0x130d918 +0x10) at
  [this+0x2c0..+0x3f8 step 0x20], then tail-calls 0x6472c8. (Same
  demote-to-base pattern as ParamContainerVtc338's D1; unverified
  interpretation: destruction-phase demotion.)
- D0 0x72c974: restores THIS class's vptrs (cell 0x130e8e8 +0x10 /
  +0x120) and ChanBase vptrs at +0x2c8..+0x428.
- Primary slots: slot0 0x72c7c0 (cell 0x130e8e0 user 0x72c7ec — base-
  family demotion), slot1 0x72c8d0 (own cell 0x130e8e8, ChanBase
  0x2c8..+0x428, bl 0x6472c8 at 0x72c960).
- size 0x448 EXACT: factory 0x72e394 (`mov w0,#0x448` 0x72e3a4,
  `operator new(0x448, 8)` 0x60b234 at 0x72e3b0, C2 0x72c35c at
  0x72e3b8). A second allocation site 0x72f458 allocates 0x488 with
  the same C2 — larger derived-or-array variant, unverified.

## Construction / init order

- Base C2 0x72b980 runs first (base size 0x2c0), then C2 0x72c35c:
  s32 [this+0x2c0] = -1 (0x72c394), vptr overwrite (0x72c3a0/0x72c3b0),
  channel-pair members from [this+0x2c8] via 0x662f30/0x662f70 (name
  0xeeee93, fn cell 0x12fae28 +0x10; next member name 0xef9389).
