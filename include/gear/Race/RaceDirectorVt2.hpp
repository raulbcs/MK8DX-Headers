#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceDirectorVt2 — PROVISIONAL vtable-anchored name (no MethodTree string).
// Vtable 0x11b3098 (.data anchor 0x11b3088, GOT 0x12fbca0), custom-RTTI fn
// 0x4e268. Mid-level base of the primary derived-director set: Vt4/Vt5/Vt6/
// Vt7 and Vt3 all chain through its ctor 0x710004e2f4. Size 0xA0, proven by
// the sole plain allocation site 0x71006f108 (new 0xA0).
namespace gear
{
    class RaceDirectorVt2 : public RaceDirector
    {
        public:
            void* mCtxPtr90;   //0x90 — race-context object selected at ctor:
                // vcall slot 0xe8 on [this+0x58] yields an index, helper
                // 0x7100024e70 returns RaceInfo container element
                // ([ri+0x1b0] -> {count@0x60, ptrs@0x68}, RTTI-checked);
                // NOT a new allocation (ctor 0x4e338)
            uint16_t mU98;     //0x98 — ctor zero; reset by slot 0x100 (0x4e354)
            uint8_t mU9a;      //0x9A — ctor zero; same reset
            // NO explicit tail pad: the derived directors (Vt3-Vt7) start
            // their first field at 0x9C, i.e. INSIDE this class's tail
            // padding (Itanium tail-padding reuse; allocation is 0xA0)
    };
}
