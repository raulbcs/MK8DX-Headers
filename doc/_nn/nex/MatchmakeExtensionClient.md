# nn::nex::MatchmakeExtensionClient

RTTI-named: typeinfo slot 0x12f4fa8 -> typeinfo data 0x12f5310, name string
0xf885a0 "N2nn3nex24MatchmakeExtensionClientE"; base typeinfo listed at
0x12f5990. GOT cell 0x13155f0 holds 0x12f4fa0 (vptr - 0x10; offset-to-top 0).
Installed vptr = 0x12f4fb0. Only 10 fn slots (0x12f4fb0-0x12f5000); unrelated
rodata strings ("@SI", "WatchingPlayer", "MatchmakeSession", ...) start at
0x12f5008 and are NOT part of the vtable.

## Member notes

- Slots: 0 = D1 0xb04d28, 1 = D0 0xb04d60; slots 2-9 = FUN_7100a41cdc /
  FUN_7100a41ce0 (x2) / FUN_7100a42094 (x3) / FUN_7100a4221c / FUN_7100b04da0
  entries — unresolved override set.
- C1 0xb04b64 first installs the BASE vptr (GOT cell 0x1310bb8 + 0x10) at
  [this], then builds members: zero 0x60, 0x68-0x98 blocks, 0xa8-0xd0, vptr
  cell 0x1313170+0x10 at +0xc8, this+0xe0 at +0xd8, zero 0xe0-0xf0, vptr cell
  0x130b4a8+0x10 at +0xf8 and +0x128, zero bytes 0x100/0x130, member init
  0xb14df4 on this+0x140.
- D1 0xb04d28 / D0 0xb04d60: reinstall vptr 0x12f4fb0, destroy member +0x140
  via 0xa3045c, then base destroy tail 0xb12e74 (D0 adds operator delete
  0x573f48).

## Construction / init order

- Factory 0x916650: new(0x1d8) via 0x573f04, then C1 0xb04b64 (0x916664);
  result stored to [x19+0x2a8] - size 0x1d8 proven. Several other call sites
  (0x9169e4, 0x92d568, 0x9552c8...).
- Init order: base vptr cell 0x1310bb8 -> scalar/pointer members 0x60..0x130 ->
  member +0x140.
