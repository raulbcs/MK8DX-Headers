#pragma once

#include <cstdint>

// Vt12ceee8 — PLACEHOLDER name; 44-slot abstract base of Vt12ced30/Vt12ceb70
// (base C1 helper FUN_710085eb3c). No independent allocation.
// extent 0x58 - details: doc/object/Vt12ceee8.md

namespace object {
class Vt12ceee8 {
 public:
  void* vtable;         // 0x00 — 0x12ceee8 (base C1 0x710085eb74)
  uint8_t mId;          // 0x08 — C1 arg w1 (Vt12ced30 passes 1)
  uint8_t mPad9[0x3];   // 0x09 — unproven
  uint32_t mFieldC;     // 0x0C — ctor zeroes
  uint32_t mCount;      // 0x10 — element count
  uint32_t mCapacity;   // 0x14 — element capacity (ctor zeroes 0x14-0x1F)
  void** mElements;     // 0x18 — 0x28-byte element array
  uint8_t mFlag20;      // 0x20 — ctor sets 1
  uint8_t mFlag21;      // 0x21 — ctor zeroes
  uint8_t mPad22[0x6];  // 0x22 — unproven
  void* mField28;       // 0x28 — ctor zeroes
  uint8_t mPad30;       // 0x30 — ctor zeroes
  uint8_t mPad31[0x7];  // 0x31 — unproven
  uint32_t mField38;    // 0x38 — ctor zeroes
  uint8_t mPad3c[0x4];  // 0x3C — unproven
  void* mField40;       // 0x40 — ctor zeroes
  uint32_t mField48;    // 0x48 — ctor zeroes
  uint8_t mPad4c[0x4];  // 0x4C — unproven
  void* mField50;       // 0x50 — ctor zeroes
};
}  // namespace object
