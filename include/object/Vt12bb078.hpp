#pragma once

#include <cstdint>

namespace object {
// Vt12bb078 - PLACEHOLDER name; 8-slot secondary hook-band vtable of
// ParamNodeVtaf38, installed at owner+0x30.
// extent 0x8 - details: doc/object/Vt12bb078.md
class Vt12bb078 {
 public:
  void* vtable;  // 0x00 - 0x12bb078 (owner ctor stores GOT cell 0x130e4b0
                 // + 0x150; no typeinfo; offset-to-top row = -0xd0)
};
}  // namespace object
