# LanJoinSessionSetting (nn::pia::lan::LanJoinSessionSetting)

- vptr 0x12dc0c8 = first slot row; typeinfo 0x12dc110 at 0x12dc0c0
  ("N2nn3pia3lan21LanJoinSessionSettingE", base session::JoinSessionSetting,
  ti 0x12ddce0). GOT cell 0x1313308 holds addend 0x12dc0b8 = vptr-0x10.
- Size 0x18: member stride in settings aggregator C1 0x912cc0 — C1 called at
  aggregator+0x56f0 (0x912de8) and the next member C1
  (LanJoinRandomSessionSetting, 0x96c8d4) at aggregator+0x5708 (0x912df4).

## Identity

pia LAN variant of the join-session settings blob; trivial derived class of
nn::pia::session::JoinSessionSetting (vt 0x12ddc98, size 0x18) — C1 0x96cb4c
only runs the base C1 0x98324c then swaps the vptr (0x96cb60-0x96cb6c).

## Construction / init order

- C1 = 0x96cb4c: base C1 0x98324c, then vptr store (cell 0x1313308 + 0x10).
- D1 = slot 0, 0x96cb7c (tail 0x983268 = plain ret); D0 = slot 1, 0x96cb80
  (base tail 0x983268 then operator delete 0x60b470).
- Slots (9): 0=0x96cb7c (D1), 1=0x96cb80 (D0), 2=0x983278 (shared base),
  3=0x96cba4 (ret), 4=0x983288 (shared base), 5=0x9832ac (shared base),
  6=0x9832b4 (shared base), 7=0x983270 (shared base), 8=0x96cba8 (tail
  0x9832d4). Overrides vs base: slot 3 and slot 8.
