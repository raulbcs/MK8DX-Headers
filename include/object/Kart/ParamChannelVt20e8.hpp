#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelVt20e8 — address-anchored name (vptr 0x12b20e8, GOT cell
// 0x130d938). Channel type of the 0x66496c cluster: built in
// place inside the headered containers (ctor family 0x7100668528 /
// in-place vptr store), derived from KartParamCacheChan via
// ChanBase (0x12b3af0). No fields beyond the Chan shape (extent 0x20).
class ParamChannelVt20e8 : public KartParamCacheChan {
 public:
  // (no own fields)
  // (0x20 total)
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
// NOTE (extent): the header above claims extent 0x20 (Chan shape only), but
// slots 18/19 dereference this+0x70/this+0x78, implying extent >= 0x7c.
// Contradiction unresolved — the 0x7c figure rests on the two virtual
// forwarders, the 0x20 figure on the ctor-family evidence.
}  // namespace object

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable. Address-anchored name retained.
