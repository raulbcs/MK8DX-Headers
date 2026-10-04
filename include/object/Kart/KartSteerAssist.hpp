#pragma once

#include <cstdint>

namespace object
{
    // Size 0x120: operator new(0x120) in the KartVehicle ctor (v400
    // 0x710017025c), allocated only when KartVehicle+0xD0 mIsMaster != 0 (else
    // nullptr at KartVehicle+0xA0). Ctor 0x71001502a8; evidenced: +0xC0 stores
    // the KartVehicle*, +0xC8 the KartVehicleMove*.
    class KartSteerAssist
	{
		public:
			uint8_t pad_00[0x120];
	};
}