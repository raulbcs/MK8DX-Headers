#pragma once

#include <cstdint>

namespace object {
// Vt12f4760 - 6-slot secondary hook-band vtable of ParamNodeVt4688
// (primary vptr 0x12f4688), installed at owner+0x30; vptr-only subobject.
// extent 0x8 - details: doc/object/Vt12f4760.md
class Vt12f4760 {
 public:
  void* vtable;  // 0x00 - 0x12f4760 (FUN_7100af2124 stores GOT cell
                 // 0x13154e0 + 0xe8; no typeinfo; offset-to-top row = -0xd0)
};
}  // namespace object
