#pragma once

#include <cstdint>

namespace repl
{
    // Thread — an nn::ae::AppletThread subclass (vptr 0x12c5478, cell 0x130fe68, n=18, site 0x7b6da8, ctor 0x7b6d40).
    // Evidence: Thread name "repl::Thread" passed to the shared nn::ae ctor 0x7100628a54 via the stack pair at the construction site.
    // Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
    // Own field map pending.
    class Thread
    {
    public:
        void* vptr;            // 0x00 — passed by the caller (cell+0x10)
        // (own fields unmapped)
    };
}
