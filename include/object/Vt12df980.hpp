#pragma once

#include <cstdint>

// Vt12df980 — parsed-message fragment (vptr 0x12df988, 5 slots, GOT cell 0x1313ce8 holds vptr-0x10).
// Stack-constructed temporaries filled by slot-3 parser 0x9bd0d0 (big-endian decode).
// extent 0x18 (lower bound from deepest field store; no allocation site found) -
// details: doc/object/Vt12df980.md

namespace object {
class Vt12df980 {
 public:
  void* mVtable;        // 0x00 — 0x12df988 (installed at 0x9bca2c and 0x9bccc0)
  uint32_t mField8;     // 0x08 — big-endian u32 decoded at 0x9bd0f4
  uint32_t mFieldC;     // 0x0c — big-endian u32 decoded at 0x9bd118
  uint64_t mField10;    // 0x10 — big-endian u64 decoded at 0x9bd160
};
}  // namespace object
