#pragma once

#include <cstdint>

// Vt12e5d00 - PLACEHOLDER name; 27-slot tree-node class with sead strings
// (std::__tree helper slots 12/13); allocated 0xd0 at 0xa35770.
// extent 0xd0 - details: doc/object/Vt12e5d00.md
namespace object {
class Vt12e5d00 {
 public:
  void* mVtable;          // 0x000 - 0x12e5d08 (cell 0x13149a8, +0x10)
  uint8_t mPad8[0x58];    // 0x008 - built by C1 0xa2b234 / strings
  uint16_t mW60;          // 0x060 - 9
  uint8_t mPad62[0x2e];   // 0x062 - unproven padding
  uint8_t mTail90[0x40];  // 0x090 - tree/array region (+0x90 self-node)
                          // (0xd0 total)
};
}  // namespace object
