#pragma once

#include <cstdint>

// Vt12d9670 — PLACEHOLDER name; large in-place state/entry-table class (9 vtable
// slots + embedded secondary vptrs at +0x250/+0x278 region/+0x288/+0x330 family).
// Ctor FUN_710092b5f0 (in-place; vptr store 0x92b640, cell 0x1312840 = vt-0x10).
// extent 0x628 - details: doc/object/Vt12d9670.md

struct Vt12d9670 {
  uint64_t vptr;             // 0x00 — 0x12d9670 (ctor store 0x92b640)
  uint8_t mPad8[0x248];      // 0x08 — flag bytes +0x2B/+0x2D read by slot thunks; fields zeroed +0x10..+0x248 (per-byte layout unproven)
  uint64_t mVptr250;         // 0x250 — secondary vptr 0x12d96e8 (ctor 0x92b648..0x92b654)
  uint8_t mPad258[0x30];     // 0x258 — self ptrs +0x258/+0x288, count 8 @+0x260, entry data +0x264..+0x288 (unproven)
  uint64_t mVptr288;         // 0x288 — secondary vptr 0x12d95b8 (ctor 0x92b698..0x92b6a0)
  uint8_t mPad290[0xa0];     // 0x290 — 0x80 @+0x298, 43x4-byte inline entry array +0x2A4 (ctor loop 0x92b8f8..0x92b90c; unproven)
  uint64_t mVptr330;         // 0x330 — embedded member vptr 0x12d9748 (ctor 0x92b6fc)
  uint8_t mPad338[0x38];     // 0x338 — self ptr +0x338, 0x20 @+0x340, zeroed entry data +0x34C..+0x36C (unproven)
  uint64_t mVptr370;         // 0x370 — embedded member vptr 0x12d9748 (ctor 0x92b6f8)
  uint8_t mPad378[0x38];     // 0x378 — self ptr +0x378, 0x20 @+0x380, zeroed entry data +0x38C..+0x3AC (unproven)
  uint64_t mVptr3B0;         // 0x3B0 — embedded member vptr 0x12d9748 (ctor 0x92b718)
  uint8_t mPad3B8[0x68];     // 0x3B8 — self ptr +0x3B8, 0x20 @+0x3C0, zeroed data +0x3CC..+0x418 (unproven)
  uint64_t mVptr420;         // 0x420 — embedded member vptr 0x12d9748 (ctor 0x92b71c)
  uint8_t mPad428[0x38];     // 0x428 — self ptr +0x428, 0x20 @+0x430, zeroed entry data +0x43C..+0x45C (unproven)
  uint64_t mVptr460;         // 0x460 — secondary vptr 0x12d97a8 (ctor 0x92b880..0x92b888)
  uint8_t mPad468[0x138];    // 0x468 — self ptr +0x468, 0x100 @+0x470, 64x4-byte entry array +0x47C (ctor loop 0x92b8a8..0x92b8c4), +0x580/+0x588/+0x590=0x80 (unproven)
  uint8_t mPad5A0[0x84];     // 0x5A0 — inline entry array to +0x620 (ctor loops 0x92b930..0x92b96c; unproven)
  uint32_t mField624;        // 0x624 — zeroed (ctor 0x92b924)
};
