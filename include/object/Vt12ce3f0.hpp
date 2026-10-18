#pragma once

#include <cstdint>

// Vt12ce3f0 — PLACEHOLDER name; 44-slot interface object of the 0x3835e8
// factory family. vptr 0x12ce3f0 at +0x00.
// extent 0xf60 - details: doc/object/Vt12ce3f0.md

namespace object {
class Vt12ce3f0 {
 public:
  void* vtable;         // 0x00 — 0x12ce3f0 (ctor 0x7100853cd8)
  char mPad8[0x50];     // 0x08 — unproven
  uint8_t mField58;     // 0x58 — bitfield; ctor clears bits 0-1 (0x7100853c98)
  char mPad59[0x7];     // 0x59 — unproven
  char mSub60[0x125];   // 0x60 — ctor memset 0 (0x7100853cb0)
  char mPad185[0x23];   // 0x185 — unproven
  uint16_t mField1a8;   // 0x1a8 — ctor zeroes (0x7100853cc8)
  char mPad1aa[0x6];    // 0x1aa — unproven
  uint32_t mField1b0;   // 0x1b0 — ctor zeroes (0x7100853ccc)
  char mPad1b4[0xc];    // 0x1b4 — unproven
  void* mHead1c0[2];    // 0x1c0 — both = this+0x1c0, empty list (0x7100853cc0)
  char mPad1d0[0x1c];   // 0x1d0 — unproven
  char mTail1ec[0x34];  // 0x1ec — tail of ctor-initialized block (0x7100853cdc)
  char mPad220[0xd40];  // 0x220 — unproven (allocated 0xf60; ctor touches < 0x220)
};
}  // namespace object
