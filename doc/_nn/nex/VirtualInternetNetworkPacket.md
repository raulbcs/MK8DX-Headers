# object::VirtualInternetNetworkPacket (nn::nex)

## Identity

RTTI-confirmed: typeinfo 0x12e52e0 = {0x10, "N2nn3nex15VirtualInternetINS0_15NetworkEmulator13NetworkPacketEEE", 0x12e4c80}; base = TimedQueue<NetworkPacket>. vptr 0x12e52a8 (ti-slot row 0x12e52a0); GOT cell 0x1314818 holds vptr-0x10.

## Member notes

- Slots (vptr 0x12e52a8, 6): slot0 0xa1ad7c = drain-and-return (byte-identical to TimedQueue's own slot0; re-installs base vptr 0x12e4c48, drains refcounted nodes, no delete); slot1 0xa1ef84 = deleting dtor (drain + operator delete 0x573f48); slot2 0xa16274 (580 B, timed enqueue override — reads float at [this+0x20]+0x24, compares against 1.0 via 0x577da0); trio 0xa1624c / 0xa1632c / 0xa163e0 = ResolveMethodContainerInterface impls.
- No standalone C2: construction inlined in device ctor 0xa17660; two instances at device+0x118 and device+0x180.

## Construction / init order

- Device ctor 0xa17660: vptr at +0x118/+0x180, sentinel/head +0x08/+0x10 = &sub+0x08, count +0x18 = 0, owner +0x20 = arg+0xa0, second owner +0x28 = arg+0xa0.
- Size 0x30 PROVEN by adjacency: first instance 0x118..0x148, second 0x180..0x1b0 (next member at +0x1b0/+0x1a8 region); stride 0x30.
