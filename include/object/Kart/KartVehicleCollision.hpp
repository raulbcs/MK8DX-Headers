#pragma once

#include <cstdint>

// KartVehicleCollision — size 0x2D0, proven by operator new(0x2D0) in the
// KartVehicle init (v400 0x7100170438, stored at KartVehicle+0x48; ctor
// 0x7100139838 receives a stack config struct built from KartUnit getters
// and SusKit+0xA8). Name mirrors KartVehicle::mKartCollision (field-mirror evidence).
namespace object
{
    struct KartVehicleCollision
    {
        uint8_t pad_00[8]; // 0x00 — vtable ptr (global 0x12fd308+0x10)
        void* param_08; //0x08 — ctor copies [x1] (init-struct pointer)
        void* ptr_10; //0x10 — ctor copies [[param]+0x58]
        uint32_t u18; //0x18 — from param+0x08
        uint32_t u1c; //0x1C — from param+0x0C
        uint32_t u20; //0x20 — from param+0x10
        float f24; //0x24 — ctor sets 1.0f
        float f28; //0x28 — ctor sets [param+0x18] * 0.5
        uint8_t zero_2c[0x14]; //0x2C - 0x3F — ctor zeroes
        void* ptr_40; //0x40 — factory result 0x7c3698(global 0x12fb148, param_08,
            // 1.0f), set at ctor end, skipped when (managerBits|2)==7 (0x139aa0)
        uint8_t zero_44[0x24]; //0x44 - 0x67 — ctor zeroes
        uint32_t u68[12]; //0x68..0x97 — twelve u32s copied from global 0x12fb188
            // (ctor 0x1398d8-0x139928)
        uint16_t u98; //0x98 — ctor zero
        uint8_t pad_9a[2]; //0x9A — unproven padding
        uint8_t cells_9c[0xc]; //0x9C — global pair 0x12fb148 (u64+u32)
        uint8_t cells_a8[0xc]; //0xA8 — same global pair
        uint8_t cells_b4[0xc]; //0xB4 — global pair 0x12fb168
        uint32_t uc0; //0xC0 — ctor zero
        uint8_t cells_c4[0xc]; //0xC4 — global pair 0x12fb148
        uint32_t ud0; //0xD0 — ctor zero
        uint8_t bd8; //0xD8 — ctor zero
        uint8_t zero_dc[0x24]; //0xDC - 0xFF
        uint8_t cells_100[0xc]; //0x100 — global pair
        uint8_t cells_10c[0xc]; //0x10C — global pair
        uint8_t cells_118[0xc]; //0x118 — global pair
        uint8_t cells_124[0xc]; //0x124 — global pair
        uint32_t u130; //0x130 — ctor zero
        uint8_t cells_138[0xc]; //0x138 — global pair
        uint8_t cells_144[0xc]; //0x144 — global pair
        uint8_t cells_150[0xc]; //0x150 — global pair
        uint8_t zero_15c[0x54]; //0x15C - 0x1AF — ctor zeroes (byte granular)
        uint8_t sub_1b0[0x60]; //0x1B0 — subobject via ctor 0x60b918(arg 10)
            // (0x139a68)
        uint8_t sub_210[0x60]; //0x210 — same ctor (0x139a80)
        uint8_t sub_270[0x60]; //0x270 — same ctor (0x139a98); 0x270+0x60 = 0x2D0
    };
}
