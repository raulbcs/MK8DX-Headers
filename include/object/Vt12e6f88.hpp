#pragma once

#include <cstdint>

// Vt12e6f88 — NEX "RendezVousLogin" descriptor object (vptr 0x12e6f90, row
// label 0x12e6f88, GOT cell 0x1314c00 holds vptr-0x10). Lazy 0x28 member of a
// protocol manager (owner+0x120), base ctor FUN_710058bd2c, owner back-ptr at
// +0x20. Slot 3 returns 21, slot 4 returns "RendezVousLogin".
// extent 0x28 - details: doc/object/Vt12e6f88.md

namespace object {
class Vt12e6f88 {
 public:
  void* mVtable;      // 0x00 — 0x12e6f90 (via GOT cell 0x1314c00 = vptr-0x10)
  uint8_t mField8;    // 0x08 — flag, zeroed by base ctor 0x58bd2c
  uint8_t mPad9[0x7];  // 0x09 — unproven padding (base ctor 0x58bd2c writes flag at +0x9)
  uint32_t mField10;  // 0x10 — zeroed by base ctor 0x58bd2c
  uint8_t mPad14[0x4];  // 0x14 — unproven padding
  uint32_t mField18;  // 0x18 — set to ctor arg (0 here) by 0x58bd2c
  uint8_t mPad1c[0x4];  // 0x1c — unproven padding
  void* mOwner20;     // 0x20 — back-pointer to owning manager
};
}  // namespace object
