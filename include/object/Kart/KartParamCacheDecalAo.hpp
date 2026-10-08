#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object {
// KartParamCacheDecalAo — named from ctor string evidence: ctor name string 'DecalAoMgr' (0xf1a97f) (was address-anchored KartParamCacheVt2be0) (vptr 0x12f2be0, cell 0x13151f0, n=14, site 0xa9a2fc, ctor 0xa9a2e0).
// Variant of the 0x63c6f8 param-cache cluster.
class KartParamCacheDecalAo : public KartParamCache {
 public:
  uint8_t mPad40[0x190];    // 0x40 — unproven gap
  uint32_t mField1d0;       // 0x1d0 — ctor-written
  uint32_t mZero1d4;        // 0x1d4 — ctor zero
  uint8_t mPad1d8[0x1068];  // 0x1d8 — unproven gap
  uint64_t mZero1240;       // 0x1240 — ctor zero
  uint64_t mZero1248;       // 0x1248 — ctor zero
  uint64_t mField1250;      // 0x1250 — ctor-written
  uint8_t mPad1258[0x180];  // 0x1258 — unproven gap
  uint32_t mZero13d8;       // 0x13d8 — ctor zero
  uint8_t mPad13dc[0x184];  // 0x13dc — unproven gap
  uint64_t mZero1560;       // 0x1560 — ctor zero
  uint32_t mZero1568;       // 0x1568 — ctor zero
  uint8_t mPad156c[0x4];    // 0x156c — unproven gap
  uint64_t mZero1570;       // 0x1570 — ctor zero
  uint64_t mZero1578;       // 0x1578 — ctor zero
  uint32_t mZero1580;       // 0x1580 — ctor zero
  uint8_t mPad1584[0x4];    // 0x1584 — unproven gap
  uint64_t mZero1588;       // 0x1588 — ctor zero
  uint8_t mPad1590[0x408];  // 0x1590 — unproven gap
  uint64_t mZero1998;       // 0x1998 — ctor zero
  uint64_t mZero19a0;       // 0x19a0 — ctor zero
};
// Vtable slot 0 (0x10) complete-object dtor (evidence TU /Users/raul/projects/mk8dx-400/src/unknown/decalAoCompleteDtorSlot0_7100a9a3dc.cpp):
// vptr from cell 0x71013151f0+0x10; runs the base dtor 0x7100654ae0 on +0x1d8; releases
// the optional sub-objects at +0x1560 and +0x1578 (0x71006373a4 — virtual release via
// vtable +8), the fixed sub-objects at +0x1950/0x1880/0x16b0/0x1490/0x1308 (0x7100639f38),
// +0x1598 (0x710063ed3c) and +0x410 (0x7100b00100); re-vptrs +0x1d8 from cell
// 0x710130d830, runs 0x7100654ae0 and 0x71006156b4 on it again; final vptr from cell
// 0x710130d848+0x10. function size 0xe0 bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
