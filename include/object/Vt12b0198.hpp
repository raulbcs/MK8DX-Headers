#pragma once

#include <cstdint>

namespace object {
// Vt12b0198 - PLACEHOLDER name; 0xe8-byte member of the aligned-buffer
// family built by FUN_7100618fc4, with a guarded static singleton accessor
// FUN_7100618038. Dtor pair 0x71006180c4 / 0x71006180f8; no RTTI.
// extent 0xe8 - details: doc/object/Vt12b0198.md
class Vt12b0198 {
 public:
  void* vtable;      // 0x00 - 0x12b0198 (GOT cell 0x130d2d8 holds 0x12b0188 =
                     //   vt-0x10)
  char pad08[0xc8];  // 0x08..0xcf - built by FUN_7100618fc4 (0x710061822c /
                     //   0x7100618278 call sites); unproven
  uint16_t mFlagsD0; // 0xd0 - pre-existing flag read at 0x7100618244 (bit 0)
  char padD2[0x06];  // 0xd2..0xd7 - unproven gap
  void* mHeadD8;     // 0xd8 - ctor zeroes the head/tail pair
  void* mTailE0;     // 0xe0 - ctor zeroes the head/tail pair
};
}  // namespace object
