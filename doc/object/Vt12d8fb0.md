# object::Vt12d8fb0

PLACEHOLDER name (identity not proven). vptr 0x12d8fb0, 21 slots (0x00-0xa0), all
unrecovered in functions.csv. GOT cell 0x1312320 holds vt-0x10 (0x12d8fa0); the
installed vptr is cell+0x10.

## Member notes

- size 0x428, proven by operator-new at 0x90f5a4 (`mov w0, #0x428` before 0x60afec).
- [this+0x00] vptr — installed by C1 0x90f5c0 after the base ctor 0x9104bc.
- [this+0x10] ptr — tick companion, a separate new(0x20) object: vptr 0x12d8ea8
  (GOT cell 0x1312328), [comp+0x08] = back-pointer to this, [comp+0x10] u16 = 0,
  [comp+0x18] = nn::os::GetSystemTick() (0x90f5d0-0x90f5f0).
- Other fields initialized by 0x9104bc and successors, unverified.

## Construction / init order

- C1 = 0x90f590: new(0x428) (0x90f5a4-0x90f5ac) -> base ctor 0x9104bc(this, arg)
  (0x90f5b8) -> vptr 0x12d8fb0 at [this] (0x90f5bc-0x90f5cc) -> new(0x20) companion,
  vptr 0x12d8ea8, back-ptr, system tick (0x90f5d0-0x90f5ec) -> companion stored at
  [this+0x10] (0x90f5f4).
- Slot set (slot 0..20 at 0x12d8fb0+0x8*i): 0x921c64, 0x921c6c, 0x9106b8, 0x910908,
  0x910b90, 0x910d24, 0x910e34, 0x910bbc, 0x910be8, 0x910fac, 0x911574, 0x91157c,
  0x921bf8, 0x910fbc, 0x9116fc, 0x91170c, 0x910664, 0x910e14, 0x910814, 0x910efc,
  0x91171c — none resolved in functions.csv (unrecovered).
- Twin of Vt12d8ee0 (factory pair 0x90f514/0x90f590); differs in size (0x428 vs
  0x1068), base ctor, companion vptr and companion offset (0x10 vs 0x30).
