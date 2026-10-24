#pragma once

#include "ObjPhysicsBody.hpp"

namespace object {
// Address-anchored name ("Vt98"). Rigid body whose head
// slots carry RigidVtableSwapInit_71000229f4 / RigidVt_0x18_7100022a2c
// (a vtable-swap-init body). Vtable .data 0x11ae6b0 (GOT cell
// 0x12fb3d8), ctor 0x7100020520 — calls the root ctor 0x116a4 directly.
// Size 0x450 (allocation 0x450 at 0x238a8, ctor call 0x238c8).
class ObjPhysicsBodyVt98 : public ObjPhysicsBody {
 public:
  uint8_t mPad328[0x4];   // 0x328 — unproven gap
  uint32_t mZero32c;      // 0x32c — ctor zero
  uint32_t mField330;     // 0x330 — ctor-written (u32: mField334 is written separately at +0x4)
  uint32_t mField334;     // 0x334
  uint32_t mField338;     // 0x338
  uint32_t mField33c;     // 0x33c
  uint32_t mField340;     // 0x340 — ctor-written (u32: mField344 is written separately at +0x4)
  uint32_t mField344;     // 0x344
  uint32_t mField348;     // 0x348
  uint32_t mField34c;     // 0x34c
  uint32_t mField350;     // 0x350
  uint32_t mField354;     // 0x354
  uint32_t mField358;     // 0x358
  uint32_t mField35c;     // 0x35c
  uint32_t mZero360;      // 0x360 — ctor zero (u32: mField364 is written separately at +0x4)
  uint32_t mField364;     // 0x364
  uint64_t mZero368;      // 0x368 — ctor zero
  uint32_t mZero370;      // 0x370 — ctor zero
  uint32_t mField374;     // 0x374
  uint32_t mField378;     // 0x378
  uint32_t mField37c;     // 0x37c
  uint32_t mField380;     // 0x380
  uint32_t mField384;     // 0x384
  uint32_t mField388;     // 0x388
  uint32_t mField38c;     // 0x38c
  uint32_t mField390;     // 0x390
  uint32_t mField394;     // 0x394
  uint32_t mField398;     // 0x398
  uint32_t mField39c;     // 0x39c
  uint32_t mField3a0;     // 0x3a0
  uint32_t mField3a4;     // 0x3a4
  uint32_t mField3a8;     // 0x3a8
  uint8_t mPad3ac[0x8];   // 0x3ac — unproven gap
  uint32_t mZero3b4;      // 0x3b4 — ctor zero
  uint32_t mField3b8;     // 0x3b8
  uint32_t mField3bc;     // 0x3bc
  uint32_t mField3c0;     // 0x3c0
  uint32_t mField3c4;     // 0x3c4
  uint32_t mField3c8;     // 0x3c8
  uint32_t mField3cc;     // 0x3cc
  uint32_t mField3d0;     // 0x3d0
  uint32_t mField3d4;     // 0x3d4
  uint32_t mField3d8;     // 0x3d8
  uint32_t mField3dc;     // 0x3dc
  uint32_t mField3e0;     // 0x3e0
  uint32_t mField3e4;     // 0x3e4
  uint32_t mField3e8;     // 0x3e8
  uint32_t mField3ec;     // 0x3ec
  uint32_t mField3f0;     // 0x3f0
  uint32_t mField3f4;     // 0x3f4
  uint32_t mField3f8;     // 0x3f8
  uint32_t mField3fc;     // 0x3fc
  uint32_t mField400;     // 0x400
  uint32_t mField404;     // 0x404
  uint32_t mField408;     // 0x408
  uint32_t mZero40c;      // 0x40c — ctor zero
  uint32_t mZero410;      // 0x410 — ctor zero
  uint32_t mZero414;      // 0x414 — ctor zero
  uint8_t mPad418;        // 0x418 — ctor zero
  uint8_t mPad419[0x17];  // 0x419 — unproven gap
  uint32_t mField430;     // 0x430
  uint8_t mPad434[0x4];   // 0x434 — unproven gap
  uint64_t mField438;     // 0x438
  uint32_t mField440;     // 0x440
  uint8_t mPad444[0x4];   // 0x444 — unproven gap
  uint64_t mField448;     // 0x448
};
}  // namespace object

// Naming: per item/kart physics-body variant; no distinguishing ctor strings, and the body's semantic identity requires the combo dictionary.
