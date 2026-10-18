#pragma once

#include <cstdint>

namespace object {
// Vt12b0078 - PLACEHOLDER name; 0x108-byte member of the aligned-buffer
// family built by FUN_7100618fc4 (sibling of Vt12b0388/Vt12b0198). Dtor pair
// 0x7100615744 / 0x7100615778; no RTTI (null typeinfo slot).
// extent 0x108 - details: doc/object/Vt12b0078.md
class Vt12b0078 {
 public:
  void* vtable;      // 0x00 - 0x12b0078 (GOT cell 0x130d2a0 holds 0x12b0068 =
                     //   vt-0x10)
  char pad08[0xc8];  // 0x08..0xcf - built by FUN_7100618fc4 (0x7100615ab0 /
                     //   0x71006158ac call sites); unproven
  uint16_t mFlagsD0; // 0xd0 - pre-existing flag read at 0x7100615b0c
                     //   (bit 0 gates the +0x90 init path)
  char padD2[0x02];  // 0xd2..0xd3 - unproven gap
  uint8_t mD4;       // 0xd4 - ctor zero
  uint8_t mD5;       // 0xd5 - ctor zero
  char padD6[0x02];  // 0xd6..0xd7 - unproven gap
  void* mHeadD8;     // 0xd8 - list head, self pointee (this+0xd8)
  void* mTailE0;     // 0xe0 - list tail, self pointee (this+0xd8)
  uint32_t mE8;      // 0xe8 - ctor 0 / -1 (stp wzr,w9 [x20,#0xe8])
  uint32_t mEc;      // 0xec - ctor 0 (bit0 path) or untouched
  void* mF0;         // 0xf0 - self pointee (this+0xf0)
  void* mF8;         // 0xf8 - self pointee (this+0xf0)
  uint32_t m100;     // 0x100 - ctor zero
  uint32_t m104;     // 0x104 - ctor -1, then 0 on the bit0 path
};
}  // namespace object
