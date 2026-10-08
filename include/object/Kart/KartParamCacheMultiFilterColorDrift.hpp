#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid.hpp"

namespace object {
// KartParamCacheMultiFilterColorDrift — named from ctor string evidence: ctor name string 'MultiFilterColorDrift' + params drift_r/g/b (0xef9e5b-0xef9e8b) (was address-anchored KartParamCacheVt37d8) (vptr 0x12b37d8,
// GOT cell 0x130db30). Derived KartParamCacheMid variant: ctor 0x7100660cc4
// (calls the mid ctor with w1=5) built by the factory 0x710065efbc;
// size 0x170 (factory alloc). Ctor 0x7100660cc4: after the mid ctor, three
// 0x20 channel-pair members at 0x110/0x130/0x150 (KartParamCacheChanBase
// ctor 0x7100662f30 + two w32 fields written by 0x7100662f70 at
// 0x128+0x12c / 0x148+0x14c / 0x168+0x16c).
class KartParamCacheMultiFilterColorDrift : public KartParamCacheMid {
 public:
  char mChanPair110[0x60];  // 0x110 — three 0x20 channel pairs (ChanBase ctor 0x7100662f30), each with two w32 tail fields (0x128/0x12c, 0x148/0x14c, 0x168/0x16c)
                            // (0x170 total)
};
// Vtable slots (evidence TUs under /Users/raul/projects/mk8dx-400/src/unknown/):
// - slot 0 (0x10) vtable-init ctor stub (colorDriftVtInitCtor_7100660e48.cpp): same
//   fan as the Vt3508 family — cell 0x710130d918(+0x10) vptr into 0xb0/0xd0/0xf0/0x110/
//   0x130, cell 0x710130d920(+0x10) into 0x68, cell 0x710130d848(+0x10) into +0x0.
// - slot 11 (0x68) per-frame multi-pass filter update (multiFilterColorDriftUpdateSlot11_7100660ed4.cpp):
//   chains 0x7100644334 (detail query) into 0x7100692e48 allocating a pass into
//   *(x2-arg+0x420) (name cell from global 0x12fae28, string 0xef9e8b); memcpy 0xab
//   bytes into +0x248; 0x710063a090 on +0x2f8 from pass+0xb0; restores +0x3c8/+0x3ca
//   and stores pass+0x178 into +0x3c0; +0x3c9 |= 1; defaults from *(0x12fbb00) into
//   +0x1f0..+0x1fc, scaled +0x1e8..+0x1ec; per-core spin byte gate (stride 0x188,
//   byte +0x1ac) runs 0x710062e6c0/0x710062e790 on +0x1e0 plus 0x710065ca4c and
//   0x710063fb50; frees the pass via 0x7100692f0c; if byte +0x41c set: latches +0x418
//   into +0x1d7, sets +0x1d4/5/6 = 2/3/4, +0x1dc |= 2, atomic bit0 set on +0x1d8,
//   0x710064556c(self+0x18), clears +0x41c. function size 0x268 bytes. Confidence medium.
// - slot 13 (0x78) copy res counts (multiFilterColorDriftCopyResCounts_7100660ea8.cpp):
//   copies the first two u32s of *(cell 0x71012fb0b0) into +0x128/+0x148 (first),
//   +0x12c/+0x14c (second) and +0x168/+0x16c. function size 0x30 bytes.
// - slot 14 (0x80) register names (colorDriftMultiFilterInitThreeSlots_7100661140.cpp):
//   calls 0x7100664e94 three times with tag pair {[0x71012fae28]+0x10, 0x7100ef90d38}
//   on self+0x110, self+0x130 and self+0x150. function size 0x7c bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
