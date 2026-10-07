#pragma once

#include <cstdint>

namespace object
{
    // Vt3dcf305d70 — PROVISIONAL vtable-anchored name (vptr 0x1265d70, cell 0x1308d18, n=18, site 0x4062f4, ctor 0x4060dc, alloc 0x170).
    // Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor): nn::ae::AppletThread subclass.
    // Site context: site 0x4062f4 inside UI archive init FUN_71004060dc (strings: UIHeap_Award, UIHeap_Credit, UIHeap_Labo, race/ending/tv sarc) — UI worker thread; class name unconfirmed.
    // Ctor-evidence note: the recorded ctor body performs no direct this-writes
    // (its calls build sub-objects); own fields unmapped — evidence insufficient.
    class Vt3dcf305d70
    {
    public:
        void* vtable;          // 0x00
        // (own fields unmapped; see ctor-evidence note)
    };
}
