#pragma once

#include <cstdint>

// Vt12bf718 — PLACEHOLDER name; vptr 0x12bf718, 8 slots, root class
// (C1 0x73e784, no base ctor). 0x28-byte node with a 2-entry pointer
// table at +0x18 and back-reference writes into table entries.
// extent 0x28 - details: doc/game/Vt12bf718.md
namespace game {
class Vt12bf718 {
 public:
  void* mVtable;        // 0x00 - vptr 0x12bf718 (GOT cell 0x130ec90 holds
                        //   vptr-0x10; C1 adds 0x10)
  uint64_t mZero08;     // 0x08 - zeroed by C1 (stp xzr, xzr, [x0])
  uint32_t mZero10;     // 0x10 - zeroed by C1
  uint8_t mZero14;      // 0x14 - zeroed by C1
  uint8_t mPad15[0x3]; // 0x15 - unproven gap
  void* mEntries[2];    // 0x18 - zeroed by C1; slot5 indexes it with a
                        //   clamp-to-2 and stores back-refs (+0x58/+0xc0)
};
}  // namespace game
