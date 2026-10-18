#pragma once

#include <cstdint>

// PaneMassDrawOn - pane created when the factory finds the "MassDrawOn"
// attribute (string 0xf07576); vptr 0x12bfe38 at +0x00, second base (vptr
// 0x12bff30) at +0x108. Ctor 0x743c38, factory 0x743448.
// extent 0x2c0 - details: doc/object/PaneMassDrawOn.md

namespace object {
class PaneMassDrawOn {
 public:
  void* vtable;      // 0x00 - 0x12bfe38 (C1 0x743c38 at 0x743c5c)
  uint8_t pad_08[0x20];   // 0x08 - 0x27 - list nodes (D1 slot 31 walks +0x28 / +0x38 lists)
  void* list28;      // 0x28 - intrusive list head (nodes freed via 0x5a0978)
  uint8_t pad_30[0x8];    // 0x30 - unproven
  void* list38;      // 0x38 - intrusive list head (nodes freed via 0xa6e540 + 0x5a0978)
  uint8_t pad_40[0xc8];   // 0x40 - 0x107 - unproven
  void* base108;     // 0x108 - second base subobject (vptr 0x12bff30; base ctor 0x643fa0)
  uint8_t pad_110[0x178]; // 0x110 - 0x287 - unproven
  uint32_t field288; // 0x288 - zeroed by C1 (0x743c64)
  uint8_t pad_28c[0x4];   // 0x28c - unproven
  uint64_t field290; // 0x290 - zeroed by C1 (0x743c68)
  uint32_t field298; // 0x298 - zeroed by C1 (0x743c6c)
  uint8_t pad_29c[0x4];   // 0x29c - unproven
  uint64_t field2a0; // 0x2a0 - zeroed by C1 (0x743c70)
  uint32_t field2a8; // 0x2a8 - zeroed by C1 (0x743c74)
  uint8_t pad_2ac[0x4];   // 0x2ac - unproven
  uint64_t field2b0; // 0x2b0 - zeroed by C1 (0x743c78)
  uint8_t field2b8;  // 0x2b8 - bool, zeroed by C1 (0x743c7c)
  uint8_t pad_2b9[0x7];    // 0x2b9 - 0x2BF - tail padding to extent 0x2c0
};
}  // namespace object
