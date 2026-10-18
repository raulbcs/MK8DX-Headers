#pragma once

#include <cstdint>

// Vt12be820 — nn::nifm-band object (ctor 0x736e70; base C1 0xa89768),
// size 0x218 EXACT (operator new(0x218, 8) at 0x735de0/0x8cf530). Two
// rows: primary 0x12be820 (7 slots) and secondary 0x12be868 installed at
// +0x138 (offset-to-top -0x138). extent 0x218 - details:
// doc/game/Vt12be820.md
namespace game {
class Vt12be820 {
 public:
  void* mVtable;       // 0x00 - primary vptr 0x12be820 (GOT cell 0x130eaa8
                       //   holds vptr-0x10 0x12be810)
  uint8_t m08[0x130];  // 0x08 - base subobject built by C1 0xa89768
                       //   (0x736e80), unproven
  void* m138;          // 0x138 - secondary vptr 0x12be868 (ctor stores
                       //   cell 0x130eaa8+0x58; ot -0x138)
  uint8_t m140[0xd8];  // 0x140 - unproven (to extent bound)
};
}  // namespace game
