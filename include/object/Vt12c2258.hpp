#pragma once

#include <cstdint>

// Vt12c2258 — placeholder name; driver-backed object (page-aligned alloc),
// primary table, RTTI-less; MI band vptr at +0x10.
// extent 0x308 - details: doc/object/Vt12c2258.md

namespace object {
class Vt12c2258 {
 public:
  void* mVtable;           // 0x00 — 0x12c2258 (via GOT cell 0x130f3a0)
  uint32_t mU08;           // 0x08 — set to 1 by the factory
  uint32_t mPad0C;         // 0x0C
  void* mVtable2;          // 0x10 — band 0x12c2298 (base subobject at +0x10)
  uint8_t mPad18[0x2F0];   // 0x18 — unproven padding
};
}  // namespace object
