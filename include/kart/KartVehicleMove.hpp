#pragma once

#include <cstdint>

// KartVehicleMove (64-bit). Size 0x5F8: operator new(0x5F8) in the
// KartVehicle ctor (v400 0x71001701e4, stored at KartVehicle+0x28; ctor
// 0x71001812b4). PROVISIONAL: name has no MethodTree string.
//
// MISATTRIBUTED FIELDS: earlier revisions declared fields at +0x1680 (flag
// bitfield) and +0x2288/+0x2298 (float pairs, "reset helper") — those lie
// BEYOND the proven 0x5F8 allocation and belong to a different, still
// unnamed class (do not re-add without a new allocation-size proof).
struct KartVehicleMove
{
    uint8_t pad_000[8]; // 0x00
    void* boost_solver; //0x08 — subobject pointer ("KartBoostSolver"): floats at
        // +0x30 (speed, KartDirector_calc_position.cpp:126) and deeper reads
        // (FUN_7100173234 / FUN_710017324c)
    uint8_t pad_010[0x20]; // 0x10
    float speed_30; //0x30 — compared against sKartSpeedThreshold via the +0x8
        // subobject (KartDirector_calc_position.cpp)
    uint8_t pad_034[0xec]; // 0x34
    void* boost_slot; //0x118 — BoostSlot (kart/BoostSlot.hpp)
    void* ptr_120; //0x120 — pointer: FUN_7100174ec8 derefs it and reads an int
        // at target+0x24
    uint8_t pad_128[0x4d0]; // 0x128 - 0x5F7
};
