# nn::pia::session::DestroyMeshJob

## Identity

- vtable row 0x12deaf0 (tsv row = typeinfo slot), vptr 0x12deaf8 = row + 8,
  6 slots. GOT cell 0x1313a88 holds 0x12deae8 = vptr - 0x10 (offset-to-top
  0x12deae8 = 0, typeinfo slot 0x12deaf0 = 0x12deb30); installed vptr =
  cell + 0x10.
- RTTI: typeinfo 0x12deb30 = {0x10, name 0xf82050, base 0x12f8d30}; name =
  "N2nn3pia7session14DestroyMeshJobE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x9a04d0, 1 D0 0x9a04d4, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5 `ret` 0x9a08a0 (bare `ret`). D1 has no extra body:
  tail-jumps straight to 0xb4a62c (shared job-base D0). D0 = 0xb4a62c then
  operator delete 0x60b470.
- extent 0x90 EXACT: operator new 0x90 at 0x986988 (factory caller
  0x986998, allocates it at [mgr+0x28]), sole site found.

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58: ptr (0 = none) — consumed by the request fn 0x9a04f8, which also
  drives [this+0x68] timeout and flags at +0x8c/+0x8d/+0x8e.
- +0x60: ptr, zeroed by C1.
- +0x68 u32 = 5000 (C1 0x9a047c); [0x6c, 0x8c) memset 0; +0x8c u16 = 0;
  +0x8e u8 = 0. No sub-objects.

## Construction / init order

1. C1 0x9a047c: base C1 0xb4a5e0(this) (0x9a048c).
2. vptr 0x12deaf8 -> [this] (0x9a04a0, cell 0x1313a88 + 0x10).
3. [this+0x58] = [this+0x60] = 0 (0x9a049c).
4. [this+0x68] = 5000 (0x9a04b4); memset(this + 0x6c, 0, 0x20) (0x9a04b8).
5. [this+0x8c] u16 = 0 (0x9a04bc); [this+0x8e] u8 = 0 (0x9a04c0).
