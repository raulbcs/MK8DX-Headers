#pragma once

#include <cstdint>

namespace nn::pia::lan {
// RTTI-confirmed (compact ti record 0x12dc7a0, name "N2nn3pia3lan11LanProtocolE");
// vptr 0x12dc728 via GOT cell 0x13133b8 (vt-0x10); 13 slots; ctor 0x96f9d4.
// Built in place at lanmanager-singleton+0x10 (cell 0x13125e0). extent 0x12a0 (lower
// bound) - details: doc/_nn/pia/lan/LanProtocol.md
class LanProtocol {
 public:
  void* vtable;           // 0x00 — 0x12dc728
  uint8_t mPad08[0x20];   // 0x08 — unproven gap (base-ctor region, 0x9a79c8)
  uint8_t mField28;       // 0x28 — init 0
  uint8_t mPad29[0x3];    // 0x29 — unproven padding
  uint32_t mField2C;      // 0x2C — init 0 (stp wzr,wzr @0x2c)
  uint32_t mField30;      // 0x30 — init 0
  uint32_t mField34;      // 0x34 — init 0
  uint8_t mField38;       // 0x38 — init 0
  uint8_t mPad39[0x17];   // 0x39 — unproven padding
  uint8_t mField50;       // 0x50 — init 0
  uint8_t mPad51[0x17];   // 0x51 — unproven padding
  uint64_t mField68;      // 0x68 — init 0
  uint8_t mPad70[0x5D8];  // 0x70 — unproven (memset region + packet buffer area)
  uint8_t mField648;      // 0x648 — init 0
  uint8_t mPad649[0xBC7]; // 0x649 — unproven (includes u32 init 0x320=800 at +0xc28, see doc)
  uint64_t mField1210;    // 0x1210 — pointer (x20 = this+0x1210 in ctor)
  uint8_t mPad1218[0x8];  // 0x1218 — unproven padding
  uint16_t mField1220;    // 0x1220 — init 0
  uint8_t mPad1222[0x26]; // 0x1222 — unproven padding
  uint64_t mField1248;    // 0x1248 — init 0
  uint8_t mPad1250[0x20]; // 0x1250 — unproven padding
  uint64_t mField1270;    // 0x1270 — init 0
  uint8_t mPad1278[0x20]; // 0x1278 — unproven padding
  uint64_t mField1298;    // 0x1298 — init 0
};
}  // namespace nn::pia::lan
