# NexJoinRandomSessionSetting (nn::pia::inet::NexJoinRandomSessionSetting)

- vptr 0x12d98a8 = first slot row; offset-to-top 0 at 0x12d9898, typeinfo
  0x12d9910 at 0x12d98a0 ("N2nn3pia4inet27NexJoinRandomSessionSettingE").
  GOT cell 0x13128c8 holds addend 0x12d9898 = vptr-0x10; every ctor/dtor does
  `cell + 0x10` before storing (0x92ea3c, 0x92ead0, 0x92eb20).
- Size 0x2078, exact: C1 is used as a member constructor at outer+0x21a0 of
  the settings aggregator C1 0x912cc0 (call 0x912d18), and the next member is
  constructed at outer+0x4218 (0x912d24). Deepest in-class store is the byte
  at +0x2076 (0x92ea7c).

## Identity

pia inet "join random session" settings blob (NEX variant). Sibling of
nn::pia::lan::LanJoinRandomSessionSetting (vt 0x12dc048) — same shape, both
embedded in aggregator C1 0x912cc0.

## Member notes

- +0x00 vptr; +0x08 subobject vptr installed by 0x92b5f0 (called with
  this+0x08, 0x92ea44), torn down by 0x92ba5c (D-tor tail, 0x92eaf8).
- +0x630 and +0x1350 member subobjects: C1 0x933694 (0x92ea50, 0x92ea60),
  D 0x933b28 (0x92eae0, 0x92eae8); entries dispatched virtually during C1
  ([+0x630]+0x18, 0x92ea84-0x92ea90) and at +0x1350 (0x92ea94).
- +0x2070 u32 = 0, +0x2074 u16 = 0x101, +0x2076 u8 = 0 (0x92ea68-0x92ea7c).

## Construction / init order

- C1 = 0x92ea18 (vptr, subobject C1 0x92b5f0 at +0x08, member C1s +0x630 and
  +0x1350, then 0x92bc74(this+8), virtual calls, flag stores).
- D1 = slot 0, 0x92eab0 (reinstall vptr, member Ds +0x1350 then +0x630, tail
  0x92ba5c on this+8). D0 = slot 1, 0x92eafc (same chain, then operator
  delete 0x60b470).
- Slots (11): 0=0x92eab0 D1, 1=0x92eafc D0, 2=0x92ebb8, 3=0x92ebf4,
  4=0x92eb58, 5=0x92ed30, 6=0x92eca0, 7=0x92eca8, 8=0x92ecc4, 9=0x92eccc,
  10=0x92ed04; slots 2-10 unrecovered (absent from functions.csv except as
  raw addresses above).
- No standalone factory: object is always a member (aggregator C1 0x912cc0,
  offset +0x21a0). Lan sibling lives at aggregator +0x5708.
