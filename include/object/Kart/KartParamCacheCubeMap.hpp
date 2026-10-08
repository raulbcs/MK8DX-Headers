#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object {
// KartParamCacheCubeMap — named from ctor string evidence: ctor string tag 'aglcube' + param cubemap_mgr (0xf02a28-0xf1c50d) (was address-anchored KartParamCacheVt31e8) (vptr 0x12f31e8, cell 0x13152a0, n=13, site 0xab86d8, ctor 0xab868c).
// Variant of the 0x63c6f8 param-cache cluster.
class KartParamCacheCubeMap : public KartParamCache {
 public:
  uint8_t mPad40[0x190];   // 0x40 — unproven gap
  uint64_t mField1d0;      // 0x1d0 — ctor-written
  uint8_t mPad1d8[0x28];   // 0x1d8 — unproven gap
  uint32_t mZero200;       // 0x200 — ctor zero
  uint8_t mPad204[0x4];    // 0x204 — unproven gap
  uint64_t mZero208;       // 0x208 — ctor zero
  uint64_t mField210;      // 0x210 — ctor-written
  uint64_t mField218;      // 0x218 — ctor-written
  uint32_t mZero220;       // 0x220 — ctor zero
  uint32_t mField224;      // 0x224 — ctor-written
  uint64_t mField228;      // 0x228 — ctor-written
  uint64_t mField230;      // 0x230 — ctor-written
  uint32_t mZero238;       // 0x238 — ctor zero
  uint32_t mField23c;      // 0x23c — ctor-written
  uint64_t mZero240;       // 0x240 — ctor zero
  uint64_t mZero248;       // 0x248 — ctor zero
  uint64_t mZero250;       // 0x250 — ctor zero
  uint32_t mZero258;       // 0x258 — ctor zero
  uint8_t mPad25c[0x4];    // 0x25c — unproven gap
  uint64_t mZero260;       // 0x260 — ctor zero
  uint64_t mZero268;       // 0x268 — ctor zero
  uint64_t mZero270;       // 0x270 — ctor zero
  uint32_t mZero278;       // 0x278 — ctor zero
  uint8_t mPad27c[0x4];    // 0x27c — unproven gap
  uint64_t mZero280;       // 0x280 — ctor zero
  uint64_t mZero288;       // 0x288 — ctor zero
  uint32_t mField290;      // 0x290 — ctor-written
  uint32_t mField294;      // 0x294 — ctor-written
  uint64_t mZero298;       // 0x298 — ctor zero
  uint32_t mField2a0;      // 0x2a0 — ctor-written
  uint32_t mField2a4;      // 0x2a4 — ctor-written
  uint32_t mField2a8;      // 0x2a8 — ctor-written
  uint32_t mField2ac;      // 0x2ac — ctor-written
  uint32_t mField2b0;      // 0x2b0 — ctor-written
  uint32_t mZero2b4;       // 0x2b4 — ctor zero
  uint32_t mField2b8;      // 0x2b8 — ctor-written
  uint32_t mField2bc;      // 0x2bc — ctor-written
  uint64_t mZero2c0;       // 0x2c0 — ctor zero
  uint32_t mZero2c8;       // 0x2c8 — ctor zero
  uint8_t mPad2cc[0x4];    // 0x2cc — unproven gap
  uint64_t mZero2d0;       // 0x2d0 — ctor zero
  uint32_t mZero2d8;       // 0x2d8 — ctor zero
  uint8_t mPad2dc[0x4];    // 0x2dc — unproven gap
  uint32_t mZero2e0;       // 0x2e0 — ctor zero
  uint8_t mPad2e4[0x4];    // 0x2e4 — unproven gap
  uint64_t mZero2e8;       // 0x2e8 — ctor zero
  uint32_t mZero2f0;       // 0x2f0 — ctor zero
  uint8_t mPad2f4[0x4];    // 0x2f4 — unproven gap
  uint64_t mZero2f8;       // 0x2f8 — ctor zero
  uint64_t mField300;      // 0x300 — ctor-written
  uint64_t mField308;      // 0x308 — ctor-written
  uint32_t mField310;      // 0x310 — ctor-written
  uint8_t mPad314[0x104];  // 0x314 — unproven gap
  uint64_t mZero418;       // 0x418 — ctor zero
  uint32_t mField420;      // 0x420 — ctor-written
  uint32_t mField424;      // 0x424 — ctor-written
  uint64_t mField428;      // 0x428 — ctor-written
  uint64_t mField430;      // 0x430 — ctor-written
  uint32_t mField438;      // 0x438 — ctor-written
  uint8_t mPad43c[0x4];    // 0x43c — unproven gap
  uint64_t mZero440;       // 0x440 — ctor zero
  uint64_t mZero448;       // 0x448 — ctor zero
  uint32_t mField450;      // 0x450 — ctor-written
};
// Vtable slot 0 (0x10) dtor/reset (evidence TU /Users/raul/projects/mk8dx-400/src/unknown/cubeMapDtorSlot0_7100ab8aa4.cpp):
// stamps vptr 0x13152a0(+0x10); frees the pooled array at +0x208 (count at -8, stride
// 0x2258); per element (last to first): stamps cell 0x1315298(+0x10) at el-0x378, cell
// +0x78 at el-0x190, cell 0x130d918(+0x10) at +0x1eb0/+0x1a58/+0x1a30/-0x20/-0x40/-0x60/
// -0x88/-0xf8, runs the KartParamCacheColorCorrectionSub slot-0 dtor on the element,
// stamps 0x130d920(+0x10) at el-0x128, 0x130d848(+0x10) at el-0x190, 0x1315290(+0x10)
// at el-0x378; if byte el-0x1e0 set and *(el-0x368) non-null, deletes it via
// 0x7100b00714 + operator delete; 0x7100639f38 on el-0x2b0; then operator delete[],
// zeroing +0x208/+0x200. Frees *(+0x298) via 0x7100b00714/delete; virtual vt[0x8/8]
// dtors on *(+0x240) and *(+0x248); 0x71006373a4/0x71006373bc pairs on +0x250/+0x270
// (when pointed); frees arrays *(+0x2d0) and *(+0x2e8) via delete[] (zeroing
// +0x2c8/+0x2e0); 0x71006286a4 on +0x8b0/+0x870; stamps 0x130d830(+0x10) into +0x638
// with 0x7100654ae0/0x71006156b4; 0x71006462c4 on +0x458; stamps 0x130d920(+0x10) into
// +0x1d0 and 0x130d848(+0x10) into +0x0. function size 0x280 bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
