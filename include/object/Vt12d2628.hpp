#pragma once

#include <cstdint>

// Vt12d2628 — PLACEHOLDER name; "RenderSubEngine" string passed by the ctor.
// Primary vptr 0x12d2628 at +0x00, secondary vptr 0x12d27a0 at +0x208.
// extent 0x2d8 (lower bound; no factory cited) - details: doc/object/Vt12d2628.md

namespace object {
class Vt12d2628 {
 public:
  void* vtable;        // 0x00 — 0x12d2628 (ctor 0x710088e3dc)
  char mPad8[0x1f0];   // 0x08 — unproven
  void* mField1f8;     // 0x1f8 — vptr copied from a singleton result (0x710088e3cc)
  void* mField200;     // 0x200 — vptr copied from a singleton result (0x710088e3ec)
  void* mVptr208;      // 0x208 — secondary vptr 0x12d27a0 (ctor 0x710088e3e0)
  void* mField210;     // 0x210 — ctor zeroes (0x710088e3e8)
  void* mField218;     // 0x218 — ctor zeroes (0x710088e3e4)
  char mSub220[0xb8];  // 0x220 — base sub-object, ctor FUN_71006429a0 (fields to +0xb0)
};
}  // namespace object
