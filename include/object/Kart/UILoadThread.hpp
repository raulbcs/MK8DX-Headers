#pragma once

#include <cstdint>

namespace object
{
    // UILoadThread — an nn::ae::AppletThread subclass (vptr 0x1265c50, cell 0x1308988, n=18, site 0x402528, ctor 0x401dd8, alloc 0xa0).
    // Evidence: Thread name "UILoadThread" (string 0xee756f) passed via the ae-ctor forwarding
    // helper 0x41f6cc (bl 0x7100628a54 at 0x41f6f4), stack pair at 0x40251c, inside boot/UI font
    // init FUN_7100401dd8 (strings UIHeap_Common, Cafe_Std.bffnt, message.sarc).
    // Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
    // Ctor-evidence note: the recorded ctor body performs no direct this-writes
    // (its calls build sub-objects); own fields unmapped — evidence insufficient.
    class UILoadThread
    {
    public:
        void* vptr;            // 0x00 — passed by the caller (cell+0x10)
        // (own fields unmapped)
    };
}
