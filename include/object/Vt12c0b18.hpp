#pragma once

#include <cstdint>

// Vt12c0b18 — PLACEHOLDER name; vptr 0x12c0b18, GOT cell 0x130ee50
// (cell holds vt-0x10; vptr = cell+0x10). Refcounted two-color state
// object, size 0x50. Details: doc/object/Vt12c0b18.md

namespace object {
class Vt12c0b18 {
 public:
  void* vtable;        // 0x00 — 0x12c0b18
  uint8_t mColorA[4];  // 0x08 — reversed-byte color (ctor 0xffffffff)
  uint8_t mColorB[4];  // 0x0c — reversed-byte color (ctor 0xffffffff)
  void* mPtr10;        // 0x10 — set by slot5 to [arg]+0x28
  void* mPtr18;        // 0x18 — set by slot5 to [arg]+0x28
  void* mPtr20;        // 0x20 — ctor zero
  float mF28;          // 0x28 — ctor 0.0f
  float mF2C;          // 0x2c — ctor 1.0f
  float mF30;          // 0x30 — ctor 1.0f
  int32_t mRefCount;   // 0x34 — inc/dec by slot5/slot8
  void* mCtx38;        // 0x38 — ctor arg1
  void* mCtx40;        // 0x40 — ctor arg2
  uint8_t mColorC[4];  // 0x48 — ctor bytes 01 ff ff ff; reworked by slot5
  uint8_t pad4c[4];    //0x4c — unproven padding (covered by new 0x50)
};
}  // namespace object
