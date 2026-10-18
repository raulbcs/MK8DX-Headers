# object::Vt12d8ee0

PLACEHOLDER name (identity not proven). vptr 0x12d8ee0, 21 slots (0x00-0xa0), all
unrecovered in functions.csv. GOT cell 0x1312310 holds vt-0x10 (0x12d8ed0); the
installed vptr is cell+0x10.

## Member notes

- size 0x1068, proven by operator-new at 0x90f528 (`mov w0, #0x1068` before 0x60afec).
- [this+0x00] vptr — installed by C1 0x90f544 *after* the base-ctor call, overriding
  the base vptr written by 0x91636c (cell 0x13123c8+0x10).
- [this+0x08]/[this+0x09] u8 flags — cleared by base ctor 0x91636c (0x916388/0x9163a0);
  0x9 becomes a bit `1 << n` from the caller's word argument (0x9163b8).
- [this+0x10..0x38] — zeroed by base ctor 0x91636c (0x9163c8-0x9163e0). Deeper fields
  of the 0x1068 body are initialized inside 0x91636c and successors (0x9165b0..),
  unverified.
- [this+0x30] ptr — tick companion, a separate new(0x20) object: vptr 0x12d8e70
  (GOT cell 0x1312318), [comp+0x08] = back-pointer to this, [comp+0x10] u16 = 0,
  [comp+0x18] = nn::os::GetSystemTick() (0x90f554-0x90f578).

## Construction / init order

- C1 = 0x90f514: new(0x1068) (0x90f528-0x90f530) -> base ctor 0x91636c(this, arg)
  (0x90f53c) -> vptr 0x12d8ee0 at [this] (0x90f540-0x90f550) -> new(0x20) companion,
  its vptr 0x12d8e70, back-ptr, system tick (0x90f554-0x90f570) -> companion stored
  at [this+0x30] (0x90f578). Return value of the enclosing factory continues with the
  caller-owned object at [x20+0x18] (0x90f57c).
- Slot set (slot 0..20 at 0x12d8ee0+0x8*i): 0x9218e4, 0x9218ec, 0x9165b0, 0x916ab0,
  0x916d44, 0x917024, 0x91716c, 0x916d70, 0x916d9c, 0x9176ac, 0x917680, 0x917698,
  0x921878, 0x9176bc, 0x917590, 0x917620, 0x916574, 0x91714c, 0x916944, 0x917470,
  0x917f6c — none resolved in functions.csv (unrecovered).
- Twin class Vt12d8fb0 is built by the sibling factory 0x90f590 with the identical
  pattern (size 0x428, companion vptr 0x12d8ea8 stored at [this+0x10]).
