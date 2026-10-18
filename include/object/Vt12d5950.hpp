#pragma once

#include <cstdint>

namespace object {
// Vt12d5950 - PLACEHOLDER name; 0xb38-byte array-element record (new 0xb38
// at 0x8dbacc, ctor 0x8d9474); base vptr 0x12d5848 then own vptr; secondary
// vptr 0x11ad200 at +0x10; +0x2c payload memset 0xb0c.
// extent 0xb38 - details: doc/object/Vt12d5950.md
class Vt12d5950 {
 public:
  void* vtable;      // 0x00 - 0x12d5950 (GOT cell 0x1311d50 holds 0x12d5940 =
                     //   vt-0x10; base vptr 0x12d5848 installed first)
  uint32_t m08;      // 0x08 - ctor arg w1 (index/id)
  char pad0c[0x04];  // 0x0c..0x0f - unproven gap
  void* m10;         // 0x10 - secondary vptr 0x11ad200 (GOT cell 0x12fae28 +
                     //   0x10)
  void* m18;         // 0x18 - [x2+8] at ctor
  void* m20;         // 0x20 - ctor arg x3
  uint32_t m28;      // 0x28 - ctor -1
  char m2c[0xb0c];   // 0x2c..0xb37 - ctor memset 0 (payload area)
};
}  // namespace object
