#pragma once

#include <cstdint>

namespace object {
// KartParamCacheEnv — named from ctor string tag 'aglenv' (0x64822c window; was address-anchored KartParamCacheVt2358) (vptr 0x12b2358,
// GOT cell 0x130d948). Small cluster class: ctor 0x710064822c (vptr, zeros 0x8..0x37).
// Used as the first base call of Vt2668's ctor.
class KartParamCacheEnv {
 public:
  void* vptr;        // 0x00
  uint64_t mZero08;  // 0x08
  uint64_t mZero10;  // 0x10
  uint64_t mZero18;  // 0x18
  uint32_t mZero20;  // 0x20
  uint32_t mZero24;  // 0x24
  uint64_t mZero28;  // 0x28
  uint64_t mZero30;  // 0x30
                     // (0x38 total)
};
// Vtable slots (evidence TUs under /Users/raul/projects/mk8dx-400/src/unknown/):
// - slot 0 (0x10) deleting dtor (envDeletingDtor_71006482a8.cpp): installs vptr from
//   cell 0x710130d948+0x10, frees +0x30 (also zeroing it and word +0x28), frees +0x20,
//   then operator delete(self). function size 0x50 bytes.
// - slot 1 (0x18) bind/alloc (envCacheBindAllocSlot1_71006482f8.cpp): (self, src,
//   heapArg): allocates from heap cell 0x71012fae80 via 0x710060b3fc (align 8):
//   [src+0x208] x 8-byte entries stored at +0x28/+0x30 when >= 1, and [0x710130d930] x
//   4-byte entries stored at +0x18/+0x20 when >= 1; fills the second array with
//   (0, halfword from src + (i < 0x80 ? i : 0)*4 + 8) pairs, accumulating the halfwords;
//   zeroes the tail of the 8-byte array from element count-1 onward. function size 0x11c bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
