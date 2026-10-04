#pragma once

#include <cstdint>

// KartVehicleMove (64-bit, partial; real object ~0x5f8B+ — the reset helper
// touches +0x22a8, so the object is at least 0x22ac bytes). PROVISIONAL:
// name has no MethodTree string.
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
        // at target+0x24 (was wrongly opaque pad)
    uint8_t pad_128[0x1558]; // 0x128
    uint32_t flags; //0x1680 — flag bitfield; orMoveFlags1680_71000b0c80 ORs into it
    uint8_t pad_1684[0xc04]; // 0x1684
    float pair_2288_a; //0x2288 — 1.0f default (resetFloatPairs2288_71000bdc24)
    uint8_t pad_228c[4]; // 0x228c
    float pair_2290_b; //0x2290 — 1.0f default
    uint32_t zero_2298; //0x2298 — zeroed by the reset helper
    uint32_t zero_229c; //0x229c — zeroed (upper half of a pair)
    uint32_t zero_22a0; //0x22a0 — zeroed (pair)
    uint32_t zero_22a8; //0x22a8 — zeroed
};
