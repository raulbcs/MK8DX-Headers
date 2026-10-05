#pragma once

#include <cstdint>

// KartVehicleDrift — drift state object (name from the recorder channel
// string "RecorderKartVehicleDrift", rodata 0xee602a). Held through the
// POINTER at KartChassis+0x110 (getters 0x71001420e4/21b4/23d8 load
// *(void**)(chassis+0x110)); allocated at runtime (no ctor/new site
// found — size is >= 0x110, exact value unproven). Accessor family:
// 0x710017b9xx-0x710017bfb4 + calc 0x710017b578.
namespace object
{
    struct KartVehicle;      // KartVehicle.hpp
    struct KartVehicleMove;  // kart/KartVehicleMove.hpp
    struct KartVehicleBody;  // KartVehicleBody.hpp

    struct KartVehicleDrift
    {
        uint8_t pad_00[8]; // 0x00 — vtable/untouched head
        KartVehicle* kart_vehicle; //0x08 — read by 0x17bab4/0x17bd6c/0x17bcc4
            // (deref +0x28 -> KartVehicleMove, +0x38 -> KartVehicleBody)
        uint32_t state_10; //0x10 — drift state: 0 none, 1 (0x17bc84), 2 wheel/
            // pre-drift (0x17bc48), 4 = drift LEFT (0x17bae4), 5 = drift RIGHT
            // (0x17baf4), 6 glide+drift (0x17bc28), 7 (0x17bc38).
            // drifting family = (state|3)==7; glide = (state|1)==5.
            // Setter 0x710017bd14: target = (arg&1)?5:4
        uint8_t pad_014[0x10]; //0x14
        float f24; //0x24 — scaled by a KartUnit wheel stat (0x17c0f8/0x17c154)
        float f28; //0x28
        float f2c; //0x2C — accumulates rodata [0xed50a5c] per frame, resets to 1.5625f
        uint8_t pad_030[8]; //0x30
        uint64_t zero_38; //0x38 — zeroed each calc (0x17c180)
        uint8_t pad_040[8]; //0x40
        float f48; //0x48 — steer-related, clamped by rodata [0xed50c4c]
        uint8_t pad_04c[8]; //0x4C
        int32_t s54; //0x54 — zeroed in calc
        float f58; //0x58 — zeroed on drift-state change; ratio num in 0x17b9e4
        float f5c; //0x5C — ratio denominator (|f5c|)
        uint8_t pad_060[4]; //0x60
        float f64; //0x64 — threshold vs KartVehicleMove+0x380 (0x17bab4)
        uint8_t pad_068[4]; //0x68
        float f6c; //0x6C — drift direction: -1.0 state 4, +1.0 otherwise
        float f70; //0x70 — drift charge (FUN_710017be98), zeroed on state change
        float f74; //0x74 — denominator when veh+0xD2 (mIsCpu) set
        uint8_t pad_078[8]; //0x78
        float f80; //0x80 — denominator (cpu-select path)
        uint8_t pad_084[8]; //0x84
        int32_t s8c; //0x8C — drift tier 0..3; predicates (s|3)==7 && tier==k
            // (k=1/2/3) in 0x17bb04/0x17bb40/0x17bb68; zeroed on state change
        uint8_t pad_090[4]; //0x90
        uint8_t b94; //0x94 — direction latch on drift start (state 4)
        uint8_t b95; //0x95 — direction latch (else)
        uint8_t pad_096[0x12]; //0x96
        uint32_t s9c; //0x9C — KartVehicle mPlayerID copy? (read at 0x17bdf4)
        uint8_t pad_0a0[0x1c]; //0xA0
        int32_t sbc; //0xBC — checked > 0 (FUN_710017bc94), zeroed in calc
        uint8_t fc0; //0xC0 — flag: clears itself + Body floats (+0x10c/+0x58/+0x60)
            // when [Move+0x5DC] < 1 or [Move subobj +0x201] (0x17bfb4)
        uint8_t pad_0c1[3]; //0xC1
        float fc4; //0xC4 — charge: fC4 += fC8, clamps, saturates at 1.0 (0x17bea0)
        float fc8; //0xC8 — charge increment
        float fcc; //0xCC — clamped by rodata [0xed508a8]/[0xed508ec], mirrored to
            // KartVehicleBody+0x114
        uint8_t pad_0d0[0x30]; //0xD0
        uint8_t f100; //0x100 — cleared by FUN_710017b9dc
        uint8_t b101; //0x101 — read by getter FUN_71001423d8
        uint8_t pad_102[2]; //0x102
        uint32_t s104; //0x104 — cleared by the state-change handler (0x17be84)
        uint32_t s108; //0x108 — cleared in calc 0x710017b578 (0x17b914)
        int32_t s10c; //0x10C — arg to 0x7100175f5c in the same calc
        // The calc also mirrors floats into KartVehicleBody+0x110/0x114/0x118
        // (0x17bf14-0x17bf74).
    };
}
