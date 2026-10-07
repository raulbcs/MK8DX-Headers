#pragma once

#include <cstdint>

// KartVehicleHeadLight — size 0x130, proven by operator new(0x130) in the
// KartVehicle init (v400 0x7100170354, stored at KartVehicle+0x60; ctor
// 0x7100140514 with args (this, ptr, flag2, flag3)). Name mirrors KartVehicle::mKartHeadLight (field-mirror evidence).
namespace object
{
    struct KartVehicleHeadLight
    {
        uint8_t pad_00[8]; // 0x00 — vtable ptr (global 0x12fd3c0+0x10)
        uint32_t flags08; //0x08 — bit0 set at init; bit1 OR'd in when the
            // 0x87e9c4 check passes (0x1405f8); bit1 tested at 0x140638
        uint32_t u0c; //0x0C — ctor zero
        void* ptr_10; //0x10 — ctor arg x1
        float f18[6]; //0x18..0x2F — ctor sets all six to 1.0f
        uint8_t pad_030[0x38]; //0x30 - 0x67 — ctor zeroes
        float f68; //0x68 — ctor sets 1.0f
        uint32_t u6c; //0x6C — ctor zero
        uint64_t u70; //0x70 — ctor zero
        float f78[2]; //0x78 — ctor sets {1.0f, 0.0f}
        uint64_t u80; //0x80 — ctor zero
        float f88[2]; //0x88 — ctor sets {1.0f, 0.0f}
        uint64_t u90; //0x90 — ctor zero
        float f98[2]; //0x98 — ctor sets {1.0f, 0.0f}
        uint64_t ua0; //0xA0 — ctor zero
        float fa8[2]; //0xA8 — ctor sets {1.0f, 0.0f}
        uint64_t ub0; //0xB0 — ctor zero
        float fb8[2]; //0xB8 — ctor sets {1.0f, 0.0f}
        uint64_t uc0; //0xC0 — ctor zero
        uint32_t uc8; //0xC8 — ctor sets (arg2 & 1) ? 2 : 0
        uint8_t pad_0cc[4]; //0xCC — unproven padding
        uint8_t zero_d0[0x48]; //0xD0 - 0x117 — ctor zeroes
        uint16_t u118[3]; //0x118/0x11A/0x11C — ctor sets all three to 0xFFFF
        uint8_t pad_11e[0x12]; //0x11E - 0x12F — unproven padding
    };
}
