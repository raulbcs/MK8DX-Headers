#pragma once

#include <cstdint>

namespace nn::pia::transport {
// nn::pia::transport::BandwidthCheckProtocol — RTTI-named (typeinfo 0x12dec10,
// name "N2nn3pia9transport22BandwidthCheckProtocolE"). 11 slots; abstract
// protocol base C1 0x9a79c8 runs first. GOT cell 0x1313ac0 holds vptr-0x10
// (vptr 0x12debb8).
// extent 0xe0 - details: doc/_nn/pia/transport/BandwidthCheckProtocol.md
class BandwidthCheckProtocol {
 public:
  void* mVtable;         // 0x00 - vptr 0x12debb8 (cell 0x1313ac0 + 0x10);
                         //   base C1 0x9a79c8 installs the base vptr first
  uint8_t mPad08[0x20];  // 0x08 - abstract protocol base fields
  uint8_t m28;           // 0x28 - C1 stores 0 (0x9a0f38)
  uint8_t mPad29[0x3];   // 0x29 - unproven
  uint32_t m2c;          // 0x2c - C1 stores 0 (0x9a0f44)
  uint16_t m30;          // 0x30 - C1 stores 0 (0x9a0f48 strh)
  uint8_t mPad32[0x6];   // 0x32 - unproven
  uint64_t m38;          // 0x38 - C1 stp xzr (0x9a0f54)
  uint64_t m40;          // 0x40 - C1 stp xzr
  uint64_t m48;          // 0x48 - C1 stp xzr
  uint64_t m50;          // 0x50 - C1 stores 0 (0x9a0f5c)
  uint8_t mPad58[0x8];   // 0x58 - unproven
  uint64_t m60;          // 0x60 - C1 stores 0 (0x9a0f60)
  uint8_t mPad68[0x8];   // 0x68 - unproven
  uint64_t m70;          // 0x70 - C1 stores 0 (0x9a0f64)
  uint8_t mPad78[0x18];  // 0x78 - unproven
  uint64_t m90;          // 0x90 - C1 stp xzr (0x9a0f6c)
  uint64_t m98;          // 0x98 - C1 stp xzr
  uint64_t ma0;          // 0xa0 - C1 stores 0 (0x9a0f68)
  uint8_t mPada8[0x8];   // 0xa8 - unproven
  uint8_t mPadb0[0x20];  // 0xb0 - subobject initialized by C1 0x92a1e0
                         //   (0x9a0f6c-0x9a0f70); layout unverified
  uint64_t md0;          // 0xd0 - C1 stores 0 (0x9a0f74)
  uint8_t mPadd8[0x8];   // 0xd8 - tail padding to 0xe0
};
}  // namespace nn::pia::transport
