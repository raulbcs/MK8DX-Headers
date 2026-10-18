#pragma once

#include <cstdint>

// Vt12c9db0 — PLACEHOLDER name; vptr 0x12c9db0 via GOT cell 0x1308130 (holds
// vt-0x10, no typeinfo); gear::Actor-derived (slots +0x58..+0x70 are the Actor
// interface), 15-slot primary table + MI groups from +0x88.
// extent 0x128 (new 0x128 at 0x3dfb6c / 0x8bd150) - details: doc/object/Vt12c9db0.md
namespace object {
class Vt12c9db0 {
 public:
  void* mVtable;         // 0x00 — 0x12c9db0 (cell 0x1308130 + 0x10)
  uint8_t mPad8[0x10];   // 0x08 — unproven padding
  void* mMember18;       // 0x18 — self back-ptr set by factory
  void* mRef20;          // 0x20 — refcounted member (addref 0x60b630 / release 0x60b618)
  void* mOwner28;        // 0x28 — owner (factory arg x19)
  void* mField30;        // 0x30 — copied from owner+0x30
  int64_t mId38;         // 0x38 — -1 on init; +0x40 = 0
  uint64_t mPad40;       // 0x40 — zeroed
  int32_t mId48[2];      // 0x48 — {-1, -1}
  int64_t mId50;         // 0x50 — {-1, 0}
  uint64_t mPad58;       // 0x58 — zeroed
  int32_t mId60[2];      // 0x60 — {-1, -1}
  int64_t mId68;         // 0x68 — {-1, 0}
  uint64_t mPad70;       // 0x70 — zeroed
  int32_t mId78[2];      // 0x78 — {-1, -1}
  int64_t mId80;         // 0x80 — {-1, 0}
  uint64_t mPad88;       // 0x88 — zeroed
  int32_t mId90[2];      // 0x90 — {-1, -1}
  int64_t mId98;         // 0x98 — {-1, 0}
  uint64_t mPadA0;       // 0xa0 — zeroed
  int32_t mIdA8[2];      // 0xa8 — {-1, -1}
  uint64_t mZeroB0;      // 0xb0 — zeroed (unproven)
  int64_t mIdB8;         // 0xb8 — -1 (unverified)
  uint64_t mZeroC0[2];   // 0xc0 — zeroed pair
  uint64_t mValD0;       // 0xd0 — 2
  uint32_t mZeroD8;      // 0xd8 — zeroed
  uint8_t mGapDc[0x44];  // 0xdc — unproven gap (embedded member ctor 0x6286a4 at +0xe0)
  uint8_t mPad120[2];    // 0x120 — u16 zeroed
  uint8_t mZero122;      // 0x122 — zeroed
  uint8_t mGap123[5];    // 0x123 — unproven gap
};
}  // namespace object
