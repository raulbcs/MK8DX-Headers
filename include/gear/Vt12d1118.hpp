#pragma once

#include <cstdint>

namespace gear {
// Vt12d1118 — PLACEHOLDER name; engine-family member subobject (base ctor
// 0x7b976c). vptr 0x12d1118 (GOT cell 0x13111b0 holds vt-0x10); 18 slots,
// gear::Actor-derived. Constructed in place (sole site 0x3a8c6c); extent is a
// lower bound from the deepest ctor store.
// extent 0x1d8 (unverified lower bound) - details: doc/gear/Vt12d1118.md
class Vt12d1118 {
 public:
  void* vtable;  // 0x00 — 0x12d1118 (cell 0x13111b0 + 0x10)
  uint8_t mBase08[0x30];  // 0x08 - engine-family base region (0x7b976c); unproven
  uint8_t mBuf38[0x158];  // 0x38 — part of a 0x198-byte block the ctor memsets
                          //   to 0 (0x888e64-0x888e74); sub-range +0xb8..+0x118
                          //   re-memset (0x888e7c-0x888e94)
  uint32_t mF190;         // 0x190 — ctor sets 0x5910 (22800) after the memset
  uint8_t mPad194[0x3c];  // 0x194 — ctor memsets 0 (tail of the 0x198 block
                          //   ending at +0x1d0); unproven beyond that
  uint8_t mByte1d0;       // 0x1d0 — ctor sets 1
  uint8_t mByte1d1;       // 0x1d1 — ctor zeroes
  uint8_t mPad1d2[2];     // 0x1d2 — unproven gap
  uint32_t mF1d4;         // 0x1d4 — ctor zeroes
};
}  // namespace gear
