#pragma once

#include <cstdint>

// Vt12e5b58 - PLACEHOLDER name; nex/InstanceTable-region object, factory
// allocates 0xe8 (new at 0xa38d60, assert string Core/InstanceTable.h at
// 0xa38d44). 15-slot primary table. extent 0xe8 -
// details: doc/object/Vt12e5b58.md

namespace object {
class Vt12e5b58 {
 public:
  void* vtable;              // 0x00 - 0x12e5b60 (GOT cell 0x1314958 holds
                             // 0x12e5b50 = vt-0x8; installed = cell+0x10)
  uint8_t mPad08[0x70];      // 0x08 - unproven padding (ctor zeroes from
                             // +0x78 on)
  uint64_t mField78;         // 0x78 - udiv result stored by ctor (0xa291f0-
                             // 0xa291f4)
  uint8_t mPad80[0x8];       // 0x80 - unproven padding
  void* mMemberVtable88;     // 0x88 - 0x12e5980 (GOT cell 0x1314960 holds
                             // 0x12e5970 = vt-0x8; embedded member spans
                             // +0x88 to extent)
  uint8_t mMemberBody90[0x18]; // 0x90 - member body, no ctor stores seen;
                             // unproven
  uint64_t mFieldA8;         // 0xa8 - ctor stores 0 (0xa29230); D1 decrefs
                             // the refcount at [this+0xe0]+8 (0xa292d8)
  uint8_t mFieldB0;          // 0xb0 - ctor zeroes byte
  uint8_t mPadB1[0x7];       // 0xb1 - unproven padding
  uint32_t mFieldB8;         // 0xb8 - ctor zeroes
  uint8_t mPadBC[0xc];       // 0xbc - unproven padding
  uint8_t mStrC8[0x20];      // 0xc8 - FUN_71005788bc member ctor (libc++
                             // string, 0xa29210)
};
}  // namespace object
