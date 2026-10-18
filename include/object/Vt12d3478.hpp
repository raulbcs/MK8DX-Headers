#pragma once

#include <cstdint>

// Vt12d3478 — PLACEHOLDER name; construction-stage primary vtable (6 slots) of
// a 0x2D0 class family; ctor 0x896BA4, factories 0x3D8E00/0x3D8E48/0x3D8E90.
// extent 0x2d0 - exact (operator new 0x2D0 in every factory) -
// details: doc/object/Vt12d3478.md

namespace object {
class Vt12d3478 {
 public:
  void* mVtable;       // 0x00 — 0x12d3478 during base-ctor stage; later 0x12d34b8,
                       //        then a concrete-family row from cells 0x1308230..0x1308258
  void* mPad08[3];     // 0x08 — zeroed by ctor
  void* mVtable20;     // 0x20 — secondary row 0x12d3508; concrete families overwrite
  void* mPad28[3];     // 0x28 — zeroed by ctor
  void* mVtable40;     // 0x40 — secondary row 0x12d34e0
  void* mPad48[5];       // 0x48 — unproven padding
  void* mPtr70;          // 0x70 — self-pointer to +0x7C
  uint8_t mPad78[0xF0];  // 0x78 — unproven (member ctors 0x61CC48 at +0x68, +0x118)
  uint8_t mPad168[0x160];  // 0x168 — unproven padding
  void* mPtr2C8;         // 0x2C8 — nulled/zeroed by factories
};
}  // namespace object
