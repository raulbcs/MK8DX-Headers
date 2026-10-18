#pragma once

#include <cstdint>

// Vt12d4b00 — PLACEHOLDER name; derived flavour of Vt12d48b8 (base C1 0x8c1de0
// then vptr override, no out-of-line C1).
// extent 0x28 (family spacing; direct proof unverified) - details:
// doc/object/Vt12d4b00.md
namespace object {
class Vt12d4b00 {
 public:
  void* mVtable;      // 0x00 — 0x12d4b00 (cell 0x1308f20 + 0x10, override)
  uint64_t mId8;      // 0x08 — -1 (base C1 0x8c1de0)
  uint64_t mId10;     // 0x10 — -1 (base C1 0x8c1de0)
  uint8_t mFlag18;    // 0x18 — 0
  uint8_t mGap19[3];  // 0x19 — unproven gap
  uint32_t mVal1c;    // 0x1C — 0
  uint32_t mId20;     // 0x20 — -1
  uint8_t mFlag24;    // 0x24 — 0
  uint8_t mGap25[3];  // 0x25 — unproven padding
};
}  // namespace object
