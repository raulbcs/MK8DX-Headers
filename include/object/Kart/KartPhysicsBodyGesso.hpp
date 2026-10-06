#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // Gesso (ink) physics body. Vtable .data 0x11af7f0 (GOT cell
    // 0x12fb5d0), ctor 0x710027098 — calls the root ctor 0x116a4 directly.
    // Size 0x4c8 (allocation 0x4c8 at 0x29bcc, ctor call 0x29bec). Slot
    // names carry ItemGesso evidence.
    class KartPhysicsBodyGesso : public KartPhysicsBody
    {
    public:
        char mOwn328[0x1a0];   // 0x328 — own-field region (map pending)
    };
}
