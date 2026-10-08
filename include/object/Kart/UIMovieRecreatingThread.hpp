#pragma once

#include <cstdint>

namespace object {
// UIMovieRecreatingThread — an nn::ae::AppletThread subclass (vptr 0x1266ea8, cell 0x13091d8, n=18, site 0x41d164, ctor 0x41cc78).
// Evidence: Thread name "UIMovieRecreatingThread" (string 0xee8773) passed via the ae-ctor
// forwarding helper 0x41f6cc (bl 0x7100628a54 at 0x41f6f4), stack pair at 0x41d158, inside
// UIMoviePlayerNX::mpMovieHeap (unique symbol) — movie decode/recreate worker.
// Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
// Ctor-evidence note: the recorded ctor body performs no direct this-writes
// (its calls build sub-objects); own fields unmapped — evidence insufficient.
class UIMovieRecreatingThread {
 public:
  void* vptr;  // 0x00 — passed by the caller (cell+0x10)
               // (own fields unmapped)
};
}  // namespace object
