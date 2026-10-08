#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid.hpp"

namespace object {
// KartParamCacheMultiFilterBlur — named from ctor string evidence: ctor name string 'MultiFilterBlur' + params blur_type/blur_num/gaussian_kernel (0xef9d6d-0xef9dd5) (was address-anchored KartParamCacheVt3628) (vptr 0x12b3628,
// GOT cell 0x130db20). Derived KartParamCacheMid variant: ctor 0x710065ffec
// (calls the mid ctor with w1=2) built by the factory 0x710065efbc;
// size 0x170 (factory alloc). Ctor 0x710065ffec: after the mid ctor, three
// 0x20 channel-pair members at 0x110/0x130/0x150 (KartParamCacheChanBase
// ctor 0x7100662f30 + w32 field written by 0x7100662f70 at 0x128/0x148/0x168).
class KartParamCacheMultiFilterBlur : public KartParamCacheMid {
 public:
  char mChanPair110[0x60];  // 0x110 — three 0x20 channel pairs (ChanBase ctor 0x7100662f30), w32 tail fields at 0x128/0x148/0x168
                            // (0x170 total)
};
// Vtable slots (evidence TUs under /Users/raul/projects/mk8dx-400/src/unknown/):
// - slot 0 (0x10) vtable-init ctor stub (blurVtInitCtor_7100660148.cpp): identical to
//   vt3508InitVt_710065f584 (cell 0x710130d918(+0x10) into 0xb0/0xd0/0xf0/0x110/0x130,
//   0x710130d920(+0x10) into 0x68, 0x710130d848(+0x10) into +0x0).
// - slot 11 (0x68) dispatch (blurMultiFilterDispatchSlot11_7100660194.cpp): index =
//   (int)+0x168 - 3; jump-table constant from 0x7100f6f100 when 0..10, else 3; then for
//   *(int*)(+0x148) iterations calls 0x7100660224(self, a, b, *(int*)(+0x128), constant).
//   function size 0x8c bytes.
// - slot 14 (0x80) register name (multiFilterBlurInitSlot14_7100660538.cpp): builds
//   {vptr from cell 0x71012fae28+0x10, name 0x710ef9de5} and calls
//   0x7100664e94(self+0x130, a2, &local). function size 0x34 bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
