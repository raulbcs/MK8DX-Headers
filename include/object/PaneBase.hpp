#pragma once

#include <cstdint>

// PaneBase - base class of the layout pane family; vptr 0x12c0298, created by
// the pane-tag factory default branch (alloc 0x110, C1 0x745624, factory
// 0x7434c4). Base ctor 0x5a3c78.
// extent 0x110 - details: doc/object/PaneBase.md

namespace object {
class PaneBase {
 public:
  void* vtable;      // 0x00 - 0x12c0298 (installed by C1 0x745624 at 0x745668)
  uint8_t pad_08[0x108];  // 0x08 - 0x10F - base region (ctor 0x5a3c78) - unproven
};
}  // namespace object
