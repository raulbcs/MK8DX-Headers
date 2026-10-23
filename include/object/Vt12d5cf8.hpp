#pragma once

#include <cstdint>
#include <object/Vt12c7d88.hpp>

// Vt12d5cf8 — PLACEHOLDER name; primitive-class sibling of the Vt12c7d88
// hierarchy (base ctor FUN_71007d4c9c with kind=9). Ctor FUN_71008dc2b0;
// operator new 0x170 at 0x80516c. GOT cell 0x1311dd8 holds vt-0x10
// (row = installed vptr). extent 0x170 - details: doc/object/Vt12d5cf8.md

namespace object {
struct Vt12d5cf8 : public Vt12c7d88 {
  uint8_t mPadD8[0x68];   // 0xD8 — unproven (tail helper 0x8dc340 writes +0xD4=1.0f, +0xD8=0, +0xF0=0, +0xF4=1.0f)
  uint64_t mField140;     // 0x140 — float pair from arg v1 (ctor 0x8dc2e4..0x8dc2f0)
  uint64_t mField148;     // 0x148 — float from arg v0, then u64 from arg x1[0] (ctor 0x8dc2ec..0x8dc308)
  uint32_t mField150;     // 0x150 — unproven (alignment)
  uint32_t mField154;     // 0x154 — arg x1[8] (ctor 0x8dc2f8)
  uint64_t mField158;     // 0x158 — float pair (ctor 0x8dc30c..0x8dc314)
  uint64_t mField160;     // 0x160 — float + u64 arg x1[0] (ctor 0x8dc314..0x8dc328)
  uint32_t mField168;     // 0x168 — unproven (alignment)
  uint32_t mField16C;     // 0x16C — arg x1[8] repeat (ctor 0x8dc318..0x8dc31c)
};

}  // namespace object
