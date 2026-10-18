#pragma once

#include <cstdint>

namespace nn::pia::session {
// nn::pia::session::SyncClockProtocol — RTTI-named (typeinfo 0x12de8d0, name
// "N2nn3pia7session17SyncClockProtocolE"). 11 slots; abstract protocol base
// C1 0x9a79c8 runs first. GOT cell 0x1313a28 holds vptr-0x10 (vptr 0x12de878).
// extent 0x80 - details: doc/_nn/pia/session/SyncClockProtocol.md
class SyncClockProtocol {
 public:
  void* mVtable;         // 0x00 - vptr 0x12de878 (cell 0x1313a28 + 0x10);
                         //   base C1 0x9a79c8 installs the base vptr first
  uint8_t mPad08[0x20];  // 0x08 - abstract protocol base fields
  uint8_t mPad28[0x10];  // 0x28 - subobject initialized by C1 0x99eaac
                         //   (0x99eb54); layout unverified
  uint32_t m38;          // 0x38 - C1 stores 0xfd (253, 0x99eb58-0x99eb60)
  uint32_t m3c;          // 0x3c - C1 stores 0x7d0 (2000, 0x99eb5c-0x99eb60)
  uint64_t m40;          // 0x40 - C1 stores 0 (0x99eb64)
  uint16_t m48;          // 0x48 - C1 stores 0 (0x99eb68 strh)
  uint8_t mPad4a[0x2];   // 0x4a - unproven
  uint32_t m4c;          // 0x4c - C1 stur xzr (0x99eb6c, 8 bytes at
                         //   +0x4c)
  uint32_t m50;          // 0x50 - covered by the same stur xzr
  uint8_t mPad54[0x1c];  // 0x54 - tail padding to 0x70
  uint8_t mPad70[0x10];  // 0x70 - tail padding to 0x80
};
}  // namespace nn::pia::session
