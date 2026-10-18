# AuthenticationClient

- RTTI-named: typeinfo 0x12e7420, name string 0xf85e10
  "N2nn3nex20AuthenticationClientE"; base typeinfo 0x12e73c0
  (ServiceClient, base RootObject).
- GOT cell convention: cell 0x1314b68 holds 0x12e6a18 = vptr - 0x10.
  Installed vptr = 0x12e6a28. 10 fn slots at vptr+0x00..+0x48.
- Size 0x48 proven: factory 0xa39bac allocates 0x48 via 0x573f04 then calls
  C1 0xa32ab8 (0xa39bbc); result stored to caller+0x2a0 region.

## Member notes

- +0x08..+0x1f: ServiceClient base region; base C1 0xa326c8 (called with
  w1 = 1) — unverified contents.
- +0x20: member, alloc 0x90 (0x573f04), init 0xa2f24c(x, 10) (0xa32b44).
  D1 releases it via 0xa42414 chain (0xa32bb8-0xa32bc8).
- +0x28: member, alloc 0x3a0, init 0xa29504 (0xa32b04). D1 releases via
  0xa29534 + operator delete 0x573f48 (0xa32ba0-0xa32bac).
- +0x30: intrusive list head node, alloc 0x28; init writes [x+0x10]=0,
  [x+8]=x+0x10, [x+0x18]=0, [x+0x20]=this (0xa32b1c-0xa32b28). D1 walks it
  via [node+0x10] (0xa32bb0-0xa32bc4).
- +0x40 u64: zeroed by C1 (0xa32aec).

## Construction / init order

- C1 = 0xa32ab8: base C1 0xa326c8(this, 1) (0xa32ad0), vptr install
  (0xa32ae4-0xa32af0), member +0x28 (alloc 0x3a0), member +0x30 (alloc
  0x28 node), member +0x20 (alloc 0x90, init 0xa2f24c), +0x40 = 0.
- D1 = slot 0, 0xa32b78: re-installs vptr, destroys +0x28, +0x30 node,
  +0x20, then base D-tail.
- D0 = slot 1, 0xa32bf4.
- Slots (10): 0 = 0xa32b78 (D1), 1 = 0xa32bf4 (D0), 2 = 0xa41cdc, 3 =
  0xa41ce0, 4 = 0xa41ef4, 5 = 0xa420dc, 6 = 0xa421d8, 7 = 0xa42250, 8 =
  0xa32c18, 9 = 0xa42204. Slots 2-7/9 are the shared ServiceClient stub set
  (same entries in SecureConnectionClient / MatchMakingClient /
  MatchmakeExtensionClient); bodies unrecovered in functions.csv.
