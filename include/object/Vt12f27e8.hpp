#pragma once

#include <cstdint>

// Vt12f27e8 — PLACEHOLDER name; vptr 0x12f27e8, n=7, primary table; base of a
// multi-level ctor chain (wrappers 0x7DFB80 / 0x8DF154).
// extent 0x34D - lower bound (deepest leaf-level store +0x34C); unverified -
// details: doc/object/Vt12f27e8.md

namespace object {
class Vt12f27e8 {
 public:
  void* mVtable;            // 0x00 — 0x12f27e8 (via GOT cell 0x1315138)
  uint8_t mPad8[0x130];     // 0x08 — unproven padding (init helper 0xA8933C)
  void* mVtable2;           // 0x138 — secondary 0x12f2830 (cell 0x1315138+0x58)
  uint8_t mPad140[0x58];    // 0x140 — unproven padding
  uint8_t mBlob198[0x18];   // 0x198 — 24 bytes copied from GOT cell 0x1315140 (rodata 0xF88188, unverified)
  uint32_t mFlags1B0;       // 0x1B0 — ctor writes 0x19181B1A
  uint8_t mPad1B4[0x199];   // 0x1B4 — unproven padding (leaf wrappers store up to +0x34C)
};
}  // namespace object
