#pragma once

#include <cstdint>

// Vt12cc3a8 — placeholder name; small append-only write-buffer record,
// primary table, RTTI-less, trivial dtor.
// extent 0x28 - details: doc/object/Vt12cc3a8.md

namespace object {
class Vt12cc3a8 {
 public:
  void* mVtable;      // 0x00 — 0x12cc3a8 (via GOT cell 0x13109a8)
  void* mPtr08;       // 0x08 — set by slot3
  uint32_t mU10;      // 0x10 — limit field, set by slot3
  uint32_t mWrite14;  // 0x14 — write position, advanced by slot4
  void* mBuf18;       // 0x18 — data buffer, set by slot5
  uint32_t mCap20;    // 0x20 — capacity, set by slot5
  uint32_t mPad24;    // 0x24
};
}  // namespace object
