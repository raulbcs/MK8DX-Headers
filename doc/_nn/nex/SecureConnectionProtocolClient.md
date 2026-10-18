# nn::nex::SecureConnectionProtocolClient

## Identity

- RTTI: typeinfo 0x12e64c0, name "N2nn3nex30SecureConnectionProtocolClientE" (0xf85970); si-type with base nn::nex::ClientProtocol (typeinfo 0x12e62e0).
- Row layout: 0x12e5ea8 is the typeinfo slot; installed vptr = 0x12e5eb0 (assigned+8); GOT cell 0x1314a00 holds 0x12e5ea0 (vptr-0x10).
- 24 slots (0x12e5eb0..0x12e5f68). Sibling class: nn::nex::TicketGrantingProtocolClient (shares the slot 0/2-20/23 fold families).

## Slots (config/functions.csv)

- slot0 0xa3045c (456B, D2-family block), slot1 0xa30550 (D0).
- slots 2-4: FUN_7100a30318 (144B folds); slots 5-7: 0x591864/0x591868/0x591874 (unrecovered small stubs); slot8 0xa2bd80 (264B); slot9 0x591880; slot10 0xa2bdb4 (52B); slot11 0x591888; slots 12/13 0x5901e8 (272B folds); slots 14/15 0x591890/0x591898; slots 16-20 0xa30388..0xa303a0 (144B fold family).
- slot21 0xa2de58 (884B), slot22 0xa30624 (436B — contains this class's ctor block 0xa306b8), slot23 0xa287c0 (308B, shared with the TicketGranting sibling).

## Member notes

- Field stores in ctor block 0xa2cdc4: strh at +0x48, stp xzr,xzr at +0x50, [x88] = 0; reads logging globals at cells 0x130b528/0x130b530/0x130b538.

## Construction / init order

1. Factory at 0xa416ac: alloc 0xb0 (`bl 0x573f04`), then `bl 0xa326c8(obj, w1=2)`, then a second vptr (cell 0x1314d48 -> row 0x12e7010+0x10, a different nex class) is stored at [obj], and finally `bl 0xa2cd30(obj+0x20, w1=0xb)` — this class lives at offset +0x20 inside that 0xb0 composite.
2. Ctor 0xa2cd30 (unrecovered, 1136B): vptr store from cell 0x1314a00 at [subobject], w1 = protocol id (11 = SecureConnection at this site; sibling TicketGranting uses 10), field stores as above.

Size 0x90 is inferred (0xb0 composite minus the +0x20 subobject offset), unverified; the TicketGranting sibling's 0x90 is factory-proven and both derive from the same base with the same ctor signature.
