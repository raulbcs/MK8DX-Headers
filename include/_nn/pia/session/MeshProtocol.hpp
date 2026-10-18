#pragma once

#include <cstdint>

namespace nn::pia::session {
// nn::pia::session::MeshProtocol — RTTI-named (typeinfo 0x12de110, name
// "N2nn3pia7session12MeshProtocolE"). 11 slots; abstract protocol base C1
// 0x9a79c8 runs first. GOT cell 0x13138c8 holds vptr-0x10 (vptr 0x12de0b8).
// extent 0xa0 - details: doc/_nn/pia/session/MeshProtocol.md
class MeshProtocol {
 public:
  void* mVtable;         // 0x00 - vptr 0x12de0b8 (cell 0x13138c8 + 0x10);
                         //   base C1 0x9a79c8 installs the base vptr first
  uint8_t mPad08[0x20];  // 0x08 - abstract protocol base fields (base C1
                         //   0x9a79c8 zeroes +0x08..+0x1a)
  uint64_t m28;          // 0x28 - C1 stp xzr (0x98b8a8)
  uint64_t m30;          // 0x30 - C1 stp xzr (0x98b8a8)
  uint64_t m38;          // 0x38 - C1 stp xzr (0x98b8c4)
  uint64_t m40;          // 0x40 - C1 stp xzr
  uint32_t m48;          // 0x48 - C1 stores 0x2710 (10000, 0x98b8dc)
  uint32_t m4c;          // 0x4c - C1 stores 0x1388 (5000, 0x98b8dc)
  uint64_t m50;          // 0x50 - C1 stores 0 (0x98b8a4)
  uint16_t m58;          // 0x58 - C1 stores 0 (0x98b8b4 stp covers +0x58)
  uint16_t m5a;          // 0x5a - C1 stores 0 (0x98b8c0 strh)
  uint8_t mPad5c[0x4];   // 0x5c - unproven
  uint64_t m60;          // 0x60 - C1 stp xzr (0x98b8b4)
  uint64_t m68;          // 0x68 - C1 stp xzr
  uint64_t m70;          // 0x70 - C1 stores 0 (0x98b8cc)
  uint32_t m78;          // 0x78 - C1 stores 0 (0x98b8e0)
  uint8_t mPad7c[0x4];   // 0x7c - unproven
  uint64_t m80;          // 0x80 - C1 stores 0 (0x98b8d0)
  uint8_t m88;           // 0x88 - C1 stores 0 (0x98b8d4)
  uint8_t mPad89[0x1];   // 0x89 - unproven
  uint16_t m8a;          // 0x8a - C1 stores 0 (0x98b8d8)
  uint8_t mPad8c[0x4];   // 0x8c - unproven
  uint64_t m90;          // 0x90 - C1 stores 0 (0x98b8e8)
  uint8_t m98;           // 0x98 - C1 stores 0 (0x98b8ec)
  uint8_t mPad99[0x7];   // 0x99 - tail padding to 0xa0
};
}  // namespace nn::pia::session
