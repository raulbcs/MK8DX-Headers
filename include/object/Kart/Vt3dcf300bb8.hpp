#pragma once

#include <cstdint>

namespace object
{
    // Vt3dcf300bb8 — PROVISIONAL vtable-anchored name (vptr 0x12b0bb8, cell 0x130d470, n=18, site 0x6292a8, ctor 0x628fc8).
    // Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor): nn::ae::AppletThread subclass.
    // Site context: site 0x6292a8 inside shared member-init FUN_7100628fc8 (references sead::ControllerMgr); likely a base-level vtable of the Controller thread stack — semantics unresolved.
    // Ctor-evidence note: the recorded ctor (0x7100628fc8) has exactly one direct
    // this-write — w32 at +0xf0 (parameter pass-through). Everything between 0x08
    // and 0xf0 is unproven; declared as padding.
    class Vt3dcf300bb8
    {
    public:
        void* vtable;          // 0x00
        uint8_t mPad08[0xe8];  // 0x08 — unproven gap
        uint32_t mFieldf0;     // 0xf0 — ctor-written (param pass-through)
        // (extent unknown)
    };
}
