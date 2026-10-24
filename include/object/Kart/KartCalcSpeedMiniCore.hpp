#pragma once

#include <cstdint>
#include <gear/Actor/Actor.hpp>

// Kart speed calculation runtime, "mini core" variant. Vtable .data
// extent 0x300
namespace object::Kart {
class KartCalcSpeedMiniCore : public gear::Actor {
 public:
  uint8_t mPad8[0x30];    // 0x8 — sead::hostio::Node base members (see
  uint64_t mField38;      // 0x38 — ctor: [0x13063a0]+0x2a8 secondary vtable
  uint8_t mPad40[0x88];   // 0x40 — unproven gap; ctor passes this+0x90 as arg to
  void* mBufVecC8;        // 0xC8 — 12B copy target from [mDriverCtx150].vt+0x60
                          //  (0x34c918-0x34c930); history source (0x34cdc4)
  uint32_t mCtxVecD0[3];  // 0xD0 — vec3 = [mField138]+0x40/0x44/0x48 (reset
                          //  0x34c9c8-0x34c9d8)
  uint8_t mPadDC[2];      // 0xDC — unproven gap
  uint16_t mFlagsDE;      // 0xDE — flags: bit0 set on reset (0x34c934), bit2
                          //  (0x34c9e0); read+rewritten in calc (0x34cdd4)
  uint8_t mPadE0[0x48];   // 0xE0 - 0x127 — unproven gap
  uint64_t mField128;     // 0x128 — ctor: [0x13063a0]+0x340 secondary vtable
  uint8_t mPad130[8];     // 0x130 — unproven gap
  void* mField138;        // 0x138 — pointer: copied wholesale into the 0x300 clone
  void* mField140;        // 0x140 — pointer, same clone copy (0x34d1b0/0x34d1b8)
  uint8_t mPad148[8];     // 0x148 — unproven gap
  void* mDriverCtx150;    // 0x150 — per-frame driver/physics context object with
                          //  its own vtable: +0x20 (u16,u32), +0x30 (vec3*),
                          //  +0x48 ()→f32, +0x58 ()→vec3, +0x60 ()→vec3
                          //  (0x34c8c4-0x34c914, 0x34ca48, 0x34cb1c)
  uint8_t mPad158[0xa0];  // 0x158 — unproven gap
  void* mField1f8;        // 0x1F8 — ctor: 0x133c7b0 (static table 0x133c790,
  void* mField200;        // 0x200 — ctor: 0x133c798 (0x34d408)
  uint64_t mField208;     // 0x208 — ctor: [0x13063a0]+0x370 secondary vtable
  uint8_t mPad210[0x3c];  // 0x210 — unproven gap (no ctor write, no located access)
  float mOut24c;          // 0x24C — f32 read by the +0x120 post-calc and stored
                          //  into 0x2b4 (0x34d8c0, 0x34d920)
  uint8_t mPad250[0x10];  // 0x250 - 0x25F — unproven gap
  uint64_t mField260;     // 0x260 — ctor: [0x13063a8]+0x10 vtable (0x34d388)
  uint8_t mField268;      // 0x268 — ctor 2 (0x34d410); loop bound vs 3 at 0x34d468
  uint8_t mFlags269;      // 0x269 — sub-state flags: zeroed on reset
                          //  (0x34ca08-0x34ca1c), read by the +0x120 post-calc
                          //  (0x34d8a0)
  uint8_t mPad26a;        // 0x26a — ctor zero
  uint8_t mField26b;      // 0x26b
  uint32_t mZero26c;      // 0x26c — ctor zero
  void* mSelf270;         // 0x270 — ctor stores `this`
  uint64_t mField278;     // 0x278 — ctor: new[](0x20) array, zeroed 32B
  uint64_t mField280;     // 0x280 — ctor: new[](0x20) array, zeroed 32B
  uint64_t mField288;     // 0x288 — ctor: call result (new[](0x20) at 0x34d43c,
  uint8_t mEmitFlag290;   // 0x290 — "emit event" flag: zeroed on reset
                          //  (0x34ca10); passed as w1 to the final dispatcher
                          //  0x34e7e8 (0x34d0dc); echoed from 0x26b by the
                          //  +0x120 post-calc (0x34d8a0-0x34d92c)
  uint8_t mPad291[0x7];   // 0x291 — untouched by ctor; no located access
  uint64_t mField298;     // 0x298 — ctor: [0x12fb038]+0x10 (0x34d35c-0x34d390)
  uint64_t mZero2a0;      // 0x2a0 — ctor zero (0x34d378)
  uint8_t mPad2a8;        // 0x2a8 — ctor zero (0x34d37c)
  uint8_t mPad2a9[0x7];   // 0x2a9 — untouched by ctor; no located access
  uint32_t mField2b0;     // 0x2b0 — ctor constant 0x437a0000 = 250.0f (0x34d380)
  uint32_t mZero2b4;      // 0x2b4 — ctor zero (0x34d39c)
  uint32_t mZero2b8;      // 0x2b8 — ctor zero (0x34d3a0)
  uint32_t mZero2bc;      // 0x2bc — ctor zero (str 1<<32 at 0x34d3a4 covers
  uint32_t mOne2c0;       // 0x2c0 — ctor 1 (same store, 0x34d3a4)
  uint32_t mField2c4;     // 0x2c4
  uint8_t mField2c8;      // 0x2c8
  uint8_t mZero2c9;       // 0x2c9 — ctor zero (strh wzr at 0x34d3b0 covers
  uint8_t mZero2ca;       // 0x2ca — ctor zero (0x34d3ac); read by
  uint8_t mPad2cb;        // 0x2cb — untouched by ctor; no located access
  uint64_t mField2cc;     // 0x2cc — ctor copy of *(void**)0x12fb0148 (0x34d398-
  uint32_t mField2d4;     // 0x2d4
  uint64_t mField2d8;     // 0x2d8
  uint32_t mField2e0;     // 0x2e0
  uint64_t mField2e4;     // 0x2e4 — ctor copy of *(void**)0x12fb0148 (0x34d3e4-
  uint32_t mField2ec;     // 0x2ec
  uint64_t mField2f0;     // 0x2f0
  uint32_t mField2f8;     // 0x2f8
  uint8_t pad_2FC[0x4];   // 0x2FC — untouched by ctor 0x34d2d8 and by the derived

  // Core extent 0x300. The concrete tail (clone array + interfaces) belongs
  // to the KartCalcSpeedMini derived class — see KartCalcSpeedMini.hpp.
  // Vtable 0x710124d0e8 (ctor 0x34d2d8 via GOT 0x71013063a0); derived
  // KartCalcSpeedMini vtable 0x710124ccf8 overrides +0x80/+0x88/+0x90 with
  // notifying wrappers (0x34c6dc/0x34c86c/0x34ca34). Slot +0x88 = reset
  // FUN_710034c898, +0x90 = main frame calc FUN_710034cae0.
};
}  // namespace object::Kart
