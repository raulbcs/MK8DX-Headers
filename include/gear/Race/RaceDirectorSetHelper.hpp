#pragma once

#include <cstdint>

// RaceDirectorSetHelper — PROVISIONAL vtable-anchored name. 0x40-byte
// helper bound to RaceDirectorPlayerSet (stored at set+0x50); ctor
// 0x71000689c8 (minimal base 0x7c2920), vtable 0x11b4408.
// Details: doc/gear/Race/RaceDirectorSetHelper.md

namespace gear {
class RaceDirectorSetHelper {
 public:
  void* vtable;      //0x00
  uint32_t u08;      //0x08 — ctor zero
  uint32_t u0c;      //0x0C — ctor zero
  void* m10;         //0x10 — ctor zero
  void* m18;         //0x18 — ctor zero
  void* mOwner20;    //0x20 — ctor arg x1 (the PlayerSet)
  uint64_t m28;      //0x28 — ctor zero
  uint32_t m30;      //0x30 — ctor zero
  uint8_t pad34[4];  //0x34 — unproven padding
  uint32_t m38;      //0x38 — ctor zero
  // extent 0x3c (ctor 0x71000689C8 stores reach 0x3c)
};
}  // namespace gear
