#pragma once

#include <cstdint>

// Vt12c01a8 - PLACEHOLDER name; layout-pane-family class (BFLYT-style pane tags "pan1"/"pic1"/"wnd1"/"bnd1"/"txt1"; byte-reversed FourCCs) from factory 0x7430bc
// (FourCC "t1pr" branch); 28-slot vtable, single vptr +0x00, no overrides.
// extent 0x100 - details: doc/agl/Vt12c01a8.md

namespace agl {
class Vt12c01a8 {
 public:
  void* vtable;            // 0x00 - 0x12c01a8 (GOT cell 0x130ed58 + 0x10)
  uint8_t mBase08[0xd8];   // 0x08 - 0xe0 base part (base C1 0x5a3aa0); layout unproven
  uint8_t mE0[0x20];       // 0xe0 - tail padding, not touched by C1; layout unproven
};
}  // namespace agl
