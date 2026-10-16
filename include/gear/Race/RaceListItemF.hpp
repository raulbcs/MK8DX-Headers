#pragma once

#include <cstdint>

// RaceListItemF — PROVISIONAL vtable-anchored name ("F"). Manager list item
// of the far race family (base chain 0x7d5450, NOT Actor). Vtable 0x11b8ab8,
// ctor 0x71000c9e04, size 0x198 (alloc 0x71003de7c4); typeinfo cell unreliable.
// Details: doc/gear/Race/RaceListItemF.md

namespace gear {
class RaceListItemF {
 public:
  void* vtable;          //0x00 — vtable ptr
  uint8_t pad08[0x17c];  //0x08 - 0x183 — unproven padding
  uint32_t mZero184;     //0x184 — ctor zero
  uint32_t mZero188;     //0x188 — ctor zero
  uint32_t m21c190;      //0x190 — ctor sets 0x21C
  uint32_t mZero194;     //0x194 — ctor zero
  // (0x198 total)
  // extent 0x198 (ctor 0x71000C9E04 stores reach 0x198)
  uint8_t mGap18C[4];  // 0x18C — unproven gap
};
}  // namespace gear
