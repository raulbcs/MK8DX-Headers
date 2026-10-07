#pragma once

#include <cstdint>

#include "_nn/ae/AppletThread.hpp"

namespace repl
{
    // SZSThread — an nn::ae::AppletThread subclass (vptr 0x12c5518, cell
    // 0x130fe70, n=18, ctor 0x7b6ff4, alloc site 0x7b5c20: new 0x108).
    // Evidence: Thread name "repl::SZSThread" (rodata 0xf0ab98) passed to
    // the shared nn::ae ctor 0x7100628a54 at the construction site.
    // Layout is identical to repl::Thread (same flag-byte protocol at
    // 0x100..0x102; teardown 0x7b71c8 calls 0x7b5ff0 on [0xf8]).
    class SZSThread : public nn::ae::AppletThread
    {
    public:
        void* mTargetF8;   // 0xf8 — ctor arg; endpoint of the teardown path
        uint8_t mFlag100;  // 0x100 — ctor zero; set 1 after the first request
        uint8_t mFlag101;  // 0x101 — ctor zero; request-pending gate
        uint8_t mFlag102;  // 0x102 — ctor zero; teardown-pending gate
        uint8_t pad103[5]; // 0x103 — to alloc size
        // (0x108 total)
    };
}
