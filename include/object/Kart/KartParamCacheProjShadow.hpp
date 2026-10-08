#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object {
// KartParamCacheProjShadow — named from ctor string evidence: ctor string tag 'aglprojsdw' + params bias_scale/anim_swing_cyc_x/scroll anim (0xf1dc97-0xf1ddb4) (was address-anchored KartParamCacheVt3f60) (vptr 0x12f3f60, cell 0x1315460, n=13, site 0xade4d0, ctor 0xade480).
// Variant of the 0x63c6f8 param-cache cluster.
class KartParamCacheProjShadow : public KartParamCache {
 public:
  uint8_t mPad40[0x344];  // 0x40 — unproven gap
  uint16_t mField384;     // 0x384 — ctor-written
  uint8_t mField386;      // 0x386 — ctor-written
  uint8_t mField387;      // 0x387 — ctor-written
  uint8_t mField388;      // 0x388 — ctor-written
  uint8_t mField389;      // 0x389 — ctor-written
  uint8_t mPad38a[0x36];  // 0x38a — unproven gap
  uint32_t mField3c0;     // 0x3c0 — ctor-written
  uint32_t mZero3c4;      // 0x3c4 — ctor zero
  uint64_t mField3c8;     // 0x3c8 — ctor-written
  uint32_t mZero3d0;      // 0x3d0 — ctor zero
  uint8_t mPad3d4[0x14];  // 0x3d4 — unproven gap
  uint64_t mField3e8;     // 0x3e8 — ctor-written
  uint8_t mPad3f0[0x28];  // 0x3f0 — unproven gap
  void* mSelf418;         // 0x418 — ctor stores `this`
  uint64_t mField420;     // 0x420 — ctor-written
  uint8_t mPad428[0x10];  // 0x428 — unproven gap
  uint32_t mField438;     // 0x438 — ctor-written
  uint32_t mField43c;     // 0x43c — ctor-written
  uint64_t mField440;     // 0x440 — ctor-written
  uint8_t mPad448[0x10];  // 0x448 — unproven gap
  uint32_t mField458;     // 0x458 — ctor-written
  uint32_t mField45c;     // 0x45c — ctor-written
  uint64_t mField460;     // 0x460 — ctor-written
  uint8_t mPad468[0x10];  // 0x468 — unproven gap
  uint32_t mZero478;      // 0x478 — ctor zero
  uint8_t mPad47c[0x4];   // 0x47c — unproven gap
  uint64_t mField480;     // 0x480 — ctor-written
  uint8_t mPad488[0x10];  // 0x488 — unproven gap
  uint32_t mZero498;      // 0x498 — ctor zero
  uint8_t mPad49c[0x4];   // 0x49c — unproven gap
  uint64_t mField4a0;     // 0x4a0 — ctor-written
  uint8_t mPad4a8[0x10];  // 0x4a8 — unproven gap
  uint32_t mField4b8;     // 0x4b8 — ctor-written
  uint32_t mField4bc;     // 0x4bc — ctor-written
  uint64_t mField4c0;     // 0x4c0 — ctor-written
  uint8_t mPad4c8[0x10];  // 0x4c8 — unproven gap
  uint32_t mField4d8;     // 0x4d8 — ctor-written
  uint32_t mField4dc;     // 0x4dc — ctor-written
  uint64_t mField4e0;     // 0x4e0 — ctor-written
  uint8_t mPad4e8[0x10];  // 0x4e8 — unproven gap
  uint32_t mZero4f8;      // 0x4f8 — ctor zero
  uint8_t mPad4fc[0x4];   // 0x4fc — unproven gap
  uint64_t mField500;     // 0x500 — ctor-written
  uint8_t mPad508[0x10];  // 0x508 — unproven gap
  uint32_t mZero518;      // 0x518 — ctor zero
  uint8_t mPad51c[0x4];   // 0x51c — unproven gap
  uint64_t mField520;     // 0x520 — ctor-written
  uint8_t mPad528[0x10];  // 0x528 — unproven gap
  uint8_t mPad538;        // 0x538 — ctor zero
  uint8_t mPad539[0x7];   // 0x539 — unproven gap
  uint8_t mPad540;        // 0x540 — ctor zero
};
// Vtable slots (evidence TUs under /Users/raul/projects/mk8dx-400/src/unknown/):
// - slot 0 (0x10) dtor, returns self (projShadowDtorSlot0_7100ade9a8.cpp): vptr from
//   cell 0x7101315460+0x10, resets the nine member sub-vptrs at +0x420..+0x520 to
//   [0x710130d918]+0x10 and +0x3e8 to [0x710130d920]+0x10, calls 0x710063a384(self)
//   and 0x7100639f38(self+0x280), installs [0x710130d848]+0x10 as outer vptr.
//   function size 0x8c bytes.
// - slot 1 (0x18) deleting dtor (projShadowDeletingDtorSlot1_7100adea34.cpp): same
//   reset sequence, then operator delete(self). function size 0x80 bytes.
// - slot 5 (0x38) per-frame update (projShadowUpdateSlot5_7100adee10.cpp): recomputes
//   shadow projection: k = rodata[0xed59c0]; +0x544 = *(+0x518)*k, +0x548 = *(+0x4f8)*k;
//   bytes +0x387/+0x388/+0x389 := (*(+0x538) ? 1 : 7); word +0x390 exclusive rmw
//   (clear/set 0x2, later clear 0x2 set 0x4); +0x384/+0x385 := 1, +0x386 := 1 or 2 by
//   byte +0x540; +0x3d0 := 0; vptr cell *(0x12fbb00) dereferenced into +0x3c8 and the
//   +0x3d4/+0x3dc pair; trig block with sinf/cosf(*(+0x518)) writing the tangent/bias
//   terms +0x398..+0x3c4 and +0x3a4/+0x3b4 = *(+0x4d8)+0.5+... / *(+0x4dc)+0.5+...
//   function size 0x1b8 bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
