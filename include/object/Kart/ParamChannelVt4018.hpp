#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelVt4018 — address-anchored name (vptr 0x12b4018, GOT cell
// 0x130dbd0). Channel type of the 0x66496c cluster: built in
// place inside the headered containers (ctor family 0x7100668528 /
// in-place vptr store), derived from KartParamCacheChan via
// ChanBase (0x12b3af0). Byte flag at 0x24 (extent 0x28).
// Slot 0x48 returns 13 (family ID) — Slot48_ret13_7100668500.cpp.
class ParamChannelVt4018 : public KartParamCacheChan {
 public:
  uint8_t mFlag24;  // 0x24 — zeroed on init
                    // (0x28 total)
};
// vtable facts (TUs paramChannelVt4018DtorSlot0_7100668468.cpp,
// paramChannel4018DeletingDtor_71006684bc.cpp,
// paramChannel4018GetStrideSlot12_7100668528.cpp):
//   slot 0 (0x10): dtor — installs the vptr from cell 0x710130dbd0 (+0x10);
//     if the byte at self+0x24 is set, frees the heap pointer at self+0x18
//     and clears the byte; then swaps in the cell 0x710130d918 (+0x10) vptr.
//   slot 1 (0x18): deleting dtor — resets the vptr from cell 0x710130dbd0
//     (+0x10); if self+0x24 is set and self+0x18 is non-null, releases it
//     with operator delete[]; then operator delete(this).
//   slot 12 (0x70): element-stride query — returns *(int*)(self+0x20) * 4.
// Field facts not declared above (extent 0x28 per header): heap pointer at
// self+0x18 (freed by the dtor family), s32 element-count/stride word at
// self+0x20.
}  // namespace object

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable. Address-anchored name retained.
