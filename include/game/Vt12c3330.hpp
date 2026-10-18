#pragma once

#include <cstdint>

// Vt12c3330 — PLACEHOLDER name; primary interface of the 0x48-byte MI
// class whose secondary 0x12c3118 is mapped as Vt12c3118. C1 0x794a9c,
// base C1 0x79deec; factory FUN_7100792518 (new 0x48).
// extent 0x48 - details: doc/game/Vt12c3330.md
namespace game {
class Vt12c3330 {
 public:
  void* mVtable;     // 0x00 - primary vptr 0x12c3330 (GOT cell 0x130f6e0
                     //   holds vptr-0x10; C1 adds 0x10)
  uint8_t mPad8[8];  // 0x08 - unproven gap
  uint32_t mState10; // 0x10 - zeroed by base C1 0x79deec
  uint8_t mPad14[4]; // 0x14 - unproven gap
  uint64_t mZero18;  // 0x18 - zeroed by base C1
  uint64_t mZero20;  // 0x20 - zeroed by base C1
  void* mVtable28;   // 0x28 - secondary vptr 0x12c3340 (cell 0x130f6e8
                     //   + 0x10; row = Vt12c3118 + 0x28)
  uint64_t mZero30;  // 0x30 - zeroed together with the secondary vptr
  void* mSelf38;     // 0x38 - set to this by C1 (intrusive node idiom)
  void* mOwner40;    // 0x40 - *(GOT cell 0x12fc390 -> .bss 0x1359a50)
};
}  // namespace game
