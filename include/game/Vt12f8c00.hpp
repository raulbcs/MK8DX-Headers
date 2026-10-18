#pragma once

#include <cstdint>

// Vt12f8c00 — PLACEHOLDER name; vptr row 0x12F8C08 (typeinfo slot 0x12f8c00,
// typeinfo object 0x12F8C40), installed only as a stack temporary; no
// materializing ctor found. size 0x8 (vptr only, unverified lower bound) -
// details: doc/game/Vt12f8c00.md

namespace game {
class Vt12f8c00 {
 public:
  void* mVtable;  // 0x00 — 0x12F8C08 (via GOT cell 0x13133C8, holds row-8)
};
}  // namespace game
