#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid.hpp"

namespace object {
// KartParamCacheVt3868 — address-anchored name (vptr 0x12b3868,
// GOT cell 0x130db10). Derived KartParamCacheMid variant built by the
// factory 0x710065efbc (case w1=6, inline extension of the mid ctor);
// size 0x150 (factory alloc). The factory also copies a u32 pair from
// the global [0x12fbb00] into 0x128/0x12c (this variant only).
class KartParamCacheVt3868 : public KartParamCacheMid {
 public:
  char mChan110[0x18];  // 0x110 — channel-pair member (ctor pair
                        // 0x7100662f30/0x7100662f70, cell 0x130d9b8)
  uint32_t mField128;   // 0x128 — factory zero
  uint8_t pad12c[4];    // 0x12c — unproven padding
  char mChan130[0x20];  // 0x130 — channel-pair member (names
                        // 0xef9d06/0xef9d13)

  // (0x150 total)
};
// Vtable slots (evidence TUs under /Users/raul/projects/mk8dx-400/src/unknown/):
// - slot 0 (0x10): vtable-init stub identical to the Vt3508 family fan (vt3868InitVt_71006612dc.cpp).
// - slot 11 (0x68) per-frame multi-pass filter update (vt3868FilterUpdateSlot11_710066134c.cpp):
//   mirrors multiFilterColorDriftUpdateSlot11_7100660ed4 with scale multipliers from
//   float +0x148 / +0x14c; allocates the pass via 0x7100692e48 into *(ps+0x420)
//   (key pair 0x12fae28+0x10 / rodata 0xef9ed2), memcpy 0xab bytes into +0x248,
//   restores +0x3c8/+0x3ca, +0x3c0 = pass+0x178, +0x3c9 |= 1; defaults from
//   *(0x12fbb00) into +0x1f0..+0x1fc, scaled sizes into +0x1e8..+0x1ec; per-core
//   gate (stride 0x188, byte +0x1ac) drives 0x710062ab24/0x710062e6c0/0x710062e790
//   on +0x1e0 and 0x710065c5a4 with the negated +0x128/+0x12c pair; frees the old
//   pass via 0x7100692f0c; +0x41c block latches +0x418 into +0x1d7, sets
//   +0x1d4/5/6 = 2/3/4, +0x1dc |= 2, atomic bit0 set on +0x1d8, clears +0x41c.
//   function size 0x2ac bytes. Confidence medium (helper arg semantics partially inferred).
// - slot 12 (0x70) resolution clamp (vt3868ClampResolutionSlot12_71006615fc.cpp):
//   arg+4 = max(1, (int)(arg+4 * float +0x148)), arg+8 = max(1, (int)(arg+8 *
//   float +0x14c)). function size 0x3c bytes.
// - slot 13 (0x78) copy res counts (kartParamCacheVt3868CopyResCounts_7100661324.cpp):
//   copies the first two u32s of *(cell 0x71012fb0b0) into +0x128/+0x12c and writes
//   0x3f000000 (0.5f) into +0x148/+0x14c. function size 0x24 bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
