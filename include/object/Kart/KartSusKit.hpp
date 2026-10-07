#pragma once

#include <cstdint>

// KartSusKit — size 0x128, proven by operator new(0x128) in the KartVehicle
// init (v400 0x71001701e4 region, stored at KartVehicle+0x68; ctor 0x710015dd9c
// receives the KartVehicle*). Name mirrors KartVehicle::mSusKit (field-mirror evidence)
// (suspension kit). Runtime cross-evidence: FUN_7100174f7c reads a float at
// +0xD0 (>= 1.0f gate); FUN_7100173204 calls into it and sets
// KartVehicle+0x1D9.
namespace object
{
    struct KartVehicle; // KartVehicle.hpp

    struct KartSusKit
    {
        uint8_t pad_00[8]; // 0x00 — vtable ptr (global 0x12fd550+0x10)
        KartVehicle* kart_vehicle; //0x08 — ctor arg
        uint8_t pad_010[0x68]; //0x10 - 0x77 — ctor zeroes
        float f78[2]; //0x78 — ctor sets {-4.0f, -4.0f}
        uint8_t pad_080[0x30]; //0x80 - 0xAF — ctor zeroes
        void* sub_b0; //0xB0 — operator new(0x70) constructed via 0x7c55cc with
            // KartVehicle+0xA8 (mPlayerID) (ctor 0x15de58-0x15de68)
        int32_t s_b8; //0xB8 — ctor sets -1
        float f_bc; //0xBC — ctor sets -4.0f
        uint8_t pad_0c0[0x10]; //0xC0 - 0xCF — ctor zeroes
        uint32_t u_d0[0x11]; //0xD0..0x113 — ctor ladder from globals
            // 0x12fce50[0] and 0x12fce10[0]: 0xD0=0, then alternating g1/g2
            // (0xD4..0x110), 0x114..0x117 zero
        float f118; //0x118 — course-conditional float from tables 0xf20860/0x68/
            // 0x870 (index 4 when course ID == 0x46, else 0) (0x15de84-0x15deac)
        uint8_t pad_11c[0xc]; //0x11C - 0x127
    };
}
