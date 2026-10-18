#pragma once

#include <cstdint>

// DynamicCaptureUseName — name-keyed node from factory FUN_71007430bc
// (key "DynamicCaptureUseName" 0xf0713c); ctor FUN_7100741bc8, vptr 0x12bfb70.
// extent 0x120 - details: doc/object/DynamicCaptureUseName.md

namespace object {
class DynamicCaptureUseName {
 public:
  void* vtable;          // 0x00 — 0x12bfb70 (ctor 0x741bf0); base vptr 0x12c0298
  char mPad8[0x100];     // 0x08 — base-ctor-managed (FUN_7100745624), unproven
  void* mHandler;        // 0x108 — optional delegate ptr, ctor zeroes (0x741be4), set by 0x741c00
  uint8_t mUseFlag;      // 0x110 — ctor zeroes (0x741be8), set by 0x741c00
  char mPad111[0xf];     // 0x111 — unproven padding to 0x120
};
}  // namespace object
