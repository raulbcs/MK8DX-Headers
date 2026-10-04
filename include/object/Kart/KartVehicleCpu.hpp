#pragma once

#include <cstdint>

#include "KartVehicleControl.hpp"

namespace object
{
    // Size 0x90: operator new(0x90) in the KartVehicle ctor (v400 0x71001701b4,
    // stored at KartVehicle+0x18; ctor 0x7100179f5c). Evidenced inside the pad:
    // +0x74 u64=0, +0x77 u8 and +0x78 u32 reset-zeroed (0x179fe0), +0x7C u8=1,
    // +0x80 f32=0.25f.
    class KartVehicleCpu : public KartVehicleControl
	{
		public:
			uint8_t mPad70[0x20];
	};
}