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
			// Proven sub-offset map from ctor 0x71001502a8 (everything listed is
			// ctor-store evidence; unlisted bytes are unproven gaps, not semantics):
			//   0x000 vptr (vtable 0x12fd548)
			//   0x008 ptr  = new(0x70) inited via 0x7c55cc
			//   0x010 ptr  = new(0xE4) + memset 0
			//   0x018 ptr  = new(0xE4) + memset 0
			//   0x020 ptr  = new(0x24), fully zeroed
			//   0x028 u32  = ctor arg x3 load
			//   0x02c s32  = -1
			//   0x030 u64  = 0
			//   0x038 s32  = -1
			//   0x03c u64  = 0
			//   0x044 u8   = 0
			//   0x048 s32  = -1
			//   0x04c/0x050 u32 = 0
			//   0x054 u8   = 1
			//   0x058 u64  = 0
			//   0x060..0x06f = 0 (two x stores)
			//   0x070 u32  = 0
			//   0x074/0x078/0x07c u32 = u32 global at [0x12fd540]
			//   0x080 u64  = self-pointer (&this + 0x80)
			//   0x088 u32  = 8
			//   0x08c u64  = 0
			//   0x094/0x09c/0x0a4/0x0ac u64 = -1 (sentinel block)
			//   0x0b8 u64  = 0
			//   0x0c0 KartVehicle* (ctor arg x1)
			//   0x0c8 KartVehicleMove* (ctor arg x2)
			//   0x0d0 u64  = ptr loaded from [0x12fb148]
			//   0x0d8 u32  = [that ptr + 8]
			//   0x0e8/0x0ec u32 = 0
			//   0x0f0 f32  = -1.0f
			//   0x0f4..0x0fb u64 = 0
			//   0x104 u16 = 0, 0x108 u32 = 0, 0x10c u16 = 0, 0x10e u8 = 0,
			//   0x110 u32 = 0, 0x114 u8 = 0, 0x118 u32 = 0
			// Unproven gaps inside the ctor: 0x024..0x027, 0x045..0x047,
			// 0x090..0x093, 0x0fc..0x107, 0x10f, 0x11c..0x11f. The trailing call
			// to 0x15042c may initialize more; extent from factory alloc 0x120
			// at 0x710017025c.
			uint8_t pad_00[0x120]; // proven sub-offset map above (ctor 0x71001502a8); gaps listed there
	};
}