# nn::nex::NATTraversalProtocolClient

## Identity

- nex RTTI record at 0x12f6020: name
  `"N2nn3nex26NATTraversalProtocolClientE"`, base record 0x12e62e0 =
  `nn::nex::ClientProtocol`.
- Assigned tsv row 0x12f5ba8 is the nex-record slot; table head:
  0x12f5ba0 = 0 (offset-to-top), 0x12f5ba8 = record pointer,
  vptr = 0x12f5bb0.
- vptr convention: GOT cell 0x13158c8 holds 0x12f5ba0 (vt-0x10, RELA addend);
  installed vptr = cell + 0x10 = 0x12f5bb0.

## Member notes

- Size 0x90: D0 0xb1798c (`mov w0, #0x90; bl 0x573f04` operator new); no own
  fields beyond ClientProtocol.
- C1 0xb16a50(this, u16 cmd): base 0xa27e78(this, 1), vptr install, then if
  (arg & 0xffff) call 0xa28d3c (4-byte stub), then the shared RMC dispatch
  tail (same shape as MatchMakingProtocolClient C1 0xb15054). Called with
  cmd = 3 by the NATTraversalRelayProtocolImpl owner (0xb16990, 0xb15d80).
- D0 tail 0xb179d4..0xb179f4: shared dtor body 0xa3045c then operator delete
  0x573f48. Slot0 = shared complete-dtor thunk 0xa3045c (0x456 bytes):
  re-installs the nn::nex::Protocol vptr (cell 0x13140930 + 0x10) and releases
  the refcounted member at +0x88.
- 24 vtable slots at 0x12f5bb0..0x12f5c98, mostly shared with the other
  ClientProtocol clients (0xa30318, 0xa30384, 0x591864/68/74, 0xa2bd80,
  0xa2bdb4, 0x5901e8, 0x5902dc, 0xa303a0, 0xa287c0 — mostly unrecovered in
  functions.csv). Own overrides: slot1 = 0xb17968 (unmapped),
  slot2 = 0xb1798c (D0/factory), slot22 = 0xb17704 (FUN_7100b17704, 0x140
  bytes).

## Construction / init order

1. D0 0xb1798c: `operator new(0x90)` (0xb1799c), null check.
2. C1 0xb16a50: ClientProtocol base ctor 0xa27e78(this, 1) (0xb16a70) —
   zeroes +0x48..+0x88, stores w1 at +0x60, installs nn::nex::Protocol vptr
   first (cell 0x13140930).
3. vptr = cell 0x13158c8 + 0x10 -> 0x12f5bb0 (0xb16a74..0xb16a80).
4. Optional 0xa28d3c stub call when (arg & 0xffff) != 0 (0xb16a84..0xb16a90).
