#pragma once

#include <cstdint>

// Vt12ceb08 — interface row of a Network:: heap stub family: 8-slot abstract
// table (never installed), stub row 0x12ceb58, concrete row 0x12ceb70
// (54 slots) installed by init entry 0x85d3c4 inside FUN_710085d228.
// extent 0x680 - details: doc/object/Vt12ceb08.md

namespace object {
class Vt12ceb08 {
 public:
  void* vtable;         // 0x00 — concrete vptr 0x12ceb70 (init 0x85d3f8);
                        //        outer wrapper FUN_7100396e44 re-installs
                        //        derived vptr 0x125fed0 afterwards (0x396e64)
  char mPad8[0x4d0];    // 0x08 — managed by init FUN_710085d228, unproven
  void* mListHead;      // 0x4d8 — ctor zeroes (0x85d3ec)
  void* mListTail;      // 0x4e0 — ctor zeroes (0x85d3e0)
  void* mNode4e8;       // 0x4e8 — list node self-ptr (0x85d434)
  void* mNode4f0;       // 0x4f0 — (0x85d468)
  void* mNode4f8;       // 0x4f8 — this+0x4f8 (0x85d41c)
  char mPad500[0x10];   // 0x500 — unproven
  void* mNode510;       // 0x510 — this+0x510 (0x85d424)
  char mPad518[0x10];   // 0x518 — unproven
  void* mNode528;       // 0x528 — this+0x528 (0x85d42c)
  char mPad530[0x10];   // 0x530 — unproven
  void* mListHead540;   // 0x540 — head of 0x18-stride node chain
                        //        +0x540..+0x600 (0x85d3fc..0x85d464)
  char mPad548[0x130];  // 0x548 — unproven
  uint16_t mField678;   // 0x678 — 0x100 after init (0x85d474)
  char mPad67a[0x6];    // 0x67a — unproven padding to 0x680
};
}  // namespace object
