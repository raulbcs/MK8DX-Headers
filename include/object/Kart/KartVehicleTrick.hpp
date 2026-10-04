#pragma once

#include <cstdint>

#include "KartRigidBody.hpp"

// KartVehicleTrick — size 0x1A0, proven by operator new(0x1A0) in the
// KartVehicle ctor (v400 0x7100170200, stored at KartVehicle+0x30; ctor
// 0x7100195768 calls the KartRigidBody base 0x710014ddb4).
namespace object
{
    struct KartVehicle; // KartVehicle.hpp

    class KartVehicleTrick : public KartRigidBody
	{
		public:
			uint8_t mPadEC[0xc]; //0xEC - 0xF7
			KartVehicle* mOwnerKartVehicle; //0xF8 — ctor arg (0x195768-0x1957f8)
			float mF100[3]; //0x100..0x10B — ctor sets all three to 1.0f
			uint8_t mPad10C[0x94]; //0x10C - 0x19F — tail zeroed in ctor blocks
				// (+0x10C/+0x114/... u64 zeros, +0x14C=1.0f, memset 0x150..0x19B)
	};
}
