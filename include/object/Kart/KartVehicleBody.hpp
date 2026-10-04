#pragma once

#include <cstdint>

#include "KartRigidBody.hpp"

// KartVehicleBody — size 0x160, proven by operator new(0x160) in the
// KartVehicle ctor (v400 0x7100170218, stored at KartVehicle+0x38; ctor
// 0x7100178da4 calls the KartRigidBody base 0x710014ddb4). NOTE: the
// 74-slot vtable family whose impl touches +0x240 is a DIFFERENT class —
// it cannot be this one (offsets beyond 0x160 are out of bounds).
namespace object
{
    struct KartVehicle; // KartVehicle.hpp

    class KartVehicleBody : public KartRigidBody
	{
		public:
			uint8_t mPadEC[0xc]; //0xEC - 0xF7
			KartVehicle* mOwnerKartVehicle; //0xF8 — ctor arg (0x178dbc)
			float mF100; //0x100 — ctor zero
			float mF104; //0x104 — ctor sets -4.0f (0xc0800000)
			uint64_t mU108; //0x108 — ctor zero
			float mF110[3]; //0x110..0x11B — ctor/reset (0x178e84) set all to 1.0f
			uint8_t mFlag11C; //0x11C — ctor zero
			uint8_t mPad11D[3]; //0x11D
			uint64_t mU120; //0x120 — ctor zero
			uint64_t mU128; //0x128 — ctor zero (stp 0x128/0x130)
			uint64_t mU130; //0x130
			uint8_t mPad138[4]; //0x138
			float mF13C[3]; //0x13C..0x147 — ctor/reset set all to 1.0f
			uint64_t mU148; //0x148 — ctor zero
			uint64_t mU150; //0x150 — ctor zero (stp 0x150/0x158)
			uint64_t mU158; //0x158
	};
}
