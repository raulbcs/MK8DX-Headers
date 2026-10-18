#pragma once

#include <cstdint>

namespace nn::pia::common {
// nn::pia::common::SimpleContainer<nn::pia::common::InetAddress, 4> - RTTI-named
// (typeinfo slot 0x12dbb00 -> record 0x12dbb68, root, base 0). vptr 0x12dbb08;
// doubles as the base-stage row staged inside NatDetectionJob C1 0x96606c.
// extent 0x3ec (lb) - details: doc/_nn/pia/common/SimpleContainerInetAddress4.md
class SimpleContainerInetAddress4 {
 public:
  void* vtable;       // 0x00 - 0x12dbb08 (GOT cell 0x1313240 + 0x10)
  char pad08[0x14];   // pad - sub-init 0xb49bb8 region, split unverified
  void* m1c;          // 0x1c - C1 sub-init 0x929fd4
  void* m24;          // 0x24 - C1 sub-init 0x929fd4
  uint32_t m2c;       // 0x2c - C1 zero
  void* m30;          // 0x30 - C1 zero
  void* m38;          // 0x38 - C1 zero
  uint32_t m40;       // 0x40 - C1 zero
  char pad44[4];      // pad - C1 zero region
  uint32_t m48;       // 0x48 - C1 zero
  char pad4c[4];      // pad - C1 zero region
  void* m50;          // 0x50 - C1 zero
  void* m58;          // 0x58 - C1 zero
  char m60[0x1c];     // 0x60 - 0x56810c-style inits / later zeros, split unverified
  uint32_t m7c;       // 0x7c - entry count read by C1 loop (ldrsw)
  void* m80;          // 0x80 - entry array base, 0x28-byte entries to 0x378
  char pad88[0x328];  // pad - entry array body, split unverified
  void* m3b0;         // 0x3b0 - C1 zero
  void* m3b8;         // 0x3b8 - C1 zero
  void* m3c0;         // 0x3c0 - C1 zero
  void* m3c8;         // 0x3c8 - C1 zero
  void* m3d0;         // 0x3d0 - C1 zero
  void* m3d8;         // 0x3d8 - C1 zero
  void* m3e0;         // 0x3e0 - C1 zero
  uint32_t m3e8;      // 0x3e8 - last field written by C1 0x96606c
};
}  // namespace nn::pia::common
