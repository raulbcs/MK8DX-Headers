#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-named (typeinfo 0x12e74a0, "N2nn3nex27ClientProtocolRequestBrokerE";
// base ProtocolRequestBrokerInterface ti 0x12e64a0). Typeinfo-slot row:
// vptr 0x12e6bb0 (GOT cell 0x1314c08), 18 slots, no secondary table.
// extent 0xd0 - details: doc/_nn/nex/ClientProtocolRequestBroker.md
class ClientProtocolRequestBroker {
 public:
  void* vtable;           // 0x00 - 0x12e6bb0 (cell 0x1314c08 + 0x10)
  char pad08[0x80];       // 0x08..0x87 - base ProtocolRequestBrokerInterface
                          //   region (base C1 0xa2c4cc); unproven
  void* m88;              // 0x88 - pointer to the +0x90 subobject (ctor)
  void* m90;              // 0x90 - ctor zero (subobject head; torn down by
                          //   0xa4258c in D1)
  void* m98;              // 0x98 - ctor zero
  uint32_t mA0;           // 0xa0 - slot2 0xa378b8 stores its w2 here
  char padA4[0x4];        // 0xa4..0xa7 - unproven gap
  void* mVptrA8;          // 0xa8 - member secondary vptr 0x128d720 (cell
                          //   0x130b898 + 0x10); inited by 0x58fe98(w1=3)
  uint32_t mB0;           // 0xb0 - ctor zero
  char padB4[0x4];        // 0xb4..0xb7 - unproven gap
  uint64_t mB8;           // 0xb8 - ctor constant -1
  uint32_t mC0;           // 0xc0 - ctor constant 1
  char padC4[0x4];        // 0xc4..0xc7 - unproven gap
  uint64_t mC8;           // 0xc8 - ctor constant -1
};
}  // namespace nn::nex
