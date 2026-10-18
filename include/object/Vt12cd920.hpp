#pragma once

#include <cstdint>

// PROVISIONAL (no RTTI: typeinfo slot zero). Small state/flag record: state
// code with range checks 1..6, 8x4-bit mask field, sentinel words. Size
// proven: operator new 0x28 (0x83f684). extent 0x28 - details:
// doc/object/Vt12cd920.md

namespace object {
class Vt12cd920 {
 public:
  void* vtable;         // 0x00 — vptr 0x12cd920 (cell 0x1310cb0 + 0x10)
  uint32_t mField08;    // 0x08 — copied by slot10 (0x848960)
  uint32_t mField0c;    // 0x0c — state code; predicates check 1..6
  uint32_t mField10;    // 0x10 — 8 fields x 4 bits (slot2 0x848880:
                        //        idx clamped 0..7, lsl #2, bic/orr)
  uint32_t mField14;    // 0x14 — copied by slot10 (0x84897c)
  uint8_t mFlag18;      // 0x18 — bool, set to 1 by C1; slot8 getter
  uint8_t mFlag19;      // 0x19 — bool, zeroed by C1
  uint8_t mPad1a[0x2];  // 0x1a — gap (C1 writes nothing)
  uint32_t mField1c;    // 0x1c — zeroed by C1 (low half of stur x9)
  uint32_t mField20;    // 0x20 — 0xFFFFFFFF sentinel (C1 0x848840)
  int32_t mField24;     // 0x24 — -1 sentinel (C1 0x848854)
};
}  // namespace object
