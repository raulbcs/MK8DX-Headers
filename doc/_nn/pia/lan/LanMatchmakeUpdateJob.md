# nn::pia::lan::LanMatchmakeUpdateJob

## Identity

- vtable row 0x12dd370 (tsv row = typeinfo slot), vptr 0x12dd378 = row + 8, 9 slots.
  GOT cell 0x1313640 holds 0x12dd368 = vptr - 0x10 (offset-to-top 0x12dd368 = 0,
  typeinfo slot 0x12dd370 = 0x12dd3c0); installed vptr = cell + 0x10.
- RTTI: typeinfo 0x12dd3c0 = {0x10, name 0xf81050, base 0x12f8d30}; name =
  "N2nn3pia3lan21LanMatchmakeUpdateJobE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x97bb84, 1 D0 0x97bbd0, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5 0x97cea0 (`ret`), 6 0x97bc24 (update loop: waits on
  sub-object at +0x60, 30000 ms budget, nnResult out via x8; writes flag
  [this+0xda0] = 1 and nulls [this+0xd98]), 7 0x97c34c (unrecovered body).
  csv has an O-quality symbol "LanMatchmakeUpdateJob::Update" covering the
  ctor region (entry 0x97bb04; sizes stale in functions.csv).
- D1 0x97bb84: re-installs vptr, destroys +0xd78 sub-object (0x929ee0), runs
  0x973b98 on the +0xb18 sub-object, tail 0xb4a62c (shared job-base D0).
  D0 0x97bbd0: same body then operator delete 0x60b470.
- extent 0xec0 EXACT: operator new 0xec0 at 0x96fc50-0x96fc68 (factory 0x96fc14)
  immediately followed by C1 0x97bb24; sole allocation site (unverified beyond
  the single site — fields only reach 0xdc0).

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58 = C1 arg x1 (0x97bb44).
- +0x60 sub-object: sub-ctor 0xb49bb8 installs a vptr (cell family 0xb49bb8);
  region 0x60..0xb18 only vptr-proven — unproven gap.
- +0xb18 sub-object: built by 0x973a74 (region to 0xd78) — unproven gap.
- +0xd78 sub-object: built by 0x929ec0 (same builder as JoinSessionJob +0x60).
- +0xd98 = 0; [0xda0, 0xdb0) memset 0.

## Construction / init order

1. C1 0x97bb24: base C1 0xb4a5e0(this) (0x97bb38).
2. [this+0x58] = x1 (0x97bb44).
3. vptr 0x12dd378 -> [this] (0x97bb50, cell 0x1313640 + 0x10).
4. Sub-object ctor 0xb49bb8(this + 0x60) (0x97bb54).
5. Sub-object ctor 0x973a74(this + 0xb18) (0x97bb5c).
6. Sub-object ctor 0x929ec0(this + 0xd78) (0x97bb64).
7. [this+0xd98] = 0 (0x97bb68); memset(this + 0xdb0, 0, 0x10) (0x97bb80).
