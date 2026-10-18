#pragma once

#include <cstdint>

namespace game {
// Unnamed intrusive-list container; operator-new size 0x20 at 0x8c174c.
// Init FUN_7100b03d94: sentinel node at +0x08 points to itself (empty
// list), count 0, capacity 0x20. Caller overrides the vptr afterwards
// (cell 0x1311a18) with a derived vtable.
// extent 0x20 (operator-new size 0x20 at 0x8c174c) -
// details: doc/game/Vt12f4ee8.md
class Vt12f4ee8 {
 public:
  void* vtable;        // 0x00 - vptr 0x12f4ee8 (GOT cell 0x13155c8 holds
                       // 0x12f4ed8 = vptr-0x10; off-top 0, no typeinfo)
  void* mSentinel08;   // 0x08 - list head; init writes this+0x08 (self)
  void* mSentinel10;   // 0x10 - list tail; init writes this+0x08 (self)
  uint32_t mField18;   // 0x18 - count, init 0
  uint32_t mField1c;   // 0x1c - init 0x20 (capacity/stride flag)
};
}  // namespace game
