# nn::pia::local::LocalResendMessageJob

## Identity

- vtable row 0x12e0d50 (tsv row = typeinfo slot), vptr 0x12e0d58 = row + 8,
  6 slots. GOT cell 0x1313e00 holds 0x12e0d48 = vptr - 0x10 (offset-to-top
  0x12e0d48 = 0, typeinfo slot 0x12e0d50 = 0x12e0d90); installed vptr =
  cell + 0x10.
- RTTI: typeinfo 0x12e0d90 = {0x10, name 0xf83040, base 0x12f8d30, 0}; name =
  "N2nn3pia5local21LocalResendMessageJobE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x9c9644, 1 D0 0x9c96a4, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314 (shared StepSequenceJob cluster), 5 bare `ret` 0x9c9894.
- D1 0x9c9644 / D0 0x9c96a4: re-install vptr, destroy + free the +0x78 buffer
  (0x568bb0 then 0x568b64), free +0x70 (0x568b64), null both and +0x80;
  tail 0xb4a62c (D0 then adds operator delete 0x60b470).
- size 0x88 EXACT: operator new 0x88 at 0x9c53e0 (factory 0x9c52c4 region,
  result stored at [owner+0x2c0]); sole site found.

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58 / +0x60: zeroed by C2 (stp xzr, xzr at 0x9c95c0).
- +0x68 u32 = 100 (0x9c95bc).
- +0x70: 0x18-byte heap buffer (alloc 0x568aa0 at 0x9c9614); 0x9d43d4 is
  called with (buf70, buf78, 0x5d8) at 0x9c962c — role unverified.
- +0x78: 0x5d8-byte heap buffer, zero-filled byte-wise loop (0x9c95e0-0x9c9600).
- +0x80: C2 x1 argument (0x9c95d4).

## Construction / init order

1. C2 0x9c9598: base C1 0xb4a5e0(this) (0x9c95b0).
2. +0x58/+0x60 = 0 (0x9c95c0); +0x68 = 100 (0x9c95c4); +0x70/+0x78 = 0
   (0x9c95c8).
3. vptr 0x12e0d58 -> [this] (0x9c95d0, cell 0x1313e00 + 0x10); arg -> +0x80
   (0x9c95d4).
4. buf78 = alloc 0x5d8, zero-filled (0x9c95e0-0x9c9600) -> +0x78.
5. buf70 = alloc 0x18 (0x9c9614); 0x9d43d4(buf70, buf78, 0x5d8) (0x9c962c)
   -> +0x70.
- Factory: operator new 0x88 at 0x9c53e0, C2 0x9c9598 at 0x9c53f4, ptr stored
  at [owner+0x2c0] (0x9c53f8).
