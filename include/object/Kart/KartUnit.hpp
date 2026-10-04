#pragma once

#include <cstdint>

// KartUnit — the per-driver kart at runtime. Target struct of the wrapper
// accessors `*(KartParameter+0x8) -> KartUnit` (cluster 0x14c284-0x14cd40;
// owner = object::KartParameter at KartVehicle+0x78) and of the stat calc
// FUN_710014b6d0. Holds live wheel/state fields with null-fallback defaults
// (1.0/23.0/10.0/2.0). PROVISIONAL: only "RecorderKartUnit" exists as a
// string in the binary; the recorder likely keeps a reference to this
// object. Offsets validated byte-exact by the mk8dx-400 check.
namespace object
{
    struct KartVehicle; // object/Kart/KartVehicle.hpp
    struct KartUnit
    {
        uint8_t pad_000[8]; // 0x00
        KartVehicle* kart_vehicle; //0x08 — back-pointer to the KartVehicle that
            // owns this unit through KartParameter (FUN_710012a30c reads its
            // mKartStatusBits +0x1cc from here)
        uint8_t pad_010[0x14]; // 0x10
        uint32_t mode_24; //0x24 — compared ==1 / ==2 / ==3 (isKartUnitField24Eq{1,2,3};
                          // FUN_710014c2cc: ==1 || (mode_28 == 3))
        uint32_t mode_28; //0x28 — compared ==2 and ==3 (isKartUnitField28Eq2 / FUN_710014c304)
        uint8_t pad_02c[0x44]; // 0x2c
        uint32_t state_block[9]; //0x70..0x90 — contiguous u32 state snapshot:
            // FUN_7100164614 copies all 9 to stack in one block (0x164ed4-0x164f1c).
            // v305-era lead: +0x78 = control bitfield (idle/drift/boost/airborne),
            // +0x7c = adjacent gate bits — bit map NOT yet confirmed in v400.
        uint8_t pad_094[0x138]; // 0x94
        uint32_t status_1cc; //0x1cc — RMW'd with ~0xc000 and 0x40000|0x4000 masks
            // in FUN_7100164614 (0x164bcc/0x164a28); mirrors the KartVehicle+0x1cc
            // bit pattern (bits 14/21)
        uint8_t pad_1d0[0xabc]; // 0x1d0

        uint32_t wheel_flag_c8c; //0xc8c — read as int, ==1 selects the PTR_DAT_71012f5148 table
            // (getKartUnitWheelFlagC8cVec_710014c82c; table[sel] has NO index clamp)
        uint32_t wheel_flag_c90; //0xc90 — read as int, ==1 table-select flag like c8c
            // (getKartUnitWheelFC90_710014c540; getKartUnitWheelFC90Vec_710014c8a0)
        uint8_t pad_c94[2]; // 0xc94
        uint8_t flag_c96; //0xc96 — bool (isKartUnitFlagC96)
        uint8_t pad_c97[5]; // 0xc97
        uint8_t flag_c9c; //0xc9c — bool (FUN_710014c3a8, sel bit0 = 0)
        uint8_t flag_c9d; //0xc9d — bool (FUN_710014c3a8, sel bit0 = 1)
        uint8_t pad_c9e[0xa]; // 0xc9e
        uint8_t vec_ca8[2][12]; //0xca8 — two 12-byte entries (FUN_710014cbac, sel = arg & 1)

        float f_cc0; //0xcc0 — default 0.0
        float f_cc4; //0xcc4 — default 0.0
        float f_cc8; //0xcc8 — default 1.0
        float f_ccc; //0xccc — default 1.0
        uint8_t unk_cd0[0x24]; //0xcd0..0xcf3 — three 12-byte in-struct cells
            // (getters 710014cbf0/cc0c/cbd4 return ku+0xcd0/0xcdc/0xce8; nothing
            // evidences stored pointers, so no void* typing)
        float wheel_stance_base; //0xcf4 — wheel stance base (deg)
        float f_cf8; //0xcf8 — default 10.0
        uint8_t pad_cfc[0x30]; // 0xcfc
        uint8_t unk_d2c[0x18]; //0xd2c..0xd43 — two 12-byte in-struct cells
            // (getters 710014c55c/c578 return ku+0xd2c/0xd38; pointer typing unevidenced)

        float wheel_stats[16]; //0xd44..0xd80 — per-wheel stats (getters d44..d80).
            // Defaults when KartUnit is null: idx 0,1,2,9 -> 0.0; idx 3 -> 23.0;
            // idx 4..8, 11, 12, 14, 15 -> 1.0 (idx 10, 13 never read)
        uint8_t wheel_vecs_a[12][12]; //0xd84 — 12 x 12-byte entries (FUN_710014c914/c94c, idx = w1 + w2*3)
        uint8_t wheel_vecs_b[6][12]; //0xe14 — 6 x 12-byte entries (FUN_710014c988/c9b8)
        uint8_t pad_e5c[8]; // 0xe5c
        int32_t s32_e64; //0xe64
        int32_t s32_e68; //0xe68
        uint8_t pad_e6c[0x18]; // 0xe6c
        uint8_t vecs_e84[4][0x18]; //0xe84 — 4 entries, stride 0x18 (FUN_710014ca24/ca40/c9ec/ca08)
        float wheel_scale_ee4; //0xee4 — default 1.0
        float wheel_f_ee8; //0xee8 — default 1.0
        uint8_t vec_eec[3][12]; //0xeec — 3 x 12-byte entries (turn rate = [0], FUN_710014caec/ca08→[1]/[2])
        uint8_t vec_f10[4][12]; //0xf10 — 4 x 12-byte entries, idx clamped < 4
            // (getKartUnitVecF10_710014c66c; At2 variant reads idx+2, c69c)
        uint8_t vec_f40[4][12]; //0xf40 — 4 x 12-byte entries, idx clamped < 4
            // (getKartUnitVecF40_710014c6d0; At2 variant, c700)
        uint8_t vec_f70[2][12]; //0xf70 — 2 x 12-byte entries, idx clamped < 2
            // (getKartUnitVecF70_710014cb54)
        float arr_f88[2]; //0xf88 — f32 pair, idx clamped to {0,1}, default 0
        float f_f90; //0xf90 — default 10.0
        uint8_t pad_f94[0xc]; // 0xf94
        float f_fa0; //0xfa0 — default 2.0
        float f_fa4; //0xfa4 — default 0.0
        float f_fa8; //0xfa8 — default 1.0
        uint8_t pad_fac[2]; // 0xfac
        uint8_t flag_fae; //0xfae — bool
        uint8_t flag_faf; //0xfaf — bool
        uint8_t flag_fb0; //0xfb0 — bool
        uint8_t flag_fb1; //0xfb1 — bool (FUN_710014c454: fb1 && !fae)
        uint8_t flag_fb2; //0xfb2 — bool
        uint8_t flag_fb3; //0xfb3 — bool
        uint8_t flag_fb4; //0xfb4 — bool
        uint8_t flag_fb5; //0xfb5 — bool
        uint8_t flag_fb6; //0xfb6 — bool
    };
}  // namespace object
