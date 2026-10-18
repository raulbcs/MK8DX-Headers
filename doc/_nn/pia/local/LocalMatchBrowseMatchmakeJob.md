# LocalMatchBrowseMatchmakeJob (nn::pia::local::LocalMatchBrowseMatchmakeJob)

- vptr 0x12e19f8 installed from GOT cell 0x1314048 (RELATIVE addend 0x12e19e8 =
  vt-0x10; code does `cell+0x10`). vt_ctors.tsv row 0x12e19f0 is the typeinfo
  slot. Typeinfo 0x12e1a40, name
  "N2nn3pia5local28LocalMatchBrowseMatchmakeJobE", base
  nn::pia::session::BrowseMatchmakeJob.
- Size 0x90, proven by the job factory at 0x9c3e20: `0x568aa0(0x90)`
  (0x9c3e44) then C2 0x9d14fc (0x9c3e58). Sibling factories: 0x9c3dcc news
  0xa0 for C2 0x9d1a70, 0x9c3e6c news 0x128.

## Identity

pia session job that browses local wireless matchmake sessions; same
StepSequenceJob base family as ConnectStationJob.

## Slots

Primary vtable 0x12e19f8, 9 slots:
- slot 0 = 0x9d1538 (D2: clears +0x60, member D 0x929ee0 on +0x68, base D
  0x97dc8c)
- slot 1 = 0x9d1574 (D0: D2 body + `operator delete` 0x60b470)
- slot 2 = 0xb4a654, slot 3 = 0xb4a67c (shared with ConnectStationJob;
  unrecovered)
- slot 4 = 0x933314 (unrecovered)
- slots 5/6 = 0x9d1a6c / 0x9d1a68 (unrecovered)
- slot 7 = 0x9d15b8 (U: stores x1 at +0x88, virtual-calls [x1 vtable+0x168],
  fills base-region fields +0x30..+0x40 from a thunk table
  (cell 0x1314050 → code 0x9d161c) and string constant 0xf130fbd)
- slot 8 = 0x9d17f0 (unrecovered)

## Member notes

- 0x00 — vptr.
- 0x08..0x5f — BrowseMatchmakeJob base: grandbase StepSequenceJob C2 0xb4a5e0
  (base vptr cell 0x13150f70, secondary vptr 0x12db178 = cell 0x1313040 + 0x10
  at +0x28), then BrowseMatchmakeJob C2 0x97dc58 zeroes +0x58 and installs the
  base vptr (cell 0x1313678).
- 0x30..0x47 — BrowseMatchmakeJob base region filled lazily by slot 7:
  [this+0x30] = thunk-table ptr (cell 0x1314050 + 0x10), [this+0x38] = 0,
  [this+0x40] = string constant 0xf130fbd.
- 0x60 — C2 arg x1 (zeroed by D2).
- 0x68..0x87 — member subobject (ctor 0x929ec0, D 0x929ee0).
- 0x88 — ptr stored by slot 7 (0x9d15b8).

## Construction / init order

1. Factory 0x9c3e20 news 0x90 (0x9c3e44) and calls C2 0x9d14fc(ctx).
2. C2 runs BrowseMatchmakeJob base C2 0x97dc58 (which runs StepSequenceJob C2
   0xb4a5e0 first), stores arg x1 at +0x60, installs vptr 0x12e19f8, tail-calls
   member ctor 0x929ec0 on +0x68.
3. D2 0x9d1538 / D0 0x9d1574 clear +0x60, run member D 0x929ee0, base D
   0x97dc8c; D0 adds `operator delete`.
