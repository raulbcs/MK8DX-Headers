#pragma once

#include <cstdint>

// Vt12cc638 — PLACEHOLDER name; vptr 0x12cc638, n=98, primary table.
// Multiple inheritance: secondary vptrs at +0x1F8/+0x200/+0x208.
// extent 0x6400 (unverified round-up, deepest member dtor +0x628) -
// details: doc/object/Vt12cc638.md

namespace object {
class Vt12cc638 {
 public:
  void* mVtable;            // 0x00 — 0x12cc638 (via GOT cell 0x1307108)
  uint8_t mPad8[0x1F0];     // 0x08 — unproven padding (member dtors at 0x178/0x3D8/0x490/0x548/0x628)
  void* mVtable2;           // 0x1F8 — 0x12cc638+0x3B0
  void* mVtable3;           // 0x200 — 0x12cc638+0x3D0
  void* mVtable4;           // 0x208 — 0x12cc638+0x3F0
  uint8_t mPad210[0x61F0];  // 0x210 — unproven padding
};
}  // namespace object
