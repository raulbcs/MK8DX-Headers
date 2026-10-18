#pragma once

#include <cstdint>

// Vt12bc2f8 — placeholder name; secondary vptr 0x12bc2f8 (offset-to-top
// -0x30) of ParamMultiChanVtc200 (primary 0x12bc200, cell 0x130e650).
// extent 0x5f0 EXACT (factory 0x712c60, operator new(0x5f0, 8)) -
// details: doc/game/Vt12bc2f8.md

namespace object {
class Vt12bc2f8 {
 public:
  void* mVtable;           // 0x00 — primary vptr 0x12bc200 (cell 0x130e650 +0x10)
  uint8_t mPad8[0x28];     // 0x08 — unproven gap (pre-secondary-base)
  void* mVtable2;          // 0x30 — secondary vptr 0x12bc2f8 (cell +0x108)
  uint8_t mPad38[0x210];   // 0x38 — unproven body region
  uint8_t mPad248[0x3a8];  // 0x248 — channel-pair members region
                           // (ChanBase vptrs re-installed up to +0x5d0 by D1/D0)
                           // (0x5f0 total, factory alloc)
};

}  // namespace object
