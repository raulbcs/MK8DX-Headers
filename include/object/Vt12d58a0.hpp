#pragma once

#include <cstdint>

namespace object {
// Vt12d58a0 - PLACEHOLDER name; 0x20 stack-built callback record registered
// by 0x84ca58 into a dispatcher slot at owner+0x2688 (via 0x84cbe4); sibling
// of Vt12d58f8/Vt12d5950.
// extent 0x20 - details: doc/object/Vt12d58a0.md
class Vt12d58a0 {
 public:
  void* vtable;  // 0x00 - 0x12d58a0 (GOT cell 0x1311d40 holds 0x12d5890 =
                 //   vt-0x10)
  void* mOwner;  // 0x08 - registrar's this (x19 of 0x84ca58)
  void* mLink;   // 0x10 - raw pointer to foreign row 0x12d5838 (GOT cell
                 //   0x1311d38 value, stored without +0x10)
  void* m18;     // 0x18 - zero at construction
};
}  // namespace object
