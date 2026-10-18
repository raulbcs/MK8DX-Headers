#pragma once

#include <cstdint>

// Vt12d6a68 — PLACEHOLDER name; secondary vtable (offset-to-top -0x70) of a 0xf8
// factory product in the Vt12d6xxx directive family; paired primary row header 0x12d6ae0.
// extent 0xf8 (operator-new size 0xf8 at 0x8efbe0) -
// details: doc/game/Vt12d6a68.md

namespace game {
class Vt12d6a68 {
 public:
  void* mVtable;         // 0x00 — product primary vptr (GOT cell 0x1311fb0 addend 0x12d6ae0; final store site shares tail 0x8ef964, unverified)
  uint8_t mPad8[0x20];   // 0x08 — unproven padding (base ctor 0x738d68)
  void* mSub28;          // 0x28 — pointer to the +0x70 subobject (0x8ef974)
  uint8_t mPad30[0x40];  // 0x30 — unproven padding
  void* mVtable70;       // 0x70 — descriptor vptr-header (GOT cell 0x1311fa0 addend +0x180, 0x8ef968)
  void* mOwner78;        // 0x78 — back-pointer to this (0x8ef970)
  uint8_t mPad80[0x78];  // 0x80 — unproven padding
};
}  // namespace game
