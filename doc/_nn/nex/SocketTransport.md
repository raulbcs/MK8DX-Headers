# _nn::nex::SocketTransport

RTTI-named via typeinfo 0x12e44e0 (`nn::nex::SocketTransport`), si-class chain:
base `nn::nex::RootTransport` (typeinfo 0x12e42b0), root `nn::nex::RootObject`
(0x128c3b0). Header: `include/_nn/nex/SocketTransport.hpp`.

- vptr 0x12e3690; GOT cell 0x1314678 holds vt-0x10 (0x12e3680 = offset-to-top
  row; ctor adds 0x10 before storing). Row: offset-to-top@0x12e3680 (0),
  typeinfo@0x12e3688, 22 slots 0x12e3690..0x12e373f.
- Ctor (C1) = 0x9fc41c; calls RootTransport base ctor 0x9f46e0 first.
- No direct instantiation found — no factory news a bare SocketTransport; the
  only live allocation of the pair is `new 0x558` in 0x9f2474 whose object is
  re-vptr'd to UDPTransport immediately after the C1 call. Size 0x558 is
  therefore the derived allocation; the Socket-only size is unverified (>= the
  deepest ctor store, 0x508+8).

## Member notes

- [0x00] vptr.
- [0x120] ptr — checked by D2 (0x9fc7e0, branch 0x9fc80c) and torn down when
  non-null.
- [0x2c8]/[0x2d0]/[0x2d8] — ring-buffer head/tail/end; zeroed at 0x9fc43c,
  then repopulated by the 0x70-stride element copy loop (0x9fc45c-0x9fc570)
  fed by the 0x20-byte allocation at 0x576368 (freed at 0x5763ac).
- [0x308]/[0x310]/[0x318]/[0x320] — zeroed by ctor (0x9fc588-0x9fc5a4).
- [0x330] — set from a GOT cell (0x9fc5ec); [0x338] zeroed.
- [0x340]/[0x348]/[0x350] — zeroed by ctor (0x9fc5d4-0x9fc5dc).
- [0x438] — set from a GOT cell (0x9fc608).
- [0x448] — list object allocated in the ctor (0x573f04 at 0x9fc60c); self
  links at +0x0/+0x8, empty-node init +0x18/+0x20/+0x28/+0x30.
- [0x450] — result of call 0xa14df8 (0x9fc650).
- [0x508] — zeroed by ctor (0x9fc664).

## Virtual slots (vptr 0x12e3690)

- slot0 = D2 0x9fc7e0 (4744 B; reinstalls vptr at 0x9fc804, tears down the
  ring pair and [0x120] sub-object).
- slot1 = D0 0x9fcfb0 (calls slot0, tail-calls delete thunk 0x573f48).
- slot2 = 0x9fcfd4 (0x96 B; status/result builder — calls 0x9d606c check, then
  either 0x9fd034 or error 0x10001/-0x7fff000c into an out-struct via
  0x5788e0). Invoked by UDP factory 0x9f2630-0x9f2640 right after the vptr
  override.
- slots 3-21: 0x9fd850, 0x9fdbf8, 0x9fe090, 0x9fe0d0, 0x9fe1e4, 0x9fe414,
  0x9fe3fc, 0x9fe2f8, 0x9feaec, 0x9febc8, 0x9fecd0, 0x9ff470, 0x9ff4d8,
  0xa192f0 (ret-0 stub), 0xa01554 (ret-0 stub), 0xa0155c (ret-0 stub),
  0x9fefa4, 0xa01564, 0xa192f8. Most unrecovered (absent from
  config/functions.csv).

## Construction / init order

1. `new 0x558` (0x573f04) — only proven allocation site 0x9f2604-0x9f260c in
   factory FUN_71009f2474 (reached via tail-chain 0x9e4700 ← FUN_71009e4610).
2. C1 0x9fc41c: base ctor 0x9f46e0 → vptr install (cell 0x1314678 + 0x10) →
   ring zeroing/alloc → field zeroing above.
3. Factory then overrides [0x00] with the UDPTransport vptr (cell 0x1314520 +
  0x10) and calls slot2 — see UDPTransport.md.
