#pragma once

#include <cstdint>

// Vt12bd660 — KartParamCache-family object (C1 FUN_7100728c20, heap factory
// FUN_710072abf8: operator new(0x470) at 0x72ac2c). GOT cell 0x130e8b0 holds
// vt-0x10; slots 6-12 are the shared paramCache cluster.
// extent 0x470 - details: doc/object/Vt12bd660.md

namespace object {
class Vt12bd660 {
 public:
  void* mVtable;          // 0x00 — vptr 0x12bd660 (cell 0x130e8b0+0x10)
  uint8_t m8[0x1C8];      // 0x08 — unproven (C1 + base init 0x728edc-path members)
  uint32_t m1D0;          // 0x1d0 — 0 (0x728c7c)
  uint32_t m1D4;          // 0x1d4 — unproven
  uint8_t m1D8[0x30];     // 0x1d8 — member ctor 0x66a2a4(this+0x1d8) (0x728c80)
  uint8_t m208[0x248];    // 0x208 — unproven tail; +0x208 member built with
                          //        vptr cell 0x130daa8+0x10 and rodata 0xed6af8
                          //        (0x728c84-0x728cc4)
  uint8_t m450[0x20];     // 0x450 — unproven (object runs to 0x470)
};
}  // namespace object
