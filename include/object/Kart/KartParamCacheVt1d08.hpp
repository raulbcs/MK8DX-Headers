#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid2.hpp"

namespace object {
// KartParamCacheVt1d08 — address-anchored name (vptr 0x12b1d08,
// GOT cell 0x130d858). Mid2-derived variant (ctor 0x710063c87c calls the Mid2 overload
// 0x7100668fc4): float constants 2.0f/-1.0f/3.0f/0.0906f at 0x1d8-0x1f4,
// u32 at 0x204. Extent 0x208.
class KartParamCacheVt1d08 : public KartParamCacheMid2 {
 public:
  // (0x208 total)
};
// Vtable slots (evidence TUs under /Users/raul/projects/mk8dx-400/src/unknown/):
// - slot 0 (0x10) dtor, returns self, no operator delete (kartParamCacheVt1d08DtorSlot0_710063c954.cpp):
//   installs vptr cell 0x710130d858(+0x10), invokes entry vtable slot 2 on each of
//   the *(+0x218) pointers while +0x210 > index, zeroes +0x210, runs 0x710060b984 on
//   +0x210/+0x220, then installs cell 0x710130d848(+0x10) as outer vptr. function size 0x94 bytes.
// - slot 1 (0x18) complete dtor (kartParamCacheVt1d08CompleteDtorSlot1_710063ca4c.cpp):
//   same reset then operator delete(self). function size 0x88 bytes.
// - slot 13 (0x78) broadcast (kartParamCacheVt1d08BroadcastArgsSlot13_710063d28c.cpp):
//   when byte +0x1e4 has bit 0 set and *(int*)(+0x220) >= 1, invokes each entry's own
//   vtable slot 0 on the pointers in *(+0x228), forwarding the five call arguments.
//   function size 0x80 bytes.
// Fields +0x1e4/+0x210/+0x218/+0x220/+0x228 proven by these TUs are not declared in
// this header (extent/layout unchanged).
}  // namespace object

// Naming closure: only ctor string is the debug icon 'Icon=EFFECT' (0xef8b50); group tag only, no role evidence. Address-anchored name retained.
