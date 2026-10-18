#pragma once

#include <cstdint>

namespace object {
// Vt12d58f8 - PLACEHOLDER name; 0x38-byte array-element record (new[] 0x38
// at 0x8daf50, ctor 0x8d91a8); derives from the Vt12d5848 family and carries
// a secondary vptr 0x11ad200 at +0x10.
// extent 0x38 - details: doc/object/Vt12d58f8.md
class Vt12d58f8 {
 public:
  void* vtable;      // 0x00 - 0x12d58f8 (GOT cell 0x1311d48 holds 0x12d58e8 =
                     //   vt-0x10; base vptr 0x12d5848 installed first)
  uint32_t m08;      // 0x08 - ctor arg w1 (index/id)
  char pad0c[0x04];  // 0x0c..0x0f - unproven gap
  void* m10;         // 0x10 - secondary vptr 0x11ad200 (GOT cell 0x12fae28 +
                     //   0x10)
  void* m18;         // 0x18 - [x2+8] at ctor
  void* m20;         // 0x20 - ctor arg x3
  uint16_t m28;      // 0x28 - ctor 0xffff
  uint16_t m2a;      // 0x2a - ctor 0xffff
  uint32_t m2c;      // 0x2c - ctor arg w4
  void* m30;         // 0x30 - 0 then [[x3+0xc8]+0x58]
};
}  // namespace object
