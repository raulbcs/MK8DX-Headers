#pragma once

#include <cstdint>

// Vt12c22f0 — mutex-bearing service object with MI, size 0x268 EXACT
// (operator new(0x268) at 0x78bd94, derived C1 0x773a64 over base C1
// 0x5f04c8). Primary vptr at +0x00, secondary at +0x18.
// extent 0x268 - details: doc/game/Vt12c22f0.md
namespace game {
class Vt12c22f0 {
 public:
  void* mVtable;   // 0x00 - primary row 0x12c22f0 (cell 0x130f3a8 holds
                   //   vptr-0x10); base C1 installs a base row, derived C1
                   //   overrides (0x773a8c-0x773a94)
  void* m08;       // 0x08 - base-managed (base C1 0x5f04c8 stp covers
                   //   +0x00..+0x0f with base rows)
  void* m10;       // 0x10 - base row pointer (0x5f04e8)
  void* mSecondary;// 0x18 - secondary row 0x12c2338 (= 0x12c22f0 + 0x48;
                   //   base: cell 0x130c000+0xdc8 +0x58, derived 0x773a90)
  uint8_t mBase20[0x210];  // 0x20 - base-class body (base C1 calls
                   //   0x5f45a4; dtor path 0x5f0524 destroys this+0x18
                   //   sub-object via 0x5f45b8). unverified.
  void* m230;      // 0x230 - 0 (base C1, 0x5f0504)
  void* m238;      // 0x238 - 0 (base C1, 0x5f0500)
  void* m240;      // 0x240 - 0 (derived C1, 0x773a9c); owned child,
                   //   released via its vt[+0x18] by the D1 pair
  void* m248;      // 0x248 - 0 (0x773aa4); owned buffer, freed with
                   //   operator delete by D1
  void* m250;      // 0x250 - 0 (0x773a88)
  void* m258;      // 0x258 - 0 (0x773a84)
  uint8_t m260;    // 0x260 - 0 (0x773a80); flag gating 0x5f0684 call in dtor
  uint8_t mPad261[7];  // 0x261 - pad to extent 0x268
};
}  // namespace game
