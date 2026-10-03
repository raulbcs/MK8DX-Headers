#pragma once

#include <cstdint>

// The real KartVehicleMove layout on Switch is kart/KartVehicleMove.hpp:
// the object lives at KartVehicle+0x28 and extends past 0x22a8
// (boost slot +0x118, flags +0x1680, reset float pairs +0x2288..+0x22a8).

namespace object
{
    /*
     * DEPRECATED name kept for the fishguy include graph
     * (KartVehicleBody/KartVehicleTrick include this header).
     *
     * The offsets this header used to carry (base 0xEC, mSpeed 0x37C,
     * total 0x5F8) were transcribed from the Wii U 32-bit build and do NOT
     * apply to the 64-bit binary. No Switch offset in this class is
     * verified — use ::KartVehicleMove (kart/KartVehicleMove.hpp).
     */
    class KartVehicleMove
    {
        public:
            void SetMatrix(/* gear::MtxT const&, sead::Vector3<float> */);
            void SetMatrix();

            KartVehicleMove();
    };
}  // namespace object
