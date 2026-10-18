#pragma once

#include <cstdint>

// Vt12e4900 — PLACEHOLDER name; secondary interface table, installed vptr
// 0x12e4908 at [this+0x10] (tsv row = typeinfo slot, vt-8; RTTI 0x12e4990).
// extent 0x130 (lower bound; deepest store +0x12c) - details: doc/object/Vt12e4900.md

namespace object {
class Vt12e4900 {
 public:
  void* mVtable;         // 0x00 — primary 0x12e2bf8 (GOT cell 0x13142b0), not this entry
  uint8_t mPad8[0x8];    // 0x08 — unproven padding
  void* mVtable10;       // 0x10 — secondary 0x12e4908 (GOT cell 0x13142b8)
  uint8_t mPad18[0x40];  // 0x18 — std::__tree/map member accessed via adjusted this+0x10
  uint8_t m58[0x90];     // 0x58 — embedded member (C0 0x9d60b0)
  void* mE8;             // 0xe8 — null
  void* mF0;             // 0xf0 — null
  uint8_t mF8;           // 0xf8 — 0
  uint8_t mPadF9[0x7];   // 0xf9 — unproven padding
  void* m100;            // 0x100 — pair {x22 arg, cell 0x13142c0+0x10}
  void* m108;            // 0x108 — self-ptr {this+0x110, this+0x110}
  void* m110;            // 0x110
  void* m118;            // 0x118 — null
  uint32_t m120;         // 0x120 — 0
  uint32_t mPad124;      // 0x124 — unproven padding
  uint8_t m128;          // 0x128 — flag (w3 & 1)
  uint8_t m129;          // 0x129 — flag (w4 & 1)
  uint8_t mPad12A[0x2];  // 0x12a — unproven padding
  uint32_t m12C;         // 0x12c — C1 arg w2
};
}  // namespace object
