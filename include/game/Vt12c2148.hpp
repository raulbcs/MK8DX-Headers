#pragma once

#include <cstdint>

// Vt12c2148 — config-ish node, size 0x68 EXACT (operator new(0x68, 8) at
// 0x75025c, C1 0x772fe4, then nonvirtual init 0x7733ac/0x7733a4/0x77338c).
// Slot 4 stores an owner handle at +0x58; slot 0 is a guarded-global
// identity predicate.
// extent 0x68 - details: doc/game/Vt12c2148.md
namespace game {
class Vt12c2148 {
 public:
  void* mVtable;   // 0x00 - row 0x12c2148 (cell 0x130f340 holds vptr-0x10);
                   //   re-installed by slot 2 (0x773038)
  uint32_t m08;    // 0x08 - 0 (C1 0x772fe8); set to 1 by init 0x7733ac
  uint32_t m0c;    // 0x0c - pad
  void* m10;       // 0x10 - 0 (C1, 0x772ffc)
  void* m18;       // 0x18 - 0 (C1)
  float m20;       // 0x20 - 1.0f (C1, 0x772ff0)
  uint32_t m24;    // 0x24 - 0 (C1, stp w9,wzr)
  uint32_t m28;    // 0x28 - 0 (C1, 0x772ff8)
  uint8_t m2c;     // 0x2c - 1 (C1, 0x773008)
  uint8_t mPad2d[3];  // 0x2d - pad to +0x30
  void* m30;       // 0x30 - *(GOT 0x12fae28)+0x10 (C1 0x773014-0x77302c;
                   //   re-stored by init 0x7733ac)
  void* m38;       // 0x38 - *(GOT 0x12fada8) (C1; re-stored by 0x7733ac)
  void* m40;       // 0x40 - same pair repeated (C1 0x773030)
  void* m48;       // 0x48 - same pair repeated (C1)
  void* m50;       // 0x50 - 0 (C1, 0x773028)
  void* m58;       // 0x58 - 0 (C1); owner handle written by virtual slot 4
                   //   (0x773050: m58 = x1)
  uint8_t m60;     // 0x60 - 0 (C1, 0x773020)
  uint8_t mPad61[7];  // 0x61 - pad to extent 0x68
};
}  // namespace game
