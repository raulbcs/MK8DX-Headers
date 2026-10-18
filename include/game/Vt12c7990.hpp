#pragma once

#include <cstdint>

// Vt12c7990 — PLACEHOLDER name; vptr 0x12c7990, 8 slots, root class.
// C1 FUN_71007c690c registers `this` into a global registry and
// snapshots a rodata defaults struct; new(0x370) in FUN_71001e08b4.
// extent 0x370 - details: doc/game/Vt12c7990.md
namespace game {
class Vt12c7990 {
 public:
  void* mVtable;        // 0x00 - vptr 0x12c7990 (GOT cell 0x130ff78 holds
                        //   vptr-0x10; C1 adds 0x10)
  uint8_t mPad08[0x18]; // 0x08 - unproven gap
  void* mRegistry20;    // 0x20 - set at the end of C1: [x8+0x1f8] of the
                        //   object from FUN_71007f7ac0; this is appended
                        //   to [registry+0x13a8][count] (cap +0x13a4)
  uint8_t mPad28[0x4];  // 0x28 - unproven gap (zeroed by C1)
  float mF2c;           // 0x2c - 1.0f by C1; re-init slot 2 rewrites the
                        //   0x28..0x5c block identically
  uint8_t mPad30[0x4]; // 0x30 - unproven gap
  uint64_t mZero34;     // 0x34 - zeroed by C1
  float mF3c;           // 0x3c - 1.0f
  uint8_t mPad40[0x4]; // 0x40 - unproven gap
  uint64_t mZero44;     // 0x44 - zeroed by C1
  float mF4c;           // 0x4c - 1.0f
  uint8_t mPad50[0x4]; // 0x50 - unproven gap
  uint64_t mZero54;     // 0x54 - zeroed by C1
  float mF5c;           // 0x5c - 1.0f
  uint8_t mPad60[0x18]; // 0x60 - unproven gap
  uint32_t mU78;        // 0x78 - result of FUN_71007c6b40 in re-init
                        //   (slot 2)
  uint8_t mPad7c[4];    // 0x7c - unproven gap
  uint8_t mMemset80[0x58];   // 0x80 - memset-only region (C1 memsets
                        //   0x2d0 from here, then overwrites the named
                        //   fields below)
  uint64_t mSnapD8;     // 0xd8 - *(cell 0x12fb148) = rodata 0xf57b7c:
                        //   {u64@+0, u32@+8} copied to six stride-0xc
                        //   pairs at 0xd8/0xe4/0x1c8/0x1d4/0x2b8/0x2c4
  uint32_t mSnapE0;    // 0xe0 - snapshot pair 1
  uint64_t mSnapE4;    // 0xe4 - snapshot pair 1
  uint32_t mSnapEc;    // 0xec - snapshot pair 1
  uint8_t mPadF0[0x84]; // 0xf0 - unproven gap
  void* mPtrs174[6];    // 0x174 - zeroed by C1 (next member at 0x1a4)
  uint8_t mPad1a4[0x24]; // 0x1a4 - unproven gap
  uint64_t mSnap1c8;    // 0x1c8 - snapshot pair 2
  uint32_t mSnap1d0;   // 0x1d0 - snapshot pair 2
  uint64_t mSnap1d4;   // 0x1d4 - snapshot pair 2
  uint32_t mSnap1dc;   // 0x1dc - snapshot pair 2
  uint8_t mPad1e0[0x84]; // 0x1e0 - unproven gap
  void* mPtrs264[6];    // 0x264 - zeroed by C1 (next member at 0x294)
  uint8_t mPad294[0x24]; // 0x294 - unproven gap
  uint64_t mSnap2b8;    // 0x2b8 - snapshot pair 3
  uint32_t mSnap2c0;   // 0x2c0 - snapshot pair 3
  uint64_t mSnap2c4;   // 0x2c4 - snapshot pair 3
  uint8_t mPad2cc[0x84]; // 0x2cc - unproven gap
  uint32_t mSnap2cc;
  uint64_t mZero350;    // 0x350 - zeroed by C1
  uint64_t mZero358;    // 0x358 - zeroed by C1
  uint64_t mZero360;    // 0x360 - zeroed by C1
  void* mOwner368;      // 0x368 - copied from the C1 x1 arg
};
}  // namespace game
