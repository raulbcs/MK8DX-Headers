#pragma once

#include <cstdint>

namespace object
{
    // Vt3dcf300708 — PROVISIONAL vtable-anchored name (vptr 0x12d0708, cell 0x1311000, n=18, site 0x872c6c, ctor 0x872600).
    // Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor): nn::ae::AppletThread subclass.
    // Site context: site 0x872c6c inside AOC init FUN_7100872600 (strings: aoc:/contents.dat, aoc:/version.txt, AocHeap) — likely the AOC worker thread; class name unconfirmed.
    // Ctor-evidence note: the recorded ctor body performs no direct this-writes
    // (its calls build sub-objects); own fields unmapped — evidence insufficient.
    class Vt3dcf300708
    {
    public:
        void* vtable;          // 0x00
        // (own fields unmapped; see ctor-evidence note)
    };
}
