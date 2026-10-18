#pragma once

#include <cstdint>

// Vt12b6f08 — PLACEHOLDER name; vptr 0x12b6f08, 8 slots, no typeinfo (game-side).
// Owns an array of 0xb80-byte records (freed by D1) plus two heap children.
// extent 0xd30 - details: doc/object/Vt12b6f08.md

namespace object {
class Vt12b6f08 {
 public:
  void* mVtable;             // 0x00 — 0x12b6f08 (via GOT cell 0x130e210, holds vt-0x10)
  uint8_t mBase8[0x240];     // 0x08 — padding, base Vt12b6f58 region (base C2 0x6c6128 runs first)
  void* mZero248;            // 0x248 — cleared by C1 (unverified use)
  uint8_t mSub250[0x258];    // 0x250 — subobject initialized by 0xafe670, internal layout unknown
  uint8_t mSub4a8[0x824];    // 0x4a8 — subobject initialized by 0x651ae4, internal layout unknown
  uint32_t mF_ccc;           // 0xccc — 1
  uint32_t mF_cd0;           // 0xcd0 — 0x3E19999A (float ~0.15)
  float mF_cd4;              // 0xcd4 — 3.0f
  float mF_cd8;              // 0xcd8 — 1.0f
  float mF_cdc;              // 0xcdc — 0x3D23D70A (float ~0.04)
  uint8_t mF_ce0;            // 0xce0 — 1
  uint8_t mPadCe1[0x3];      // 0xce1 — padding, remainder of the byte+word group
  float mF_ce4;              // 0xce4 — 8.0f
  uint64_t mF_ce8;           // 0xce8 — 0x080000003F800000 (split unverified)
  void* mChild_cf0;          // 0xcf0 — heap child ptr, virtually destroyed by D1
  void* mChild_cf8;          // 0xcf8 — heap child ptr, virtually destroyed by D1
  uint64_t mPadD00;          // 0xd00 — padding, unproven
  uint32_t mCount_d08;       // 0xd08 — record count (array)
  uint32_t mPadD0c;          // 0xd0c — padding, unproven
  void* mRecords_d10;        // 0xd10 — array base (elements 0xb80 bytes)
  uint16_t mF_d18;           // 0xd18 — 0x7e
  uint8_t mF_d1a;            // 0xd1a — 0xc
  uint8_t mPadD1b[0x5];      // 0xd1b — padding, rest of the word
  uint32_t mCount_d20;       // 0xd20 — second count, iterated by D1
  uint32_t mPadD24;          // 0xd24 — padding, unproven
  uint64_t mZero_d28;        // 0xd28 — zeroed by C1
};
}  // namespace object
