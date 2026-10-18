#pragma once

#include <cstdint>

namespace nn::pia::transport {
// PacketHandler — RTTI-named (typeinfo 0x12deeb0, name
// "N2nn3pia9transport13PacketHandlerE"; base typeinfo
// nn::pia::transport::ProcessConnectionRequestJob). 19 slots. GOT cell
// 0x1313b48 holds vptr-0x10. extent 0x4e8 (unverified; proven lower bound
// 0x4e8) - details: doc/_nn/pia/transport/PacketHandler.md
class PacketHandler {
 public:
  void* mVtable;            // 0x00 - 0x12dee18 (cell 0x1313b48 + 0x10)
  uint8_t mPad8[0x8];       // 0x08 - unproven gap
  void* m10;                // 0x10 - zeroed by C1
  uint8_t mSub18[0x400];    // 0x18 - subobject initialized by 0x71009a89e0
                            //   (size unknown, unproven gap)
  uint8_t mSub418[0x60];    // 0x418 - subobject initialized by 0x71009a859c
  uint8_t mPad478[0x8];     // 0x478 - zeroed by C1
  uint8_t mPad480[0x10];    // 0x480 - unproven gap
  void* m490;               // 0x490 - C1 stores this (self-pointer)
  void* mZero498;           // 0x498 - zeroed by C1
  void* mZero4a0;           // 0x4a0 - zeroed by C1
  void* mZero4a8;           // 0x4a8 - zeroed by C1
  void* mZero4b0;           // 0x4b0 - zeroed by C1
  uint8_t mSub4b8[0x18];    // 0x4b8 - subobject initialized by 0x7100929fc4
  uint8_t mPad4d0[0x18];    // 0x4d0 - zeroed by C1 (0x4d0/0x4d8/0x4e0)
};
}  // namespace nn::pia::transport
