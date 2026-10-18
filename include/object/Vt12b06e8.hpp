#pragma once

#include <cstdint>

namespace object {
// Vt12b06e8 - PLACEHOLDER name; sead-stream-flavored secondary base (slot 3
// is sead::BufferWriteStreamSrc::rewind). Always installed at owner+0x20;
// primary vptr of the owner comes from GOT cell 0x130d3b8. No RTTI.
// extent 0x40 (lower bound; ctor stores) - details: doc/object/Vt12b06e8.md
class Vt12b06e8 {
 public:
  void* vtable;      // 0x00 - 0x12b06e8 (GOT cell 0x130d3c0 holds vt-0x10)
  void* m08;         // 0x08 - copied from [param1+0x10]
  void* m10;         // 0x10 - param2 (pointer argument)
  uint32_t m18;      // 0x18 - param3 (w3, ctor-copied)
  uint32_t m1c;      // 0x1c - ctor 0
  char pad20[0x20];  // 0x20..0x3f - written by helpers 0x625c68 / 0x625c70;
                     //   unproven
};
}  // namespace object
