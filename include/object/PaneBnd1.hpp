#pragma once

#include <cstdint>

// PaneBnd1 - pane created for the "bnd1" pane tag (factory 0x743214); vptr
// 0x12bf8a0; thin leaf over the intermediate base (vptr 0x12ad428, C1
// 0x5ac4d8). No owned fields beyond the base regions.
// extent 0xe0 - details: doc/object/PaneBnd1.md

namespace object {
class PaneBnd1 {
 public:
  void* vtable;      // 0x00 - 0x12bf8a0 (C1 0x73fb2c at 0x73fb4c)
  uint8_t pad_08[0xd8];   // 0x08 - 0xDF - base regions (0x5ac4d8 -> 0x5a22e4) - unproven
};
}  // namespace object
