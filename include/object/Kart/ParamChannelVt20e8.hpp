#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelVt20e8 — address-anchored name (vptr 0x12b20e8, GOT cell
// 0x130d938). Channel type of the 0x66496c cluster: built in
// place inside the headered containers (ctor family 0x7100668528 /
// in-place vptr store), derived from KartParamCacheChan via
// ChanBase (0x12b3af0). EXTENT PROVEN 0x80 (not the bare Chan 0x20):
// embedded instances share vptr cell 0x130d938 and are spaced 0x80 apart
// in their parents (0x71006dda30..0x71006dda68: sub-objects at +0x518,
// +0x598, +0x618, +0x698; the next sub-object at +0x718 carries a
// different vptr from cell 0x130d918 — same pattern at 0x710069600c:
// +0x978 -> +0x9f8). Member writes reach +0x78 (slots 18/19), inside
// the 0x80 stride.
class ParamChannelVt20e8 : public KartParamCacheChan {
 public:
  // (no own fields)
  char mPad20[0x60];  // 0x20 — unproven padding to the 0x80 embedded stride
  // (0x80 total)
};
// vtable facts (TU paramChannelDeletingDtor_7100647c40.cpp,
// vtInitTailBaseCtor_7100647c2c.cpp, paramChannelForwardVtCall_7100647bec.cpp,
// virtualForwardSlot19_7100647c14.cpp):
//   slot 0 (0x10): vtable-init — stores vptr from GOT cell 0x710130938 (+0x10)
//     into *this, then tail-calls the base-class ctor continuation
//     0x7100661c4c.
//   slot 1 (0x18): deleting dtor — resets vptr from cell 0x710130d938 (+0x10),
//     calls cleanup helper 0x7100661c4c, then operator delete(this).
//   slot 18 (0xa0): invokes the child object at this+0x70 through its own
//     vtable slot 2 (0x10), passing (child, x1, u32 at this+0x78).
//   slot 19 (0xa8): trampoline — loads object at this+0x70, tail-jumps its
//     vtable slot 3 (0x18) with (obj, *(this+0x78)).
// EXTENT RESOLVED (was: 0x20 vs >= 0x7c): true extent is 0x80. Evidence:
// parents embed consecutive ParamChannelVt20e8 sub-objects (same vptr,
// cell 0x710130d938 +0x10) exactly 0x80 apart — 0x71006dda30..
// 0x71006dda68 (+0x518/+0x598/+0x618/+0x698, next different-vptr member
// at +0x718) and 0x710069600c..0x7100696028 (+0x978 -> +0x9f8). The
// +0x70/+0x78 dereferences in slots 18/19 sit inside the stride. There
// is no operator-new site for this class (built in place only).
}  // namespace object

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable. Address-anchored name retained.
