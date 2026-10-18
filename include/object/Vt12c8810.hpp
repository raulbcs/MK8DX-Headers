#pragma once

#include <cstdint>

// Vt12c8810 — PLACEHOLDER name; gear::Actor-derived (base C1 0x7b976c), 14 slots, no RTTI.
// C1 0x7e4ad8 zeroes +0x38..+0xB1; derived flavour overrides the vptr with 0x12cdf48.
// extent 0xB8 (inferred: zero-fill ends +0xB1, derived flavour writes +0xB4; unverified) -
// details: doc/object/Vt12c8810.md

namespace object {
class Vt12c8810 {
 public:
  void* mVtable;         // 0x00 — 0x12c8810 (via GOT cell 0x1310178, cell holds vptr-0x10)
  uint8_t mPad8[0x30];   // 0x08 — unproven padding (gear::Actor base C1 0x7b976c zeroes +0x10..+0x38)
  uint8_t mPad38[0x79];  // 0x38 — ctor memset zero (0x7e4afc-0x7e4b08)
  uint8_t mPadb1[0x7];   // 0xB1 — unproven padding to 8-byte alignment
};
}  // namespace object
