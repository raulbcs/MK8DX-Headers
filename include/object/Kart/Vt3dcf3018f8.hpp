#pragma once

#include <cstdint>

namespace object {
// Vt3dcf3018f8 — GAP PROVEN: thread name is built at runtime, no static class name exists.
// The parametric ctor wrapper 0x71006366b0 forwards the (vptr, name) pair to the shared
// nn::ae ctor 0x7100628a54; its only caller (0x6326f4, worker-spawn manager FUN_7100632520)
// passes a heap-allocated name formatted with "%s/Worker%d(%s)" (fragment 0xef7b93).
// The class is a scene-context pooled worker (SiteVt00/SceneVt01 slots nearby); the thread
// name differs per instance, so no semantic class name is derivable from the binary.
// Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
// Own fields unmapped — evidence insufficient.
class Vt3dcf3018f8 {
 public:
  void* vptr;  // 0x00 — passed by the caller (cell+0x10)
               // (own fields unmapped)
};
}  // namespace object
