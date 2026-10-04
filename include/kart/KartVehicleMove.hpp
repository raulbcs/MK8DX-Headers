#pragma once

#include <cstdint>

// KartVehicleMove (64-bit, partial; real object ~0x5f8B+ — the reset helper
// touches +0x22a8, so the object is at least 0x22ac bytes). PROVISIONAL:
// name has no MethodTree string.
struct KartVehicleMove
{
    uint8_t pad_000[0x118]; // 0x00
    void* boost_slot; //0x118 — BoostSlot (kart/BoostSlot.hpp)
    uint8_t pad_120[0x1560]; // 0x120
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
