#pragma once

#include <cstdint>

// Vt12bda10 — placeholder name; secondary vptr 0x12bda10 (offset-to-top
// -0x30) of the class with primary 0x12bd900 (cell 0x130e8e8); derives
// from the Vt12bd8c0 class.
// extent 0x448 EXACT (factory 0x72e394) - details: doc/game/Vt12bda10.md

namespace object {
class Vt12bda10 {
 public:
  void* mVtable;           // 0x00 — primary vptr 0x12bd900 (cell 0x130e8e8 +0x10)
  uint8_t mPad8[0x28];     // 0x08 — unproven gap (pre-secondary-base)
  void* mVtable2;          // 0x30 — secondary vptr 0x12bda10 (cell +0x120)
  uint8_t mPad38[0x288];   // 0x38 — base-class body region (base size 0x2c0)
  uint8_t mPad2c0[0x4];    // 0x2c0 — s32, C2 writes -1
  uint8_t mPad2c4[0x184];  // 0x2c4 — derived channel-pair members region
                           // (ChanBase members from 0x2c8 via 0x662f30/0x662f70)
                           // (0x448 total, factory alloc)
};

}  // namespace object
