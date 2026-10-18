#pragma once

#include <cstdint>

// Vt12c2f40 — PLACEHOLDER name; primary interface of the 0x50-byte
// class whose secondary 0x12c2ed0 is mapped as Vt12c2ed0. C1 0x78ef44,
// base C1 0x79deec (base vptr 0x12c3778); factory FUN_7100790050.
// extent 0x50 - details: doc/game/Vt12c2f40.md
namespace game {
class Vt12c2f40 {
 public:
  void* mVtable;     // 0x00 - primary vptr 0x12c2f40 (GOT cell 0x130f638
                     //   holds vptr-0x10; C1 adds 0x10)
  uint8_t mBase08[0x8];  // 0x08 - unwritten by the ctor (see Vt12c2ed0.md)
  uint32_t mState10; // 0x10 - zeroed by base C1 0x79deec
  uint8_t mPad14[4]; // 0x14 - unproven gap
  uint64_t mZero18;  // 0x18 - zeroed by base C1
  uint64_t mZero20;  // 0x20 - zeroed by base C1
  uint8_t mFlag28;   // 0x28 - bool, zeroed by C1
  uint8_t mPad29[0x7]; // 0x29 - unproven gap
  void* mVtable30;   // 0x30 - secondary vptr 0x12c2ed0 (cell 0x130f640
                     //   + 0x10; 14 slots, see include/game/Vt12c2ed0.hpp)
  uint64_t mZero38;  // 0x38 - zeroed together with the secondary vptr
  void* mSelf40;     // 0x40 - set to this by C1 (intrusive node idiom)
  void* mOwner48;    // 0x48 - *(GOT cell 0x12fce70 -> .bss 0x1359a38)
};
}  // namespace game
