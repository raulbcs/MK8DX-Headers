# BerkeleySocket (nn::pia::nex::BerkeleySocketDriver::BerkeleySocket)

- vt row 0x12e2280 is the typeinfo slot; real vptr 0x12e2288 (vptr-8 ->
  typeinfo 0x12e2560, "N2nn3nex20BerkeleySocketDriver14BerkeleySocketE"). GOT
  cell 0x13141b8 holds addend 0x12e2278 = vptr-0x10.
- Size 0x40, proven at both construction sites (0x71009d54c4/0x71009d5834:
  `operator new(0x40)` -> inlined C1).

## Identity

Per-socket state for the nex Berkeley socket driver. No RTTI-named base: the
C1 first installs an unnamed base vptr 0x12e26c0 (cell 0x13141b0, addend
0x12e26b8, typeinfo slot reads 0 — plain compiler-generated table), then the
derived vptr.

## Slots

Primary vtable 0x12e2288, 23 slots (all unrecovered FUN_*): slot 2 =
0x71009d576c (SetSockOpt wrapper: getsockopt SO_TYPE etc. via
nn::socket::SetSockOpt), slot 3 = 0x71009d4dd0, slot 4 = 0x71009d4fd4, slot 5
= 0x71009d5138, slot 6 = 0x71009d57a0, slot 7 = 0x71009d5230 (Listen wrapper:
nn::socket::Listen(fd, 0x400), maps EAGAIN/EINTR/EBUSY to status 4/2/1,
sets [this+0x14]=1 on success), slot 12 = 0x71009d5464 (Accept wrapper:
nn::socket::Accept(fd, sockaddr, &len) then news the 0x40 peer object),
slot 16 = 0x71009d57e4, slot 27 (secondary table) references
ClientWebSocketDriver::ClientWebSocket (only recovered symbol). Slots 17..20
= 0x71009dfbc8..9dfbe0 and 21/22 = 0x71009d4d1c/9d4d20 (dtor pair stubs).

## Construction / init order

C1 (inlined at 0x71009d54c8 accept path and 0x71009d5824 connect path):
1. base vptr 0x12e26c0 at [this]; `stlr wzr, [this+8]`.
2. derived vptr 0x12e2288 at [this].
3. connect path: [this+0xc] = -1, [this+0x14] = 0; accept path: fd from
   accept() at +0xc, +0x10 copied from the listener, +0x14 = 0x100.
4. memset(this+0x18, 0, 0x10); byte at +0x19 = 2; [this+0x30] = 0.
5. [this+0x38] = &table 0x1361140 + idx*0x148 (idx from a global settings
   byte read via cell 0x130b528; 0 default).
