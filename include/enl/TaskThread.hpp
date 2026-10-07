#pragma once

#include <cstdint>

namespace enl
{
    // TaskThread — an nn::ae::AppletThread subclass (vptr 0x128a8e0, cell 0x130b0f0, n=20, site 0x557c64, ctor 0x557c0c).
    // Evidence: Constructed inside enl::TaskThread (unique symbol at the site); nn::ae applet-thread subclass.
    // Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
    // Own field map pending.
    class TaskThread
    {
    public:
        void* vptr;            // 0x00 — passed by the caller (cell+0x10)
        // (own fields unmapped)
    };
}
