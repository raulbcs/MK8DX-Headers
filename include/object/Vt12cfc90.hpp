#pragma once

#include <cstdint>

// Vt12cfc90 - PLACEHOLDER name (28-slot game class from the 0x86axxx UI family, created by
// three subsystem factories); single vptr +0x00.
// extent 0x38 - details: doc/object/Vt12cfc90.md

namespace object {
class Vt12cfc90 {
 public:
  void* vtable;            // 0x00 - 0x12cfc90 (GOT cell 0x1310f40 + 0x10)
  void* m08;               // 0x08 - [arg1] (owner/parent ptr)
  uint32_t m10;            // 0x10 - flags u32, zeroed; bit5 set/cleared via [m28->0x20]
  uint8_t m14[0xc];        // 0x14 - 12-byte serial/token copied from global cell 0x12fb148
  uint8_t m20;             // 0x20 - initialized flag byte (1 after first update)
  uint8_t mPad21[0x7];     // 0x21 - 0x28 padding
  void* m28;               // 0x28 - [arg1+8], lazily allocated via 0x8155cc if null
  uint8_t mPad30[0x8];     // 0x30 - 0x38 padding
};
}  // namespace object
