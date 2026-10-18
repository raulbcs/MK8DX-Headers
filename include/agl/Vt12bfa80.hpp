#pragma once

#include <cstdint>

// Vt12bfa80 - PLACEHOLDER name; layout-pane-family class (BFLYT-style pane tags "pan1"/"pic1"/"wnd1"/"bnd1"/"txt1"; byte-reversed FourCCs) created by factory 0x7430bc
// (fallback key "DynamicCaptureOn"); 28-slot vtable, single vptr +0x00, secondary vptr +0x108.
// extent 0x360 - details: doc/agl/Vt12bfa80.md

namespace agl {
class Vt12bfa80 {
 public:
  void* vtable;           // 0x00 - 0x12bfa80 (GOT cell 0x130ecd8 + 0x10)
  uint8_t mBase08[0xd8];  // 0x08 - 0xe0 base-class part (base C1 0x5a22e4); layout unproven
  void* mListHead;        // 0xe0 - = this+0xe0 (empty intrusive list head)
  void* mListTail;        // 0xe8 - = this+0xe0
  uint8_t mF0;            // 0xf0 - flag, zeroed
  uint8_t mPadF1[0x7];    // 0xf1 - 0xf8 padding (only byte +0xf0 stored)
  void* mF8;              // 0xf8 - subobject built by 0x73fe20 (heap, freed in dtor)
  void* m100;             // 0x100 - heap object (virtual dtor called in D0)
  void* vtable2;          // 0x108 - 0x1266110 (GOT cell 0x1308f98 + 0x10)
  int64_t m110;           // 0x110 - = -1
  uint32_t m118;          // 0x118 - zeroed
  uint8_t mPad11C[0x4];   // 0x11c - 0x120 padding (only word +0x118 stored)
  void* m120;             // 0x120 - zeroed
  uint8_t mSub128[0x68];  // 0x128 - member ctor 0x63ecbc
  uint8_t mSub190[0xb0];  // 0x190 - member ctor 0x63f778
  uint8_t mSub240[0x120]; // 0x240 - member dtor 0x639f38; layout unproven
};
}  // namespace agl
