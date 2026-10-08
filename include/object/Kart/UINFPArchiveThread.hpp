#pragma once

#include <cstdint>

namespace object {
// UINFPArchiveThread — an nn::ae::AppletThread subclass (vptr 0x1265d70, cell 0x1308d18, n=18, site 0x4062f4, ctor 0x4060dc, alloc 0x170).
// Evidence: Thread name "UINFP" (string 0xee7705) passed via the ae-ctor forwarding helper
// 0x41f6cc (bl 0x7100628a54 at 0x41f6f4), stack pair at 0x4062e8, inside UI archive init
// FUN_71004060dc (strings UIHeap_Award, UIHeap_Credit, UIHeap_Labo, race/ending/tv sarc).
// NOTE: distinct from gear::UINFPThread (vptr 0x126f470) — the "UINFP" thread-name string is
// reused by two different AppletThread subclasses; this one is the UI-archive worker.
// "UINFPArchiveThread" is a descriptive name from the proven construction context.
// Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
// Ctor-evidence note: the recorded ctor body performs no direct this-writes
// (its calls build sub-objects); own fields unmapped — evidence insufficient.
class UINFPArchiveThread {
 public:
  void* vptr;  // 0x00 — passed by the caller (cell+0x10)
               // (own fields unmapped)
};
}  // namespace object
