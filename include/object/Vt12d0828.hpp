#pragma once

#include <cstdint>

// Vt12d0828 — PLACEHOLDER name; gear::Actor-derived (base C1 0x7b976c), 14 slots, no RTTI.
// C1 0x874a90; slot 6 FUN_7100874bb0 is a state machine over [+0x40] driving a sub-object at +0x200.
// extent 0x2B0 (nothrow new[] 0x2B0 at factory 0x879108) -
// details: doc/object/Vt12d0828.md

namespace object {
class Vt12d0828 {
 public:
  void* mVtable;             // 0x00 — 0x12d0828 (via GOT cell 0x1311058, cell holds vptr-0x10)
  uint8_t mPad8[0x30];       // 0x08 — unproven padding (gear::Actor base C1 0x7b976c zeroes +0x10..+0x38)
  uint64_t m38;              // 0x38 — ctor: 0
  uint32_t mState40;         // 0x40 — state, ctor 0; driven by FUN_7100874bb0 (0..3)
  uint32_t m44;              // 0x44 — ctor: 2
  int32_t m48;               // 0x48 — ctor: -1
  int32_t m4c;               // 0x4C — ctor: -1
  uint8_t m50;               // 0x50 — ctor: 0
  uint8_t mPad51[0x7];       // 0x51 — unproven padding
  void* m58;                 // 0x58 — ctor: this+0x6C (self-referential node link)
  uint64_t m60;              // 0x60 — ctor: 5
  uint32_t m68;              // 0x68 — ctor: 0
  uint8_t mPad6c[0x4];       // 0x6C — unproven padding (node body)
  uint8_t mRecords70[0x60];  // 0x70 — 5 records, stride 0x14: {0xC, 0xC, -1, 0} pattern (first) / {0, 0xC, -1, 0} (rest)
  uint8_t mPadd0[0x130];     // 0xD0 — ctor zeros +0xD0, inits +0xDC/+0xE0 via 0x87c0d8, [+0x148]=0, +0x140 pair = -1; rest unproven padding
  uint8_t mPad200[0xB0];     // 0x200 — sub-object ptr read by FUN_7100874bb0 (virtuals slot+0x70/0x78/0x88); unverified layout
};
}  // namespace object
