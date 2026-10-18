#pragma once

#include <cstdint>

namespace nn::nex {

// RTTI-confirmed (typeinfo 0x12f8700, mangled name N2nn3nex13RankingClientE).
// ServiceClient-family client; vptr 0x12f8578 installed at +0x00 by in-place
// C1 0xb408dc; embedded RankingProtocolClient at +0x20 (init 0xb4308c).
// extent 0xb0 - details: doc/_nn/nex/RankingClient.md

class RankingClient {
 public:
  void* vtable;           // 0x00 - 0x12f8578 (GOT cell 0x1315e60 = vt-0x10)
  uint8_t mPad08[0x18];   // 0x08 - 0x1F - ServiceClient base region (base C1 0xa326c8, w1=0x70)
  void* mProtocolClient;  // 0x20 - embedded RankingProtocolClient (init 0xb4308c, this+0x20)
  uint8_t mPad28[0x88];   // 0x28 - 0xAF - unproven
};

}  // namespace nn::nex
