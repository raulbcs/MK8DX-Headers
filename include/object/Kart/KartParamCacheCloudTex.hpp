#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object
{
    // KartParamCacheCloudTex — named from ctor string evidence: ctor string tag 'aglclwd' + member names mBaseTextureNo/mNoiseTextureNo/mbCloudTexBlend/mCloudTexBlendRate (0xf1a080-0xf1a0f7) (was address-anchored KartParamCacheVt2ab0) (vptr 0x12f2ab0, cell 0x13151d0, n=13, site 0xa94c04, ctor 0xa94bb8).
    // Variant of the 0x63c6f8 param-cache cluster.
    class KartParamCacheCloudTex : public KartParamCache
    {
    public:
        uint8_t mPad40[0x190];  // 0x40 — unproven gap
        uint64_t mField1d0;     // 0x1d0 — ctor-written
        uint8_t mPad1d8[0x28];  // 0x1d8 — unproven gap
        uint64_t mField200;     // 0x200 — ctor-written
        uint8_t mPad208[0x10];  // 0x208 — unproven gap
        uint8_t mPad218;        // 0x218 — ctor zero
        uint8_t mPad219[0x7];   // 0x219 — unproven gap
        uint64_t mField220;     // 0x220 — ctor-written
        uint8_t mPad228[0x10];  // 0x228 — unproven gap
        uint32_t mZero238;      // 0x238 — ctor zero
        uint8_t mPad23c[0x4];   // 0x23c — unproven gap
        uint64_t mField240;     // 0x240 — ctor-written
        uint8_t mPad248[0x10];  // 0x248 — unproven gap
        uint32_t mField258;     // 0x258 — ctor-written
        uint8_t mPad25c[0x4];   // 0x25c — unproven gap
        uint64_t mField260;     // 0x260 — ctor-written
        uint8_t mPad268[0x10];  // 0x268 — unproven gap
        uint8_t mPad278;        // 0x278 — ctor zero
        uint8_t mPad279[0x7];   // 0x279 — unproven gap
        uint64_t mField280;     // 0x280 — ctor-written
        uint8_t mPad288[0x10];  // 0x288 — unproven gap
        uint32_t mZero298;      // 0x298 — ctor zero
        uint8_t mPad29c[0x4];   // 0x29c — unproven gap
        uint64_t mField2a0;     // 0x2a0 — ctor-written
        uint8_t mPad2a8[0x10];  // 0x2a8 — unproven gap
        uint32_t mField2b8;     // 0x2b8 — ctor-written
        uint8_t mPad2bc[0x4];   // 0x2bc — unproven gap
        uint64_t mField2c0;     // 0x2c0 — ctor-written
        uint8_t mPad2c8[0x10];  // 0x2c8 — unproven gap
        uint32_t mField2d8;     // 0x2d8 — ctor-written
        uint8_t mPad2dc[0x4];   // 0x2dc — unproven gap
        uint64_t mField2e0;     // 0x2e0 — ctor-written
        uint8_t mPad2e8[0x10];  // 0x2e8 — unproven gap
        uint32_t mField2f8;     // 0x2f8 — ctor-written
        uint8_t mPad2fc[0x4];   // 0x2fc — unproven gap
        uint64_t mField300;     // 0x300 — ctor-written
        uint8_t mPad308[0x10];  // 0x308 — unproven gap
        uint32_t mField318;     // 0x318 — ctor-written
        uint8_t mPad31c[0x4];   // 0x31c — unproven gap
        uint64_t mField320;     // 0x320 — ctor-written
        uint8_t mPad328[0x10];  // 0x328 — unproven gap
        uint32_t mField338;     // 0x338 — ctor-written
        uint8_t mPad33c[0x4];   // 0x33c — unproven gap
        uint64_t mField340;     // 0x340 — ctor-written
        uint8_t mPad348[0x10];  // 0x348 — unproven gap
        uint32_t mField358;     // 0x358 — ctor-written
        uint8_t mPad35c[0x4];   // 0x35c — unproven gap
        uint64_t mField360;     // 0x360 — ctor-written
        uint8_t mPad368[0x10];  // 0x368 — unproven gap
        uint32_t mField378;     // 0x378 — ctor-written
        uint8_t mPad37c[0x4];   // 0x37c — unproven gap
        uint64_t mField380;     // 0x380 — ctor-written
        uint8_t mPad388[0x10];  // 0x388 — unproven gap
        uint32_t mZero398;      // 0x398 — ctor zero
        uint8_t mPad39c[0x4];   // 0x39c — unproven gap
        uint64_t mField3a0;     // 0x3a0 — ctor-written
        uint8_t mPad3a8[0x10];  // 0x3a8 — unproven gap
        uint32_t mZero3b8;      // 0x3b8 — ctor zero
        uint8_t mPad3bc[0x4];   // 0x3bc — unproven gap
        uint64_t mField3c0;     // 0x3c0 — ctor-written
        uint8_t mPad3c8[0x10];  // 0x3c8 — unproven gap
        uint32_t mZero3d8;      // 0x3d8 — ctor zero
        uint8_t mPad3dc[0x4];   // 0x3dc — unproven gap
        uint64_t mField3e0;     // 0x3e0 — ctor-written
        uint8_t mPad3e8[0x10];  // 0x3e8 — unproven gap
        uint32_t mZero3f8;      // 0x3f8 — ctor zero
        uint8_t mPad3fc[0x4];   // 0x3fc — unproven gap
        uint64_t mField400;     // 0x400 — ctor-written
        uint8_t mPad408[0x10];  // 0x408 — unproven gap
        uint32_t mField418;     // 0x418 — ctor-written
        uint8_t mPad41c[0x4];   // 0x41c — unproven gap
        uint64_t mField420;     // 0x420 — ctor-written
        uint8_t mPad428[0x10];  // 0x428 — unproven gap
        uint32_t mField438;     // 0x438 — ctor-written
        uint8_t mPad43c[0x4];   // 0x43c — unproven gap
        uint64_t mField440;     // 0x440 — ctor-written
        uint8_t mPad448[0x10];  // 0x448 — unproven gap
        uint32_t mField458;     // 0x458 — ctor-written
        uint8_t mPad45c[0x4];   // 0x45c — unproven gap
        uint64_t mField460;     // 0x460 — ctor-written
        uint8_t mPad468[0x10];  // 0x468 — unproven gap
        uint32_t mField478;     // 0x478 — ctor-written
        uint8_t mPad47c[0x4];   // 0x47c — unproven gap
        uint64_t mField480;     // 0x480 — ctor-written
        uint8_t mPad488[0x10];  // 0x488 — unproven gap
        uint32_t mField498;     // 0x498 — ctor-written
        uint8_t mPad49c[0x4];   // 0x49c — unproven gap
        uint64_t mField4a0;     // 0x4a0 — ctor-written
        uint8_t mPad4a8[0x10];  // 0x4a8 — unproven gap
        uint32_t mField4b8;     // 0x4b8 — ctor-written
        uint8_t mPad4bc[0x4];   // 0x4bc — unproven gap
        uint64_t mField4c0;     // 0x4c0 — ctor-written
        uint8_t mPad4c8[0x10];  // 0x4c8 — unproven gap
        uint32_t mField4d8;     // 0x4d8 — ctor-written
        uint8_t mPad4dc[0x4];   // 0x4dc — unproven gap
        uint64_t mField4e0;     // 0x4e0 — ctor-written
        uint8_t mPad4e8[0x10];  // 0x4e8 — unproven gap
        uint32_t mField4f8;     // 0x4f8 — ctor-written
        uint8_t mPad4fc[0x4];   // 0x4fc — unproven gap
        uint64_t mField500;     // 0x500 — ctor-written
        uint8_t mPad508[0x10];  // 0x508 — unproven gap
        uint32_t mField518;     // 0x518 — ctor-written
        uint8_t mPad51c[0x4];   // 0x51c — unproven gap
        uint64_t mField520;     // 0x520 — ctor-written
        uint8_t mPad528[0x10];  // 0x528 — unproven gap
        uint32_t mField538;     // 0x538 — ctor-written
        uint8_t mPad53c[0x4];   // 0x53c — unproven gap
        uint64_t mField540;     // 0x540 — ctor-written
        uint8_t mPad548[0x10];  // 0x548 — unproven gap
        uint32_t mField558;     // 0x558 — ctor-written
        uint8_t mPad55c[0x4];   // 0x55c — unproven gap
        uint64_t mField560;     // 0x560 — ctor-written
        uint8_t mPad568[0x10];  // 0x568 — unproven gap
        uint32_t mField578;     // 0x578 — ctor-written
        uint8_t mPad57c[0x4];   // 0x57c — unproven gap
        uint64_t mField580;     // 0x580 — ctor-written
        uint8_t mPad588[0x10];  // 0x588 — unproven gap
        uint32_t mField598;     // 0x598 — ctor-written
        uint8_t mPad59c[0x4];   // 0x59c — unproven gap
        uint64_t mField5a0;     // 0x5a0 — ctor-written
        uint8_t mPad5a8[0x10];  // 0x5a8 — unproven gap
        uint32_t mZero5b8;      // 0x5b8 — ctor zero
        uint8_t mPad5bc[0x4];   // 0x5bc — unproven gap
        uint64_t mField5c0;     // 0x5c0 — ctor-written
        uint8_t mPad5c8[0x10];  // 0x5c8 — unproven gap
        uint32_t mField5d8;     // 0x5d8 — ctor-written
        uint8_t mPad5dc[0x4];   // 0x5dc — unproven gap
        uint64_t mField5e0;     // 0x5e0 — ctor-written
        uint8_t mPad5e8[0x10];  // 0x5e8 — unproven gap
        uint32_t mField5f8;     // 0x5f8 — ctor-written
        uint8_t mPad5fc[0x4];   // 0x5fc — unproven gap
        uint64_t mField600;     // 0x600 — ctor-written
        uint8_t mPad608[0x10];  // 0x608 — unproven gap
        uint32_t mField618;     // 0x618 — ctor-written
        uint8_t mPad61c[0x4];   // 0x61c — unproven gap
        uint64_t mField620;     // 0x620 — ctor-written
        uint8_t mPad628[0x10];  // 0x628 — unproven gap
        uint32_t mField638;     // 0x638 — ctor-written
        uint8_t mPad63c[0x4];   // 0x63c — unproven gap
        uint64_t mField640;     // 0x640 — ctor-written
        uint8_t mPad648[0x10];  // 0x648 — unproven gap
        uint32_t mZero658;      // 0x658 — ctor zero
        uint8_t mPad65c[0x4];   // 0x65c — unproven gap
        uint64_t mField660;     // 0x660 — ctor-written
        uint8_t mPad668[0x10];  // 0x668 — unproven gap
        uint64_t mField678;     // 0x678 — ctor-written
        uint32_t mField67c;     // 0x67c — ctor-written
        uint64_t mField680;     // 0x680 — ctor-written
        uint32_t mField684;     // 0x684 — ctor-written
        uint64_t mField688;     // 0x688 — ctor-written
        uint8_t mPad690[0x10];  // 0x690 — unproven gap
        uint32_t mField6a0;     // 0x6a0 — ctor-written
        uint8_t mPad6a4[0x4];   // 0x6a4 — unproven gap
        uint64_t mField6a8;     // 0x6a8 — ctor-written
        uint8_t mPad6b0[0x10];  // 0x6b0 — unproven gap
        uint32_t mField6c0;     // 0x6c0 — ctor-written
        uint8_t mPad6c4[0x4];   // 0x6c4 — unproven gap
        uint64_t mField6c8;     // 0x6c8 — ctor-written
        uint8_t mPad6d0[0x10];  // 0x6d0 — unproven gap
        uint32_t mField6e0;     // 0x6e0 — ctor-written
        uint8_t mPad6e4[0x4];   // 0x6e4 — unproven gap
        uint64_t mField6e8;     // 0x6e8 — ctor-written
        uint8_t mPad6f0[0x10];  // 0x6f0 — unproven gap
        uint32_t mField700;     // 0x700 — ctor-written
        uint8_t mPad704[0x4];   // 0x704 — unproven gap
        uint64_t mField708;     // 0x708 — ctor-written
        uint8_t mPad710[0x10];  // 0x710 — unproven gap
        uint64_t mField720;     // 0x720 — ctor-written
        uint32_t mField724;     // 0x724 — ctor-written
        uint64_t mField728;     // 0x728 — ctor-written
        uint32_t mField72c;     // 0x72c — ctor-written
        uint64_t mField730;     // 0x730 — ctor-written
        uint8_t mPad738[0x10];  // 0x738 — unproven gap
        uint64_t mField748;     // 0x748 — ctor-written
        uint32_t mField74c;     // 0x74c — ctor-written
        uint64_t mField750;     // 0x750 — ctor-written
        uint32_t mField754;     // 0x754 — ctor-written
        uint64_t mField758;     // 0x758 — ctor-written
        uint8_t mPad760[0x10];  // 0x760 — unproven gap
        uint64_t mField770;     // 0x770 — ctor-written
        uint32_t mField774;     // 0x774 — ctor-written
        uint64_t mField778;     // 0x778 — ctor-written
        uint32_t mField77c;     // 0x77c — ctor-written
        uint64_t mField780;     // 0x780 — ctor-written
        uint8_t mPad788[0x10];  // 0x788 — unproven gap
        uint32_t mField798;     // 0x798 — ctor-written
        uint8_t mPad79c[0x4];   // 0x79c — unproven gap
        uint64_t mField7a0;     // 0x7a0 — ctor-written
        uint8_t mPad7a8[0x10];  // 0x7a8 — unproven gap
        uint32_t mField7b8;     // 0x7b8 — ctor-written
        uint8_t mPad7bc[0x4];   // 0x7bc — unproven gap
        uint64_t mField7c0;     // 0x7c0 — ctor-written
        uint8_t mPad7c8[0x10];  // 0x7c8 — unproven gap
        uint32_t mField7d8;     // 0x7d8 — ctor-written
        uint8_t mPad7dc[0x4];   // 0x7dc — unproven gap
        uint64_t mField7e0;     // 0x7e0 — ctor-written
        uint8_t mPad7e8[0x10];  // 0x7e8 — unproven gap
        uint32_t mField7f8;     // 0x7f8 — ctor-written
        uint8_t mPad7fc[0x4];   // 0x7fc — unproven gap
        uint64_t mField800;     // 0x800 — ctor-written
        uint8_t mPad808[0x10];  // 0x808 — unproven gap
        uint32_t mField818;     // 0x818 — ctor-written
        uint8_t mPad81c[0x4];   // 0x81c — unproven gap
        uint64_t mField820;     // 0x820 — ctor-written
        uint8_t mPad828[0x10];  // 0x828 — unproven gap
        uint32_t mField838;     // 0x838 — ctor-written
        uint8_t mPad83c[0x4];   // 0x83c — unproven gap
        uint64_t mField840;     // 0x840 — ctor-written
        uint8_t mPad848[0x10];  // 0x848 — unproven gap
        uint32_t mField858;     // 0x858 — ctor-written
        uint8_t mPad85c[0x4];   // 0x85c — unproven gap
        uint64_t mField860;     // 0x860 — ctor-written
        uint8_t mPad868[0x10];  // 0x868 — unproven gap
        uint32_t mField878;     // 0x878 — ctor-written
        uint8_t mPad87c[0x4];   // 0x87c — unproven gap
        uint64_t mField880;     // 0x880 — ctor-written
        uint8_t mPad888[0x10];  // 0x888 — unproven gap
        uint32_t mField898;     // 0x898 — ctor-written
        uint8_t mPad89c[0x4];   // 0x89c — unproven gap
        uint64_t mField8a0;     // 0x8a0 — ctor-written
        uint8_t mPad8a8[0x10];  // 0x8a8 — unproven gap
        uint32_t mField8b8;     // 0x8b8 — ctor-written
        uint8_t mPad8bc[0x4];   // 0x8bc — unproven gap
        uint64_t mField8c0;     // 0x8c0 — ctor-written
        uint8_t mPad8c8[0x10];  // 0x8c8 — unproven gap
        uint32_t mField8d8;     // 0x8d8 — ctor-written
        uint8_t mPad8dc[0x4];   // 0x8dc — unproven gap
        uint64_t mField8e0;     // 0x8e0 — ctor-written
        uint8_t mPad8e8[0x10];  // 0x8e8 — unproven gap
        uint32_t mField8f8;     // 0x8f8 — ctor-written
        uint8_t mPad8fc[0x4];   // 0x8fc — unproven gap
        uint64_t mField900;     // 0x900 — ctor-written
        uint8_t mPad908[0x10];  // 0x908 — unproven gap
        uint32_t mField918;     // 0x918 — ctor-written
        uint8_t mPad91c[0x4];   // 0x91c — unproven gap
        uint64_t mField920;     // 0x920 — ctor-written
        uint8_t mPad928[0x10];  // 0x928 — unproven gap
        uint32_t mField938;     // 0x938 — ctor-written
        uint8_t mPad93c[0x4];   // 0x93c — unproven gap
        uint64_t mField940;     // 0x940 — ctor-written
        uint8_t mPad948[0x10];  // 0x948 — unproven gap
        uint32_t mField958;     // 0x958 — ctor-written
        uint8_t mPad95c[0x4];   // 0x95c — unproven gap
        uint64_t mField960;     // 0x960 — ctor-written
        uint8_t mPad968[0x10];  // 0x968 — unproven gap
        uint32_t mField978;     // 0x978 — ctor-written
        uint8_t mPad97c[0x4];   // 0x97c — unproven gap
        uint64_t mField980;     // 0x980 — ctor-written
        uint8_t mPad988[0x10];  // 0x988 — unproven gap
        uint32_t mField998;     // 0x998 — ctor-written
        uint8_t mPad99c[0x4];   // 0x99c — unproven gap
        uint64_t mField9a0;     // 0x9a0 — ctor-written
        uint8_t mPad9a8[0x10];  // 0x9a8 — unproven gap
        uint32_t mField9b8;     // 0x9b8 — ctor-written
        uint8_t mPad9bc[0x4];   // 0x9bc — unproven gap
        uint64_t mField9c0;     // 0x9c0 — ctor-written
        uint8_t mPad9c8[0x10];  // 0x9c8 — unproven gap
        uint32_t mField9d8;     // 0x9d8 — ctor-written
        uint8_t mPad9dc[0x4];   // 0x9dc — unproven gap
        uint64_t mField9e0;     // 0x9e0 — ctor-written
        uint8_t mPad9e8[0x10];  // 0x9e8 — unproven gap
        uint32_t mField9f8;     // 0x9f8 — ctor-written
        uint8_t mPad9fc[0x4];   // 0x9fc — unproven gap
        uint64_t mFielda00;     // 0xa00 — ctor-written
        uint8_t mPada08[0x10];  // 0xa08 — unproven gap
        uint32_t mFielda18;     // 0xa18 — ctor-written
        uint8_t mPada1c[0x4];   // 0xa1c — unproven gap
        uint64_t mFielda20;     // 0xa20 — ctor-written
        uint8_t mPada28[0x10];  // 0xa28 — unproven gap
        uint32_t mFielda38;     // 0xa38 — ctor-written
        uint8_t mPada3c[0x4];   // 0xa3c — unproven gap
        uint64_t mFielda40;     // 0xa40 — ctor-written
        uint8_t mPada48[0x10];  // 0xa48 — unproven gap
        uint32_t mFielda58;     // 0xa58 — ctor-written
        uint8_t mPada5c[0x4];   // 0xa5c — unproven gap
        uint64_t mFielda60;     // 0xa60 — ctor-written
        uint8_t mPada68[0x10];  // 0xa68 — unproven gap
        uint32_t mFielda78;     // 0xa78 — ctor-written
        uint8_t mPada7c[0x4];   // 0xa7c — unproven gap
        uint64_t mFielda80;     // 0xa80 — ctor-written
        uint8_t mPada88[0x10];  // 0xa88 — unproven gap
        uint32_t mZeroa98;      // 0xa98 — ctor zero
        uint8_t mPada9c[0x4];   // 0xa9c — unproven gap
        uint64_t mFieldaa0;     // 0xaa0 — ctor-written
        uint8_t mPadaa8[0x10];  // 0xaa8 — unproven gap
        uint8_t mPadab8;        // 0xab8 — ctor zero
        uint8_t mPadab9[0x7];   // 0xab9 — unproven gap
        uint64_t mFieldac0;     // 0xac0 — ctor-written
        uint8_t mPadac8[0x10];  // 0xac8 — unproven gap
        uint8_t mPadad8;        // 0xad8 — ctor zero
        uint8_t mPadad9[0x7];   // 0xad9 — unproven gap
        uint64_t mFieldae0;     // 0xae0 — ctor-written
        uint8_t mPadae8[0x10];  // 0xae8 — unproven gap
        uint8_t mPadaf8;        // 0xaf8 — ctor zero
    };
}

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
