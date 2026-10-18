#pragma once

#include <cstdint>

// Vt12d64a8 — PLACEHOLDER name; stack-passed descriptor (C2 0x8ef5bc, base
// C2 0x73a9f8 over base vptr 0x12beb40); slot 2 scans a region for a
// language byte. Heap size not proven.
// extent 0x58 lower bound - details: doc/game/Vt12d64a8.md
namespace game {
class Vt12d64a8 {
 public:
  void* mVtable;      // 0x00 - vptr 0x12d64a8 (GOT cell 0x1311f90 holds
                      //   vptr-0x10; C2 adds 0x10 after the base C2)
  void* m08;          // 0x08 - arg1 of C2 (stored by base C2 0x73a9f8)
  void* m10;          // 0x10 - arg2 of C2
  void* m18;          // 0x18 - arg3 of C2
  uint8_t m20[0x30];  // 0x20 - unproven gap (no ctor stores; slot 2 touches
                      //   up to this+0x50)
  uint8_t m50;        // 0x50 - touched by slot 2 0x8ef5ec (extent evidence)
  uint8_t m51[7];     // 0x51 - gap to extent lower bound
};
}  // namespace game
