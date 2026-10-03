#pragma once

#include <cstdint>

// KartUnit — the per-driver kart at runtime. Target struct of the 45 wrapper
// accessors `*(owner+0x8) -> KartUnit` (cluster 0x14c284-0x14cd28) and of the
// stat calc 0x14b6d0. Holds live wheel/state fields with null-fallback
// defaults (1.0/23.0/10.0/2.0). PROVISIONAL: only "RecorderKartUnit" exists
// as a string in the binary; the recorder likely keeps a reference to this
// object. Offsets validated byte-exact by the mk8dx-400 check.
namespace object
{
    struct KartUnit
    {
        uint8_t pad_000[0x24]; // 0x00
        uint32_t mode_24; //0x24 — compared ==1 / ==2 / ==3 (isKartUnitField24Eq{1,2,3}); stat calc treats 1 specially
        uint32_t mode_28; //0x28 — compared ==2 (isKartUnitField28Eq2)
        uint8_t pad_02c[0xc60]; // 0x2c
        uint32_t wheel_flag_c8c; //0xc8c — ==1 selects the PTR_DAT_71012f5148 table
        float wheel_f_c90; //0xc90
        uint8_t pad_c94[2]; // 0xc94
        uint8_t flag_c96; //0xc96 — bool (isKartUnitFlagC96)
        uint8_t pad_c97[0x29]; // 0xc97
        float f_cc0; //0xcc0 — default 0.0
        float f_cc4; //0xcc4 — default 0.0
        float f_cc8; //0xcc8 — default 1.0
        float f_ccc; //0xccc — default 1.0
        uint8_t pad_cd0[0x24]; // 0xcd0
        float wheel_stance_base; //0xcf4 — wheel stance base (deg)
        float f_cf8; //0xcf8 — default 10.0
        uint8_t pad_cfc[0x48]; // 0xcfc
        float wheel_stats[16]; //0xd44..0xd80 — per-wheel stats (getters d44..d80; stats[3] default 23.0)
        uint8_t pad_d84[0xe0]; // 0xd84
        int32_t s32_e64; //0xe64
        int32_t s32_e68; //0xe68
        uint8_t pad_e6c[0x78]; // 0xe6c
        float wheel_scale_ee4; //0xee4 — default 1.0
        float wheel_f_ee8; //0xee8 — default 1.0
        float turn_rate[3]; //0xeec..0xef4 — vec3, default (1,1,1) (getKartUnitVecEec)
        uint8_t pad_ef8[0x90]; // 0xef8
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
        uint8_t pad_fb1; // 0xfb1
        uint8_t flag_fb2; //0xfb2 — bool
        uint8_t flag_fb3; //0xfb3 — bool
        uint8_t flag_fb4; //0xfb4 — bool
        uint8_t flag_fb5; //0xfb5 — bool
        uint8_t flag_fb6; //0xfb6 — bool
    };
}  // namespace object
