#pragma once

#include <cstdint>

namespace object {
// Vt12f3670 - 6-slot secondary hook-band vtable of ParamNodeVt35a8
// (primary vptr 0x12f35a8), installed at owner+0x30; vptr-only subobject.
// extent 0x8 - details: doc/object/Vt12f3670.md
class Vt12f3670 {
 public:
  void* vtable;  // 0x00 - 0x12f3670 (owner ctor stores GOT cell 0x13152f0
                 // + 0xd8; no typeinfo; offset-to-top row = -0xd0)
};
}  // namespace object
