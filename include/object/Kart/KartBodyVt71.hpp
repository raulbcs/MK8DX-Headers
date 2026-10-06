#pragma once

#include <cstdint>

#include "gear/Actor/Actor.hpp"

namespace object
{
    // PROVISIONAL vtable-anchored name ("Vt71"). Base of the kart body
    // family: 161 vtables of 71 slots sharing PrePass20_7100197798 /
    // GetCurrentSpeed_7100197c90 / CoinItemInteraction_71001981ec — the
    // per-kart+driver-combination body classes (data-parametrized variants
    // of this one base design).
    //
    // Vtable .data 0x11bb5c0 (GOT cell 0x12fd6a8), ctor 0x710019888, size
    // 0x208 (allocation 0x208 at 0x19d554). Ctor: Actor base 0x7b976c,
    // embedded member at 0x38 (ctor 0x86838c), zeros at 0x150-0x160,
    // u32 0x160 = 0. Derived variants add fields up to ~0x2b8 (observed
    // factory allocs 0x1f8..0x2b8).
    class KartBodyVt71 : public gear::Actor
    {
    public:
        char mSub38[0x118];    // 0x38 — embedded member (ctor 0x86838c);
                               // extent to next ctor write
        uint64_t mField150;    // 0x150 — zeroed on ctor
        uint64_t mField158;    // 0x158 — zeroed on ctor
        uint32_t mField160;    // 0x160 — zeroed on ctor
        char mPad164[0xa4];    // 0x164 — to end (0x208)
    };
}
