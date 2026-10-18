# nn::pia::local::LocalKickoutManageJob

## Identity

- vtable row 0x12e1910 (tsv row = typeinfo slot), vptr 0x12e1918 = row + 8, 9 slots.
  GOT cell 0x1314038 holds 0x12e1908 = vptr - 0x10 (offset-to-top 0x12e1908 = 0,
  typeinfo slot 0x12e1910 = 0x12e1960); installed vptr = cell + 0x10.
- RTTI: typeinfo 0x12e1960 = {0x10, name 0xf83530, base 0x12dde30}; name =
  "N2nn3pia5local21LocalKickoutManageJobE"; base = nn::pia::session::KickoutManageJob
  (base C1 0x984354 called directly by the derived C1 0x9d127c).
- Slots: 0 D1 0x9d12b4, 1 D0 0x9d12cc, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314 (inherited cluster), 5 `ret` 0x9d1324, 6 0x9d1304
  (Step override: x8 = [this+0x190], sets byte [x8+0x33c] = 1 via
  [[x8+0x18]]), 7 0x9d1318 (tail 0x9c6b78([[this+0x190]+0x18])).
- D1 0x9d12b4: [this+0x190] = 0, re-installs vptr, tail base D1 0x98439c.
  D0 0x9d12cc: same then operator delete 0x60b470.
- extent 0x198 EXACT: operator new 0x198 at 0x9c3c20-0x9c3c38 followed by
  C1 0x9d127c (sole allocation site).

## Member notes

- [0x00, 0x190) is the KickoutManageJob subobject (base C1 0x984354,
  extent 0x190 — see doc/_nn/pia/session/KickoutManageJob.md).
- +0x190 = C1 arg x1 (0x9d129c), stored after the base C1 returns; nulled by
  D1. The stored pointer's [+0x18] sub-object is dereferenced by slots 6/7.

## Construction / init order

1. C1 0x9d127c: base C1 0x984354(this) (0x9d1290).
2. [this+0x190] = x1 (0x9d129c).
3. vptr 0x12e1918 -> [this] (0x9d12a4, cell 0x1314038 + 0x10).
