#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // BomheiBomb (bomb) physics body. Vtable .data 0x11ae100 (GOT cell
    // 0x12fb2d0), ctor 0x71001bfbc — calls the root ctor 0x116a4 directly.
    // Size 0x3e8 (allocation 0x3e8 at 0x1fb18, ctor call 0x1fb2c). Slot 0
    // is PhysicsBodySingletonGetter_710001e258 (a lazily-guarded static
    // singleton accessor).
    class KartPhysicsBodyBomhei : public KartPhysicsBody
    {
    public:
        char mOwn328[0xc0];    // 0x328 — own-field region (map pending)
    };
}
