# nn::nex::SocketTransport::TransportJob

RTTI-confirmed (typeinfo mangled name: N2nn3nex15SocketTransport12TransportJobE). vptr 0x12e4af8 (GOT cell 0x13146a0, n=12). Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18 secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8; base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).

Object size 0x70 (allocation size orr w0, #0x70 at the factory new 0x9fd140, which runs shared job ctor 0x582804 + vptr store from GOT cell 0x13146a0). NOTE: the 0x58 alloc at 0x9fd0ac is a DIFFERENT class constructed by 0xa0189c, not this one. Nearby function 0x9fd034 is NOT this class's ctor either — it is a manager method whose [x19, #0x2b0/#0x2b8/#0x510] accesses hit the enclosing SocketTransport manager object.

## Construction / init order

1. Factory 0x9fd140: operator new(0x70) (orr w0, #0x70).
2. Shared job ctor 0x582804; vptr store from GOT cell 0x13146a0.
3. Site 0x9fd1a4: strb wzr at 0x61; site 0x9fd1a0: str x19 (owner back-pointer) at 0x68.
