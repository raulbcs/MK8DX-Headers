#pragma once

#include <cstdint>

// Vt12e5f80 — PLACEHOLDER name; vptr 0x12e5f80 (GOT cell 0x1314a40, cell = vptr-0x10), 24 slots.
// Only class in this batch with a real typeinfo slot (0x12e6300); offtot 0.
// extent 0x88 - details: doc/object/Vt12e5f80.md

namespace object {
class Vt12e5f80 {
 public:
  void* mVtable;          // 0x00 — 0x12e5f80
  uint8_t mPad8[0x40];    // 0x08 — unproven padding
  uint16_t m48;           // 0x48 — zeroed by C1
  uint8_t mPad4a[0x6];    // 0x4a — unproven padding
  uint8_t mPad50[0x10];   // 0x50 — zeroed by C1 (0x50..0x60)
  uint32_t m60;           // 0x60 — C1 arg (w1)
  uint8_t mPad64[0xc];    // 0x64 — zeroed by C1 (0x64..0x70)
  uint8_t m70;            // 0x70 — zeroed by C1
  uint8_t mPad71[0x7];    // 0x71 — unproven padding
  void* m78;              // 0x78 — zeroed by C1
  uint32_t m80;           // 0x80 — zeroed by C1
  uint8_t mPad84[0x4];    // 0x84 — unproven padding
};
}  // namespace object
