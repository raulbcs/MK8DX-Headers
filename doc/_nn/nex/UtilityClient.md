# nn::nex::UtilityClient

## Identity

- RTTI-confirmed: typeinfo record 0x12f8b20 = {0x10, name 0xf8a170, base-ti
  0x12e73c0}; name string "N2nn3nex13UtilityClientE". Row 0x12f8990 is the
  typeinfo slot (offset-to-top 0 at 0x12f8988); installed vptr = row+8 =
  **0x12f8998**. GOT cell 0x1315f18 holds 0x12f8988 (vt-0x10).
- ServiceClient family (base ti 0x12e73c0 = nn::nex::ServiceClient); embeds
  nn::nex::UtilityProtocolClient (ti 0x12f8b00, base ClientProtocol 0x12e62e0).

## Member notes

- size 0xb0: operator-new(0xb0) at 0x844440 (w0=0xb0 at 0x844438) followed by
  in-place C1 0xb462d0 at 0x844450.
- +0x00 vptr 0x12f8998 (0xb462f0: `ldr cell; add #0x10; str [x19],#0x20`).
- +0x20 embedded UtilityProtocolClient: C1 advances this by 0x20 and calls
  0xb4661c(this+0x20, w1 = passthrough param w20) at 0xb46304.
- Base ServiceClient C1 0xa326c8 called at 0xb462e8 (w1 = ctor's int param,
  forwarded from the factory).
- vtable 0x12f8998 (10 slots): slot0 D1 0xb4631c, slot1 D0 0xb46350, slots 2-7
  shared family stubs (0xa41cdc/0xa41ce0/0xa41ef4/0xa420dc/0xa421d8/0xa42250),
  slot8 = 0xb4638c (`add x0,#0x20; b 0xa287c0` - forwards to the +0x20
  protocol-client slot), slot9 = 0xa42204.
- D1 0xb4631c re-installs the vptr, calls ServiceClient destroy tail 0xa3045c,
  then 0xa32868 (ServiceClient D-tail).

## Construction / init order

1. Factory FUN (0x844400 region): new 0xb0, C1 0xb462d0 (x1 = caller int).
2. C1: ServiceClient base C1 0xa326c8 -> vptr 0x12f8998 at +0x00 -> this +=
   0x20 -> protocol client init 0xb4661c.
3. Only one construction site (bl 0xb462d0 at 0x844450).
