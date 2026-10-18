# nn::pia::local::LdnJoinSessionSetting

## Identity

- vtable row 0x12dfaf0 (tsv row = typeinfo slot), vptr 0x12dfaf8 = row + 8, 12 slots.
  GOT cell 0x1313d18 holds 0x12dfae8 = vptr - 0x10 (offset-to-top row 0x12dfae8 = 0,
  descriptor slot 0x12dfaf0 = 0x12dfb60); installed vptr = cell + 0x10.
- RTTI: descriptor 0x12dfb60 = {0x10, name 0xf82bf0, base 0x12e0700, 0};
  name 0xf82bf0 = "N2nn3pia5local21LdnJoinSessionSettingE";
  base 0x12e0700 = "N2nn3pia5local23LocalJoinSessionSettingE".
- Slots (12, mostly unrecovered): 0 0x9c38dc (D1), 1 0x9be054 (D0), 2 0x983278,
  3 0x9c399c, 4 0x9c39a0, 5 0x9832ac, 6 0x9832b4, 7 0x983270, 8 0x9bdfc8,
  9 0x9be078, 10 0x9bdff4, 11 0x9c39b8. (The sibling LdnCreateSessionSetting
  vtable 0x12dfa68 appears in slots 2-7 region of LocalJoinSessionSetting's
  table — the Local/Ldn setting pair shares a marker cluster.)
- extent 0x98: max C1 store = memset(this + 0x58, 0, 0x40) (0x9bdfc4); base C1
  0x9c3840 covers [0x00,0x40) (upper boundary unproven); not operator-new
  proven (unverified tail).

## Member notes

- [0x58,0x98) memset 0 by the C1 (0x9bdfb4-0x9bdfc4).
- Base region [0x08,0x40+) built by base C1 0x9c3840 (LocalJoinSessionSetting:
  +0x16 byte 0, +0x18 secondary vptr from cell 0x1312858, +0x28 = 0x20,
  halfword chain 0x35-0x3d) — gap unproven here.
- Function 0x9bdfc8 (slot 8) destroys [this+0x58,0x98) via base 0x9c3924 then
  memset — member cleanup helper.

## Construction / init order

1. C1 0x9bdf8c: base C1 0x9c3840(this) (0x9bdf9c).
2. vptr 0x12dfaf8 -> [this] (0x9bdfac).
3. memset(this + 0x58, 0, 0x40) (0x9bdfb4-0x9bdfc4).
