#pragma once

#include <cstdint>

// Vt12dff50 — PLACEHOLDER name (local-communications/LDN-adjacent manager,
// 0x82e0-byte pooled object registered into global registries); installed
// vptr 0x12dff58.
// extent 0x82e0 - details: doc/object/Vt12dff50.md

namespace object {
class Vt12dff50 {
 public:
  void* vtable;           // 0x00 — 0x12dff58 (ctor 0x71009bed68)
  char mSub8[0x38];       // 0x08 — member, dtor 0x71009b3a40 (0x71009b211c)
  char mSub40[0x15a0];    // 0x40 — member, dtor 0x71009b3a40 (0x71009b2114)
  char mPad15e0[0x30];    // 0x15e0 — ctor-zeroed pointers (0x71009bed58..0x71009bed90)
  char mSub1610[0x6c20];  // 0x1610 — container init FUN_7100567ca0(-1) (0x71009bed94)
  uint32_t mField8230;    // 0x8230 — ctor zeroes (0x71009bed98)
  char mPad8234[0x4];     // 0x8234 — unproven
  char mSub8238[0x20];    // 0x8238 — container init FUN_7100567ca0(-1) (0x71009beda8)
  uint8_t mFlag8258;      // 0x8258 — ctor zeroes (0x71009bedb4)
  char mPad8259[0x87];    // 0x8259 — unproven, to end (0x82e0)
};
}  // namespace object
