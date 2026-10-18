#pragma once

#include <cstdint>

namespace object {
// Vt12d5e98 — PLACEHOLDER name (identity not proven); abstract game base,
// shared slot0/slot1/slot4/slot5/slot6/slot10/slot15 with derived Vt12c8470.
// vptr 0x12d5e98 (GOT cell 0x1310060 holds vt-0x10, row header zeros); MI:
// secondary group vptr vt+0x90 installed at [this+0x138].
// extent 0x350 (unverified lower bound) - details: doc/object/Vt12d5e98.md
class Vt12d5e98 {
 public:
  void* vtable;            // 0x00 — 0x12d5e98 (cell 0x1310060 + 0x10)
  uint8_t mPad08[0x130];   // 0x08 — unproven gap (mPad08: no ctor stores found)
  void* vtable138;         // 0x138 — secondary group 0x12d5e98+0x90 (offtop -0x138)
  uint8_t mPad140[0x208];  // 0x140 — unproven gap (mPad140: no ctor stores found)
  uint32_t mF348;          // 0x348 — D2 zeroes (0x8df160)
  uint8_t mByte34c;        // 0x34c — D2 zeroes (0x8df164)
  uint8_t mPad34d[3];      // 0x34d — unproven gap to 0x350
};
}  // namespace object
