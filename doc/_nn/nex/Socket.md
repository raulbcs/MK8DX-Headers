# object::Socket (nn::nex)

## Identity

RTTI-confirmed: typeinfo 0x12e26a0 = {0x10, "N2nn3nex6SocketE", 0x128c3b0}. Primary vptr 0x12e2468 (ti-slot row 0x12e2460); GOT cell 0x13141e0 holds vptr-0x10. Secondary base InetAddress: vptr 0x12e2428, ti 0x12e2680 ("N2nn3nex11InetAddressE"), cell 0x13141c8 (vptr-0x10); InetAddress slot cluster includes 0x9d6434/0x9d6438 (same member helpers reused as queue-node teardown in the TimedQueue family).

## Member notes

- Primary slots (vptr 0x12e2468, 6): 0x9d7270 (dtor family; re-installs own vptr at 0x9d7284), 0x9d7754 (unrecovered), 0x9d779c (152 B), 0x9dc134 (unrecovered), 0x9dc184 (80 B), 0x9dbd48 (136 B).
- C2 = 0x9d690c (x0, w1 type, w2): installs both vptrs, memset(this+0x10,0,0x10), writes type code 2 at +0x11, arg pair at +0x9c/+0xa0, subobject vptrs 0x12e2828 (+0xa8) and 0x12e2918 (+0xc8), +0xb8 = [0x1361430 + w1*8] with virtual init via slot +0x10. Later code allocates counter/sub blocks (new 0x20 at 0x9d6c4c region, new via 0x573f04 at 0x9d6cb4) stored at +0xb0; +0xd0 ptr set at 0x9d6e38.
- Sole construction site found: device ctor 0xa17660 calls Socket C2 with its own this (Socket is the base subobject at +0); the derived ctor then writes its own fields from +0xd8 on -> Socket size 0xd8 EXACT.

## Construction / init order

- Base C2 0x9d690c -> derived C2 0xa17660 (installs vptr cell 0x1314808+0x10, flag 1 at +0xd8, then embedded TimedQueue-family members at +0xe8/+0x118/+0x150/+0x180).
