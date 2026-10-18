# nn::pia::local::LdnUpdateSessionSetting

## Identity

- vtable row 0x12e03e0 (tsv row = typeinfo slot), vptr 0x12e03e8 = row + 8, 12 slots.
  GOT cell 0x1313d70 holds 0x12e03d8 = vptr - 0x10 (offset-to-top row 0x12e03d8 = 0,
  descriptor slot 0x12e03e0 = 0x12e0450); installed vptr = cell + 0x10.
- RTTI: descriptor 0x12e0450 = {0x10, name 0xf82e10, base 0x12e0f50, 0};
  name 0xf82e10 = "N2nn3pia5local23LdnUpdateSessionSettingE";
  base 0x12e0f50 = "N2nn3pia5local25LocalUpdateSessionSettingE".
- Slots (12, mostly unrecovered): 0 0x9c2458 (D1, tail b 0x9c9da4 = base D1),
  1 0x9c245c (D0), 2 0x9c24e4, 3 0x9c2544, 4 0x9c9de4 (shared with the
  LocalUpdateSessionSetting table), 5-8 0x99f4d8/0x99f4a8/0x99f4b0/0x99f4c8
  (shared markers), 9 0x9c24b8, 10 0x9c25a8, 11 0x9c25b0.
- extent 0x178: max C1 store = memset(this + 0x10, 0, 0x168) (0x9c2444); not
  operator-new proven (unverified tail).

## Member notes

- [0x10,0x178) memset 0 by the C1 (0x9c2444).
- Base region: base C1 0x9c9d70 (LocalUpdateSessionSetting) zeroes +0xc and
  installs the base vptr; [0x08,0x0c) gap unproven.
- Slot 0 D1 0x9c2458 is a 4-byte tail-branch to 0x9c9da4 (base D1); slot 1 D0
  0x9c245c calls 0x9c9da4 then the deleting path.

## Construction / init order

1. C1 0x9c241c: base C1 0x9c9d70(this) (0x9c242c).
2. vptr 0x12e03e8 -> [this] (0x9c243c).
3. memset(this + 0x10, 0, 0x168) (0x9c2444-0x9c2454).
