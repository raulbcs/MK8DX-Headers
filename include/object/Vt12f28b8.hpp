#pragma once

#include <cstdint>

// Vt12f28b8 — PLACEHOLDER name; vptr 0x12f28b8, n=7, primary table; sibling of
// Vt12f27e8 (shared slots and init helper 0xA8933C).
// extent 0x208 - lower bound (+0x198 blob of 0x70); unverified -
// details: doc/object/Vt12f28b8.md

namespace object {
class Vt12f28b8 {
 public:
  void* mVtable;            // 0x00 — 0x12f28b8 (via GOT cell 0x1315150)
  uint8_t mPad8[0x130];     // 0x08 — unproven padding (init helper 0xA8933C)
  void* mVtable2;           // 0x138 — secondary 0x12f2900 (cell 0x1315150+0x58)
  uint8_t mPad140[0x58];    // 0x140 — unproven padding
  uint8_t mBlob198[0x70];   // 0x198 — 0x70 bytes memcpy'd from GOT cell 0x1315158 (rodata 0xF881A4, unverified)
};
}  // namespace object
