#pragma once

#include <cstdint>

namespace object {
// LowPrioWorkerThread — an nn::ae::AppletThread subclass (vptr 0x12c14d0, cell 0x130efe0, n=18, site 0x756c84, ctor 0x756c54).
// Evidence: the parametric ctor wrapper 0x7100756c54 forwards the (vptr, name) pair to the
// shared nn::ae ctor 0x7100628a54; its only caller (0x750750) passes the thread name
// "aal::LowPrioWorkerThread" (string 0xf076c4, stack pair at 0x750728) together with an
// nn::aac result (0x629674). Class name normalized to LowPrioWorkerThread.
// Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
// Own fields unmapped — evidence insufficient.
class LowPrioWorkerThread {
 public:
  void* vptr;  // 0x00 — passed by the caller (cell+0x10)
               // (own fields unmapped)
};
}  // namespace object
