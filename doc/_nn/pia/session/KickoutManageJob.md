# nn::pia::session::KickoutManageJob

## Identity

- vtable row 0x12ddde0 (tsv row = typeinfo slot), vptr 0x12ddde8 = row + 8, 9 slots.
  GOT cell 0x13137a0 holds 0x12dddd8 = vptr - 0x10 (offset-to-top 0x12dddd8 = 0,
  typeinfo slot 0x12ddde0 = 0x12dde30); installed vptr = cell + 0x10.
- RTTI: typeinfo 0x12dde30 = {0x10, name 0xf815f0, base 0x12f8d30}; name =
  "N2nn3pia7session16KickoutManageJobE"; base = nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x98439c, 1 D0 0x9843d4, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5-7 `ret` stubs 0x984a64/0x984a68/0x984a6c (base no-op
  overrides; the derived LocalKickoutManageJob fills these).
- D1 0x98439c: re-installs vptr, destroys the +0x160 sub-object (0x929ee0),
  tail 0xb4a62c (shared job-base D0). D0 0x9843d4: same body then
  operator delete 0x60b470.
- extent 0x190 EXACT: operator new 0x190 then C1 0x984354 at two factories
  (0x931954-0x931968 and 0x96d02c-0x96d040).

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- [0x58, 0x158) untouched by C1 — unproven gap.
- +0x160 sub-object built by 0x929ec0 (same builder as JoinSessionJob +0x60 and
  LanMatchmakeUpdateJob +0xd78); only the vptr at +0x160 is vtable-proven.

## Construction / init order

1. C1 0x984354: base C1 0xb4a5e0(this) (0x984364).
2. vptr 0x12ddde8 -> [this] (0x984378, cell 0x13137a0 + 0x10).
3. Sub-object ctor 0x929ec0(this + 0x160) (0x98437c).
4. Tail zeroes: [0x18c] = 0, [0x158] = 0, [0x180] = 0, [0x188] byte = 0
   (0x984380-0x98438c).
