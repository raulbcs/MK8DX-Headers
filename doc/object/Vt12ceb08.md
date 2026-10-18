# object::Vt12ceb08

Network:: heap stub family (slots share code with Network::HttpHeap#NN
functions).

- Identity: no RTTI. Primary row 0x12ceb08: 8 slots 0x85cc48/0x85ccfc/
  0x85cdb0/0x85ce3c/0x85cef4/0x85d284/0x85cf90/0x85cf94; never installed
  (no GOT cell, no code reference).
- Stub row 0x12ceb58 (GOT cell 0x1310e58 holds vt-0x10; vptr = cell+0x10):
  1 slot 0x85d288; lazy guards at 0x85cb3c/0x85cc00 install the stateless
  singleton (this == vptr) into a cell pair under guard 0x1310e50 (unverified
  cell addresses).
- Concrete row 0x12ceb70 (GOT cell 0x1310e80; vptr = cell+0x10): 54 slots,
  0x12ceb70..0x12ced20. First slots 0x396f48 (Network::HttpHeap#13),
  0x39705c, 0x397068, 0x397074, 0x397164, 0x39716c ... Installed into
  [this] by init entry 0x85d3c4 (0x85d3f8).

## Member notes

- +0x4d8/+0x4e0 list head/tail zeroed by init (0x85d3ec/0x85d3e0).
- +0x4e8..+0x600: 0x18-stride intrusive node chain, head +0x540
  (0x85d3fc..0x85d464).
- +0x678 u16 = 0x100 after init (0x85d470..0x85d474).
- Init also calls FUN_710060b918 with (this+0x4d8, 0xc, this+0x618)
  (0x85d46c) — list/queue setup, details unproven.

## Construction / init order

1. Outer wrapper FUN_7100396e44 (csv FUN_7100396e44, size 0x30): `new` 0x680
   via FUN_710060afec (0x3836ac..0x3836bc).
2. Wrapper calls init entry 0x85d3c4 (0x396e54) — the entry sits inside
   FUN_710085d228 (csv size 0x412), which zeroes the list fields, installs
   vptr 0x12ceb70 and builds the node chain.
3. Wrapper then re-installs a further-derived vptr 0x125fed0
   (cell 0x1307528, 0x396e58..0x396e64) — the concrete leaf of this
   hierarchy is outside the assigned rows (unverified).
