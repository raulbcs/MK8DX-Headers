#pragma once

#include <cstdint>

namespace object {
// Vt12bb538 - PLACEHOLDER name; 8-slot secondary hook-band vtable of
// ParamContainerVtb448, installed at owner+0x30 (reset body 0x6fb174).
// extent 0x8 - details: doc/object/Vt12bb538.md
class Vt12bb538 {
 public:
  void* vtable;  // 0x00 - 0x12bb538 (owner family stores GOT cell 0x130e470
                 // + 0x100; no typeinfo; offset-to-top row = -0xd0)
};
}  // namespace object
