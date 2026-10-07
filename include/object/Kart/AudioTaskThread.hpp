#pragma once

#include <cstdint>

namespace object
{
    // AudioTaskThread — an nn::ae::AppletThread subclass (vptr 0x12c24e8, cell 0x130f438, n=18, site 0x77523c, ctor 0x774e7c).
    // Evidence: the parametric ctor wrapper 0x7100775200 forwards the (vptr, name) pair to the
    // shared nn::ae ctor 0x7100628a54; its only caller (0x774af0) passes the thread name
    // "sead::AudioTaskThread" (string 0xf08620, stack pair at 0x774ad0-0x774aec).
    // Class name normalized to AudioTaskThread.
    // Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
    // Own fields unmapped — evidence insufficient.
    class AudioTaskThread
    {
    public:
        void* vptr;            // 0x00 — passed by the caller (cell+0x10)
        // (own fields unmapped)
    };
}
