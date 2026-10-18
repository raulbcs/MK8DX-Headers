# JoinSessionSetting (nn::pia::session::JoinSessionSetting)

- vptr 0x12ddc98 = first slot row; typeinfo 0x12ddce0 at 0x12ddc90
  ("N2nn3pia7session18JoinSessionSettingE"; base slot empty — root,
  unverified). GOT cell 0x1313790 holds addend 0x12ddc80 = vptr-0x10.
- Size 0x18: derived nn::pia::lan::LanJoinSessionSetting (vt 0x12dc0c8) is
  size 0x18 by member stride in aggregator C1 0x912cc0 (+0x56f0 → next
  member +0x5708) and adds no fields; deepest base store +0x14.

## Identity

pia session "join session" settings blob; base of
nn::pia::lan::LanJoinSessionSetting. Getter/setter-style vtable (slots 2-8),
no job-framework slots. An inet-side derived ctor (0x9c3840) keeps the base
C1 0x98324c and stores its own u32 at derived+0x28 (unverified which
derived).

## Member notes

- +0x08 ptr: slot 7 setter 0x983270 (`str x1,[x0,#8]`), slot 2 getter
  0x983278 (`ldr x0,[x0,#8]`).
- +0x10 u32: slot 3 setter 0x983280 (`str w1,[x0,#0x10]`); slot 4 getter
  0x983288 returns +0x10, and if 0 walks the +0x08 ptr's vtable slot +0x18.
- +0x14 u16: slot 5 setter 0x9832ac (`strh w1,[x0,#0x14]`); slot 6 getter
  0x9832b4 (unverified body).

## Construction / init order

- C1 = 0x98324c: vptr from GOT cell 0x1313790 (+0x10) at +0x00, +0x08 = 0,
  +0x10 u32 = 0, +0x14 u16 = 0.
- D1 = slot 0, 0x983268 (plain ret — trivial); D0 = slot 1, 0x98326c
  (operator delete 0x60b470).
- Slots (9): 0=0x983268 (D1), 1=0x98326c (D0), 2=0x983278, 3=0x983280,
  4=0x983288, 5=0x9832ac, 6=0x9832b4, 7=0x983270, 8=0x9832d4 (unrecovered).
