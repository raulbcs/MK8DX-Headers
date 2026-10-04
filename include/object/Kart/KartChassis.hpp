#pragma once

#include <cstdint>

// KartChassis — size 0x510, proven by operator new(0x510) in the KartVehicle
// ctor (v400 0x7100170298, stored at KartVehicle+0x50; ctor 0x710011c0c4).
// PROVISIONAL: name mirrors the KartVehicle::mKartChassis field; no MethodTree
// string. Runtime cross-evidence: FUN_7100174ea8 reads a float at +0x198
// (multiplied by KartVehicle+0x118), FUN_7100174cc4 a u8 at +0x1C0, and the
// drift-state accessors (0x71001420e4/21b4/23d8, 0x710017b9xx-bcxx family)
// reach a drift-state object through the pointer at +0x110.
namespace object
{
    struct KartVehicle; // KartVehicle.hpp

    struct KartChassis
    {
        uint8_t pad_00[8]; // 0x00 — vtable ptr
        KartVehicle* kart_vehicle; //0x08 — ctor arg (0x11c100)
        uint8_t pad_010[0x28]; //0x10 — ctor zeroes (incl. the +0x10 subcomponent
            // handed to KartChassisAnim)
        uint32_t s38; //0x38 — ctor sets -1
        uint32_t s3c; //0x3C — ctor sets -1
        uint8_t pad_040[8]; //0x40
        int32_t s48; //0x48 — ctor sets -1
        uint8_t pad_04c[0xc]; //0x4C
        int32_t s58; //0x58 — ctor sets -1
        uint8_t blocks_60[5][0x30]; //0x60..0x14F — five 0x30-byte blocks each
            // copied from the static template at 0x12fd108 (ctor 0x11c160-0x11c1a0)
        float f13c[9]; //0x13C..0x15F — ctor sets all nine to 1.0f
        uint8_t flag160; //0x160 — ctor arg: KartUnit flagC9cSel (isKartUnitFlagC9cSel_710014c3a8)
        uint8_t flag161; //0x161 — ctor arg: KartUnit fb1 && !fae (isKartUnitFlagFb1AndNotFae_710014c454)
        uint8_t flag162; //0x162 — ctor arg: (KartVehicle+0xC4 == 1)
        uint8_t pad_163[9]; //0x163
        float f16c; //0x16C — ctor sets 0.2f (0x3E4C0000)
        uint32_t u170; //0x170 — ctor sets 0x4CCCCCCC
        float f174; //0x174 — ctor sets -4.0f
        uint32_t u178; //0x178 — ctor sets 0xFFFFFFFF
        uint8_t pad_17c[8]; //0x17C
        float f184[2]; //0x184 — ctor sets {1.0f, 1.0f}
        float f18c; //0x18C — ctor sets 2.0f
        uint8_t pad_190[0x20]; //0x190
        float f1b0; //0x1B0 — ctor sets 1.0f
        float f1b4; //0x1B4 — ctor sets 0.1f (0x3DCCCCCD)
        float f1b8; //0x1B8 — ctor sets 0.1f
        uint8_t pad_1bc[4]; //0x1BC
        uint8_t sub_1c0[0x28]; //0x1C0 — sub-init call 0x710016f7e4; the u8 at
            // +0x1C0 is read by FUN_7100174cc4
        uint8_t pad_1e8[0x24]; //0x1E8 — ctor zeroes through 0x20B (+0x208 u8=0,
            // zeros at 0x20C/0x214/0x21C)
        uint8_t blocks_224[2][0x30]; //0x224..0x283 — two more 0x30 template blocks
        uint8_t pad_284[0x34]; //0x284 — ctor zeroes through 0x2B7
        uint8_t pad_2b8[0x58]; //0x2B8 — ctor zeroes 0x2C0..0x2F7
        float f310[3]; //0x310 — ctor sets {1.0f, 1.0f, 1.0f}
        uint16_t u31c[2]; //0x31C — ctor sets both to 0xFFFF
        uint8_t b320; //0x320 — ctor zero
        uint8_t pad_321[3]; //0x321
        uint8_t pad_324[0x20]; //0x324 — ctor zeroes through 0x343
        uint64_t s344; //0x344 — ctor sets -1
        int32_t s34c; //0x34C — ctor sets -1
        uint8_t b350; //0x350 — ctor zero
        uint8_t pad_351[0xf]; //0x351
        int32_t s370[2]; //0x370 — ctor sets both to -1
        uint16_t u378[3]; //0x378 — ctor sets all three to 0xFFFF
        int32_t s380; //0x380 — ctor sets -1
        float f384; //0x384 — ctor sets -4.0f
        uint32_t u388; //0x388 — ctor sets 0xFFFFFFFF
        uint8_t pad_38c[8]; //0x38C
        float f394; //0x394 — ctor sets 1.0f
        uint8_t pad_398[0x10]; //0x398
        uint8_t sub_3a8[0x38]; //0x3A8 — second sub-init call 0x710016f7e4
        uint8_t pad_3e0[0xc]; //0x3E0
        uint8_t block_3ec[0x30]; //0x3EC — another 0x30 template block
        uint8_t pad_41c[0xf4]; //0x41C — 0x510 total
    };
}
