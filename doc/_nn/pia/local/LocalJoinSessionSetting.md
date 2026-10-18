# LocalJoinSessionSetting (nn::pia::local::LocalJoinSessionSetting)

- vptr 0x12e0698 installed from GOT cell 0x1313da8 (RELATIVE addend 0x12e0688 =
  vt-0x10; code does `cell+0x10`). vt_ctors.tsv row 0x12e0690 is the typeinfo
  slot. Typeinfo 0x12e0700, name
  "N2nn3pia5local23LocalJoinSessionSettingE", base
  nn::pia::session::JoinSessionSetting (base vptr cell 0x1313790).
- Size 0x58, proven by the derived-class inline ctor at 0x9bdf9c (Ldn
  JoinSessionSetting family, vptr override cell 0x1313d18) which runs this C2
  and then memsets a 0x40-byte block at [this+0x58].

## Identity

Local (LDN) flavor of the pia join-session setting record; carries a secondary
base at +0x18 and a zeroed parameter block at +0x34.

## Slots

Primary vtable 0x12e0698, 9 slots:
- slot 0 = 0x9c38dc (D2: reinstalls vptr, tail `b 0x983268` base D2)
- slot 1 = 0x9c38f0 (D0: D2 + `operator delete` 0x60b470)
- slot 2 = 0x983278 (base: returns [this+0x08])
- slot 3 = 0x9c399c, slot 4 = 0x9c39a0 (unrecovered)
- slot 5 = 0x9832ac, slot 6 = 0x9832b4 (base, unrecovered)
- slot 7 = 0x983270 (base: stores x1 into [this+0x08])
- slot 8 = 0x9c3924 (U, 148; called by the derived teardown at 0x9bdfd8)

## Member notes

- 0x08..0x17 — JoinSessionSetting base fields (+0x08 ptr zero, +0x10 word
  zero, +0x14 halfword zero), from base C2 0x98324c.
- 0x18 — secondary base subobject, vptr 0x12d9748 (cell 0x1312858 + 0x10);
  secondary type name unverified.
- 0x20 — C2 stores this+0x34 (list/vector-style head, unverified);
  0x28 — 0x20; 0x2c — 0.
- 0x34..0x57 — 0x34-byte block zeroed with byte/halfword stores
  (0x9c3880..0x9c38c4).

## Construction / init order

1. C2 0x9c3840 calls base C2 0x98324c, sets [this+0x28]=0x20.
2. Installs primary vptr 0x12e0698 at [this] and secondary vptr 0x12d9748 at
   [this+0x18].
3. Zeroes byte +0x16, then the 0x34..0x57 block; stores this+0x34 at [this+0x20]
   and 0 at [this+0x2c].
4. Derived ctor 0x9bdf9c overrides [this] with its own vptr and adds the
   +0x58..0x97 block; D2 0x9c38dc / D0 0x9c38f0 run the reverse.
