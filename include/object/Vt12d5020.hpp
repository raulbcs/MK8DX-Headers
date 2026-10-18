#pragma once

#include <cstdint>

// Vt12d5020 — PLACEHOLDER name; 6-slot primary vtable of a small param object;
// ctor 0x8C9DF8 (base ctor 0x7499F8 fills +0x00/+0x08/+0x10); stack-constructed
// extent 0x18 - lower bound (base ctor stores through +0x10) - details: doc/object/Vt12d5020.md

namespace object {
class Vt12d5020 {
 public:
  void* mVtable;    // 0x00 — 0x12d5020 (GOT cell 0x1311BF0 holds vt-0x10)
  void* mField08;   // 0x08 — second base-ctor argument (NULL at 0x8C9E08 site)
  void* mField10;   // 0x10 — third base-ctor argument (forwarded by 0x8C9DF8)
};
}  // namespace object
