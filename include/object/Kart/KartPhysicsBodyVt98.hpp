#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // PROVISIONAL vtable-anchored name ("Vt98"). Rigid body whose head
    // slots carry RigidVtableSwapInit_71000229f4 / RigidVt_0x18_7100022a2c
    // (a vtable-swap-init body). Vtable .data 0x11ae6b0 (GOT cell
    // 0x12fb3d8), ctor 0x710020520 — calls the root ctor 0x116a4 directly.
    // Size 0x450 (allocation 0x450 at 0x238a8, ctor call 0x238c8).
    class KartPhysicsBodyVt98 : public KartPhysicsBody
    {
    public:
        char mOwn328[0x128];   // 0x328 — own-field region (map pending)
    };
}
