#pragma once

#include "KartPhysicsBodyKoura.hpp"

namespace object
{
    // TogezoBomb (spiked shell bomb) physics body. Vtable .data 0x11b0898
    // (GOT cell 0x12fc7c0), ctor 0x71002c5cc — calls the Koura ctor
    // 0x30d50. Size 0x4d8 (allocation 0x4d8 at 0x30b10, ctor call 0x30b30).
    // Slot names carry ItemTogezoBomb/TogezoBomb evidence.
    class KartPhysicsBodyKouraTogezo : public KartPhysicsBodyKoura
    {
    public:
        char mOwn460[0x78];    // 0x460 — own-field region (map pending)
    };
}
