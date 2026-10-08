#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo mangled name: N2nn3nex43JobAcquireAccessTokenAndCallOnlineLoungeApiINS0_21OnlineLoungeApiTraitsILNS0_17ONLINE_LOUNGE_APIE5EEEEE).
// vptr 0x12d7130 (GOT cell 0x1312148, n=13, ctor 0x88eab4, sole construction site 0x88f924).
// Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
// secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
// base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
class JobAcquireAccessTokenAndCallOnlineLoungeApiV5 {
 public:
  void* vtable;           // 0x00
  uint8_t mBase08[0x98];  // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
                          // (no own-field ctor evidence found)
  // Object size 0x58 (allocation size at the factory new preceding ctor 0x88eab4).
};
}  // namespace nn::nex
