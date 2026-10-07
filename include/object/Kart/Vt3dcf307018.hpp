#pragma once

#include <cstdint>

namespace object
{
    // Vt3dcf307018 — GAP PROVEN: no thread name exists for this class anywhere in the binary.
    // Ctor 0x7100408910 stores the vptr (cell 0x1308ea0, +0x10 convention) and calls base init
    // 0x71006286a4 — a different base path than the named shared nn::ae ctor 0x7100628a54; no
    // name string is loaded in the ctor or at any materialization site, and no direct bl caller
    // of the ctor was found (singleton guard-init pattern at 0x408714 compares the instance
    // against global 0x12fbea8). Semantics unresolved; renaming would be invention.
    // Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
    // Ctor-evidence note: the recorded ctor body performs no direct this-writes
    // (its calls build sub-objects); own fields unmapped — evidence insufficient.
    class Vt3dcf307018
    {
    public:
        void* vptr;            // 0x00 — written by ctor 0x408910
        // (own fields unmapped)
    };
}
