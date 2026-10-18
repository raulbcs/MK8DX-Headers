#pragma once

#include <cstdint>

// Vt12b6af8 — PLACEHOLDER name (model/scene-region aggregate, 83+ slots);
// primary vptr 0x12b6af8 at +0x00, secondary vptr 0x12b6da0 at +0xd0.
// extent 0x5ec8 - details: doc/object/Vt12b6af8.md

namespace object {
class Vt12b6af8 {
 public:
  void* vtable;          // 0x00 — 0x12b6af8 (ctor 0x71006bb33c)
  char mPad8[0xc8];      // 0x08 — unproven
  void* mVptrD0;         // 0xd0 — secondary vptr 0x12b6da0 (ctor 0x71006bb340)
  char mPadD8[0x18];     // 0xd8 — unproven
  uint32_t mFieldF0;     // 0xf0 — ctor zeroes (0x71006bb320)
  char mPadF4[0x4];      // 0xf4 — unproven
  void* mArrayF8;        // 0xf8 — 0x3e0-stride element array (dtor 0x71006bb488)
  char mPad100[0x260];   // 0x100 — unproven (sub-object ctors at +0x16a0, +0x1dd8,
                         // +0x39c8, +0x3cd0, +0x3fd0, +0x4d00, +0x54b8)
  void* mSelf360;        // 0x360 — ctor stores this (0x71006bb440)
  char mPad368[0x5990];  // 0x368 — unproven (sub-object ctors at +0x5670, +0x5af8)
  void* mField5cf8;      // 0x5cf8 — ctor zeroes (0x71006bb3e0)
  uint64_t mField5d00;   // 0x5d00 — ctor 0xa39 (0x71006bb3d0)
  uint64_t mField5d08;   // 0x5d08 — ctor 3 (0x71006bb3d4)
  uint32_t mField5d10;   // 0x5d10 — ctor -1 (0x71006bb3e4)
  uint64_t mField5d14;   // 0x5d14 — ctor zeroes (0x71006bb3f4)
  uint16_t mField5d1c;   // 0x5d1c — ctor zeroes (0x71006bb3ec)
  char mPad5d1e[0x2];    // 0x5d1e — unproven
  uint64_t mField5d20;   // 0x5d20 — ctor 1.0f, 1.0f (0x71006bb3f8)
  char mSub5d28[0x20];   // 0x5d28 — ctor-zeroed block (0x71006bb3ac..0x71006bb408)
  char mSub5d48[0xc8];   // 0x5d48 — sub-object ctor FUN_710063194c (0x71006bb418)
  uint32_t mField5e10;   // 0x5e10 — ctor zeroes (0x71006bb420)
  char mPad5e14[0x4];    // 0x5e14 — unproven
  void* mField5e18;      // 0x5e18 — ctor zeroes, dtor frees (0x71006bb42c/0x71006bb4d0)
  char mSub5e20[0x8];    // 0x5e20 — unproven
  char mSub5e28[0x40];   // 0x5e28 — sub-object ctor FUN_7100628628 (0x71006bb430)
  char mSub5e68[0x60];   // 0x5e68 — sub-object ctor FUN_7100628628 (0x71006bb43c)
};
}  // namespace object
