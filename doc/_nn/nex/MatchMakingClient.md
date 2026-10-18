# MatchMakingClient

- RTTI-named: typeinfo 0x12f5990, name string 0xf88950
  "N2nn3nex17MatchMakingClientE"; base typeinfo 0x12e73c0 (ServiceClient).
- GOT cell convention: cell 0x13157c0 holds 0x12f5578 = vptr - 0x10.
  Installed vptr = 0x12f5588. 10 fn slots at vptr+0x00..+0x48.
- Size: no standalone allocation found. Sole construction is in-place as the
  primary base of MatchmakeExtensionClient (its C1 0xb04b64 calls 0xb12a7c at
  0xb04b74). Proven lower bound 0xb8 (member region starting at +0xb0).

## Member notes

- +0x08..+0x1f: ServiceClient base region; base C1 0xa326c8 called with
  w1 = 0xc — unverified contents.
- +0x20: member object, init C1 0xb15054(this+0x20, 0x15) (0xb12aa8-0xb12ab4).
  0xb15054 installs its own vptr (cell 0x1315838 + 0x10 — AnyObjectAdapter
  family) and calls 0xa27e78/0xa28d3c. Size unproven.
- +0xb0: member object, init C1 0xb152f4(this+0xb0, 50) (0xb12abc-0xb12ac0),
  vptr cell 0x1315840 + 0x10. Size unproven — extent lower bound only.

## Construction / init order

- C1 = 0xb12a7c (in-place): base C1 0xa326c8(this, 0xc) (0xb12a98), vptr
  install 0x12f5588 (0xb12a9c-0xb12ab0), member +0x20 via 0xb15054(., 0x15),
  member +0xb0 via 0xb152f4(., 50). Post C1, MatchmakeExtensionClient
  continues with nn::util::ReferSymbol (0xb12acc) and registry bookkeeping.
- D1 = slot 0, 0xb12e74 (this is the "base destroy tail" that
  MatchmakeExtensionClient's D1/D0 tail-call). D0 = slot 1, 0xb13010.
- Slots (10): 0 = 0xb12e74 (D1), 1 = 0xb13010 (D0), 2 = 0xa41cdc, 3 =
  0xa41ce0, 4 = 0xa41ef4, 5 = 0xa420dc, 6 = 0xa421d8, 7 = 0xa42250, 8 =
  0xb13060 (72 bytes), 9 = 0xa42204. Slots 2-7/9 = shared ServiceClient stub
  set; bodies unrecovered in functions.csv.
