#pragma once

#include <cstdint>

namespace nn::pia::local {
// RTTI-confirmed (compact ti record 0x12e10d0, name "N2nn3pia5local19LdnConnectionStatusE");
// vptr 0x12e1018 via GOT cell 0x1313d48 (vt-0x10); 23 slots; lazy singletons stored at
// parent+0x1b8/0x1c0/0x1c8. extent 0x4a0 - details: doc/_nn/pia/local/LdnConnectionStatus.md
class LdnConnectionStatus {
 public:
  void* vtable;           // 0x00 — 0x12e1018
  uint16_t mField08;      // 0x08 — u16, cleared by reset slot2; getter slot19
  uint8_t mPad0A[0xE];    // 0x0A — unproven (head of the 0x18..0x498 entry array region)
  uint8_t mEntries18[0x480];  // 0x18 — 18 x 0x40-byte entries (slot4: byte
                          // [this+idx*0x40+0x8b]; slot2 memsets this+0x18 len 0x480)
  int32_t mField498;      // 0x498 — init -1 (slot2)
  uint8_t mPad49C[0x4];   // 0x49C — unproven padding
};
}  // namespace nn::pia::local
