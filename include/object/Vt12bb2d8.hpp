#pragma once

#include <cstdint>

namespace object {
// Vt12bb2d8 - PLACEHOLDER name; 8-slot secondary hook-band vtable of
// ParamContainerVtb1e8, installed at owner+0x30.
// extent 0x8 - details: doc/object/Vt12bb2d8.md
class Vt12bb2d8 {
 public:
  void* vtable;  // 0x00 - 0x12bb2d8 (owner ctor stores GOT cell 0x130e4c8
                 // + 0x100; no typeinfo; offset-to-top row = -0xd0)
};
}  // namespace object
