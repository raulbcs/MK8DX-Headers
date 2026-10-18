#pragma once

#include <cstdint>

// Vt12dc450 — PLACEHOLDER name; element record of a pooled container
// (37 slots). Row 0x12dc450 is the typeinfo slot (ti 0x12dc580, name string
// not recoverable); installed vptr = row+8 = 0x12dc458 (GOT cell 0x1313320
// holds 0x12dc448, vptr = cell+0x10).
// extent 0x858 - details: doc/object/Vt12dc450.md

namespace object {
class Vt12dc450 {
 public:
  void* vtable;      // 0x00 — 0x12dc458 (installed by callers, e.g. 0x710096d81c)
  char mBase8[0x840]; // 0x08 — members init'd by FUN_71009721ac, unproven
  char m848[0x10];   // 0x848 — unproven tail
};
}  // namespace object
