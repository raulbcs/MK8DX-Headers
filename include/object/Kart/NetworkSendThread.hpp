#pragma once

#include <cstdint>

namespace object
{
    // NetworkSendThread — an nn::ae::AppletThread subclass (vptr 0x12cca48, cell 0x1310a40, n=18, site 0x838c10, ctor 0x835608, alloc 0x28).
    // Evidence: Thread name "Network::Send" (string 0xf0c5a0) passed to the shared nn::ae ctor
    // 0x7100628a54 (stack pair at 0x838bd8-0x838c04), inside NetworkEngine::preSceneCalc
    // (unique symbol). Thread name normalized to NetworkSendThread.
    // Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
    // Ctor-evidence note: recorded ctor 0x7100835608 zeros a qword at +0xb0 and a
    // halfword at +0xb8, but the quoted factory alloc for the site is only 0x28 —
    // the alloc and ctor likely belong to different objects; no field map asserted.
    class NetworkSendThread
    {
    public:
        void* vptr;            // 0x00 — passed by the caller (cell+0x10)
        // (own fields unmapped)
    };
}
