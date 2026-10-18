#pragma once

#include <cstdint>

namespace object {
// Vt12bb650 - PLACEHOLDER name; 8-slot secondary hook-band vtable of
// ParamContainerVtb578, installed at owner+0x30.
// extent 0x8 - details: doc/object/Vt12bb650.md
class Vt12bb650 {
 public:
  void* vtable;  // 0x00 - 0x12bb650 (owner ctor stores GOT cell 0x130e498
                 // + 0xe8; no typeinfo; offset-to-top row = -0xd0)
};
}  // namespace object
