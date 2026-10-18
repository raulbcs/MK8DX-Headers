# nn::pia::inet::MonitoringDataSendJobBase

Identity: typeinfo-row vtable, assigned address 0x12dba20 (= typeinfo slot,
vptr-8); installed vptr **0x12dba28**. GOT cell 0x13131f8 holds vptr-0x10
(0x12dba10 = offset-to-top 0). Typeinfo data 0x12dba60, name
"N2nn3pia4inet21MonitoringDataSendJobE", base typeinfo 0x12f8d30
("N2nn3pia6common15StepSequenceJobE"). 6 slots (0x12dba28..0x12dba58).

NOTE: this vtable is the true RTTI carrier of "MonitoringDataSendJob". The
pre-existing include/_nn/pia/inet/MonitoringDataSendJob.hpp /
doc/_nn/pia/inet/MonitoringDataSendJob.md actually document vtable
0x12ddae8, whose typeinfo 0x12ddb30 is
"N2nn3pia7session34GenerateMatchmakeSystemPasswordJobE" — mislabeled by an
earlier pass. Not fixed here (out of scope).

## Member notes

- Slot0 0x9647a0: D1 — re-installs vptr 0x12dba28 (cell 0x13131f8 + 0x10),
  calls stub 0x929ee0 at this+0x58, then tail `b 0xb4a62c`. Slot1
  0x9647d4: D0, same shape.
- Slot2/3 0xb4a654 / 0xb4a67c and slot4 0x933314: shared pia-job stubs.
  Slot5 0x964970: own, unrecovered (the surrounding 0x96497c..0x9649a8
  thunky accessors belong to the region, not the vtable).
- [this+0x08..0x57] — StepSequenceJob base subobject (base C1 0xb4a5e0).
- [+0x58..+0x70] — 0x19-byte subobject inited by 0x929ec0 (ptrs +0x58/+0x60,
  bool +0x68; last initialized byte is +0x70).

## Construction / init order

1. C2 FUN_7100964764 (0x964764..0x96479c): base C1 0xb4a5e0 (0x964774),
   vptr install (0x964778..0x964784), member init 0x929ec0 at this+0x58
   (0x96478c), tail `b 0x929ed0(this)` which re-zeroes +0x08..+0x18.
2. Constructed in-place by a manager aggregate ctor (bl 0x964764 at
   0x93a99c, x0 = x19). No factory operator new found — size 0x71 is a
   lower bound from the 0x929ec0 bool store at +0x70.
3. Adjacent size stub 0x96475c returns 0xa4 — plausibly a derived wrapper
   size (unverified).
