#pragma once

#include <cstdint>

#include "object/Kart/KartRigidBody.hpp"

// KartVehicleMove — size 0x5F8, proven by operator new(0x5F8) in the
// KartVehicle ctor (v400 0x71001701e4, stored at KartVehicle+0x28). Derives
// from KartRigidBody (ctor 0x71001812b4 calls 0x710014ddb4 first) — NOT a
// standalone struct. Name CONFIRMED by the recorder channel string "RecorderKartVehicleMove"
// (rodata 0xee6002).
//
// MISATTRIBUTED FIELDS: earlier revisions declared fields at +0x1680 (flag
// bitfield) and +0x2288/+0x2298 (float pairs, "reset helper") — those lie
// BEYOND the proven 0x5F8 allocation and belong to a different, still
// unnamed class (do not re-add without a new allocation-size proof).
namespace object { struct KartVehicle; } // object/Kart/KartVehicle.hpp

struct KartVehicleMove : public object::KartRigidBody
{
    void* static_table_e0; //0xE0 — ctor overwrites with global+0x40 pointer
        // (0x12fd668+0x40; same pattern as KartVehicleBody+0xE0)
    uint8_t pad_e8[0x10]; //0xE8 - 0xF7
    object::KartVehicle* kart_vehicle; //0xF8 — ctor arg (0x1812d0)
    uint8_t pad_100[8]; //0x100
    uint8_t pad_108[0x20]; //0x108 - 0x127 — ctor zeroes
    float f128[2]; //0x128 — ctor sets {1.0f, 1.0f}
    uint8_t pad_130[8]; //0x130
    float f138; //0x138 — ctor sets 1.0f
    uint8_t pad13c[4]; //0x13C
    uint8_t zero_140[0xd0]; //0x140 - 0x20F — memset 0
    uint8_t flag210; //0x210 — ctor sets 1
    uint8_t pad_211[5]; //0x211 - 0x215 — ctor zeroes
    uint8_t course_flag216; //0x216 — 0 on course IDs 0x61/0x5E, else 1 (ctor 0x181520)
    uint8_t course_flag217; //0x217 — 1 on course 0x6E (0x18156c)
    uint8_t course_flag218; //0x218 — 1 on course 0x71 (0x181584)
    uint8_t pad_219; //0x219
    uint16_t course_flag21a; //0x21A — set to 0x101 on course 0x65 (0x181558)
    uint8_t course_flag21b; //0x21B — 1 on course 0x71 (0x18158c)
    uint8_t pad_21c[3]; //0x21C
    uint8_t zero_220[0x7c]; //0x220 - 0x29B — ctor zeroes
    uint8_t block_29c[0x30]; //0x29C — 0x30-byte memcpy from the shared default
        // block (same source as KartChassis). Source block: GOT cell 0x12fd108 -> bss 0x7101328d28, a 0x30-byte default block populated by static init before any kart exists (not a rodata constant).
    uint8_t block_2cc[0x30]; //0x2CC — same source
    uint8_t zero_2fc[0x8c]; //0x2FC - 0x387 — memset 0
    float f388; //0x388 — ctor sets 1.0f
    uint8_t pad_38c[0x14]; //0x38C - 0x39F
    float f3a0; //0x3A0 — ctor sets 1.0f
    uint8_t pad_3a4[0x10]; //0x3A4 - 0x3B3
    float f3b8; //0x3B8 — ctor sets 0.75f (0x3F400000)
    uint8_t pad_3bc[0x34]; //0x3BC - 0x3EF (ctor zeroes; +0x3EC u8=0, +0x3ED u8=1)
    uint8_t zero_3f0[0x4c]; //0x3F0 - 0x43B — memset 0
    float f43c[30]; //0x43C..0x4B3 — ctor sets all thirty to 1.0f
        // (fifteen 8-byte {1.0, 1.0} pairs, 0x181458-0x1814d0)
    uint8_t zero_4b4[0x84]; //0x4B4 - 0x537 — memset 0
    float f538; //0x538 — ctor sets 1.0f
    uint8_t zero_53c[0x60]; //0x53C - 0x59B — memset 0 (+0x590/+0x594 re-zeroed)
    float f59c; //0x59C — ctor sets 1.0f
    uint8_t zero_5a0[0x54]; //0x5A0 - 0x5F3 — memset 0
    float f5f4; //0x5F4 — ctor sets 0.1f (last field of the 0x5F8 object)
};
