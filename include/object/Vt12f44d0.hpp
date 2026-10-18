#pragma once

#include <cstdint>

namespace object {
// Vt12f44d0 - 6-slot secondary hook-band vtable of ParamNodePseudoOcclusion
// (primary vptr 0x12f4400), installed at owner+0x30; vptr-only subobject.
// extent 0x8 - details: doc/object/Vt12f44d0.md
class Vt12f44d0 {
 public:
  void* vtable;  // 0x00 - 0x12f44d0 (owner ctor stores GOT cell 0x13154d0
                 // + 0xe0; no typeinfo; offset-to-top row = -0xd0)
};
}  // namespace object
