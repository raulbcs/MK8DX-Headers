#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceDirectorSetChain — PROVISIONAL vtable-anchored name. Base of the
// second PlayerSet dispatch chain (0x61514/0x620a0 -> 0x628bc -> this);
// ctor 0x710005f558, secondary vptr at +0x38 (GOT 0x12fbe00).
// Size unproven (< 0xF8). Details: doc/gear/Race/RaceDirectorSetChain.md

namespace gear {
class RaceDirectorSetChain : public Actor {
 public:
  void* mSecondary38;   //0x38 — secondary vptr
  uint32_t mFlag40;     //0x40 — ctor sets 0x01000000
  uint8_t pad44[0x4c];  //0x44 - 0x8F — unproven padding
  void* mOwner90;       //0x90 — ctor arg x1
  uint8_t pad98[0x18];  //0x98 - 0xAF — unproven padding
  int32_t mB0;          //0xB0 — ctor -1
  uint8_t padB4[0xc];   //0xB4 - 0xBF — unproven padding
};
}  // namespace gear
