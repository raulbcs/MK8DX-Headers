# nn::nex::MatchMakingProtocolClient

## Identity

- nex RTTI record at 0x12f5950: name `"N2nn3nex25MatchMakingProtocolClientE"`,
  base record 0x12e62e0 = `nn::nex::ClientProtocol`.
- Assigned tsv row 0x12f5668 is the nex-record slot; table head:
  0x12f5660 = 0 (offset-to-top), 0x12f5668 = record pointer,
  vptr = 0x12f5670.
- vptr convention: GOT cell 0x1315838 holds 0x12f5660 (vt-0x10, RELA addend);
  installed vptr = cell + 0x10 = 0x12f5670.

## Member notes

- Size 0x90: D0 0xb15698 (`mov w0, #0x90; bl 0x573f04` operator new) calls
  C1 with no own fields beyond ClientProtocol.
- C1 0xb15054(this, u16 cmd): base 0xa27e78(this, 1), vptr install, then if
  (arg & 0xffff) call 0xa28d3c (4-byte stub), then the shared RMC dispatch
  tail reading the +0x48 protocol id and calling vtable slot 0 (0xb150f4..
  0xb15120).
- D2 0xb156e0: shared nex Protocol dtor body 0xa3045c then operator delete.
  Slot0 = shared complete-dtor thunk 0xa3045c (0x456 bytes): re-installs the
  nn::nex::Protocol vptr (cell 0x13140930 + 0x10) and releases the refcounted
  member at +0x88.
- 24 vtable slots at 0x12f5670..0x12f5708, mostly shared with the other
  ClientProtocol clients (0xa30318, 0xa30384, 0x591864/68/74, 0xa2bd80,
  0xa2bdb4, 0x5901e8, 0x5902dc, 0xa303a0, 0xa287c0 — mostly unrecovered in
  functions.csv). Own overrides: slot1 = 0xb15674 (unmapped), slot2 = 0xb15698
  (D0/factory).

## Construction / init order

1. D0 0xb15698: `operator new(0x90)` (0xb156a8), null check.
2. C1 0xb15054: ClientProtocol base ctor 0xa27e78(this, 1) (0xb15074) —
   zeroes +0x48..+0x88, stores w1 at +0x60, installs nn::nex::Protocol vptr
   first (cell 0x13140930).
3. vptr = cell 0x1315838 + 0x10 -> 0x12f5670 (0xb15078..0xb15084).
4. Optional 0xa28d3c stub call when (arg & 0xffff) != 0 (0xb15088..0xb15094).
