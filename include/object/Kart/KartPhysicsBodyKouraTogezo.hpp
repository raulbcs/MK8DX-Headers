#pragma once

#include "KartPhysicsBodyKoura.hpp"

namespace object
{
    // TogezoBomb (spiked shell bomb) physics body. Vtable .data 0x11b0898
    // (GOT cell 0x12fc7c0), ctor 0x71002c5cc — calls the Koura ctor
    // 0x30d50. Size 0x4d8 (allocation 0x4d8 at 0x30b10, ctor call 0x30b30).
    // Slot names carry ItemTogezoBomb/TogezoBomb evidence.
    //
    // Slot comparison vs Koura (n=128 vs 126): the extra slots 0x3f0/
    // 0x3f8 (0x71002f140/0x71002fd14) are the bomb-only overrides; ~20
    // slots 0x2c8-0x3e8 are Togezo-specific state machines (0x2cdxx-
    // 0x2fdxx region), while 0x340/0x348/0x3c0/0x3c8/0x3d0 share the
    // Koura values (inherited behavior).
    class KartPhysicsBodyKouraTogezo : public KartPhysicsBodyKoura
    {
    public:
    };
}
