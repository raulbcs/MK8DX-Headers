#pragma once

#include <cstdint>

namespace nn::nex {

// RTTI-confirmed (typeinfo 0x12f8b20, mangled name N2nn3nex13UtilityClientE).
// ServiceClient-family client; vptr 0x12f8998 installed at +0x00 by in-place
// C1 0xb462d0; embedded UtilityProtocolClient at +0x20 (init 0xb4661c).
// extent 0xb0 - details: doc/_nn/nex/UtilityClient.md

class UtilityClient {
 public:
  void* vtable;           // 0x00 - 0x12f8998 (GOT cell 0x1315f18 = vt-0x10)
  uint8_t mPad08[0x18];   // 0x08 - 0x1F - ServiceClient base region (base C1 0xa326c8)
  void* mProtocolClient;  // 0x20 - embedded UtilityProtocolClient (init 0xb4661c, this+0x20)
  uint8_t mPad28[0x88];   // 0x28 - 0xAF - unproven
};

}  // namespace nn::nex
