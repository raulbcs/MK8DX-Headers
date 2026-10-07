#pragma once

#include <cstdint>

namespace object
{
    // VibrationThread — an nn::ae::AppletThread subclass (vptr 0x12af620, cell 0x130d0e0, n=18, site 0x60c3f8, ctor 0x60c36c).
    // Evidence: Thread name "VibrationThread" (string 0xef7836) passed to the shared nn::ae ctor
    // 0x7100628a54 (stack pair at 0x60c3c8-0x60c3ec) by ctor 0x710060c36c, which also stores the
    // vptr (cell 0x130d0d8, +0x10 convention) at 0x60c3b0.
    // Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
    // Own fields unmapped — evidence insufficient.
    class VibrationThread
    {
    public:
        void* vptr;            // 0x00 — written by ctor 0x60c36c
        // (own fields unmapped)
    };
}
