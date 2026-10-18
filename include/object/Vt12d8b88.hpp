#pragma once

#include <cstdint>

// Vt12d8b88 — PLACEHOLDER name (44-slot class, ldn-adjacent 0x12d region);
// vptr 0x12d8b88 at +0x00, ctor FUN_710091f950.
// extent 0x88 - details: doc/object/Vt12d8b88.md

namespace object {
class Vt12d8b88 {
 public:
  void* vtable;         // 0x00 — 0x12d8b88 (ctor 0x91f998)
  char mPad8[0x4];      // 0x08 — base-ctor u8 field (0x920b38)
  char mPadC[0x10];     // 0x0c — unproven (base ctor zeroes +0x0c/+0x14)
  uint32_t mField1C;    // 0x1c — base ctor zeroes (0x920b44)
  char mPad20[0x3c];    // 0x20 — unproven (base ctor +0x20=1, +0x28=0, +0x30=0,
                        // +0x38=0)
  uint32_t mField5C;    // 0x5c — ctor zeroes (0x91f968)
  uint16_t mField60;    // 0x60 — ctor 3000 (0x91f980)
  uint16_t mField62;    // 0x62 — ctor zeroes (0x91f98c)
  char mPad64[0x4];     // 0x64 — unproven
  void* mField68;       // 0x68 — ctor zeroes (0x91f978)
  uint32_t mField70;    // 0x70 — ctor zeroes (0x91f97c)
  char mPad74[0x4];     // 0x74 — unproven
  uint32_t mField78;    // 0x78 — ctor zeroes (0x91f990)
  char mPad7C[0x4];     // 0x7c — unproven
  uint64_t mField80;    // 0x80 — ctor zeroes (0x91f994)
};
}  // namespace object
