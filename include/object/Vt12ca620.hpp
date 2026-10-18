#pragma once

#include <cstdint>

// Vt12ca620 — PLACEHOLDER name; gear::Actor-derived (base C1 0x7b976c), 14 slots, no RTTI.
// C1 0x7fd5f4 zeroes +0x38..+0x4F; slot 4 FUN_71007fd62c populates a 0x58 heap sub-object.
// extent 0x50 (nothrow new 0x50 at factory 0x13da2c) -
// details: doc/object/Vt12ca620.md

namespace object {
class Vt12ca620 {
 public:
  void* mVtable;        // 0x00 — 0x12ca620 (via GOT cell 0x1310488, cell holds vptr-0x10)
  uint8_t mPad8[0x30];  // 0x08 — unproven padding (gear::Actor base C1 0x7b976c zeroes +0x10..+0x38)
  void* m38;            // 0x38 — ctor: null; slot1 FUN_7100800f28 fills it
  void* m40;            // 0x40 — ctor: null
  void* m48;            // 0x48 — ctor: null
};
}  // namespace object
