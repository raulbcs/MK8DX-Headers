#pragma once

#include <cstdint>

// PaneAlignOn - pane created when the factory finds the "AlignOn" attribute
// (string 0xf0742a); vptr 0x12bf7b0. Ctor 0x73ed4c, factory 0x743488.
// extent 0xf0 - details: doc/object/PaneAlignOn.md

namespace object {
class PaneAlignOn {
 public:
  void* vtable;      // 0x00 - 0x12bf7b0 (C1 0x73ed4c at 0x73ed88)
  uint8_t pad_08[0xd4];   // 0x08 - 0xDB - base ctor 0x5a22e4 region - unproven
  uint32_t fieldDC;  // 0xdc - zeroed by C1 (0x73ed74)
  uint16_t fieldE0;  // 0xe0 - u16, init 0x100 (0x73ed8c..0x73ed94)
  uint8_t fieldE2;   // 0xe2 - bool, zeroed by C1 (0x73ed78)
  uint8_t pad_E3[0xd];    // 0xe3 - 0xEF - unproven
};
}  // namespace object
