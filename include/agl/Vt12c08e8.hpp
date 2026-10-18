#pragma once

#include <cstdint>

// Vt12c08e8 - PLACEHOLDER name; family-B BASE class of the agl layout-pane family (derived variants:
// Vt12bfc68 0x150, Vt12c00b8 0x160). 28-slot vtable, vptr +0x00, secondary vptr +0x100.
// extent 0x140 - details: doc/agl/Vt12c08e8.md

namespace agl {
class Vt12c08e8 {
 public:
  void* vtable;             // 0x00 - 0x12c08e8 (GOT cell 0x130edc8 + 0x10)
  uint8_t mBase08[0xe8];    // 0x08 - 0x0f0 base C1 0x5a7384 part; layout unproven
  uint32_t mF0;             // 0x0f0 - u32 param word (4 bytes copied from arg stream)
  uint32_t mF4;             // 0x0f4 - u32 param word
  uint32_t mF8;             // 0x0f8 - u32 param word
  uint32_t mFC;             // 0x0fc - u32 param word
  void* vtable2;            // 0x100 - 0x12ad238 (GOT cell 0x130c998 + 0x10)
  uint8_t m108[0x8];        // 0x108 - unverified
  uint8_t m110;             // 0x110 - u8 (from [arg+0x65]>>2 & 3)
  uint8_t m111;             // 0x111 - u8 (zeroed, then from ctor arg byte)
  uint8_t m112;             // 0x112 - flag bits 0/1/2 composed from [arg+0x65]
  uint8_t mPad113[0x5];     // 0x113 - 0x118 padding
  void* m118;               // 0x118 - allocation set late in C1 (0x5a77f8 region)
  uint8_t mPad120[0x8];     // 0x120 - 0x128 padding
  void* m128;               // 0x128 - zeroed, then allocation (0x5a77f8)
  uint32_t m130;            // 0x130 - zeroed, then u32 (0x5a77fc)
  uint8_t mPad134[0xc];     // 0x134 - 0x140 padding
};
}  // namespace agl
