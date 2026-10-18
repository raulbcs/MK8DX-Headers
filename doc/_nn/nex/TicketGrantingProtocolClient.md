# nn::nex::TicketGrantingProtocolClient

## Identity

- RTTI: typeinfo 0x12e6560, name "N2nn3nex28TicketGrantingProtocolClientE" (0xf85a20); si-type with base nn::nex::ClientProtocol (typeinfo 0x12e62e0).
- Row layout: 0x12e60c0 is the typeinfo slot; installed vptr = 0x12e60c8 (assigned+8); GOT cell 0x1314a78 holds 0x12e60b8 (vptr-0x10).
- 24 slots (0x12e60c8..0x12e6180).

## Slots (config/functions.csv)

- slot0 0xa3045c (456B, D2-family block — same fold as the SecureConnection sibling), slot1 0xa30704 (D0).
- slots 2-20: identical fold families to SecureConnectionProtocolClient (0xa30318 144B folds, 0x5918xx stubs, 0xa2bd80, 0xa2bdb4, 0x5901e8 272B folds, 0xa30388..0xa303a0).
- slot21 0xa30214 (992B), slot22 0xa307d8 (184B — contains this class's ctor block 0xa3086c), slot23 0xa287c0 (308B, shared).

## Member notes

- Layout matches the ClientProtocol base (mProtocolId48 at 0x48, mCredentials88 at 0x88).
- Field stores in ctor block 0xa2f2e0: strb wzr at +0x70, str xzr at +0x78, str wzr at +0x80, stp xzr,xzr at +0x50, str xzr at +0x88, strh w20 at +0x48; reads logging globals at cells 0x130b528/0x130b530/0x130b538 and a vector scan at 0x130b598.

## Construction / init order

1. Factory at 0xa32b2c: alloc 0x90 (`mov w0, #0x90; bl 0x573f04`), null-check, `mov w1, #0xa; bl 0xa2f24c` (protocol id 10 = TicketGranting).
2. Ctor 0xa2f24c (unrecovered, 1920B): vptr store from cell 0x1314a78 at [this], then field stores as above.

Size 0x90 proven by the factory allocation.
