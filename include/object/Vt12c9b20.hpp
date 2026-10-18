#pragma once

#include <cstdint>

// Vt12c9b20 — PLACEHOLDER name; vptr 0x12c9b20, n=32, primary table.
// Base class of Vt12c9158; ctor FUN_71007f6b48, ten owned 0x10-byte sub-objects at +0x1E0..+0x228.
// extent 0x230 - details: doc/object/Vt12c9b20.md

namespace object {
class Vt12c9b20 {
 public:
  void* mVtable;           // 0x00 — 0x12c9b20 (via GOT cell 0x13103c8, holds vt-0x10)
  uint8_t mPad8[0x160];    // 0x08 — unproven padding
  uint32_t m168;           // 0x168 — zeroed by ctor
  uint8_t m16C;            // 0x16C — zeroed by ctor
  uint8_t mPad16D[3];      // 0x16D — unproven padding
  void* m170;              // 0x170 — zeroed by ctor
  uint8_t mPad178[2];      // 0x178 — unproven padding
  uint16_t m17A;           // 0x17A — unproven
  uint32_t m17C;           // 0x17C — zeroed by ctor
  uint32_t m180;           // 0x180 — ctor arg (w3)
  uint32_t m184;           // 0x184 — copy of [ctor arg x2]
  uint8_t m188[0x58];      // 0x188 — memset 0, 0x58 bytes
  void* mSub[10];          // 0x1E0..0x228 — ten new(0x10) objects (vt 0x12c9c30)
};

}  // namespace object
