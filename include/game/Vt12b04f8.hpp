#pragma once

#include <cstdint>

// Vt12b04f8 — PLACEHOLDER name; vptr row 0x12B04F8 installed directly from GOT
// cell 0x130D380 (holds row-0x10, vt-0x10 convention); ctor 0x623300,
// D1 0x623318, D0 0x623340.
// extent 0x20 - details: doc/game/Vt12b04f8.md

namespace game {
class Vt12b04f8 {
 public:
  void* mVtable;    // 0x00 — 0x12B04F8
  void* mPtr8;      // 0x08 — owned pointer, deleted by D1/D0 when mFlag18 set
  void* mField10;   // 0x10 — zeroed by ctor
  uint8_t mFlag18;  // 0x18 — ownership flag tested by D1/D0
  uint8_t mPad19[0x7];  // 0x19 — unproven padding
};
}  // namespace game
