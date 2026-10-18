#pragma once

#include <cstdint>

namespace nn::pia::nat {
// nn::pia::nat::NatTraverser - RTTI-named (typeinfo slot 0x12dba80 -> record
// 0x12dbab0, "N2nn3pia3nat12NatTraverserE", root class, base 0). vptr
// 0x12dba88, 5 slots; secondary 3-slot row 0x12dbad0 at this+0x28.
// extent 0xc8 (lb) - details: doc/_nn/pia/nat/NatTraverser.md
class NatTraverser {
 public:
  void* vtable;       // 0x00 - 0x12dba88 (GOT cell 0x1313208 + 0x10)
  void* m08;          // 0x08 - used by slot 2 (0x964e34)
  uint16_t m10;       // 0x10 - C1 zero
  uint16_t m12;       // 0x12 - C1 zero
  uint32_t m14;       // 0x14 - C1 zero
  void* m18;          // 0x18 - C1 zero
  uint32_t m20;       // 0x20 - C1 zero
  uint8_t m24;        // 0x24 - C1 zero
  char pad25[3];      // pad - unproven gap
  void* m28;          // 0x28 - secondary vptr 0x12dbad0 (cell 0x1313210 + 0x10)
  uint32_t m30;       // 0x30 - C1 zero
  char m34[0x20];     // 0x34 - C1 sub-init 0x929fd4, split unverified
  char pad54[0xc];    // pad - unproven gap
  uint32_t m60;       // 0x60 - C1 zero
  char pad64[4];      // pad - unproven gap
  uint8_t m68;        // 0x68 - C1 zero
  char pad69[3];      // pad - unproven gap
  uint16_t m6c;       // 0x6c - region read/written near 0x6a, unverified
  char pad6e[2];      // pad - unproven gap
  void* m70;          // 0x70 - new 0x518, C1 0x967140 (D1 deletes via slot 0)
  void* m78;          // 0x78 - new 0x4a0, C1 0x968c40 (NatPropertyDetecter)
  char m80[0x20];     // 0x80 - C1 sub-init 0x929ec0, split unverified
  char ma0[0x20];     // 0xa0 - C1 sub-init 0x929ec0, split unverified
  void* mc0;          // 0xc0 - C1 zero
};
}  // namespace nn::pia::nat
