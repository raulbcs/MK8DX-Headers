#pragma once

#include <cstdint>

// Vt12d2820 — PLACEHOLDER name (43-slot MI class, framework-range secondary
// bases); vptr 0x12d2820 at +0x00, secondary vptr 0x125f2e0 at +0x430/+0x4c8.
// extent 0x770 - details: doc/object/Vt12d2820.md

namespace object {
class Vt12d2820 {
 public:
  void* vtable;          // 0x00 — 0x12d2820 (ctor 0x3c44e0)
  char mPad8[0x170];     // 0x08 — unproven (sub-object ctor 0x7b978c at +0x178)
  char mSub178[0xc0];    // 0x178 — sub-object ctor FUN_71007b978c (0x3c7888)
  char mPad238[0x1e0];   // 0x238 — unproven (sub-object ctor 0x674a50 at +0x238)
  char mPad418[0x8];     // 0x418 — unproven
  void* mPtr420;         // 0x420 — ctor zeroes (0x3c44cc)
  void* mPtr428;         // 0x428 — ctor zeroes (0x3c44c0)
  char mPad430[0x40];    // 0x430 — secondary vptr 0x125f2e0 at +0x430;
                         // sub-object ctors 0x60bf28/0x6155bc
  void* mSelf470;        // 0x470 — ctor stores this+0x430 (0x3c44f4)
  void* mField478;       // 0x478 — ctor 0x11ad210 (0x3c4508)
  void* mField480;       // 0x480 — ctor 0xee66a8 (0x3c450c)
  char mPad488[0x20];    // 0x488 — unproven (+0x4a8 zeroed)
  void* mField4A8;       // 0x4a8 — ctor zeroes (0x3c4518)
  char mPad4B0[0x18];    // 0x4b0 — unproven (+0x4b8/+0x4c0 zeroed)
  char mSub4C8[0x2a8];   // 0x4c8 — secondary vptr 0x125f2e0 at +0x4c8; rest
                         // unproven (extends to 0x770)
};
}  // namespace object
