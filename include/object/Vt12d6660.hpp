#pragma once

#include <cstdint>

// Vt12d6660 — PLACEHOLDER name; MI secondary base (offset-to-top -0x70) of a
// 0xf8 complete object from factory 0x8ef924; sub-object at owner+0x70.
// extent 0x18 (ctor reach; upper bound 0x88 from owner size) - details:
// doc/object/Vt12d6660.md
namespace object {
class Vt12d6660 {
 public:
  void* mVtable;   // 0x00 — 0x12d6660 (cell 0x1311fa0 + 0x180, secondary)
  void* mOwner;    // 0x08 — back-pointer to the complete object (0x8ef970)
  void* mHandler;  // 0x10 — init argument pointer (base init 0x8bddf4)
};
}  // namespace object
