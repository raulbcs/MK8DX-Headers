# nn::nex::MatchmakeExtensionProtocolClient

## Identity

- nex RTTI record at 0x12f52f0: name `"N2nn3nex32MatchmakeExtensionProtocolClientE"`,
  base record 0x12e62e0 = `nn::nex::ClientProtocol` (chain: Protocol).
- Assigned tsv row 0x12f5050 is the nex-record slot, NOT the vptr. Layout of the
  table head: 0x12f5040..0x12f504f = three rodata DDL-string pointers
  (0xf1f6eb "@VR", 0xf1f6fc "@TS", 0xf1f705 "@UpGI" — tail of the preceding
  DDL string table), 0x12f5048 = 0 (offset-to-top), 0x12f5050 = record pointer,
  vptr = 0x12f5058.
- vptr convention: GOT cell 0x1315758 holds 0x12f5048 (vt-0x10, RELA addend);
  installed vptr = cell + 0x10 = 0x12f5058.

## Member notes

- Size 0x90: D0 0xb10144 does `mov w0, #0x90; bl 0x573f04` (operator new) then
  C1 0xb0aa88. No own fields beyond ClientProtocol (0x90).
- C1 0xb0aa88(this, u16 cmd): base 0xa27e78(this, 1), vptr install, then if
  (arg & 0xffff) call 0xa28d3c (4-byte stub), then the shared RMC dispatch tail
  (sends via vtable slot 0xb0 and ClientProtocol::SendRMCMessage helpers,
  0xb0aabc..0xb0ab58).
- D2 0xb1018c: calls 0xb4ba2c (shared nex Protocol dtor body) then operator
  delete 0x573f48. Slot0 vtable entry is the shared complete-dtor thunk
  0xa3045c (0x456 bytes): re-installs the nn::nex::Protocol vptr
  (cell 0x13140930 + 0x10) and releases the refcounted object at +0x88.
- 24 vtable slots at 0x12f5058..0x12f50f0. Most slots shared with the other
  ClientProtocol clients (0xa30318, 0xa30384, 0x591864/68/74, 0xa2bd80,
  0xa2bdb4, 0x5901e8, 0x5902dc, 0xa303a0, 0xa287c0 — mostly unrecovered in
  functions.csv). Own overrides: slot1 = 0xb10120 (unmapped), slot2 = 0xb10144
  (D0/factory).

## Construction / init order

1. D0 0xb10144: `operator new(0x90)` (0xb10154), null check.
2. C1 0xb0aa88 on the block: ClientProtocol base ctor 0xa27e78(this, 1)
   (0xb0aaa8) — zeroes +0x48..+0x88, stores w1 at +0x60, installs the
   nn::nex::Protocol vptr first (cell 0x13140930).
3. vptr = cell 0x1315758 + 0x10 -> 0x12f5058 (0xb0aaac..0xb0aab8).
4. Optional per-instance call 0xa28d3c (stub) when (arg & 0xffff) != 0
   (0xb0aabc).
5. Same sequence inlined in the relay/singleton composites that embed a
   MatchmakeExtensionProtocolClient; no other construction sites found.
