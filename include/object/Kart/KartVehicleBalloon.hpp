#pragma once

#include <cstdint>

// KartVehicleBalloon — size 0xAB8, proven by operator new(0xAB8) in the
// KartVehicle init (v400 0x71001703f4, stored at KartVehicle+0x70; ctor
// 0x71001142e4 receives the KartVehicle*). PROVISIONAL: name mirrors
// KartVehicle::mKartBalloon (balloon/battle item object).
namespace object
{
    struct KartVehicle; // KartVehicle.hpp

    struct KartVehicleBalloon
    {
        uint8_t pad_00[8]; // 0x00 — vtable ptr (global 0x12fd100+0x10)
        uint32_t u08; //0x08 — ctor zero
        KartVehicle* kart_vehicle; //0x10 — ctor arg
        uint8_t pad_018[0x70]; //0x18 - 0x87
        // Five 0x200-stride slots (loop x8 = 0,0x200,..,0x800; ctor 0x114324-
        // 0x1143a0). Within each slot base +N*0x200 the ctor touches:
        //   +0x88/+0x98/+0xA8 u64 zeros; twelve {void* -> global 0x12fb038+0x10,
        //   u64 zero, u8 zero} entries at +0x108/0x120/0x138/0x150/0x168/0x180/
        //   0x198/0x1B0/0x1C8/0x1E0/0x1F8/0x210 (stride 0x18)
        uint8_t mSlots[0x9A0]; //0x88 - 0xA27 — five 0x200-stride windows
            // (loop base x8 = 0,0x200,..,0x800); window N content at
            // N*0x200+0x88 .. +0x220
        uint64_t s_a28; //0xA28 — ctor sets -1
        void* sub_a30; //0xA30 — operator new(0x70) constructed via 0x7c55cc(-1)
            // (0x11441c-0x114438)
        uint8_t block_a38[0x30]; //0xA38 — 0x30-byte memcpy from the shared
            // runtime-init default block (see KartChassis blocks_60 note)
        uint8_t cells_a68[0xc]; //0xA68 — global pair 0x12fb148
        uint8_t cells_a74[0xc]; //0xA74 — same
        uint8_t cells_a80[0xc]; //0xA80 — same
        uint32_t m8c; //0xA8C — ctor zero (unaligned u64 store 0xa8c)
        uint32_t m90; //0xA90
        uint32_t m94; //0xA94 — ctor zero (unaligned u64 store 0xa94)
        uint32_t m98; //0xA98
        uint32_t m9c; //0xA9C — ctor zero (unaligned u64 store 0xa9c)
        uint32_t ma0; //0xAA0
        uint8_t baa8; //0xAA8 — ctor zero
        uint8_t pad_aa9[3]; //0xAA9
        uint32_t s_aac; //0xAAC — ctor sets -1 (unaligned u64 store 0xaac)
        uint32_t mab0; //0xAB0 — upper half of the -1 store
        uint32_t s_ab4; //0xAB4 — ctor sets -1; 0xAB4+4 = 0xAB8
    };
}
