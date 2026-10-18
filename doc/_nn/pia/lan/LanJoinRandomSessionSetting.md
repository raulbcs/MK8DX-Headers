# LanJoinRandomSessionSetting (nn::pia::lan::LanJoinRandomSessionSetting)

- vptr 0x12dc048 = first slot row; offset-to-top 0 at 0x12dc038, typeinfo
  0x12dc0a0 at 0x12dc040 ("N2nn3pia3lan27LanJoinRandomSessionSettingE"). GOT
  cell 0x1313300 holds addend 0x12dc038 = vptr-0x10.
- Size 0x680, exact: C1 is used as a member constructor at aggregator+0x5708
  of settings aggregator C1 0x912cc0 (call 0x912df4), next member initialized
  at aggregator+0x5d88 (0x912dfc-0x912e14); deepest in-class store +0x678
  (0x96c920).

## Identity

pia LAN variant of the "join random session" settings blob; sibling of
nn::pia::inet::NexJoinRandomSessionSetting (vt 0x12d98a8, size 0x2078). Both
are embedded in aggregator C1 0x912cc0 (+0x5708 and +0x21a0).

## Member notes

- +0x08 subobject vptr installed by 0x96c32c (C1, 0x96c900) — LAN settings
  base; re-touched by 0x96c41c (0x96c924).
- +0x1c8 and +0x420 member subobjects, C1 0x973a74 (0x96c90c, 0x96c918);
  both receive a virtual call [x8,#0x18] in the C1 tail (0x96c928-0x96c950).
- +0x678 u32 = 0.

## Construction / init order

- C1 = 0x96c8d4 (vptr, subobject C1 0x96c32c at +0x08, member C1s +0x1c8 and
  +0x420, +0x678 = 0, subobject calls 0x96c41c/+0x18 vcalls).
- D1 = slot 0, 0x96c954; D0 = slot 1, 0x96c99c (operator delete 0x60b470).
- Slots (11): 0=0x96c954 (D1), 1=0x96c99c (D0), 2=0x96ca3c, 3=0x96ca78,
  4=0x96c9f4, 5=0x96cb40, 6=0x96caf8, 7=0x96cb00, 8=0x96cb1c, 9=0x96cb24,
  10=0x96cb44. Slots 2-10 unrecovered.
- No standalone factory: always a member of aggregator C1 0x912cc0
  (+0x5708).
