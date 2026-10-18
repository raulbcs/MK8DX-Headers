#pragma once

#include <cstdint>

namespace nn::pia::transport {
// nn::pia::transport::ReliableBroadcastProtocol — RTTI-named (typeinfo
// 0x12df1c0, name "N2nn3pia9transport25ReliableBroadcastProtocolE"). 11 slots;
// abstract protocol base C1 0x9a79c8 runs first. GOT cell 0x1313bf0 holds
// vptr-0x10 (vptr 0x12df168).
// extent 0xb0 - details: doc/_nn/pia/transport/ReliableBroadcastProtocol.md
class ReliableBroadcastProtocol {
 public:
  void* mVtable;         // 0x00 - vptr 0x12df168 (cell 0x1313bf0 + 0x10);
                         //   base C1 0x9a79c8 installs the base vptr first
  uint8_t mPad08[0x20];  // 0x08 - abstract protocol base fields
  uint32_t m28;          // 0x28 - C1 stores 0 (0x9ac79c stp covers +0x28)
  uint32_t m2c;          // 0x2c - C1 stores 0x10000 (65536, 0x9ac798-0x9ac79c)
  uint32_t m30;          // 0x30 - C1 stores 0xfd (253, 0x9ac7a0-0x9ac7a4)
  uint8_t mPad34[0xc];   // 0x34 - unproven
  uint16_t m40;          // 0x40 - C1 stores 0x1a (26, 0x9ac7a8-0x9ac7ac)
  uint8_t mPad42[0xe];   // 0x42 - unproven
  uint64_t m50;          // 0x50 - C1 stores 0 (0x9ac7b8)
  uint8_t mPad58[0x18];  // 0x58 - unproven
  uint64_t m70;          // 0x70 - C1 stores 0 (0x9ac7bc)
  uint16_t m78;          // 0x78 - C1 stores 0 (0x9ac7c0 strh)
  uint8_t mPad7a[0x2];   // 0x7a - unproven
  uint32_t m7c;          // 0x7c - C1 stores 0 (0x9ac7d0 stp wzr,wzr)
  uint32_t m80;          // 0x80 - C1 stores 0 (0x9ac7d0 stp wzr,wzr)
  uint8_t mPad84[0xc];   // 0x84 - unproven
  uint32_t m90;          // 0x90 - C1 stores 0 (0x9ac7d4)
  uint8_t mPad94[0xc];   // 0x94 - unproven
  void* ma0;             // 0xa0 - heap pointer, zeroed by C1 (0x9ac7c8 stp
                         //   xzr covers +0xa0/+0xa8); freed in D1 0x9ac7e4
                         //   via 0x568bb0/0x568b64
  void* ma8;             // 0xa8 - zeroed by C1 (0x9ac7c8)
};
}  // namespace nn::pia::transport
