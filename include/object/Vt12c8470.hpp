#pragma once

#include <cstdint>

namespace object {
// Vt12c8470 — PLACEHOLDER name (identity not proven); game class derived from
// Vt12d5e98 (C2 0x7dded0 calls base dtor-path 0x8df144 then re-installs both
// vptrs). Base subobject of object::Vt12c8520 at +0x3d8. vptr 0x12c8470 (GOT
// cell 0x13100e8 holds vt-0x10); secondary group vptr vt+0x90 at [this+0x138].
// extent 0x360 (unverified, see doc) - details: doc/object/Vt12c8470.md
class Vt12c8470 {
 public:
  void* vtable;            // 0x00 — 0x12c8470 (cell 0x13100e8 + 0x10)
  uint8_t mPad08[0x130];   // 0x08 — unproven gap (mPad08: no ctor stores found)
  void* vtable138;         // 0x138 — secondary group 0x12c8470+0x90 (offtop -0x138)
  uint8_t mPad140[0x208];  // 0x140 — unproven gap (mPad140: no ctor stores found)
  uint32_t mF348;          // 0x348 — C2 zeroes
  uint8_t mByte34c;        // 0x34c — C2 zeroes
  uint8_t mPad34d[0xb];    // 0x34d — unproven gap to 0x358
  uint32_t mF358;          // 0x358 — C2 zeroes (0x7ddeec)
  uint16_t mW35c;          // 0x35c — C2 stores 0xf1e (0x7ddfc8-0x7ddf04)
  uint8_t mPad35e[2];      // 0x35e — unproven tail to 0x360
};
}  // namespace object
