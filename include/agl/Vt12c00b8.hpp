#pragma once

#include <cstdint>

// Vt12c00b8 - PLACEHOLDER name; layout-pane-family class (BFLYT-style pane tags "pan1"/"pic1"/"wnd1"/"bnd1"/"txt1"; byte-reversed FourCCs) from factory 0x7430bc
// ("FrameBufferUse" branch); 28-slot vtable, vptr +0x00, secondary vptr +0x140.
// extent 0x160 - details: doc/agl/Vt12c00b8.md

namespace agl {
class Vt12c00b8 {
 public:
  void* vtable;            // 0x00 - 0x12c00b8 (GOT cell 0x130ed40 + 0x10)
  uint8_t mBase08[0x130];  // 0x08 - 0x138 family-B base part (base C1 0x746cd0); layout unproven
  void* m138;              // 0x138 - operator new 0x250 buffer (freed via virtual dtor in D0)
  void* vtable2;           // 0x140 - 0x1266110 (GOT cell 0x1308f98 + 0x10)
  uint64_t m148;           // 0x148 - = -1 (str x9 of -1)
  uint32_t m150;           // 0x150 - zeroed
  uint8_t mPad154[0xc];    // 0x154 - 0x160 padding
};
}  // namespace agl
