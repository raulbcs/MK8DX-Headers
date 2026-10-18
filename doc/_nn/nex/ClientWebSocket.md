# nn::nex::ClientWebSocketDriver::ClientWebSocket

## Identity

- RTTI: typeinfo 0x12e2660, name "N2nn3nex21ClientWebSocketDriver15ClientWebSocketE"; si_class_typeinfo with base nn::nex::SocketDriver::Socket (typeinfo 0x12e2540).
- Row layout: 0x12e2348 is the typeinfo slot; installed vptr = 0x12e2350 (assigned+8); GOT cell 0x13141c0 holds 0x12e2340 (vptr-0x10).
- 24 slots (0x12e2350..0x12e2408).

## Slots (config/functions.csv)

- slot0 0x9d59dc and slot1 0x9d5d4c (D1/D0 pair; blocks inside unrecovered ctor 0x9d57e4, 576B).
- slot2 0x9dfc80 — the only named slot, config name "ClientWebSocketDriver::ClientWebSocket" (O quality, 4B: `ret` stub — abstract/pure override).
- slots 3-9, 11-14, 16-18, 21-23: ICF-folded clones of FUN_71009d57e4 (576B) / FUN_71009d5a24 (620B) / FUN_71009d5c90 (228B) / FUN_71009d5c90-family — one shared body per fold group.
- slots 10/15/19/20: 0x9dfc84/0x9dfc8c/0x9dfc94/0x9dfca0, unrecovered ret-stub family near the named slot 2.

## Member notes

- Ctor block 0x9d592c: primary vptr stored at [this] AND [this+0x10] (str with post-index #0x10) — read as one vptr slot at 0x00 plus an unexplained copy at 0x10 (unverified).
- 0x140 and 0x170: two Socket subobjects sharing secondary vptr cell 0x130b4a8 (row 0x128c688+0x10); each gets base ctor 0x5790b4 (bl at 0x9d5950 with this+0x170, bl at 0x9d595c with this+0x140).

## Construction / init order

1. Ctor 0x9d57e4 (unrecovered): vptr store from cell 0x13141c0, secondary vptr installs at +0x170 and +0x140, base ctor 0x5790b4 on each.

Size: no operator-new factory found; extent >= 0x178 (max field store +0x170..+0x177), unverified.
