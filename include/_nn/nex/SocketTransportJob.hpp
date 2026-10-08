#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo mangled name: N2nn3nex15SocketTransport12TransportJobE).
// True nesting: nn::nex::SocketTransport::TransportJob.
// vptr 0x12e4af8 (GOT cell 0x13146a0, n=12; constructed inline by the factory at 0x9fd140).
// Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
// secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
// base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
class SocketTransportJob {
 public:
  void* vtable;           // 0x00
  uint8_t mBase08[0x58];  // 0x08 — job base region (object is only 0x70 bytes; smaller than
                          // the 0xa0 ForcedCriticalSection extent of the larger jobs)
  uint8_t mPad60[0x1];    // 0x60 — unproven gap
  uint8_t mField61;       // 0x61 — ctor-written (strb wzr at construction site 0x9fd1a4)
  uint8_t mPad62[0x6];    // 0x62 — unproven gap
  uint64_t mField68;      // 0x68 — ctor-written (owner back-pointer, str x19 at 0x9fd1a0)
  // Object size 0x70 (allocation size orr w0, #0x70 at the factory new 0x9fd140, which
  // shared job ctor 0x582804 + vptr store from GOT cell 0x13146a0). NOTE: the 0x58 alloc at
  // 0x9fd0ac is a DIFFERENT class constructed by 0xa0189c, not this one. Nearby function
  // 0x9fd034 is NOT this class's ctor either — it is a manager method whose
  // [x19, #0x2b0/#0x2b8/#0x510] accesses hit the enclosing SocketTransport manager object.
};
}  // namespace nn::nex
