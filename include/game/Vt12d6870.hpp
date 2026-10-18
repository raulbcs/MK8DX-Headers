#pragma once

#include <cstdint>

// Vt12d6870 — PLACEHOLDER name; secondary vtable (offset-to-top -0x90) of a 0x118
// factory product in the Vt12d6xxx directive family; primary vptr 0x12d68f8.
// extent 0x118 (operator-new size 0x118 at 0x8efa7c) -
// details: doc/game/Vt12d6870.md

namespace game {
class Vt12d6870 {
 public:
  void* mVtable;         // 0x00 — primary vptr 0x12d68f8 (GOT cell 0x1311fa8+0x10)
  uint8_t mPad8[0x20];   // 0x08 — unproven padding (base ctor 0x73b040 leaves rest to 0x588b04-like init)
  void* mSub28;          // 0x28 — pointer to the +0x90 subobject (0x8efaac)
  uint8_t mPad30[0x12];  // 0x30 — unproven padding
  uint16_t mFlags42;     // 0x42 — ctor 0x73b040 ORs in 0x400 (0x73b078)
  uint8_t mPad44[0x2C];  // 0x44 — unproven padding
  uint64_t mField70;     // 0x70 — zeroed by ctor 0x73b040 (0x73b05c)
  uint64_t mField78;     // 0x78 — zeroed by ctor (0x73b060)
  uint64_t mField80;     // 0x80 — zeroed by ctor 0x73b040 (stp at 0x73b060)
  uint16_t mField88;     // 0x88 — 0x101 (0x73b074)
  uint8_t mPad8A[0x6];   // 0x8a — unproven padding
  void* mVtable90;       // 0x90 — 0x12d7068 (0x12d7078-0x10 header form, factory 0x8efab4)
  void* mOwner98;        // 0x98 — back-pointer to this (factory 0x8efab8)
  uint8_t mPadA0[0x78];  // 0xa0 — unproven padding
};
}  // namespace game
