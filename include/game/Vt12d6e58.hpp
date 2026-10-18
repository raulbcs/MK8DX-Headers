#pragma once

#include <cstdint>

// Vt12d6e58 — PLACEHOLDER name; secondary vtable (offset-to-top -0x80) of the shared
// subobject base constructed by 0x8bdd9c; used as +0x80 descriptor of Vt12d6c60's product.
// extent 0x88 (lower bound: 0x8bdd9c initializes through +0x83; complete object unverified) -
// details: doc/game/Vt12d6e58.md

namespace game {
class Vt12d6e58 {
 public:
  void* mVtable;         // 0x00 — subobject base vptr (0x8bdd9c: GOT cell 0x13119e0+0x10)
  uint8_t mPad8[0x8];    // 0x08 — zeroed by 0x8bdd9c (stp at 0x8bddd4)
  void* mField10;        // 0x10 — 0 (0x8bdd9c)
  int32_t mField18;      // 0x18 — -1 (0x8bddc0)
  uint32_t mPad1C;       // 0x1c — unproven padding
  void* mField20;        // 0x20 — 0 (0x8bddc4)
  uint8_t mPad28[0x10];  // 0x28 — zeroed by 0x8bdd9c (0x8bddb4)
  uint32_t mField38;     // 0x38 — 0 (0x8bddac)
  uint32_t mPad3C;       // 0x3c — unproven padding
  void* mField40;        // 0x40 — 0 (0x8bddc8)
  uint8_t mPad48[0x10];  // 0x48 — zeroed by 0x8bdd9c (0x8bddbc)
  int32_t mField58;      // 0x58 — -0x7ffffff1 (0x8bddec)
  uint32_t mPad5C;       // 0x5c — unproven padding
  uint64_t mField60;     // 0x60 — 0 (0x8bdda8)
  int32_t mField68;      // 0x68 — -1 (0x8bddcc)
  uint32_t mPad6C;       // 0x6c — unproven padding
  uint64_t mField70;     // 0x70 — 0 (0x8bddd0)
  uint8_t mByte78;       // 0x78 — 1 (0x8bdddc)
  uint8_t mPad79[0x3];   // 0x79 — unproven padding
  uint32_t mField7C;     // 0x7c — 5 (0x8bdde4)
  uint32_t mField80;     // 0x80 — -1 (0x8bdde4 stp second word)
  uint8_t mPad84[0x4];   // 0x84 — unproven padding to lower-bound extent
};
}  // namespace game
