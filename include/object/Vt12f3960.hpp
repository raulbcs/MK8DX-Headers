#pragma once

#include <cstdint>

namespace object {
// Vt12f3960 - 6-slot secondary hook-band vtable of ParamNodeVt3898
// (primary vptr 0x12f3898), installed at owner+0x30; vptr-only subobject.
// extent 0x8 - details: doc/object/Vt12f3960.md
class Vt12f3960 {
 public:
  void* vtable;  // 0x00 - 0x12f3960 (owner ctor stores GOT cell 0x1315328
                 // + 0xd8; no typeinfo; offset-to-top row = -0xd0)
};
}  // namespace object
