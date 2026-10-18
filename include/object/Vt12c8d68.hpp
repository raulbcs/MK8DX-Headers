#pragma once

#include <cstdint>

// Vt12c8d68 — PLACEHOLDER name (15-slot MI class, size 0x140, created by
// FUN_71007e9fdc at 0xcc7a4); vptr 0x12c8d68 at +0x00, secondary at +0x78.
// extent 0x140 - details: doc/object/Vt12c8d68.md

namespace object {
class Vt12c8d68 {
 public:
  void* vtable;         // 0x00 — 0x12c8d68 (C1 0x7e9ffc..0x7ea010)
  char mPad8[0x68];     // 0x08 — unproven (pre-init 0x7e0848-managed)
  void* mField70;       // 0x70 — C1 zeroes (0x7ea000)
  void* vtable2;        // 0x78 — 0x12c8df0 secondary (cell 0x13101c8 +0x10,
                        //        0x7ea01c..0x7ea034)
  char mPad80[0x1];     // 0x80 — unproven
  uint8_t mField81;     // 0x81 — C1 zeroes (0x7ea004)
  uint8_t mField82;     // 0x82 — C1 zeroes (0x7ea008)
  uint8_t mField83;     // 0x83 — C1 sets 1 (0x7ea014)
  uint32_t mField84;    // 0x84 — C1 zeroes (0x7ea024)
  char mPad88[0x20];    // 0x88 — unproven
  void* mFieldA8;       // 0xA8 — C1 zeroes (0x7ea03c)
  void* mFieldB0;       // 0xB0 — C1 copies from global 0x12fb148 (0x7ea048)
  uint32_t mFieldB8;    // 0xB8 — C1 copies [0x12fb148+8] (0x7ea044)
  char mPadBC[0x24];    // 0xBC — C1 memcpy 0x24 from 0x12fd01c8 (0x7ea068)
  void* mFieldE0;       // 0xE0 — C1 copies from global 0x12fb148 (0x7ea084)
  uint32_t mFieldE8;    // 0xE8 — C1 copies [0x12fb148+8] (0x7ea06c)
  char mPadEC[0x54];    // 0xEC — unproven (further 0x24-byte memcpy at
                        //        0x7ea088 mirrors the +0xBC block)
};
}  // namespace object
