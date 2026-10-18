#pragma once

#include <cstdint>

namespace nn::nex {
// nn::nex::SecureConnectionProtocolClient — RTTI-named (typeinfo 0x12e64c0,
// name string at 0xf85970, base nn::nex::ClientProtocol); vptr 0x12e5eb0 (GOT
// cell 0x1314a00 holds 0x12e5ea0 = vt-0x10); ctor 0xa2cd30.
// extent 0x90 - details: doc/_nn/nex/SecureConnectionProtocolClient.md
class SecureConnectionProtocolClient {
 public:
  void* vtable;            // 0x00 - 0x12e5eb0 (cell 0x1314a00 + 0x10)
  char pad08[0x40];        // 0x08..0x47 - unproven gap
  uint16_t mProtocolId48;  // 0x48 - ctor strh (protocol id 11 at the observed
                           //   factory)
  char pad4a[0x6];         // 0x4a..0x4f - unproven gap
  char pad50[0x10];        // 0x50..0x5f - ctor zeroes (stp xzr,xzr)
  char pad60[0x10];        // 0x60..0x6f - unproven gap
  char pad70[0x18];        // 0x70..0x87 - ctor zeroes [0x88] and strh region
  void* mCredentials88;    // 0x88 - ctor writes 0 (ClientProtocol field)
};
}  // namespace nn::nex
