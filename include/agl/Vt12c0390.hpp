#pragma once

#include <cstdint>

// Vt12c0390 - PLACEHOLDER name; layout-pane-family class (BFLYT-style pane tags "pan1"/"pic1"/"wnd1"/"bnd1"/"txt1"; byte-reversed FourCCs) from factory 0x7430bc
// (final fallback branch); 28-slot vtable, single vptr +0x00.
// extent 0xf0 - details: doc/agl/Vt12c0390.md

namespace agl {
class Vt12c0390 {
 public:
  void* vtable;            // 0x00 - 0x12c0390 (GOT cell 0x130ed68 + 0x10)
  uint8_t mBase08[0xd8];   // 0x08 - 0xe0 base part (base C1 0x5a22e4); layout unproven
  void* mE0;               // 0xe0 - = [ctor arg x2 + 0x28]
  uint8_t mPadE8[0x8];     // 0xe8 - 0xf0 padding
};
}  // namespace agl
