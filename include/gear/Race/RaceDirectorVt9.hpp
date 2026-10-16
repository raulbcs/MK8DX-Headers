#pragma once

#include <cstdint>

#include "gear/Actor/Actor.hpp"

namespace gear {
// RaceDirector-family director: overrides prepare/enter (slots 0x20/0x28),
// shared calc/render/exit hooks. Vtable .data 0x11b93f8, ctor 0x7100107c3c,
// 0x228 bytes (alloc 0x398a9c). Details: doc/gear/Race/RaceDirectorVt9.md
class RaceDirectorVt9 : public Actor {
 public:
  uint32_t mField38;  // 0x38 — zeroed on ctor
  uint8_t mPad3c[4];  // 0x3c — unproven padding
  uint64_t mField40;  // 0x40 — zeroed on ctor
  void* mChan48;      // 0x48 — zeroed on ctor
  void* mChan50;      // 0x50 — cell 0x12fcf48 (vptr, +0x10)
  void* mChan58;      // 0x58 — cell 0x12fcf50
  uint64_t mField60;  // 0x60 — zeroed on ctor
  uint64_t mField68;  // 0x68 — zeroed on ctor
  void* mField70;     // 0x70 — memset region start; ctor sets it
  void* mField78;     // 0x78 — owned node set by the ctor
  uint8_t mPad80[8];  // 0x80 — unproven padding

  struct Node {
    uint64_t a, b;
  };
  Node mNodes[12];  // 0x88 — node array, 0x10 bytes each (init 0x60b930)

  uint8_t mPad148[8];  // 0x148 — unproven padding
  char mPad150[0x6c];  // 0x150 — memset tail (to 0x1bc)
  uint32_t mField1bc;  // 0x1bc — zeroed on ctor (str = 32-bit)
  uint8_t mPad1c0[4];  // 0x1c0 — unproven padding
  uint32_t mField1c4;  // 0x1c4 — zeroed on ctor
  uint8_t mPad1c8[4];  // 0x1c8 — unproven padding
  uint8_t mPad1cc[4];  // 0x1cc — unproven padding
  char mSub1d0[0x40];  // 0x1d0 — member sub-object (ctor 0x628628)
  uint64_t mField210;  // 0x210 — zeroed on ctor
  uint64_t mField218;  // 0x218 — zeroed on ctor
  uint8_t mField220;   // 0x220 — zeroed on ctor
  uint8_t mPad221[7];  // 0x221 — unproven padding
  // extent 0x228 (allocation size 0x228 @0x398a9c → ctor 0x7100107c3c)
};
}  // namespace gear
