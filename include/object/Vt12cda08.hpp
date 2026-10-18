#pragma once

#include <cstdint>

// Vt12cda08 — PLACEHOLDER name; vptr 0x12cda08, n=32, primary table.
// Ctor FUN_710084c024 wraps nn::prepo::Initialize; slots are ret-stubs (pure interface, no overrides).
// extent 0x30 (lower bound; owns dynamic arrays) - details: doc/object/Vt12cda08.md

namespace object {
class Vt12cda08 {
 public:
  void* mVtable;           // 0x00 — 0x12cda08 (via GOT cell 0x1310ce0, holds vt-0x10)
  uint32_t m8;             // 0x08 — count written by ctor loop (0x84c158)
  uint8_t mPadC[4];        // 0x0C — unproven padding
  void* m10;               // 0x10 — zeroed by ctor
  void* m18;               // 0x18 — array pointer (grown/reassigned in ctor loop)
  void* m20;               // 0x20 — second array pointer (0x84c0fc)
  uint8_t mPad28[8];       // 0x28 — unproven padding (extent lower bound)
};

}  // namespace object
