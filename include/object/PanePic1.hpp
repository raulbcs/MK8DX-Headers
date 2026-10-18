#pragma once

#include <cstdint>

// PanePic1 - layout pane created for the "pic1" pane tag (factory 0x7431d4);
// vptr 0x12bffc0, holds an agl::TextureData at +0x108. Base PaneBase ctor 0x745624.
// extent 0x130 - details: doc/object/PanePic1.md

namespace object {
class PanePic1 {
 public:
  void* vtable;        // 0x00 - 0x12bffc0 (ctor 0x745028 re-store in D1 0x744fcc)
  uint8_t pad_08[0x100];  // 0x08 - 0x107 - PaneBase region - unproven
  void* textureData_108;   // 0x108 - agl::TextureData (new 0x250, ctor 0x74b5e0); freed by D1
  uint8_t pad_110[0x8];    // 0x110 - 0x117 - unproven
  int64_t field118;        // 0x118 - init -1 (0x744f68)
  uint32_t field120;       // 0x120 - init 0 (0x744f7c)
  uint8_t pad_124[0xc];    // 0x124 - 0x12F - unproven
};
}  // namespace object
