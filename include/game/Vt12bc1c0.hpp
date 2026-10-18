#pragma once

#include <cstdint>

// Vt12bc1c0 — placeholder name; secondary vptr 0x12bc1c0 (offset-to-top
// -0x30) of the undocumented base class Vt12bc0f0 (cell 0x130e648), the
// base of ParamContainerVtc338.
// extent 0x370 (derived shell; base-exclusive size unproven) -
// details: doc/game/Vt12bc1c0.md

namespace object {
class Vt12bc1c0 {
 public:
  void* mVtable;           // 0x00 — primary vptr 0x12bc0f0 (cell 0x130e648 +0x10)
  uint8_t mPad8[0x28];     // 0x08 — unproven gap (pre-secondary-base)
  void* mVtable2;          // 0x30 — secondary vptr 0x12bc1c0 (cell +0xe0)
  uint8_t mPad38[0x2f8];   // 0x38 — array/body region — unproven gap
  uint8_t mPad330[0x28];   // 0x330 — ctor-zeroed tail in the derived fill
  uint8_t mPad358[0x18];   // 0x358 — derived-only fields (see ParamContainerVtc338)
                           // (0x370 shell proven only for the derived class)
};

}  // namespace object
