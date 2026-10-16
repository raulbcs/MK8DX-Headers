#pragma once

#include <cstdint>

namespace object {
// ParamNodeEnvObjName — named from ctor string evidence: ctor params env 'name'/object-name JP + 'enable' display block (0xef8f59-0xef8f86) (was address-anchored ParamNodeVt1fc0) (vptr 0x12b1fc0, cell 0x130d900, n=22, site 0x646de0, ctor 0x646dac).
class ParamNodeEnvObjName {
 public:
  void* vtable;          // 0x00
  uint8_t mPad8[0x38];   // 0x8 — unproven gap
  uint64_t mField40;     // 0x40
  uint8_t mPad48[0x10];  // 0x48 — unproven gap
  uint8_t mPad58;        // 0x58 — ctor zero
  uint8_t mPad59[0x7];   // 0x59 — unproven gap
  uint64_t mField60;     // 0x60
  uint8_t mPad68[0x18];  // 0x68 — unproven gap
  uint64_t mField80;     // 0x80
  uint32_t mField88;     // 0x88
  uint8_t mPad8c[0x24];  // 0x8c — unproven gap
  uint16_t mPadb0;       // 0xb0 — ctor zero
  uint8_t mFieldb2;      // 0xb2
  uint8_t mPadb3[0x5];   // 0xb3 — unproven gap
  uint64_t mFieldb8;     // 0xb8
  uint8_t mPadc0[0x18];  // 0xc0 — unproven gap
  uint64_t mFieldd8;     // 0xd8
  uint32_t mFielde0;     // 0xe0
  uint8_t mPade4[0x24];  // 0xe4 — unproven gap
  uint16_t mField108;    // 0x108
};
}  // namespace object
