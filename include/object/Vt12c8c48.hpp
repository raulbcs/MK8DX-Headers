#pragma once

#include "object/Vt12c8698.hpp"

// PROVISIONAL (no RTTI: typeinfo slot zero). Vt12c8698 derivative adding a
// resettable float bank (0x025f default 50.0) and settings vec3; ctor stores
// reach +0x90. Alloc site at 0xcc800-0xcc834 uses a stale 0x78 (anomaly).
// extent 0x94 - details: doc/object/Vt12c8c48.md

namespace object {
class Vt12c8c48 : public Vt12c8698 {
 public:
  uint32_t mField70;        // 0x70 — zeroed (0x7e8100); re-zeroed by slot1
  uint8_t mField74;         // 0x74 — flag, zeroed; set to 1 by 0x7e8170
  uint8_t mPad75[0x3];      // 0x75 — unproven padding
  void* mField78;           // 0x78 — zeroed
  float mField80;           // 0x80 — 50.0f default (0x7e8110-0x7e8114)
  float mField84;           // 0x84 — unverified (upper half of stp imm)
  float mField88[3];        // 0x88 — vec3 from settings singleton 0x12fb148
};
}  // namespace object
