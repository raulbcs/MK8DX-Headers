#pragma once

#include <cstdint>

// Vt12e5978 — NEX "CallProtocolMethod" context subobject (vptr 0x12e5980, row
// label 0x12e5978, GOT cell 0x1314960 holds vptr-0x10). Subobject at owner+0x88
// of the 0xe8 class built by FUN_7100a2917c; base ctor FUN_710058bd2c (base
// vptr cell 0x130b848 -> rodata 0x128cee0), extent 0x40 up to the next
// subobject vptr at owner+0xc8.
// extent 0x40 - details: doc/object/Vt12e5978.md

namespace object {
class Vt12e5978 {
 public:
  void* mVtable;      // 0x00 — 0x12e5980 (via GOT cell 0x1314960 = vptr-0x10)
  uint8_t mPad8[0x18];  // 0x08 — unproven padding
  uint64_t mField20;  // 0x20 — zeroed by owner ctor (0xa29230)
  uint8_t mField28;   // 0x28 — flag, zeroed by owner ctor (0xa29234)
  uint8_t mPad29[0x7];  // 0x29 — unproven padding
  uint32_t mField30;  // 0x30 — zeroed by owner ctor (0xa2921c str wzr,[x20,#0xb8])
  uint8_t mPad34[0x4];  // 0x34 — unproven padding
  uint32_t mField38;  // 0x38 — zeroed by owner ctor (0xa2923c str wzr,[x20,#0xc0])
  uint8_t mPad3c[0x4];  // 0x3c — unproven padding
};
}  // namespace object
