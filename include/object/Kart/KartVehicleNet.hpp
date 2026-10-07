#pragma once

#include <cstdint>

#include "KartVehicleControl.hpp"

// KartVehicleNet — size 0x42D8, proven by operator new(0x42D8) in the
// KartVehicle ctor (v400 0x71001701cc, stored at KartVehicle+0x20; ctor
// 0x710018d664 calls the 0x70-byte Control base first). The old
// pad_5C[0x4268] was off by 0x14: 0x5C is inside the base class.
namespace object
{
    class KartVehicleNet : public KartVehicleControl
	{
		public:
			uint8_t mEntries[50][0x64]; //0x70 — 50 entries, stride 0x64 (ctor loop
				// 0x18d6a0-0x18d6fc inits through +0x13F8 = 0x70 + 50*0x64). Per
				// entry: +0x00 u32=0, +0x04 =-1, +0x08/+0x28 f32=1.0f, +0x58/+0x5A
				// u16 from a global, +0x5C u32=0, rest zeroed
			uint8_t mPad13F8[8]; //0x13F8 — unproven padding
			uint32_t mFlags1400; //0x1400 — bitfield; bits 9/11 tested by the
				// accessor at 0x190288-0x1902a4
			int32_t mS1404; //0x1404 — ctor sets -1
			float mF1408; //0x1408 — ctor sets 1.0f
			uint8_t mPad140C[0x2EB4]; //0x140C - 0x42BF — unproven padding
			uint32_t mCounters42C0[3]; //0x42C0..0x42CA — incremented by the
				// accessor family at 0x190278-0x1902b0
			uint8_t mPad42CC[0xc]; //0x42CC - 0x42D7 — unproven padding
	};
}
