#pragma once

#include <cstdint>

// Vt12c3850 — PLACEHOLDER name; derived of base Vt12c33c8 (base C2 0x7956fc).
// Built in count-prefixed arrays by factory FUN_710078fc94 (stride 0x198).
// extent 0x198 - details: doc/game/Vt12c3850.md
namespace game {
class Vt12c3850 {
 public:
  void* mVtable;          // 0x00 - vptr 0x12c3850 (GOT cell 0x130f678 holds
                          //   vptr-0x10; init adds 0x10 after base C2)
  uint8_t mBase08[0x90];  // 0x08 - base Vt12c33c8 members
  uint32_t m98;           // 0x98 - default A *(cell 0x12fce50) at init
  uint32_t m9c;           // 0x9c - default A (init)
  uint32_t ma0;           // 0xa0 - default A (init)
  uint32_t ma4;           // 0xa4 - default B *(cell 0x12fce10) at init
  uint8_t mA8[0xa0];      // 0xa8 - unwritten by the factory loop (unverified
                          //   whether callers fill it)
  uint32_t m148;          // 0x148 - default A (init)
  uint32_t m14c;          // 0x14c - default A (init)
  uint32_t m150;          // 0x150 - default A (init)
  uint32_t m154;          // 0x154 - default B (init)
  uint32_t m158;          // 0x158 - default A (init)
  uint32_t m15c;          // 0x15c - default A (init)
  uint32_t m160;          // 0x160 - default A (init)
  uint32_t m164;          // 0x164 - default B (init)
  uint8_t m168[0x18];     // 0x168 - unproven gap
  uint64_t m180;          // 0x180 - 0 (init)
  uint64_t m188;          // 0x188 - tail pad to extent
  uint8_t m190[8];        // 0x190 - tail pad to extent
};
}  // namespace game
