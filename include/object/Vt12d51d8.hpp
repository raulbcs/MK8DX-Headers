#pragma once

#include <cstdint>

// Vt12d51d8 — PLACEHOLDER name; 6-slot primary vtable of a lazy global
// singleton (alloc 0x180, holder cell 0x130E0A90 stores this+0x08);
// accessor/ctor 0x8CA25C.
// extent 0x180 - exact (operator new 0x180 at 0x8CA284) -
// details: doc/object/Vt12d51d8.md

namespace object {
class Vt12d51d8 {
 public:
  void* mVtable;         // 0x00 — 0x12d51d8 (GOT cell 0x1311C18 holds vt-0x10)
  void* mHeader08;       // 0x08 — subobject header; its address is what the
                         //        singleton holder 0x130E0A90 stores
  uint8_t mPad10[0x48];  // 0x10 — unproven; init 0x61561C(this+0x08, arg, 3)
  uint8_t mPad58[0x10];  // 0x58 — zeroed by the ctor (0x8CA2DC)
  void* mVtable68;       // 0x68 — [cell 0x12FADA0]+0x10 (0x11AD0F8), init 0x61CC48
  void* mPtr70;          // 0x70 — self-pointer to +0x7C
  uint32_t mField78;     // 0x78 — 0x100
  uint8_t mPad7C[0x104]; // 0x7C — unproven padding to extent
};
}  // namespace object
