#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo 0x12e7eb0: nn::nex::AuthenticationInfo).
// Login-result info object; C1 is inlined at both construction sites,
// no standalone C1.
// extent 0x48 - details: doc/_nn/nex/AuthenticationInfo.md
class AuthenticationInfo {
 public:
  void* vtable;             // 0x00 - vptr 0x12e7e68 (GOT cell 0x1314db8 holds
                            // 0x12e7e58 = vptr-0x10; typeinfo slot 0x12e7e60)
  uint8_t mPad08[0x1];      // 0x08 - unproven
  uint8_t mFlag09;          // 0x09 - zeroed at both ctor sites
  uint8_t mPad0A[0x6];      // 0x0a..0x0f - padding (nothing stored)
  void* mOwner10;           // 0x10 - caller object+0x10 (role unverified)
  uint8_t mInline18[0x10];  // 0x18..0x27 - inline buffer, first byte zeroed
  void* mData28;            // 0x28 - = this+0x18 (points at mInline18)
  uint64_t mCap30;          // 0x30 - = 0x10
  uint32_t m38;             // 0x38 - = 4
  uint8_t m3C;              // 0x3c - = 2
  uint8_t mPad3D[0x3];      // 0x3d..0x3f - padding (nothing stored)
  uint32_t m40;             // 0x40 - = 0xfab (4011)
  uint8_t mPad44[0x4];      // 0x44..0x47 - padding (nothing stored)
};
}  // namespace nn::nex
