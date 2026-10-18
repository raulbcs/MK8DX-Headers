# StationConnectionInfo (nn::pia::transport::StationConnectionInfo)

- vptr 0x12df380 installed from GOT cell 0x1313c40 (RELATIVE addend 0x12df370 =
  vt-0x10; code does `cell+0x10`). vt_ctors.tsv row 0x12df378 is the typeinfo
  slot. Typeinfo 0x12df3c8, name
  "N2nn3pia9transport21StationConnectionInfoE", no base (root class).
- Size 0x78 (lower bound: C2/D2 only touch 0x00..0x77; all observed
  constructions are stack objects, e.g. 0x923d44, 0x92dd84, 0x9402f4 — no heap
  allocation site found).

## Identity

Per-station connection state record in the pia transport stack: two identical
0x38-byte member records, one per connection direction/endpoint.

## Slots

Primary vtable 0x12df380, 9 slots:
- slot 0 = 0x9b20b4 (D2: reinstalls vptr, runs member D 0x9b3a40 on +0x40 then
  +0x08)
- slot 1 = 0x9b20ec (D0: same teardown; also used as copy-form C2 body source —
  copy C2 0x9b2020 and assign-form 0x9b20ec region)
- slots 2..8 = 0x9b21c0 / 0x9b21f4 / 0x9b22e8 / 0x9b237c / 0x9b2384 /
  0x9b2524 / 0x9b26a4 (0x9b26a4 quality O, 4 bytes; rest unrecovered)

## Member notes

- 0x08 / 0x40 — two 0x38-byte member records (ctor 0x9b38b8, D 0x9b3a40, copy
  0x9b39bc). Each record: vptr 0x12df3e8 (cell 0x1313c50 + 0x10), inner member
  at +0x30 (ctor 0x929fd4), zeroed flags/bytes at +0x18..+0x2e.
- Copy C2 0x9b2020 copies both records via 0x9b39bc and the scalar fields.

## Construction / init order

1. C2 0x9b1fe8 installs vptr 0x12df380 at [this], then runs ctor 0x9b38b8 on
   +0x08 and +0x40 (in that order).
2. Copy C2 0x9b2020 (arg = source): vptr, ctor both members, then member copies
   0x9b39bc(+0x08, src+0x08) and the +0x40 record.
3. D2 0x9b20b4 destroys +0x40 then +0x08 via 0x9b3a40; D0 (0x9b20ec region)
   additionally deletes this.
