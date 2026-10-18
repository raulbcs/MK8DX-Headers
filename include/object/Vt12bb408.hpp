#pragma once

#include <cstdint>

namespace object {
// Vt12bb408 - PLACEHOLDER name; 8-slot secondary hook-band vtable of
// ParamMultiChanVtb318, installed at owner+0x30 (ctor path 0x6fc324).
// extent 0x8 - details: doc/object/Vt12bb408.md
class Vt12bb408 {
 public:
  void* vtable;  // 0x00 - 0x12bb408 (owner ctor stores GOT cell 0x130e468
                 // + 0x100; no typeinfo; offset-to-top row = -0xd0)
};
}  // namespace object
