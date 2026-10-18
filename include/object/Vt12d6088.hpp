#pragma once

#include <cstdint>

#include "object/Vt12c7a50.hpp"

// Vt12d6088 — PLACEHOLDER name; vptr 0x12d6088 (GOT cell 0x1311ea0 = vptr-0x10),
// >=32 slots, derives Vt12c7a50. extent 0x3a8 - details: doc/object/Vt12d6088.md

namespace object {
class Vt12d6088 : public Vt12c7a50 {
 public:
  uint8_t mPad39c[0x8];   // 0x39c — zeroed by C1 (0x3a4 w, 0x39c w)
  uint32_t m3a4;          // 0x3a4 — zeroed by C1
};
}  // namespace object
