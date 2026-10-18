#pragma once

#include <cstdint>

// Vt12d4268 — PLACEHOLDER name; SubEngine-family derivative (38 slots).
// vptr 0x12d4268 via GOT cell 0x1308118 (cell = vt-0x10, vptr = cell+0x10).
// extent 0x208 (lower bound; no factory found) - details: doc/object/Vt12d4268.md

namespace object {
class Vt12d4268 {
 public:
  void* vtable;        // 0x00 — 0x12d4268 (ctor site 0x71003d732c)
  char mBase8[0x1f0];  // 0x08 — SubEngine base subobject, unproven
  void* m1f8;          // 0x1f8 — vptr copied from singleton [x8+0x10] (0x71003d7324)
  void* m200;          // 0x200 — vptr copied from singleton [x8+0x18] (0x71003d7334)
};
}  // namespace object
