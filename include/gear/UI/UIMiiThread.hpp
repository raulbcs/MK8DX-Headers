#pragma once

#include <cstdint>

namespace gear {
// UIMiiThread — an nn::ae::AppletThread subclass (vptr 0x1266bd8, cell 0x1309158, n=18, site 0x419d78, ctor 0x4199ac).
// Evidence: Thread name "UIMiiThread" passed to the shared nn::ae ctor 0x7100628a54 (UIHeap_MiiIconAuthor context).
// Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
// Own field map pending.
class UIMiiThread {
 public:
  void* vptr;  // 0x00 — passed by the caller (cell+0x10)
               // (own fields unmapped)
};
}  // namespace gear
