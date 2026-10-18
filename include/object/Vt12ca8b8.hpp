#pragma once

#include <cstdint>

// Vt12ca8b8 — PLACEHOLDER name; vptr 0x12ca8b8, n=10, primary table, no typeinfo.
// Created only by factory FUN_71008054c8 (heap wrapper family, stored at wrapper+0x10).
// extent 0x170 - details: doc/object/Vt12ca8b8.md

namespace object {
class Vt12ca8b8 {
 public:
  void* mVtable;         // 0x00 — 0x12ca8b8 (via GOT cell 0x1310518)
  uint8_t mPad8[0x168];  // 0x08 — unproven padding (no stores in the creation path; ctor 0x8dc2b0 initializes internals)
};
}  // namespace object
