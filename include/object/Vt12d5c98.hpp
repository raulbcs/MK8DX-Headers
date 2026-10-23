#pragma once

#include <cstdint>
#include <object/Vt12c7d88.hpp>

// Vt12d5c98 — PLACEHOLDER name; primitive-class sibling of the Vt12c7d88
// hierarchy (base ctor FUN_71007d4c9c with kind=8). Ctor FUN_71008dbf08;
// operator new 0x108 at 0x804fc0. GOT cell 0x1311dd0 holds vt-0x10
// (row = installed vptr). extent 0x108 - details: doc/object/Vt12d5c98.md

namespace object {
struct Vt12d5c98 : public Vt12c7d88 {
  uint8_t mPadD8[0x4];    // 0xD8 — unproven (alignment)
  uint64_t mFieldDC;      // 0xDC — u32 pair copied from arg x1[0]/x1[8] (ctor 0x8dbf48..0x8dbf54)
  uint64_t mFieldE4;      // 0xE4 — unused here; float region +0xE4..+0xF0 (base tail fills vertices)
  uint64_t mFieldEC;      // 0xEC — u32 pair copied from global [0x12fb058] (ctor 0x8dbf60..0x8dbf74)
  uint64_t mFieldF4;      // 0xF4 — u32 pair copied from arg x2[0]/x2[8] (ctor 0x8dbf78..0x8dbf84)
  uint32_t mFieldFC;      // 0xFC — unproven (alignment)
  uint32_t mField100;     // 0x100 — copy of arg x2[8] (ctor 0x8dbf7c)
  uint8_t mPad104[0x4];   // 0x104 — unproven (alignment)
};

}  // namespace object
