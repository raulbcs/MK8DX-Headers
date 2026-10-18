#pragma once

#include <cstdint>

// Vt12ce718 — PLACEHOLDER name; 44-slot class derived from Vt12ce888, ctor
// FUN_710085664c (1452 B, shared with the base phase). vptr 0x12ce718.
// extent 0x918 - details: doc/object/Vt12ce718.md

namespace object {
class Vt12ce718 {
 public:
  void* vtable;         // 0x00 — 0x12ce718 (derived-ctor phase 0x71008566fc)
  char mPad8[0x1c8];    // 0x08 — unproven (base phase inits +0x58 run)
  uint32_t mField1d0;   // 0x1d0 — ctor -1 (0x7100856700)
  char mPad1d4[0x2c];   // 0x1d4 — unproven
  uint32_t mField200;   // 0x200 — ctor -1 (0x7100856708)
  uint32_t mField204;   // 0x204 — unproven
  uint32_t mField208;   // 0x208 — unproven
  char mPad20c[0x24];   // 0x20c — unproven
  uint32_t mField230;   // 0x230 — ctor -1 (0x710085670c)
  char mPad234[0x2c];   // 0x234 — unproven
  uint32_t mField260;   // 0x260 — ctor -1 (0x7100856710)
  char mPad264[0x2c];   // 0x264 — unproven
  uint32_t mField290;   // 0x290 — ctor -1 (0x7100856714)
  char mPad294[0x684];  // 0x294 — unproven (ctor touches +0x3fa, +0x70c)
};
}  // namespace object
