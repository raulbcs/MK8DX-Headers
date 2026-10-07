#pragma once

#include <cstdint>

namespace object
{
    // ContentsThread — an nn::ae::AppletThread subclass (vptr 0x12d0708, cell 0x1311000, n=18, site 0x872c6c, ctor 0x872600).
    // Evidence: Thread name "ContentsThread" passed to the shared nn::ae ctor 0x7100628a54
    // (stack pair at 0x872c60, AOC init FUN_7100872600: strings aoc:/contents.dat, aoc:/version.txt, AocHeap).
    // Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
    // Ctor-evidence note: the recorded ctor body performs no direct this-writes
    // (its calls build sub-objects); own fields unmapped — evidence insufficient.
    class ContentsThread
    {
    public:
        void* vptr;            // 0x00 — passed by the caller (cell+0x10)
        // (own fields unmapped)
    };
}
