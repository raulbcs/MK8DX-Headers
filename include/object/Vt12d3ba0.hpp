#pragma once

#include <cstdint>

// Vt12d3ba0 — PLACEHOLDER name; pooled keyed-entry class, sibling of Vt12d3b40
// (u32 key pair, release handle). In-place member subobject of the 0xC78 base
// initialized by FUN_71008a12f0 (vptr store 0x8a1c44, cell 0x1311870 = vt-0x10).
// extent 0x218 - details: doc/object/Vt12d3ba0.md

struct Vt12d3ba0 {
  uint64_t vptr;            // 0x00 — 0x12d3ba0 (installed at [base+0xa60] by FUN_71008a12f0)
  uint8_t mPad8[0x210];     // 0x08 — key u32 pair +0x08/+0x0C, release handle +0x10, s32 -1 at +0x100 (region-scoped, per-byte layout unproven)
};
