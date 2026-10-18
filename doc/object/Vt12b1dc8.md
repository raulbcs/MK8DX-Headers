# Vt12b1dc8 (object::Vt12b1dc8)

PLACEHOLDER name (identity not proven). 0x68-byte record whose default init
seeds four floats with 1.0f and zeroes a 0x48-byte tail; an alternate
copy-style init takes the same fields from two source objects.

- Identity: no RTTI (typeinfo slot 0x12b1dc0 = 0); vptr 0x12b1dc8 installed
  from GOT cell 0x130d880 (addend 0x12b1db8 = vt-0x10; vptr = cell+0x10).
- Size: 0x68 — memset(this+0x20, 0, 0x48) at 0x710063ece0/0x710063ed24;
  tail ends exactly at 0x68.
- Family: derived override of the 0x12b0e38 base (GOT cell 0x130d6f0, row
  unmapped) — the copy init at 0x710063ecec first installs the base vptr
  from cell 0x130d6f0 then overwrites [x0] with 0x12b1dc8. Shares the
  0x62ab30/0x62ab34 stub pair with Vt12b1818.

## Slots (8)

- slot 0 = 0x63f5fc (U, 0x288; presumed D1), slot 1 = 0x63f71c (U, 0x92).
- slot 2 = 0x63ed3c (O; tail `b 0x62ab34` — shared family helper).
- slot 3 = 0x63ed40 (D0: calls 0x62ab34 then `b operator delete 0x60b470`).
- slot 4 = 0x63f0a4 (U, 0x520), slot 5 = 0x63f2ac (M, 0x296),
  slot 6 = 0x62ab30 (shared stub), slot 7 = 0x63f00c (U, 0x152).

## Member notes

- Default init (0x710063ecbc): 1.0f -> +0x08/+0x0c/+0x18/+0x1c
  (`orr w9, wzr, #0x3f800000`), 0 -> +0x10, vptr store, zero tail.
- Copy init (0x710063ecec): [param1] -> +0x08, [param2] -> +0x10,
  [param2+8] -> +0x18, then vptr override and zero tail — same layout
  with copied scalars (float interpretation unverified for this path).
- Helper FUN_710063ec74 reads +0x2c, +0x18, +0x10 and +0x20 as
  (count, base, ptr, extra) for a stride computation `mul/madd` —
  +0x18/+0x2c behave as integers there, so the +0x1c float read is
  confined to +0x1c..+0x1f (unverified).

## Construction / init order

- Default: vptr -> +0x00 (last), floats first — order: floats, +0x10 = 0,
  vptr, memset tail (0x710063ecbc-0x710063ece8).
- Copy: base vptr, +0x08/+0x10/+0x18 from params, then 0x12b1dc8 vptr
  override, memset tail (0x710063ecec-0x710063ed38).
