#pragma once

#include <cstdint>

// Vt12ca918 — PLACEHOLDER name; vptr 0x12ca918, n=10, primary table, no typeinfo.
// Created by factories FUN_7100804db0 / FUN_71008054c8 (heap wrapper family, stored at wrapper+0x10).
// extent 0x108 - details: doc/object/Vt12ca918.md

namespace object {
class Vt12ca918 {
 public:
  void* mVtable;         // 0x00 — 0x12ca918 (via GOT cell 0x1310500)
  uint8_t mPad8[0x100];  // 0x08 — unproven padding (no stores in the creation path; ctor 0x8dbf08 initializes internals)
};
}  // namespace object
