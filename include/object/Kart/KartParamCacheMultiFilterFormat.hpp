#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid.hpp"

namespace object {
// KartParamCacheMultiFilterFormat — named from ctor string evidence: params format/comp_sel_r/g/b/a (0xef9e0f-0xef9e4e); format config of the MultiFilter family (Blur/ColorDrift siblings) (was address-anchored KartParamCacheVt3748) (vptr 0x12b3748,
// GOT cell 0x130db28). Derived KartParamCacheMid variant: ctor 0x710066092c
// (calls the mid ctor with w1=4) built by the factory 0x710065efbc;
// size 0x1b0 (factory alloc). Ctor 0x710066092c: after the mid ctor, five
// 0x20 channel-pair members at 0x110..0x190 (KartParamCacheChanBase
// ctor 0x7100662f30 + w32 field written by 0x7100662f70 at 0x128/0x148/0x168/0x188/0x1a8).
class KartParamCacheMultiFilterFormat : public KartParamCacheMid {
 public:
  char mChanPair110[0xa0];  // 0x110 — five 0x20 channel pairs (ChanBase ctor 0x7100662f30), w32 tail fields at 0x128/0x148/0x168/0x188/0x1a8
                            // (0x1b0 total)
};
// Vtable slots (evidence TUs under /Users/raul/projects/mk8dx-400/src/unknown/):
// - slot 0 (0x10) vtable-init ctor stub (multiFilterFormatVtInitCtor_7100660b24.cpp):
//   fans cell 0x710130d918(+0x10) vptr into 0x80..0xc0 (nine qwords), cell
//   0x710130d920(+0x10) into 0x30, cell 0x710130d848(+0x10) into +0x0. function size 0x4c bytes.
// - slot 11 (0x68) write params (multiFilterFormatWriteParamsSlot11_7100660b78.cpp):
//   (self, unused, dst): maps +0x128 via table 0x7100f6f150 (index < 5, else keeps
//   dst+0x10) and +0x148/0x168/0x1a8 via table 0x7100f6f130 (index < 5, else defaults
//   2/3/4) into dst+0x10 and dst+0x1d4..0x1d7; sets bit 1 of byte dst+0x1dc, atomically
//   ORs bit 0 of word dst+0x1d8, calls 0x710064556c(dst+0x18), sets byte dst+0x41c = 1.
//   function size 0x100 bytes.
// - slot 12 (0x70) lookup format (lookupFormatWriteOut_7100660c78.cpp): if
//   (unsigned)+0x128 <= 4, *out = table[0x7100f6f150][idx], else *out untouched.
//   True extent 28.
// - slot 13 (0x78) reset counts (multiFilterFormatResetCounts_7100660c98.cpp):
//   +0x128=4, +0x168=1, +0x188=2, +0x148=0, +0x1a8=3 (per-tap sample counts/offsets).
//   function size 0x28 bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
