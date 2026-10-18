#pragma once

#include <cstdint>

// Vt12c93a8 — PLACEHOLDER name; zero-init member sub-object of the
// named-subsystem engine family (Vt12c9268 doc, field +0x178, 0x30 bytes
// claimed there); base of Vt12ca0b0 (engine list node).
// extent 0x38 (store lower bound) - details: doc/object/Vt12c93a8.md

namespace object {
class Vt12c93a8 {
 public:
  void* vtable;          // 0x00 — 0x12c93a8 (cell 0x1310290 / 0x130fea0 + 0x10)
  uint64_t mField08;     // 0x08 — ctor zero
  uint64_t mField10;     // 0x10 — ctor zero
  uint64_t mField18;     // 0x18 — ctor zero
  uint64_t mField20;     // 0x20 — ctor zero
  uint64_t mField28;     // 0x28 — ctor zero
  uint64_t mField30;     // 0x30 — ctor zero (proves size >= 0x38)
};
}  // namespace object
