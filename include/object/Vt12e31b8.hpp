#pragma once

#include <cstdint>

// Vt12e31b8 — PLACEHOLDER name; derived of Vt12e2ec8 (shares 4 of 7 slot impls); installed vptr
// 0x12e31c0; GOT cell 0x13144d0 holds vptr-0x10 (0x12e31b8 is the typeinfo slot, typeinfo 0x12e4230).
// size 0x58 (operator new at 0x9F0AD8) - details: doc/object/Vt12e31b8.md

namespace object {
class Vt12e31b8 : public Vt12e2ec8 {
 public:
  // vtable 0x12e31c0: slot1 0x9F2200, slot3 0x9F225C, slot5 0x9F226C overridden;
  // slots 0/2/4/6 shared with Vt12e2ec8 (0x9E5C3C/0x9E5E8C/0xA191C4/0x9E6048).
  void* m48;  // 0x48 — zeroed by factory-ctor 0x9F0B04
  void* m50;  // 0x50 — owner ptr stored by factory-ctor 0x9F0B08
};
}  // namespace object
