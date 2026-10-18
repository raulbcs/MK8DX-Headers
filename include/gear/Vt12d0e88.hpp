#pragma once

#include <cstdint>

namespace gear {
// Vt12d0e88 — PLACEHOLDER name (identity not proven); gear::Actor-family
// member (base ctor 0x7b976c, same base as gear::Vt12d1118). vptr 0x12d0e88
// (GOT cell 0x1311120 holds vt-0x10, row header zeros). Owns a 0x38-byte
// heap subobject at +0x68, deleted by D2/D0.
// extent 0x70 - details: doc/gear/Vt12d0e88.md
class Vt12d0e88 {
 public:
  void* vtable;           // 0x00 — 0x12d0e88 (cell 0x1311120 + 0x10)
  uint8_t mBase08[0x30];  // 0x08 — gear::Actor-family base region (0x7b976c)
  void* mPtr38;           // 0x38 — C1 zeroes (0x882dc4)
  uint64_t mBlock40;      // 0x40 — C1 zeroes (0x882dd0/0x882dd4, +0x40..+0x48)
  void* mPtr48;           // 0x48 — C1 zeroes
  uint64_t mBlock50;      // 0x50 — C1 zeroes (0x882de0/0x882de8, +0x50..+0x58)
  uint8_t mPad58[0x10];   // 0x58 — unproven gap (mPad58: covered by 0x882de8 stur)
  void* mSub68;           // 0x68 — owned 0x38-byte subobject (operator new 0x38
                          //   at 0x882df0); D2/D0 delete it (0x882e70/0x882eb0)
};
}  // namespace gear
