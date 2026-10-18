#pragma once

#include <cstdint>

namespace nn::nex {
// MatchMakingClient — RTTI-named (typeinfo 0x12f5990, name
// "N2nn3nex17MatchMakingClientE"; base 0x12e73c0 ServiceClient). GOT cell
// 0x13157c0 holds vptr-0x10. In-place-only (base of MatchmakeExtensionClient);
// member at +0xb0 unbounded.
// extent 0xb8 (lower bound) - details: doc/_nn/nex/MatchMakingClient.md
class MatchMakingClient {
 public:
  void* mVtable;         // 0x00 - 0x12f5588 (cell 0x13157c0 + 0x10)
  uint8_t mPad8[0x18];   // 0x08..0x1f - ServiceClient base region (base C1
                         //   0xa326c8, w1 = 0xc); unproven gap
  uint8_t mPad20[0x90];  // 0x20 - member, C1 0xb15054(this+0x20, 0x15)
                         //   (0xb12ab4); size unproven
  uint8_t mPadB0[8];     // 0xb0 - member, C1 0xb152f4(this+0xb0, 50)
                         //   (0xb12abc-0xb12ac0); size unproven, lower bound
};
}  // namespace nn::nex
