#pragma once

#include <cstdint>

#include "KartRigidBody.hpp"

namespace object
{
    class KartVehicleBody : public KartRigidBody
	{
		public:
			uint8_t mPadEC[0x4c]; //0xEC - 0x137
			void* mDriftStateRef; //0x138 — object holding floats at +0x10..0x30
				// (BodyVt18 family: BodyVt18_71001a43c8 copies them into +0xc0/+0x208)
			uint8_t mPad140[0xc8]; //0x140 - 0x207
			float mF208; //0x208 — written by BodyVt18_71001a43c8
			uint8_t mPad20C[0x34]; //0x20C - 0x23F
			uint32_t mU240; //0x240 — BodyVt18: mU240 += mU244
			uint32_t mU244; //0x244 — added into mU240 each BodyVt18 call
	};
}