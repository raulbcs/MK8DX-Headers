#pragma once

#include <cstdint>
#include <object/Kart/KartParamCache.hpp>

// KartParamCacheSsao — named from ctor string evidence: ctor string tag 'aglssao' + params radius/ao_far/dist_attn/enable_reprojection/mix_rate (0xf1e713-0xf1e7ef) (vptr 0x12f40c8, cell 0x1315480, n=13, site 0xae7da4, ctor 0xae7d58).
// extent 0x3cf4
namespace object::Kart {
class KartParamCacheSsao : public KartParamCache {
 public:
  uint8_t mPad40[0x190];    // 0x40 — unproven gap
  uint32_t mZero1d0;        // 0x1d0 — ctor zero
  uint8_t mPad1d4[0x4];     // 0x1d4 — unproven gap
  uint64_t mZero1d8;        // 0x1d8 — ctor zero
  uint64_t mField1e0;       // 0x1e0
  uint8_t mPad1e8[0x28];    // 0x1e8 — unproven gap
  void* mSelf210;           // 0x210 — ctor stores `this`
  uint64_t mField218;       // 0x218
  uint8_t mPad220[0x10];    // 0x220 — unproven gap
  uint8_t mField230;        // 0x230
  uint8_t mPad231[0x7];     // 0x231 — unproven gap
  uint64_t mField238;       // 0x238
  uint8_t mPad240[0x10];    // 0x240 — unproven gap
  uint32_t mField250;       // 0x250
  uint8_t mPad254[0x4];     // 0x254 — unproven gap
  uint64_t mField258;       // 0x258
  uint8_t mPad260[0x10];    // 0x260 — unproven gap
  uint32_t mField270;       // 0x270
  uint8_t mPad274[0x4];     // 0x274 — unproven gap
  uint64_t mField278;       // 0x278
  uint8_t mPad280[0x10];    // 0x280 — unproven gap
  uint32_t mField290;       // 0x290
  uint8_t mPad294[0x4];     // 0x294 — unproven gap
  uint64_t mField298;       // 0x298
  uint8_t mPad2a0[0x10];    // 0x2a0 — unproven gap
  uint8_t mField2b0;        // 0x2b0
  uint8_t mPad2b1[0x7];     // 0x2b1 — unproven gap
  uint64_t mField2b8;       // 0x2b8
  uint8_t mPad2c0[0x10];    // 0x2c0 — unproven gap
  uint8_t mField2d0;        // 0x2d0
  uint8_t mPad2d1[0x7];     // 0x2d1 — unproven gap
  uint64_t mField2d8;       // 0x2d8
  uint8_t mPad2e0[0x10];    // 0x2e0 — unproven gap
  uint32_t mField2f0;       // 0x2f0
  uint8_t mPad2f4[0x4];     // 0x2f4 — unproven gap
  uint64_t mField2f8;       // 0x2f8
  uint8_t mPad300[0x10];    // 0x300 — unproven gap
  uint32_t mField310;       // 0x310
  uint8_t mPad314[0x4];     // 0x314 — unproven gap
  uint32_t mZero318;        // 0x318 — ctor zero
  uint32_t mField31c;       // 0x31c
  uint32_t mField320;       // 0x320
  uint32_t mField324;       // 0x324
  uint32_t mField328;       // 0x328
  uint32_t mField32c;       // 0x32c
  uint32_t mField330;       // 0x330
  uint32_t mField334;       // 0x334
  uint32_t mField338;       // 0x338
  uint32_t mField33c;       // 0x33c
  uint32_t mField340;       // 0x340
  uint32_t mField344;       // 0x344
  uint32_t mField348;       // 0x348
  uint32_t mField34c;       // 0x34c
  uint32_t mField350;       // 0x350
  uint32_t mField354;       // 0x354
  uint32_t mField358;       // 0x358
  uint32_t mField35c;       // 0x35c
  uint32_t mField360;       // 0x360
  uint32_t mField364;       // 0x364
  uint32_t mField368;       // 0x368
  uint32_t mField36c;       // 0x36c
  uint32_t mField370;       // 0x370
  uint32_t mField374;       // 0x374
  uint32_t mField378;       // 0x378
  uint32_t mField37c;       // 0x37c
  uint32_t mField380;       // 0x380
  uint32_t mField384;       // 0x384
  uint32_t mField388;       // 0x388
  uint32_t mField38c;       // 0x38c
  uint32_t mField390;       // 0x390
  uint32_t mField394;       // 0x394
  uint32_t mField398;       // 0x398
  uint32_t mField39c;       // 0x39c
  uint32_t mField3a0;       // 0x3a0
  uint32_t mField3a4;       // 0x3a4
  uint32_t mField3a8;       // 0x3a8
  uint8_t mPad3ac[0x25c];   // 0x3ac — unproven gap
  uint32_t mZero608;        // 0x608 — ctor zero
  uint32_t mField60c;       // 0x60c
  uint8_t mPad610;          // 0x610 — ctor zero
  uint8_t mPad611[0x3487];  // 0x611 — unproven gap
  uint64_t mZero3a98;       // 0x3a98 — ctor zero
  uint32_t mZero3aa0;       // 0x3aa0 — ctor zero
  uint8_t mPad3aa4[0x4];    // 0x3aa4 — unproven gap
  uint64_t mZero3aa8;       // 0x3aa8 — ctor zero
  uint64_t mZero3ab0;       // 0x3ab0 — ctor zero
  uint32_t mZero3ab8;       // 0x3ab8 — ctor zero
  uint8_t mPad3abc[0x4];    // 0x3abc — unproven gap
  uint64_t mZero3ac0;       // 0x3ac0 — ctor zero
  uint64_t mZero3ac8;       // 0x3ac8 — ctor zero
  uint32_t mZero3ad0;       // 0x3ad0 — ctor zero
  uint8_t mPad3ad4[0x4];    // 0x3ad4 — unproven gap
  uint64_t mZero3ad8;       // 0x3ad8 — ctor zero
  uint64_t mZero3ae0;       // 0x3ae0 — ctor zero
  uint32_t mZero3ae8;       // 0x3ae8 — ctor zero
  uint8_t mPad3aec[0x4];    // 0x3aec — unproven gap
  uint64_t mZero3af0;       // 0x3af0 — ctor zero
  uint64_t mZero3af8;       // 0x3af8 — ctor zero
  uint32_t mZero3b00;       // 0x3b00 — ctor zero
  uint8_t mPad3b04[0x4];    // 0x3b04 — unproven gap
  uint64_t mZero3b08;       // 0x3b08 — ctor zero
  uint64_t mZero3b10;       // 0x3b10 — ctor zero
  uint32_t mZero3b18;       // 0x3b18 — ctor zero
  uint8_t mPad3b1c[0x4];    // 0x3b1c — unproven gap
  uint64_t mZero3b20;       // 0x3b20 — ctor zero
  uint64_t mZero3b28;       // 0x3b28 — ctor zero
  uint32_t mZero3b30;       // 0x3b30 — ctor zero
  uint8_t mPad3b34[0x4];    // 0x3b34 — unproven gap
  uint64_t mZero3b38;       // 0x3b38 — ctor zero
  uint64_t mZero3b40;       // 0x3b40 — ctor zero
  uint32_t mZero3b48;       // 0x3b48 — ctor zero
  uint8_t mPad3b4c[0x4];    // 0x3b4c — unproven gap
  uint64_t mZero3b50;       // 0x3b50 — ctor zero
  uint64_t mZero3b58;       // 0x3b58 — ctor zero
  uint32_t mZero3b60;       // 0x3b60 — ctor zero
  uint8_t mPad3b64[0x4];    // 0x3b64 — unproven gap
  uint64_t mZero3b68;       // 0x3b68 — ctor zero
  uint64_t mZero3b70;       // 0x3b70 — ctor zero
  uint32_t mZero3b78;       // 0x3b78 — ctor zero
  uint8_t mPad3b7c[0x4];    // 0x3b7c — unproven gap
  uint64_t mZero3b80;       // 0x3b80 — ctor zero
  uint64_t mZero3b88;       // 0x3b88 — ctor zero
  uint32_t mZero3b90;       // 0x3b90 — ctor zero
  uint8_t mPad3b94[0x4];    // 0x3b94 — unproven gap
  uint64_t mZero3b98;       // 0x3b98 — ctor zero
  uint64_t mZero3ba0;       // 0x3ba0 — ctor zero
  uint32_t mZero3ba8;       // 0x3ba8 — ctor zero
  uint8_t mPad3bac[0x4];    // 0x3bac — unproven gap
  uint64_t mZero3bb0;       // 0x3bb0 — ctor zero
  uint64_t mZero3bb8;       // 0x3bb8 — ctor zero
  uint32_t mZero3bc0;       // 0x3bc0 — ctor zero
  uint8_t mPad3bc4[0x4];    // 0x3bc4 — unproven gap
  uint64_t mZero3bc8;       // 0x3bc8 — ctor zero
  uint64_t mZero3bd0;       // 0x3bd0 — ctor zero
  uint32_t mZero3bd8;       // 0x3bd8 — ctor zero
  uint8_t mPad3bdc[0x4];    // 0x3bdc — unproven gap
  uint64_t mZero3be0;       // 0x3be0 — ctor zero
  uint64_t mZero3be8;       // 0x3be8 — ctor zero
  uint32_t mZero3bf0;       // 0x3bf0 — ctor zero
  uint8_t mPad3bf4[0x4];    // 0x3bf4 — unproven gap
  uint64_t mZero3bf8;       // 0x3bf8 — ctor zero
  uint64_t mZero3c00;       // 0x3c00 — ctor zero
  uint32_t mZero3c08;       // 0x3c08 — ctor zero
  uint8_t mPad3c0c[0x4];    // 0x3c0c — unproven gap
  uint64_t mZero3c10;       // 0x3c10 — ctor zero
  uint64_t mField3c18;      // 0x3c18
  uint8_t mPad3c20[0x18];   // 0x3c20 — unproven gap
  uint64_t mField3c38;      // 0x3c38
  uint8_t mPad3c40[0x18];   // 0x3c40 — unproven gap
  uint64_t mField3c58;      // 0x3c58
  uint8_t mPad3c60[0x18];   // 0x3c60 — unproven gap
  uint64_t mField3c78;      // 0x3c78
  uint8_t mPad3c80[0x10];   // 0x3c80 — unproven gap
  uint32_t mField3c90;      // 0x3c90
  uint8_t mPad3c94[0x4];    // 0x3c94 — unproven gap
  uint64_t mField3c98;      // 0x3c98
  uint8_t mPad3ca0[0x10];   // 0x3ca0 — unproven gap
  uint32_t mZero3cb0;       // 0x3cb0 — ctor zero
  uint8_t mPad3cb4[0x4];    // 0x3cb4 — unproven gap
  uint64_t mField3cb8;      // 0x3cb8
  uint8_t mPad3cc0[0x10];   // 0x3cc0 — unproven gap
  uint32_t mField3cd0;      // 0x3cd0
  uint8_t mPad3cd4[0x4];    // 0x3cd4 — unproven gap
  uint64_t mField3cd8;      // 0x3cd8
  uint8_t mPad3ce0[0x10];   // 0x3ce0 — unproven gap
  uint32_t mField3cf0;      // 0x3cf0
};

}  // namespace object
