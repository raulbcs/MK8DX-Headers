#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo mangled name: N2nn3nex7JobHttpE).
// vptr 0x12e54d8 (GOT cell 0x13148b0, n=14, ctor 0xa20d00, sole construction site 0xa20d38).
// Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
// secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
// base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
class JobHttp {
 public:
  void* vtable;           // 0x00
  uint8_t mBase08[0x98];  // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
                          // (no own-field ctor evidence found)
  // Object size unknown (factory function 0xa20d00 performs no direct allocation).
};
}  // namespace nn::nex
