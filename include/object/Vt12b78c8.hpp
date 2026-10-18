#pragma once

#include <cstdint>

// Vt12b78c8 — PLACEHOLDER name; vptr 0x12b78c8, 8 slots, no typeinfo (game-side).
// Large aggregate member with 9 in-place subobjects and a counter table.
// extent 0x1588 - details: doc/object/Vt12b78c8.md

namespace object {
class Vt12b78c8 {
 public:
  void* mVtable;             // 0x00 — 0x12b78c8 (via GOT cell 0x130e250, holds vt-0x10)
  uint8_t mBase8[0x240];     // 0x08 — padding, base Vt12b6f58 region (base C2 0x6c6128 runs first)
  void* mZero248;            // 0x248 — cleared by C1 (unverified use)
  uint32_t mF_250;           // 0x250 — 13
  uint32_t mPad254;          // 0x254 — padding, unproven
  void* mF_258;              // 0x258 — [[0x12fce60]] + 0x58
  uint8_t mSub260[0x1c8];    // 0x260 — subobject initialized by 0x645410, internal layout unknown
  uint8_t mSub428[0x190];    // 0x428 — subobject initialized by 0x643fa0, internal layout unknown
  uint8_t mSub5b8[0x1c8];    // 0x5b8 — subobject initialized by 0x645410, internal layout unknown
  uint8_t mSub780[0x188];    // 0x780 — subobject initialized by 0x643fa0, internal layout unknown
  uint8_t mSub908[0x180];    // 0x908 — subobject initialized by 0x643fa0, internal layout unknown
  uint8_t mSubA88[0x190];    // 0xa88 — subobject initialized by 0x643fa0, internal layout unknown
  uint8_t mSubC18[0x188];    // 0xc18 — subobject initialized by 0x643fa0, internal layout unknown
  uint8_t mSubDA0[0x1f8];    // 0xda0 — subobject initialized by 0x643fa0; internal zero words at +0xf48/+0xf80 etc.
  uint8_t mSubF98[0x1b0];    // 0xf98 — memset 0 (0x1b0 bytes); also gets later writes, see doc
  uint32_t mF_1148;          // 0x1148 — global u32 from 0x13585d0
  uint32_t mPad114c;         // 0x114c — padding, unproven
  uint64_t mF_1150;          // 0x1150 — 0
  uint64_t mPad1158;         // 0x1158 — zeroed, unproven
  void* mSelf_1160;          // 0x1160 — self pointer (this + value(0x13585d0))
  void* mSelf_1168;          // 0x1168 — same
  uint64_t mF_1170;          // 0x1170 — 0; upper word +0x1178 = 0x32 (written via +0x1174 qword store)
  uint32_t mF_1178;          // 0x1178 — 0x32
  uint32_t mF_117c;          // 0x117c — 1
  uint64_t mTick_1180;       // 0x1180 — nn::os::GetSystemTick()
  uint32_t mF_1188;          // 0x1188 — 0
  uint32_t mPad118c;         // 0x118c — padding, unproven
  uint64_t mF_1190;          // 0x1190 — 0
  uint8_t mSub1198[0x238];   // 0x1198 — embedded polymorphic subobject (0x654990; secondary vptr cell 0x130d830)
  void* mVtable13d0;         // 0x13d0 — secondary vptr (cell 0x130e258 + 0x10)
  void* mSelf_13d8;          // 0x13d8 — this
  uint8_t mTail13e0[0x1a8];  // 0x13e0 — memset 0 tail (ends exactly at 0x1588)
};
}  // namespace object
