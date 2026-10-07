#pragma once

#include <cstdint>

namespace object
{
    // BackgroundLoadThread — an nn::ae::AppletThread subclass (vptr 0x12d2d90, cell 0x1311630, n=21, site 0x891200, ctor 0x8911a0).
    // Evidence: Thread name "BackgroundLoad" passed to the shared nn::ae ctor 0x7100628a54
    // (stack pair at 0x8911f4). The "BackgroundLoad" string also appears as a heap name
    // (Gear/, Light/, Screw/, .bfres loads in the ctor); the ctor here is the thread itself.
    // Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
    // Own fields unmapped — evidence insufficient.
    class BackgroundLoadThread
    {
    public:
        void* vptr;            // 0x00 — passed by the caller (cell+0x10)
        // (own fields unmapped)
    };
}
