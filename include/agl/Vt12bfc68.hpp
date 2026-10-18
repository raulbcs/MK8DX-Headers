#pragma once

#include <cstdint>

// Vt12bfc68 - PLACEHOLDER name; layout-pane-family class (BFLYT-style pane tags "pan1"/"pic1"/"wnd1"/"bnd1"/"txt1"; byte-reversed FourCCs) from factory 0x7430bc
// (fallback key "DynamicCaptureUseName"); 28-slot vtable, single vptr +0x00.
// extent 0x150 - details: doc/agl/Vt12bfc68.md

namespace agl {
class Vt12bfc68 {
 public:
  void* vtable;            // 0x00 - 0x12bfc68 (GOT cell 0x130ece8 + 0x10)
  uint8_t mBase08[0x130];  // 0x08 - 0x138 family-B base part (base C1 0x746cd0); layout unproven
  void* m138;              // 0x138 - zeroed by C1; setter 0x741e40 stores here
  uint8_t m140;            // 0x140 - bool, zeroed by C1; setter 0x741e40
  uint8_t mPad141[0xf];    // 0x141 - 0x150 padding
};
}  // namespace agl
