#pragma once

#include <cstdint>

// Vt12c0618 - PLACEHOLDER name; layout-pane-family class (BFLYT-style pane tags "pan1"/"pic1"/"wnd1"/"bnd1"/"txt1"; byte-reversed FourCCs) from factory 0x7430bc
// (fallback key "ScissorOn"); 28-slot vtable, single vptr +0x00, base size.
// extent 0xe0 - details: doc/agl/Vt12c0618.md

namespace agl {
class Vt12c0618 {
 public:
  void* vtable;            // 0x00 - 0x12c0618 (GOT cell 0x130ed98 + 0x10)
  uint8_t mBase08[0xd8];   // 0x08 - 0xe0 base part (base C1 0x5a22e4); layout unproven
};
}  // namespace agl
