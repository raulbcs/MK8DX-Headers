#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid2.hpp"

namespace object {
// KartParamCacheFilterAA — named from ctor string evidence: ctor string tag 'aglfila' + params antialias_type/fxaa_detect_edge_qa/subpix_param/max_span (0xef9661-0xef97a3) (was address-anchored KartParamCacheVt3130) (vptr 0x12b3130,
// GOT cell 0x130da98, n=13). Mid2-derived variant: ctor memsets, member 0x710066a2a4, then a
// table of u32 entries at 0x460..0x580 and pointers 0x588/0x590,
// zeros to 0x5e0. Extent 0x5e8.
class KartParamCacheFilterAA : public KartParamCacheMid2 {
 public:
  // additional writes by ctor 0x7100651ae4
};
// Vtable slot 0 (+0x10) dtor/reset (evidence TU /Users/raul/projects/mk8dx-400/src/unknown/filterAADtorResetSlot0_7100652020.cpp):
// runs 0x71006373a4 (mid-function cold fragment) on each +0x918 child of the +0x5e0
// pooled array (stride 0xb40, count +0x5d8), frees the array running nine element
// destructors per entry, re-inits the +0x5e8 container, and re-stamps default vptr
// fields +0x568..+0x408 (cell 0x710130d918), +0x3d8 (0x710130d920), +0x5e8
// (0x710130d830), +0x0 (0x710130d848). function size 0x198 bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
