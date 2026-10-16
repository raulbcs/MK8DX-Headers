#pragma once

#include <cstdint>

#include "RaceDirectorSetChainMid.hpp"

// RaceDirectorSetChainA — PROVISIONAL vtable-anchored name. Chain variant
// (ctor 0x7100061514, vtable 0x11b3c98 / GOT 0x12fbe18); size 0x100 (factory
// allocs 0x6ed40/0x6ef10/0x6f00c/0x6f2d8).
// Details: doc/gear/Race/RaceDirectorSetChainA.md

namespace gear {
class RaceDirectorSetChainA : public RaceDirectorSetChainMid {
 public:
  uint64_t mListF8;  //0xF8 — ctor zero; list/map head
  // (0x100 total)
};
}  // namespace gear
