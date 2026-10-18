#pragma once

#include <cstdint>

// Vt12c33c8 — PLACEHOLDER name; base of the 12c3250/12c3850 cluster.
// C2 0x7956fc installs this vptr; two intrusive lists + counters.
// extent 0x98 lower bound - details: doc/game/Vt12c33c8.md
namespace game {
class Vt12c33c8 {
 public:
  void* mVtable;   // 0x00 - vptr 0x12c33c8 (GOT cell 0x130f730 holds
                   //   vptr-0x10; C2 adds 0x10)
  uint32_t m08;    // 0x08 - 0 (init); dtor path reads it as a count
  uint32_t m0c;    // 0x0c - tail pad / unproven
  uint64_t m10;    // 0x10 - 0 (init)
  uint64_t m18;    // 0x18 - 0 (init)
  uint32_t m20;    // 0x20 - 0 (init); dtor path compares it (state?)
  uint32_t m24;    // 0x24 - tail pad / unproven
  uint64_t m28;    // 0x28 - 0 (init)
  uint64_t m30;    // 0x30 - unproven gap
  uint64_t m38;    // 0x38 - unproven gap
  uint64_t m40;    // 0x40 - 0 (init)
  uint64_t m48;    // 0x48 - 0 (init)
  uint8_t m50;     // 0x50 - 1 (init, bool)
  uint8_t m51[7];  // 0x51 - unproven gap
  void* m58;       // 0x58 - 0 (init); child pointer walked by D1 0x795784
  void* mList60;   // 0x60 - intrusive list head, self-init to this+0x60
  void* m68;       // 0x68 - list tail, self-init to this+0x60
  uint32_t m70;    // 0x70 - 0 (init)
  uint32_t m74;    // 0x74 - 8 (init)
  void* mList78;   // 0x78 - second intrusive list head, self-init to
                   //   this+0x78 (walked with count +0x8c by 0x7957cc)
  void* m80;       // 0x80 - list tail, self-init to this+0x78
  uint32_t m88;    // 0x88 - 0 (init)
  uint32_t m8c;    // 0x8c - 8 (init)
  uint32_t m90;    // 0x90 - unproven gap
  uint8_t m94;     // 0x94 - 0xff (init)
  uint8_t m95[3];  // 0x95 - unproven gap to extent lower bound
};
}  // namespace game
