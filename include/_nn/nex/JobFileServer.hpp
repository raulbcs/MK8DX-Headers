#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-named (typeinfo 0x12e76a0, "N2nn3nex13JobFileServerE"). Typeinfo-slot
// row: vptr 0x12e6e38 (GOT cell 0x1314c20), 15 primary slots; MI secondary
// vptr 0x12e6ed8 (vt+0xb0) installed at [this+0xa0], Job base at +0xb0.
// extent 0x1d8 - details: doc/_nn/nex/JobFileServer.md
class JobFileServer {
 public:
  void* vtable;           // 0x00 - 0x12e6e38 (cell 0x1314c20 + 0x10)
  char pad08[0x98];       // 0x08..0x9f - nex job base region (shared ctor
                          //   0x588b04, x1=2); unproven
  void* mVptrA0;          // 0xa0 - own MI secondary vptr 0x12e6ed8 (vt+0xb0)
  uint32_t mA8;           // 0xa8 - ctor zero
  char padAC[0x4];        // 0xac..0xaf - unproven gap
  void* mVptrB0;          // 0xb0 - nn::nex::Job secondary vptr 0x128c698
                          //   (cell 0x130b4a8 + 0x10)
  uint8_t mB8;            // 0xb8 - ctor zero
  char padB9[0xf];        // 0xb9..0xc7 - unproven gap
  void* mC8;              // 0xc8 - self-pointer to +0xb8 (ctor)
  uint64_t mD0;           // 0xd0 - ctor constant 0x10
  uint32_t mD8;           // 0xd8 - ctor zero
  char padDC[0x4];        // 0xdc..0xdf - unproven gap
  void* mE0;              // 0xe0 - ctor zero
  void* mE8;              // 0xe8 - ForcedCriticalSection vptr (cell
                          //   0x130b618 + 0x10)
  uint32_t mF0;           // 0xf0 - stlr 1 (atomic flag)
  uint8_t mF4;            // 0xf4 - ctor zero
  char padF5[0x3];        // 0xf5..0xf7 - unproven gap
  void* mF8;              // 0xf8 - ctor zero
  uint32_t m100;          // 0x100 - ctor zero
  char pad104[0x4];       // 0x104..0x107 - unproven gap
  void* m108;             // 0x108 - self-pointer to +0x108
  void* m110;             // 0x110 - self-pointer to +0x108 (ctor, stp high)
  char pad118[0x20];      // 0x118..0x137 - member built by 0x5788e0
                          //   (ctor zeroes 0x118/0x128/0x138); unproven
  void* m138;             // 0x138 - ctor zero
  char pad140[0x18];      // 0x140..0x157 - unproven gap
  void* m158;             // 0x158 - ctor zero
  uint32_t m160;          // 0x160 - ctor zero
  char pad164[0x4];       // 0x164..0x167 - unproven gap
  void* m168;             // 0x168 - ctor zero
  void* m170;             // 0x170 - ctor zero
  char pad178[0x30];      // 0x178..0x1a7 - subobject inited by 0xa211f8;
                          //   trailing bytes +0x180/+0x190/+0x1a0 zeroed
                          //   by ctor; unproven
  void* mVptr1a8;         // 0x1a8 - Job secondary vptr 0x128c698 (second
                          //   Job-base subobject head)
  uint8_t m1b0;           // 0x1b0 - ctor zero
  char pad1b1[0xf];       // 0x1b1..0x1bf - unproven gap
  void* m1c0;             // 0x1c0 - self-pointer to +0x1b0
  uint64_t m1c8;          // 0x1c8 - ctor constant 0x10
  uint64_t m1d0;          // 0x1d0 - ctor zero
};
}  // namespace nn::nex
