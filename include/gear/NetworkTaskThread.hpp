#pragma once

#include <cstdint>

namespace gear
{
    // NetworkTaskThread — an nn::ae::AppletThread subclass (vptr 0x12cdd30, cell 0x1310da8, n=18, site 0x8510bc, ctor 0x851060).
    // Evidence: Thread name "gear::NetworkTaskThread" passed to the shared nn::ae ctor 0x7100628a54; site inside the gear network-task setup path.
    // Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
    // Own field map pending.
    class NetworkTaskThread
    {
    public:
        void* vptr;            // 0x00 — passed by the caller (cell+0x10)
        // (own fields unmapped)
    };
}
