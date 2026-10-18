#pragma once

#include <cstdint>

// Vt12cbf20 — PLACEHOLDER name; vptr 0x12cbf20, n=90, primary table.
// Built with a 200-entry free-list pool; deepest field 0x5D3.
// extent 0x5D4 - details: doc/object/Vt12cbf20.md

namespace object {
class Vt12cbf20 {
 public:
  void* vtable;          // 0x00 — 0x12cbf20 (via GOT cell 0x1310920)
  uint8_t mPad8[0x5cc];  // unproven padding — 0x08-0x5D4 unproven (pool ptrs 0x5B8/0x5C0/0x5C8, counters 0x5D0-0x5D3)
};
}  // namespace object
