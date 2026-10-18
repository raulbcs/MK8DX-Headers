#pragma once

#include <cstdint>

// Vt12f5b40 — PLACEHOLDER name; vptr 0x12f5b40, 11 slots + pointer row.
// In-place wrapper holding two virtual pointers at +0x20/+0x28 (release via
// [vt+0x18]); embedded as a member at parent+0x78. Extent only a proven
// lower bound (no standalone allocation found).
// extent 0x30 (lower bound) - details: doc/game/Vt12f5b40.md
namespace game {
class Vt12f5b40 {
 public:
  void* mVtable;      // 0x00 - vptr 0x12f5b40 (GOT cell 0x1315888 holds
                      //   vptr-0x10; C1 adds 0x10)
  char mPad08[0x18];  // 0x08..0x1f - base object (base C1 0xa326c8 writes
                      //   u32 arg@+0x08, 0@+0x10, byte@+0x18, its own vptr)
  void* m20;          // 0x20 - interface ptr, zeroed by C1 (0xb15e68);
                      //   released via [vt+0x18] by slot-2 cleanup
  void* m28;          // 0x28 - second interface ptr, zeroed by C1;
                      //   released via [vt+0x08] by D-tors
};
}  // namespace game
