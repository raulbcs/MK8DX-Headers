#pragma once

#include <cstdint>

// Vt12e6c48 — NEX protocol handler wrapper class (vptr 0x12e6c50, row label
// 0x12e6c48, GOT cell 0x1314c10 holds vptr-0x10). Base ctor FUN_7100a2e070,
// refcounted member ptr at +0x50, D1/D0 at slots 0/1. Size unverified (no
// operator-new found); extent is a lower bound.
// extent 0x58 (lower bound) - details: doc/object/Vt12e6c48.md

namespace object {
class Vt12e6c48 {
 public:
  void* mVtable;       // 0x00 — 0x12e6c50 (via GOT cell 0x1314c10 = vptr-0x10)
  uint8_t mPad8[0x48];  // 0x08 — unproven padding
  void* mMember50;     // 0x50 — refcounted 0xd0 object (ctor FUN_7100a2c4cc), released by D1/D0
};
}  // namespace object
