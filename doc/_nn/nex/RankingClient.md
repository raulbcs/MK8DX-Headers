# nn::nex::RankingClient

## Identity

- RTTI-confirmed: typeinfo record 0x12f8700 = {0x10, name 0xf89f50, base-ti
  0x12e73c0}; name string "N2nn3nex13RankingClientE". Row 0x12f8570 is the
  typeinfo slot (offset-to-top 0 at 0x12f8568); installed vptr = row+8 =
  **0x12f8578**. GOT cell 0x1315e60 holds 0x12f8568 (vt-0x10).
- ServiceClient family (base ti 0x12e73c0 = nn::nex::ServiceClient); embeds
  nn::nex::RankingProtocolClient (ti 0x12f86e0, base ClientProtocol 0x12e62e0).

## Member notes

- size 0xb0: operator-new(0xb0) at 0x84c4c4 (caller 0x84c480 region) followed
  by in-place C1 0xb408dc at 0x84c4d4.
- +0x00 vptr 0x12f8578 (0xb408f8: `ldr cell; add #0x10; str [x19],#0x20`).
- +0x20 embedded RankingProtocolClient: after the store C1 advances this by
  0x20 and calls 0xb4308c(this+0x20, w1=0x70) at 0xb4090c.
- Base ServiceClient C1 0xa326c8 called with w1=0x70 (0xb408e8; semantics of
  w1 unverified - other ServiceClient tiers used 1/2/0xc).
- vtable 0x12f8578 (10 slots): slot0 D1 0xb40924, slot1 D0 0xb40958, slots 2-7
  shared family stubs (0xa41cdc/0xa41ce0/0xa41ef4/0xa420dc/0xa421d8/0xa42250),
  slot8 = 0xb40994 (`add x0,#0x20; b 0xa287c0` - forwards to the +0x20
  protocol-client slot), slot9 = 0xa42204.
- D1 0xb40924 re-installs the vptr, calls ServiceClient destroy tail 0xa3045c,
  then 0xa32868 (ServiceClient D-tail).

## Construction / init order

1. Factory: new 0xb0 (0x84c4c4), result stored at [mgr+0x20].
2. C1 0xb408dc: ServiceClient base C1 0xa326c8 (w1=0x70) -> vptr 0x12f8578 at
   +0x00 -> this += 0x20 -> protocol client init 0xb4308c.
3. Only one construction site (bl 0xb408dc at 0x84c4d4).
