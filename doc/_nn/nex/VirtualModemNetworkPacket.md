# object::VirtualModemNetworkPacket (nn::nex)

## Identity

RTTI-confirmed: typeinfo 0x12e5280 = {0x10, "N2nn3nex12VirtualModemINS0_15NetworkEmulator13NetworkPacketEEE", 0x12e4c80}; base = TimedQueue<NetworkPacket>. vptr 0x12e5248 (ti-slot row 0x12e5240); GOT cell 0x1314810 holds vptr-0x10.

## Member notes

- Slots (vptr 0x12e5248, 6): slot0 0xa1ac78 = drain-and-return (re-installs the TimedQueue base vptr 0x12e4c48 at entry, drains refcounted nodes, no delete); slot1 0xa1ee7c = deleting dtor (same drain + operator delete 0x573f48); slot2 0xa15c6c (132 B, enqueue override); trio 0xa1624c / 0xa1632c / 0xa163e0 = ResolveMethodContainerInterface impls (shared with TimedQueue/VirtualInternet rows).
- No standalone C2: construction is inlined in device ctor 0xa17660, which stores this vptr at [dev+0xe8].

## Construction / init order

- Device ctor 0xa17660 (Socket-derived device, primary vptr cell 0x1314808): Socket base C2 0x9d690c -> own vptr -> flag 1 at +0xd8 -> this subobject at +0xe8: vptr, sentinel/head +0x08/+0x10 = &sub+0x08, count +0x18 = 0, owner +0x20 = arg+0xa0.
- Size 0x30 PROVEN by adjacency: next queue member at +0x118 (VirtualInternet) and next after the second VirtualModem at +0x1a8; stride 0x30.
