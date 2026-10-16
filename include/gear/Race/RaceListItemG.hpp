#pragma once

#include <cstdint>

// RaceListItemG — PROVISIONAL vtable-anchored name ("G"). Manager list item
// of the far race family (base chain 0x7ee400, NOT Actor). Vtable 0x11b9650,
// ctor 0x710010adec, size 0xA10 (alloc 0x71003989cc); registers into
// manager+0x218. Offsets 0x00-0x9AF are the primary base RaceListItemGBase.
// Details: doc/gear/Race/RaceListItemG.md

namespace gear {
class RaceListItemG {
 public:
  void* vtable;           //0x00 — vtable ptr
  uint8_t pad08[0xf8];    //0x08 — unproven padding
  uint8_t pad_100[0x8];   //0x100 — unproven gap
  uint32_t m108;          //0x108 — ctor sets 8
  uint32_t m10c;          //0x10C — ctor sets 0xC
  uint32_t m110;          //0x110 — ctor sets 4
  uint8_t pad114[0x89c];  //0x114 — unproven padding
  uint8_t zero9b0[0x18];  //0x9B0 - 0x9C7 — ctor memset 0x48
  int32_t m9c8;           //0x9C8 — ctor -1
  uint8_t pad9cc[0xc];    //0x9CC — unproven padding
  int32_t m9d8;           //0x9D8 — ctor -1
  uint8_t pad9dc[0xc];    //0x9DC — unproven padding
  int32_t m9e8;           //0x9E8 — ctor -1
  uint8_t pad9ec[0xc];    //0x9EC — unproven padding
  int32_t m9f8;           //0x9F8 — ctor -1
  uint8_t pad9fc[4];      //0x9FC — unproven padding
  uint32_t mA00;          //0xA00 — ctor zero
  uint8_t mA04[4];        //0xA04  // unproven
  uint8_t bA08;           //0xA08 — ctor zero
  uint8_t padA09[7];      //0xA09 — unproven padding
  // (0xA10 total)
};
}  // namespace gear
