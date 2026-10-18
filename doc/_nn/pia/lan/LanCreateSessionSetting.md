# LanCreateSessionSetting (nn::pia::lan::LanCreateSessionSetting)

- vptr 0x12dbfd0 = first slot row; typeinfo 0x12dc020 at 0x12dbfc8
  ("N2nn3pia3lan23LanCreateSessionSettingE", base
  session::CreateSessionSetting, ti 0x12dda50 — whose base slot is empty,
  root, unverified). GOT cell 0x13132e8 holds addend 0x12dbfc0 = vptr-0x10.
- Size 0x1c0: member stride in settings aggregator C1 0x912cc0 — the C1 is
  called at aggregator+0x5080 (0x912dc4) and the next member init starts at
  aggregator+0x5240 (0x973a74 at 0x912dd0).

## Identity

pia LAN variant of the "create session" settings blob; sibling of
nn::pia::session::CreateSessionSetting (base). Always constructed in place
as a member (aggregator 0x912cc0 at +0x5080; no standalone factory found).

## Member notes

- +0x08 u64 = 0, +0x10 u32 = 0 (C1 0x96c32c).
- +0x18..0x2f and +0x30..0x1af memset 0 by C1 (0x96c36c / 0x96c384).
- +0x1b0 u32, +0x1b4 u8, +0x1b8 u32 = 0 (0x96c34c-0x96c368).

## Construction / init order

- C1 = 0x96c32c: vptr from GOT cell 0x13132e8 (+0x10), zero/memset as above.
- D1 = slot 0, 0x96c388 (tail 0x97f010); D0 = slot 1, 0x96c38c (then
  operator delete 0x60b470).
- Slots (9): 0=0x96c388 (D1), 1=0x96c38c (D0), 2=0x97f038, 3=0x96c46c,
  4=0x96c4d0, 5=0x96c534, 6=0x96c53c, 7=0x96c41c, 8=0x96c640.
  Slots 2-8 unrecovered (no symbols).
