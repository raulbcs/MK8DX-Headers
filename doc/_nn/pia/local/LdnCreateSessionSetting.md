# nn::pia::local::LdnCreateSessionSetting

## Identity

- vtable row 0x12dfa60 (tsv row = typeinfo slot), vptr 0x12dfa68 = row + 8, 12 slots.
  GOT cell 0x1313d10 holds 0x12dfa58 = vptr - 0x10 (offset-to-top row 0x12dfa58 = 0,
  descriptor slot 0x12dfa60 = 0x12dfad0); installed vptr = cell + 0x10.
  Cells 0x1313d00/0x1313d08 are NOT vtable cells: they point at constant u32 0x7d0
  (2000) values at 0x12dfa50/0x12dfa54, selected by `csel` on [this+0x18] == 9 in
  0x9bd97c.
- RTTI: descriptor 0x12dfad0 = {0x10, name 0xf82bc0, base 0x12e05e0, 0};
  name 0xf82bc0 = "N2nn3pia5local23LdnCreateSessionSettingE";
  base 0x12e05e0 = "N2nn3pia5local25LocalCreateSessionSettingE".
- Slots (12, mostly unrecovered): 0 0x9bdd30 (D1), 1 0x9bdd34 (D0), 2 0x9bdee8,
  3 0x9bde10, 4 0x9bde70, 5 0x9bded4, 6 0x9bdedc, 7 0x9bdd58, 8 0x9bdee4,
  9 0x9bdef4, 10 0x9c2a74, 11 0x9bddb0.
- extent 0x238: max C1 store byte [0x230] (0x9bdd20); not operator-new proven
  (unverified tail padding).

## Member notes

- +0x50 = 0x9762c8 (function pointer loaded from cell 0x1313478 + 0x10, 0x9bdd08);
  +0x58 = 0; +0x60 = 0 (0x9bdcd8); [0x64,0xa4) memset (0x9bdd0c); +0xa4 = 0
  (0x9bdce4); [0xa5,0x225) memset (0x9bdd10); +0x228 u32 = 0 (0x9bdce8);
  +0x22c u16 = 0 (0x9bdcec); +0x230 byte = 0 (0x9bdd20).
- [0x08,0x50) built by base C1 0x9c293c (LocalCreateSessionSetting: +0x10
  secondary vptr from cell 0x1312858, +0x20 = 0x20) — gap unproven here.

## Construction / init order

1. C1 0x9bdcbc: base C1 0x9c293c(this) (0x9bdccc).
2. vptr 0x12dfa68 -> [this] (0x9bdd04); +0x50 static fn ptr, +0x58 = 0 (0x9bdd08).
3. +0x60 = 0; [0x64,0xa4) memset; +0xa4 = 0; [0xa5,0x225) memset (0x9bdd0c-
   0x9bdd1c).
4. +0x228 = 0, +0x22c halfword = 0, +0x230 byte = 0 (0x9bdce8-0x9bdd20).
