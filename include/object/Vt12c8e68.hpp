#pragma once

#include "object/Vt12c8698.hpp"

// PROVISIONAL (no RTTI: typeinfo slot zero). Vt12c8698-family selector-array
// entry 3 ([mgr+0x130]); adds a u64 at 0x70 zeroed by C1 and slot1. Size
// proven: operator new 0x78 at 0xcc808. extent 0x78 - details: doc/object/Vt12c8e68.md

namespace object {
class Vt12c8e68 : public Vt12c8698 {
 public:
  uint64_t mField70;  // 0x70 — zeroed by C1 (0x7ebe58) and slot1
};
}  // namespace object
