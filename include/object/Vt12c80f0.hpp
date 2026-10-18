#pragma once

#include <cstdint>

// object::Vt12c80f0 — PLACEHOLDER name; derives from Vt12c8020, overriding slots
// 2/3 (dtors) and 7/8/9/16/17/18/19. Same 0x3a0 layout.
// vptr 0x12c80f0, GOT cell 0x1310078 holds vt-0x10.
// extent 0x3a0 - details: doc/object/Vt12c80f0.md

namespace object {
class Vt12c80f0 : public Vt12c8020 {
 public:
  char mPad00[0x3a0];  // layout identical to Vt12c8020; see doc/object/Vt12c80f0.md
};
}  // namespace object
