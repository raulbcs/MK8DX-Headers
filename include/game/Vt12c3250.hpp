#pragma once

#include <cstdint>

// Vt12c3250 — PLACEHOLDER name; derived of base Vt12c33c8 (base C2 0x7956fc).
// Built in count-prefixed arrays by factory FUN_710079227c (elem stride 0xe8).
// extent 0xe8 - details: doc/game/Vt12c3250.md
namespace game {
class Vt12c3250 {
 public:
  void* mVtable;          // 0x00 - vptr 0x12c3250 (GOT cell 0x130f6c0 holds
                          //   vptr-0x10; init adds 0x10 after base C2)
  uint8_t mBase08[0x90];  // 0x08 - base Vt12c33c8 members (see Vt12c33c8.hpp)
  uint32_t m98;           // 0x98 - 0 (init)
  float m9c;              // 0x9c - 1.0f (init)
  float ma0;              // 0xa0 - -1.0f (init)
  float ma4;              // 0xa4 - 1.0f (init)
  uint32_t ma8;           // 0xa8 - 0 (init)
  uint8_t mAc[4];         // 0xac - unproven gap
  float mb0;              // 0xb0 - 1.0f (init)
  uint64_t mB4;           // 0xb4 - 0 (D2 clears 0xb4/0xbc/0xc4/0xcc)
  uint64_t mBc;           // 0xbc - 0 (init)
  uint64_t mC4;           // 0xc4 - 0 (init)
  uint64_t mCc;           // 0xcc - 0 (init)
  uint32_t mD4;           // 0xd4 - unproven gap
  uint64_t mD8;           // 0xd8 - 0 (init)
  uint16_t mE0;           // 0xe0 - 0 (init, strh)
  uint16_t mE2;           // 0xe2 - tail pad to extent
  uint32_t mE4;           // 0xe4 - tail pad to extent
};
}  // namespace game
