#pragma once

#include <cstdint>

namespace gear {
// UINFPThread — an nn::ae::AppletThread subclass (vptr 0x126f470, cell 0x1309f58, n=18, site 0x485a08, ctor 0x485390, alloc 0x240).
// Evidence: Thread name "UINFP" passed to the shared nn::ae ctor 0x7100628a54 (amiibo/NFP UI context: AmiiboSet, HandleELink).
// Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
// Own field map pending.
class UINFPThread {
 public:
  void* vptr;  // 0x00 — passed by the caller (cell+0x10)
               // (own fields unmapped)
};
}  // namespace gear
