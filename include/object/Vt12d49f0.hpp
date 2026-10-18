#pragma once

#include <cstdint>

// Vt12d49f0 — PLACEHOLDER name; connection-status family class with an
// out-of-line C1 (0x8c27d4) and a 0x128 sub-object at +0x28 (init 0x49b7e0).
// extent 0x150 (two owners embed it with 0x150 spacing) - details:
// doc/object/Vt12d49f0.md
namespace object {
class Vt12d49f0 {
 public:
  void* mVtable;       // 0x00 — 0x12d49f0 (cell 0x1311a50 + 0x10)
  uint32_t mId8;       // 0x08 — -1 (ctor 0x8c2808)
  uint32_t mValC;      // 0x0C — 7, written after sub-object init (0x8c2818)
  uint64_t mId10;     // 0x10 — -1 (ctor 0x8c27e8, 64-bit store)
  uint8_t mFlag18;     // 0x18 — 0 (ctor 0x8c27ec)
  uint8_t mGap19[3];   // 0x19 — unproven gap
  uint32_t mVal1c;     // 0x1C — 0 (ctor 0x8c27fc)
  uint32_t mId20;      // 0x20 — -1 (ctor 0x8c27fc)
  uint8_t mFlag24;     // 0x24 — 0 (ctor 0x8c280c)
  uint8_t mGap25[3];   // 0x25 — unproven padding
  char mSub28[0x128];  // 0x28 — sub-object, init 0x49b7e0; ctor reaches +0x118,
                       // rest unproven (owner memset-0)
};
}  // namespace object
