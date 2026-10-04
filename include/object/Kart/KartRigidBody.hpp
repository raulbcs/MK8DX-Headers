#pragma once

#include <math/seadVector.hpp>
#include <gear/RigidBody.hpp>

namespace object
{
    class KartRigidBody : public gear::RigidBody
    {
        public:
            virtual void test();
            // KartVehicleBody's ctor (0x178da4) overwrites +0xE0 with a pointer
            // into a static table (global+0x40) — so despite the name it is a
            // pointer-sized slot in the Body subclass, not a vector.
            sead::Vector3<float> mPadE0; //0xE0 - 0xE8

            KartRigidBody();
    };
}

