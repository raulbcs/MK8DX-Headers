#pragma once

#include <cstdint>

// Vt12bc560 — placeholder name; secondary vptr 0x12bc560 (offset-to-top
// -0x30) of the ParamMultiChanVtc200-derived final class (primary
// 0x12bc468, cell 0x130e658).
// extent 0x5f0 EXACT (factory 0x712c60) - details: doc/game/Vt12bc560.md
// details: doc/game/Vt12bc560.md

namespace object {
class Vt12bc560 {
 public:
  void* mVtable;           // 0x00 — primary vptr 0x12bc468 (cell 0x130e658 +0x10)
  uint8_t mPad8[0x28];     // 0x08 — unproven gap (pre-secondary-base)
  void* mVtable2;          // 0x30 — secondary vptr 0x12bc560 (cell +0x108)
  uint8_t mPad38[0x5b8];   // 0x38 — channel-pair members body region
                           // (ChanBase vptrs re-installed up to +0x5d0 by D1/D0)
                           // (0x5f0 total, factory alloc)
};

}  // namespace object
