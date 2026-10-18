# nn::pia::local::LocalScanNetworkJob

## Identity

- vtable row 0x12e0db0 (tsv row = typeinfo slot), vptr 0x12e0db8 = row + 8,
  6 slots. GOT cell 0x1313e10 holds 0x12e0da8 = vptr - 0x10 (offset-to-top
  0x12e0da8 = 0, typeinfo slot 0x12e0db0 = 0x12e0df0); installed vptr =
  cell + 0x10.
- RTTI: typeinfo 0x12e0df0 = {0x10, name 0xf83080, base 0x12f8d30, 0}; name =
  "N2nn3pia5local19LocalScanNetworkJobE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x9c98f8, 1 D0 0x9c9944, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314 (shared StepSequenceJob cluster), 5 bare `ret` 0x9c9ba8.
- D1 0x9c98f8 / D0 0x9c9944: re-install vptr, destroy + free the +0x60
  subobject (0x929ee0 then 0x568b64), null +0x68; tail 0xb4a62c (D0 then adds
  operator delete 0x60b470).
- size 0x70 EXACT: operator new 0x70 at 0x9c52b0 (factory, result stored at
  [owner+0x288]); sole site found.
- Non-virtual member LocalScanNetworkJob::WaitForCancel 0x9c9a30 (functions.csv
  recovered name) — not a vtable slot.

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58: zeroed by C2 (0x9c98b8).
- +0x60: 0x20-byte heap subobject (alloc 0x568aa0 at 0x9c98d4, ctor 0x929ec0
  at 0x9c98e4); destroyed by D1/D0.
- +0x68: C2 x1 argument (0x9c98bc), cleared by D1/D0 (0x9c9930/0x9c9958 path).
- 0x9c990c (between C2 and D1, not a slot): D2-style — re-installs vptr,
  destroys +0x60, nulls +0x68, tail 0xb4a62c.

## Construction / init order

1. C2 0x9c9898: base C1 0xb4a5e0(this) (0x9c98ac).
2. +0x58 = 0 (0x9c98b8); arg -> +0x68 (0x9c98bc).
3. vptr 0x12e0db8 -> [this] (0x9c98c4, cell 0x1313e10 + 0x10).
4. sub = alloc 0x20 (0x9c98d4); 0x929ec0(sub) (0x9c98e4); sub -> +0x60
   (0x9c98e8).
- Factory: operator new 0x70 at 0x9c52b0, C2 0x9c9898 at 0x9c52c4, ptr stored
  at [owner+0x288] (0x9c52c8).
