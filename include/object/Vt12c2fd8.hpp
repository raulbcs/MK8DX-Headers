#pragma once

#include <cstdint>

// Placeholder Vt12c2fd8: no RTTI. Singleton root object at the base of a huge
// arena (factory 0x78f99c reserves 0x24905000 via 0x60b2a8; guard cell 0x12fce70).
// vptr 0x12c2fd8 (GOT cell 0x130f660, holds vt-0x10) stored at arena offset 0.
// extent unbounded (arena-backed) - details: doc/object/Vt12c2fd8.md
class Vt12c2fd8 {
 public:
  void* vtable;            // 0x00 — vptr 0x12c2fd8
  uint8_t mPad08[0x7cc];   // 0x08
  uint8_t mInit7d4;        // 0x7d4 — embedded member (vptr cell 0x130f650, ctor 0x799ec0; singleton ptr kept in cell 0x130f658) (size unknown)
  uint8_t mPad7d5[0x23];   // 0x7d5
  uint64_t mField7f8;      // 0x7f8 — zeroed
  uint64_t mField800;      // 0x800 — zeroed (head; released by slot9 dtor 0x78fad0)
  uint64_t mField808;      // 0x808 — zeroed
  uint64_t mField810;      // 0x810 — zeroed (end; released by slot10 dtor 0x78fb44)
  uint8_t mPad818[0x58];   // 0x818
  uint8_t mElems870;       // 0x870 — element array start; records of stride 0x28e0, {0,-1,-1,0,...} seeded (size unknown)
};
