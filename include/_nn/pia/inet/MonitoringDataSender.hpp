#pragma once

#include <cstdint>

// nn::pia::inet::MonitoringDataSender — RTTI-named (embedded typeinfo at
// 0x12daa20). Size 0x150 proven: alloc wrapper 0x932300 (new 0x150) before
// C1. extent 0x150 - details: doc/_nn/pia/inet/MonitoringDataSender.md

namespace nn::pia::inet {
class MonitoringDataSender {
 public:
  void* mVtable;          // 0x00 — vptr 0x12da9b8 (GOT cell 0x1312b70
                          //   holds vptr-0x10; C1 adds 0x10, 0x93a98c)
  void* mBuffer08;        // 0x08 — new(0xb90) zeroed 5-byte-stride array
  void* mBuffer10;        // 0x10 — new(0xbd0) zeroed 7-byte-stride array
  void* mBuffer18;        // 0x18 — new(0x2730) zeroed 6-byte-stride array
  uint32_t mField20;      // 0x20 — 3 << 32 pattern (orr x8, #0x300000000;
                          //        actually +0x20 = 0x300000000)
  uint32_t mField24;      // 0x24 — upper half of the u64 above
  uint8_t mSub28[0x80];   // 0x28 — embedded member, C1 0x964764
  uint8_t mSubA8[0x90];   // 0xa8 — embedded member, C1 0x93b340
  uint8_t mField138;      // 0x138 — zeroed (C1 0x93a9ac)
  uint8_t mPad139[0x3];   // 0x139 — gap
  uint8_t mSub13c[0x14];  // 0x13c — embedded member, C1 0x929fd4
};
}  // namespace nn::pia::inet
