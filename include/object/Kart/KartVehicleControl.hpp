#pragma once

#include <cstdint>

// KartVehicleControl — size 0x70, proven by operator new(0x70) in the
// KartVehicle ctor (v400 0x7100170194, stored at KartVehicle+0x10; ctor
// 0x7100179660). Fields below come from that ctor + reset 0x71001796e4.
namespace object
{
    class KartVehicleControl
	{
		public:
			uint8_t mPad00[0x10]; //0x00 - 0x0F — vtable ptr at +0x00, u32=0 at +0x04
			void* mOwnerKartVehicle; //0x10 — ctor 0x17966c stores the KartVehicle*;
				// Net method 0x19026c reads owner mKartStatusBits through it
			uint8_t mFlag18; //0x18 — enable/level flag written by
				// setKartVehicleLevelMode (FUN_7100172e90), ctor-zeroed
			uint8_t mPad19[3]; //0x19
			uint32_t m1c; //0x1C — ctor zero (unaligned u64 store 0x1c)
			uint32_t m20; //0x20 — upper half
			float mF24[2]; //0x24 — ctor/reset set {1.0, 1.0} (also reset 0x7100179f44)
			float mF2c; //0x2C — 1.0
			uint64_t mU30; //0x30 — copied from the sCell12fb148 global pair
			uint32_t mU38; //0x38
			uint32_t m3c; //0x3C — same global pair (unaligned u64 store 0x3c)
			uint32_t m40; //0x40 — upper half
			uint32_t mU44; //0x44
			uint16_t mU48; //0x48 — ctor zero
			float mF4c; //0x4C — 52.0f (reset 0x179738)
			float mF50; //0x50 — 76.0f
			float mF54; //0x54 — 1.0f
			float mF58; //0x58 — 1.0f
			float mF5c; //0x5C — 25.0f
			void* mOwned60; //0x60 — owned subobject, destroyed via 0x71001470ec
			uint8_t mBool68; //0x68 — result of a call to 0x710013d578
			uint8_t mPad69[3]; //0x69
			uint32_t mU6c; //0x6C — zeroed by both the Cpu and Net ctors
	};
}
