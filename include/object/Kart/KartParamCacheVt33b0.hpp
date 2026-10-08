#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object {
// KartParamCacheVt33b0 — address-anchored name (vptr 0x12f33b0, cell 0x13152c8, n=13, site 0xa83f70, ctor 0xa83984, alloc 0xa0).
// Variant of the 0x63c6f8 param-cache cluster.
class KartParamCacheVt33b0 : public KartParamCache {
 public:
  uint8_t mPad40[0xc0];   // 0x40 — unproven gap
  uint64_t mField100;     // 0x100 — ctor: call result
  uint8_t mPad108[0x8];   // 0x108 — unproven gap
  uint32_t mField110;     // 0x110 — ctor-written
  uint32_t mField114;     // 0x114 — ctor-written
  uint64_t mZero118;      // 0x118 — ctor zero
  uint8_t mPad120[0x8];   // 0x120 — unproven gap
  uint64_t mField128;     // 0x128 — ctor-written
  uint64_t mField130;     // 0x130 — ctor-written
  uint8_t mPad138[0x10];  // 0x138 — unproven gap
  uint64_t mField148;     // 0x148 — ctor: call result
  uint64_t mField150;     // 0x150 — ctor: call result
  uint64_t mField158;     // 0x158 — ctor: call result
  uint64_t mField160;     // 0x160 — ctor: call result
  uint64_t mField168;     // 0x168 — ctor: call result
  uint64_t mField170;     // 0x170 — ctor: call result
  uint32_t mField178;     // 0x178 — ctor-written
  uint8_t mPad17c[0x4];   // 0x17c — unproven gap
  uint64_t mField180;     // 0x180 — ctor-written
  uint8_t mPad188[0x10];  // 0x188 — unproven gap
  uint64_t mField198;     // 0x198 — ctor: call result
  uint8_t mPad1a0[0x18];  // 0x1a0 — unproven gap
  uint64_t mField1b8;     // 0x1b8 — ctor-written
  uint64_t mField1c0;     // 0x1c0 — ctor: call result
};
// Vtable slot 0 (+0x10) dtor/reset (evidence TU /Users/raul/projects/mk8dx-400/src/unknown/vt33b0DtorResetSlot0_7100abc240.cpp):
// runs 0x71006373a4 (cold fragment) on four sub-blocks of each 0x1a20-byte entry of the
// +0x1d8 pooled array, frees the array (0x7100abd8f4 element dtor), re-stamps default
// vptr fields +0x948..+0x828 (cell 0x710130d918), +0x7f8 (0x710130d920), +0x760
// (0x710130d838), +0x608 (cell 0x713152d8), +0x1e8 (0x710130d830), +0x0 (0x710130d848)
// interleaved with 0x710063ea80 / 0x71006374e4 / 0x71006469c4 / 0x71006462c4 resets.
// function size 0x1a4 bytes.
}  // namespace object

// Naming closure: docblock ctor anchor yields only nvn init strings (nvnDeviceInitialize/nvnDeviceGetProcAddress) — anchor misquote suspected; needs re-verification. Address-anchored name retained.
