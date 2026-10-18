#pragma once

#include <cstdint>

namespace nn::pia::session {
// nn::pia::session::SessionProtocol — RTTI-named (typeinfo 0x12de740, name
// "N2nn3pia7session15SessionProtocolE"). 11 slots; abstract protocol base C1
// 0x9a79c8 runs first. GOT cell 0x13139f0 holds vptr-0x10 (vptr 0x12de6e8).
// extent 0x150 - details: doc/_nn/pia/session/SessionProtocol.md
class SessionProtocol {
 public:
  void* mVtable;         // 0x00 - vptr 0x12de6e8 (cell 0x13139f0 + 0x10);
                         //   base C1 0x9a79c8 installs the base vptr first
  uint8_t mPad08[0x20];  // 0x08 - abstract protocol base fields
  uint32_t m28;          // 0x28 - C1 stores 0xfd (253, 0x99b554-0x99b558)
  uint8_t mPad2c[0x4];   // 0x2c - unproven
  uint64_t m30;          // 0x30 - C1 stores 0 (0x99b55c)
  uint16_t m38;          // 0x38 - C1 stores 0 (0x99b56c strh)
  uint8_t mPad3a[0x6];   // 0x3a - unproven
  uint64_t m40;          // 0x40 - C1 stores 0 (0x99b55c)
  uint16_t m48;          // 0x48 - C1 stores 0 (0x99b560 strh)
  uint8_t mPad4a[0x106];  // 0x4a - region allocated (0x150) but not touched
                          //   by C1; used by protocol logic (unverified)
};
}  // namespace nn::pia::session
