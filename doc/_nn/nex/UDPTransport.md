# _nn::nex::UDPTransport

RTTI-named via typeinfo 0x12e4880 (`nn::nex::UDPTransport`), si-class chain:
SocketTransport (0x12e44e0) → RootTransport (0x12e42b0) → RootObject
(0x128c3b0). Header: `include/_nn/nex/UDPTransport.hpp`.

- vptr 0x12e3e60; GOT cell 0x1314520 holds vt-0x10 (0x12e3e50 = offset-to-top
  row; install site adds 0x10). Row: offset-to-top@0x12e3e50, typeinfo@0x12e3e58,
  22 slots 0x12e3e60..0x12e3f0f.
- size 0x558 — proven: the only construction is `new 0x558` at 0x9f2604
  (operator new 0x573f04) in factory FUN_71009f2474; the object is a UDP
 specialization of the SocketTransport allocation (no separate UDP alloc).

## Member notes

- Layout is identical to SocketTransport (see SocketTransport.md): the factory
  calls the SocketTransport C1 0x9fc41c and then only overrides [0x00]; no
  UDP-specific field init exists, so UDP adds virtual overrides only.
- [0xe8] of the factory's owner object (x19 in 0x9f2474) stores the transport
  pointer (0x9f262c).

## Virtual slots (vptr 0x12e3e60)

- slot0 = inherited SocketTransport D2 0x9fc7e0.
- slot1 = override 0xa191a0 — UDP D0 (deleting): calls D2 0x9fc7e0, then
  tail-calls delete thunk 0x573f48. This is the single override vs the
  SocketTransport table (0x9fcfb0 there).
- slots 2-21: identical to SocketTransport (0x9fcfd4, 0x9fd850, 0x9fdbf8,
  0x9fe090, 0x9fe0d0, 0x9fe1e4, 0x9fe414, 0x9fe3fc, 0x9fe2f8, 0x9feaec,
  0x9febc8, 0x9fecd0, 0x9ff470, 0x9ff4d8, 0xa192f0, 0xa01554, 0xa0155c,
  0x9fefa4, 0xa01564, 0xa192f8).

## Construction / init order

1. `new 0x558` (0x9f2604-0x9f260c, via 0x573f04); null check 0x9f2610.
2. SocketTransport C1 0x9fc41c (0x9f2618) — full Socket init.
3. vptr override to 0x12e3e60 (0x9f2620-0x9f2628, cell 0x1314520 + 0x10).
4. Virtual call slot2 (0x9f2630-0x9f2640) with an sp-backed result struct —
   transport init/status query (0x9fcfd4 body).
5. Pointer stored at owner+0xe8 (0x9f262c).

Factory FUN_71009f2474 is reached via tail-branch 0x9e4700 in
FUN_71009e4610 (called from 0x9e552c); a directly-named caller was not found.
