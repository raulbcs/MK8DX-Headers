#pragma once

#include <cstdint>

// Vt12e54d0 - PLACEHOLDER name; nex-region object built by factory
// FUN_7100a21214 (new 0x118) which then invokes virtual slot +0x68. 15-slot
// primary table. extent 0x118 - details: doc/object/Vt12e54d0.md

namespace object {
class Vt12e54d0 {
 public:
  void* vtable;              // 0x00 - 0x12e54d8 (GOT cell 0x13148b0 holds
                             // 0x12e54c8 = vt-0x8; installed = cell+0x10)
  uint8_t mPad08[0x98];      // 0x08 - unproven padding (factory zeroes only
                             // from +0xa0 on)
  uint32_t mFieldA0;         // 0xa0 - factory zeroes (0xa21290)
  uint8_t mPadA4[0x4];       // 0xa4 - unproven padding
  void* mFieldA8;            // 0xa8 - factory stores 0; D1 calls its [0]+8
                             // slot (member dtor) if non-null (0xa21a10)
  void* mMemberVtableB0;     // 0xb0 - 0x128c698 (GOT cell 0x130b4a8 holds
                             // 0x128c688 = vt-0x8; member of the 0x128cxxx
                             // family, cf. Vt12e2f18)
  uint8_t mFieldB8;          // 0xb8 - factory zeroes byte; +0xc8 string
                             // points back here (SSO buffer)
  uint8_t mPadB9[0xf];       // 0xb9 - unproven padding
  void* mStrC8[2];           // 0xc8 - std::string {&this+0xb8, 0x10} then
                             // FUN_7100578f98 assigns "" (0xa212bc-0xa212c0)
  uint32_t mFieldD8;         // 0xd8 - factory zeroes
  uint8_t mPadDC[0x4];       // 0xdc - tail of the 0xd8-0xdf zeroing; unproven
  uint64_t mFieldE0[2];      // 0xe0 - factory zeroes 0xe0-0xef
  uint64_t mFieldF0;         // 0xf0 - factory stores 0
  uint8_t mFieldF8;          // 0xf8 - factory zeroes byte
  uint8_t mPadF9[0x7];       // 0xf9 - unproven padding
  uint64_t mField100[2];     // 0x100 - factory zeroes 0x100-0x10f
  uint32_t mField110;        // 0x110 - 10 or 5, from global byte at GOT cell
                             // 0x130b808 (0xa212e0-0xa212f4)
  uint8_t mPad114[0x4];      // 0x114 - unproven padding to extent
};
}  // namespace object
