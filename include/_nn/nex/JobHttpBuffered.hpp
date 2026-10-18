#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-named (typeinfo 0x12e5830, "N2nn3nex15JobHttpBufferedE"). Typeinfo-slot
// row: vptr 0x12e5558 (GOT cell 0x13148b8), 18 primary slots; MI secondary
// vptr 0x12e5600 (vt+0xb0) installed at [this+0x118], Job base at +0xb0.
// extent 0x1a0 - details: doc/_nn/nex/JobHttpBuffered.md
class JobHttpBuffered {
 public:
  void* vtable;           // 0x00 - 0x12e5558 (cell 0x13148b8 + 0x10)
  char pad08[0x98];       // 0x08..0x9f - nex job base region (shared ctor
                          //   0x588b04; primary base vptr 0x12e54d0 via cell
                          //   0x13148b0); unproven
  uint32_t mA0;           // 0xa0 - ctor zero
  char padA4[0x4];        // 0xa4..0xa7 - unproven gap
  void* mA8;              // 0xa8 - ctor zero (released in D1 via slot call)
  void* mVptrB0;          // 0xb0 - nn::nex::Job secondary vptr 0x128c698
                          //   (cell 0x130b4a8 + 0x10)
  uint8_t mB8;            // 0xb8 - ctor zero
  char padB9[0xf];        // 0xb9..0xc7 - unproven gap
  void* mC8;              // 0xc8 - self-pointer to +0xb8 (ctor)
  uint64_t mD0;           // 0xd0 - ctor constant 0x10
  uint32_t mD8;           // 0xd8 - ctor zero
  char padDC[0x4];        // 0xdc..0xdf - unproven gap
  void* mE0;              // 0xe0 - ctor zero (released in D1)
  void* mE8;              // 0xe8 - ctor zero
  void* mF0;              // 0xf0 - ctor zero
  uint8_t mF8;            // 0xf8 - ctor zero
  char padF9[0x7];        // 0xf9..0xff - unproven gap
  void* m100;             // 0x100 - ctor zero
  void* m108;             // 0x108 - ctor zero
  uint32_t m110;          // 0x110 - 10 or 5, selected by data flag 0x128cd98
  char pad114[0x4];       // 0x114..0x117 - unproven gap
  void* mVptr118;         // 0x118 - own MI secondary vptr 0x12e5600
                          //   (vt+0xb0); D1 restores it before +0xb0
  uint32_t m120;          // 0x120 - ctor constant 0x10
  char pad124[0x4];       // 0x124..0x127 - unproven gap
  void* m128;             // 0x128 - ctor zero
  char pad130[0x8];       // 0x130..0x137 - unproven gap
  void* m138;             // 0x138 - buffer returned by 0x576368; refcount
                          //   byte at *m138 cleared
  uint64_t m140;          // 0x140 - use counter (init 1)
  void* m148;             // 0x148 - ctor zero
  void* m150;             // 0x150 - ctor zero
  void* m158;             // 0x158 - ctor zero
  uint64_t m160;          // 0x160 - ctor zero
  uint64_t m168;          // 0x168 - ctor constant 1
  void* m170;             // 0x170 - self-pointer to +0x178
  uint64_t m178;          // 0x178 - ctor zero
  void* m180;             // 0x180 - ctor zero
  void* m188;             // 0x188 - ctor zero
  uint64_t m190;          // 0x190 - ctor zero
  uint8_t m198;           // 0x198 - ctor constant 1
  char pad199[0x7];       // 0x199..0x19f - unproven gap
};
}  // namespace nn::nex
