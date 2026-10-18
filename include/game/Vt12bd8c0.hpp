#pragma once

#include <cstdint>

// Vt12bd8c0 — placeholder name; secondary vptr 0x12bd8c0 (offset-to-top
// -0x30) of the class with primary 0x12bd7b0 (cell 0x130e8e0); base of
// the Vt12bda10 class.
// extent 0x2c0 EXACT (factory 0x72e378) - details: doc/game/Vt12bd8c0.md

namespace object {
class Vt12bd8c0 {
 public:
  void* mVtable;           // 0x00 — primary vptr 0x12bd7b0 (cell 0x130e8e0 +0x10)
  uint8_t mPad8[0x28];     // 0x08 — unproven gap (pre-secondary-base)
  void* mVtable2;          // 0x30 — secondary vptr 0x12bd8c0 (cell +0x120)
  uint8_t mPad38[0xe8];    // 0x38 — unproven body region
  uint8_t mPad120[0x4];    // 0x120 — u32, C2 zero
  uint8_t mPad124[0x19c];  // 0x124 — channel-pair members region
                           // (ChanBase vptrs re-installed 0xf8..0x270 by D1)
                           // (0x2c0 total, factory alloc)
};

}  // namespace object
