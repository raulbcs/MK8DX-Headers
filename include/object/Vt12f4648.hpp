#pragma once

#include <cstdint>

namespace object {
// Vt12f4648 - 6-slot secondary hook-band vtable of ParamNodeVt4510
// (primary vptr 0x12f4510), installed at owner+0x30; vptr-only subobject.
// extent 0x8 - details: doc/object/Vt12f4648.md
class Vt12f4648 {
 public:
  void* vtable;  // 0x00 - 0x12f4648 (owner ctor stores GOT cell 0x13154d8
                 // + 0x148; no typeinfo; offset-to-top row = -0xd0)
};
}  // namespace object
