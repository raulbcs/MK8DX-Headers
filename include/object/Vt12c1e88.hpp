#pragma once

#include <cstdint>

// Vt12c1e88 — placeholder name (theme unproven). C1 0x76a06c, vptr 0x12c1e88 at
// +0x00; member C1 0x628628 at +0x90. Two factories share the folded C1: new 0x110
// (0xbc780) and new 0xd8 (0x78bc78) — 0x110 is the proven max size.
// extent 0x110 - details: doc/object/Vt12c1e88.md

namespace object {
class Vt12c1e88 {
 public:
  void* mVtable;        // 0x00 — vptr 0x12c1e88 (C1 0x76a090-0x76a098)
  uint8_t m8[0x40];     // 0x08 — zero run 0x08-0x48 (0x76a088-0x76a0ac); unproven
  uint16_t m48;         // 0x48 — 13 (0x76a09c-0x76a0a0)
  uint16_t m4a;         // 0x4a — 0xffff (0x76a0c8)
  uint32_t mPad4c;      // 0x4c — unproven
  uint8_t m50[0x10];    // 0x50 — zeroed (0x76a0cc)
  uint8_t m60;          // 0x60 — 0 (0x76a0c4)
  uint8_t mPad61[0x3];  // 0x61 — unproven
  uint8_t m64[0x10];    // 0x64 — zeroed (stp 0x76a0b0)
  uint32_t mPad74;      // 0x74 — unproven
  uint32_t m78;         // 0x78 — 0 (0x76a0b8)
  uint32_t mPad7c;      // 0x7c — unproven
  uint32_t m80;         // 0x80 — 0 (0x76a0bc)
  uint32_t mPad84;      // 0x84 — unproven
  void* m88;            // 0x88 — 0 (0x76a0c0)
  uint8_t m90[0x80];    // 0x90 — member C1 0x628628 (0x76a0d0); C1 also reads
                        //        u32 cell 0x130f2b0 at 0x76a0d8-0x76a0dc;
                        //        tail to extent (unverified content)
};
}  // namespace object
