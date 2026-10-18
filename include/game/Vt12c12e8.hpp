#pragma once

#include <cstdint>

// Vt12c12e8 — PLACEHOLDER name; vptr 0x12c12e8, 8 slots. Tiny flagged
// base: C1 0x753e58 only installs the vptr and clears the +0x8 flag
// word; derived classes embed it (e.g. ctors 0x89a74 / 0x89b30).
// extent 0x10 - details: doc/game/Vt12c12e8.md
namespace game {
class Vt12c12e8 {
 public:
  void* mVtable;   // 0x00 - vptr 0x12c12e8 (GOT cell 0x130ef90 holds
                   //   vptr-0x10; C1 adds 0x10)
  uint32_t mFlags;  // 0x08 - bit flags, cleared by C1; bit i set alongside
                   //   float member i at +0xc (setters 0x89adc..0x89b2c
                   //   tail-call the bit-set helper 0x753ea0)
  uint8_t mPad0c[0x4]; // 0x0c - unproven gap
};
}  // namespace game
