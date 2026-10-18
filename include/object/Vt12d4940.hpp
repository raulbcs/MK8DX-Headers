#pragma once

#include <cstdint>

// Vt12d4940 — PLACEHOLDER name; sibling of Vt12d48b8 (shares its ICF-merged
// slot impls; adds +0x24 flag = 1 and +0x28 ptr). vptr via GOT cell 0x1311a48
// (holds vt-0x10, no typeinfo); embedded, derived vptr overrides after init.
// extent 0x38 (ctor reach +0x30, derived writes 0x31; tail unproven) -
// details: doc/object/Vt12d4940.md
namespace object {
class Vt12d4940 {
 public:
  void* mVtable;      // 0x00 — 0x12d4940 (cell 0x1311a48 + 0x10)
  uint64_t mId8;      // 0x08 — -1
  uint64_t mId10;     // 0x10 — -1
  uint8_t mFlag18;    // 0x18 — 0
  uint8_t mGap19[3];  // 0x19 — unproven gap
  uint32_t mVal1c;    // 0x1c — 0
  uint32_t mId20;     // 0x20 — -1
  uint8_t mFlag24;    // 0x24 — 1
  uint8_t mGap25[3];  // 0x25 — unproven padding
  void* mZero28;      // 0x28 — 0
  uint8_t mFlag30;    // 0x30 — 0
  uint8_t mGap31[7];  // 0x31 — unproven padding (derived zeroes 0x31)
};
}  // namespace object
