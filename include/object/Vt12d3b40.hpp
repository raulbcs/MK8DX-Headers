#pragma once

#include <cstdint>

// Vt12d3b40 — PLACEHOLDER name; pooled keyed-entry class, sibling of Vt12d3ae0
// (u32 key pair, release handle). In-place member subobject of the 0xC78 base
// initialized by FUN_71008a12f0 (vptr store 0x8a1a20, cell 0x1311868 = vt-0x10).
// extent 0x2d0 - details: doc/object/Vt12d3b40.md

struct Vt12d3b40 {
  uint64_t vptr;            // 0x00 — 0x12d3b40 (installed at [base+0x790] by FUN_71008a12f0)
  uint8_t mPad8[0x2c8];     // 0x08 — key u32 pair +0x08/+0x0C, release handle +0x10, flag +0x25 (region-scoped, per-byte layout unproven)
};
