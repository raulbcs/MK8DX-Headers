#pragma once

#include <cstdint>

// Vt12d3960 — PLACEHOLDER name; pooled keyed-entry class (u32 key pair at +0x08/+0x0C,
// release handle at +0x10). GOT cell 0x1311840 holds 0x12d3960-0x10 (row = installed vptr).
// extent 0xa0 - details: doc/object/Vt12d3960.md

struct Vt12d3960 {
  uint64_t vptr;             // 0x00 — 0x12d3960 (installed by in-place init FUN_71008a12f0)
  uint8_t mPad8[0x98];       // 0x08 — key u32 pair +0x08/+0x0C, flag +0x25, handle ptr +0x10 (region-scoped, per-byte layout unproven)
};
