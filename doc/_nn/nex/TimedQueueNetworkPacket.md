# object::TimedQueueNetworkPacket (nn::nex)

## Identity

RTTI-confirmed: typeinfo 0x12e4c80 = {0x10, "N2nn3nex10TimedQueueINS0_15NetworkEmulator13NetworkPacketEEE", 0x128c3b0}; secondary base ti 0x12e4c98 = "N2nn3nex31ResolveMethodContainerInterfaceE" (base 0, abstract interface). vptr 0x12e4c48 (ti-slot row 0x12e4c40); GOT cell 0x1314820 holds vptr-0x10. Secondary interface vtable exists at 0x12e4cb8 (thunk slots 0xa1b254/0xa1b258/0xa1b25c); its object offset is unverified (never observed installed).

## Member notes

- Nodes are doubly-linked (node+0x00/+0x08 next/prev), hold a refcounted payload at node+0x10 (atomics at payload+0x08, destroy via payload vtable slot +0x08, released-flag byte payload+0x0c), node+0x18 torn down by 0x9d6434; node freed via 0x5763ac.
- Slots (vptr 0x12e4c48): slot0 0xa1ad7c = drain-and-return (re-installs this vptr at entry; shared verbatim with VirtualInternet); slot1 0xa1ae80 = deleting dtor (drain + operator delete 0x573f48); slot2 0xa1af88 (620 B, timed enqueue); trio 0xa1624c / 0xa1632c / 0xa163e0 = ResolveMethodContainerInterface impls (capacity check at [this+0x10]->+0xa8; pop-front unlink + count-- + payload release), shared with VirtualModem/VirtualInternet rows.
- No standalone C2 found: template ctors are inlined into the NetworkEmulator-device ctor 0xa17660 (which inits the four queue members at +0xe8/+0x118/+0x150/+0x180 directly).

## Construction / init order

- Inlined init pattern (device ctor 0xa17660): vptr, sentinel/head at +0x08/+0x10 = &this+0x08, count +0x18 = 0, owner ptr +0x20 (arg-derived).
- Size 0x30 proven indirectly: the four queue subobjects sit at +0xe8/+0x118/+0x150/+0x180 in the device (stride 0x30, next member at +0x1a8). Exact size of a standalone TimedQueue object unverified.
