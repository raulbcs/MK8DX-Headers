#pragma once

#include <cstdint>

namespace game {
// Unnamed class; arena-constructed with size 0xa0 (FUN_71006b0b08, alloc
// w1=0xa0 via 0x69ea94); also embedded at +0x28 of a larger in-place
// aggregate (C1 FUN_71006a9c1c). All slots are unrecovered FUN_*.
// extent 0xa0 (arena alloc size 0xa0 at 0x6b0b48) -
// details: doc/game/Vt12f4210.md
class Vt12f4210 {
 public:
  void* vtable;           // 0x00 - vptr 0x12f4210 (GOT cell 0x130dfb0 holds
                          // 0x12f4200 = vptr-0x10; off-top 0, no typeinfo);
                          // base ctor 0xaec2a4 first installs the base vptr
                          // (cell 0x130dfa8), ctor re-installs 0x12f4210
  uint8_t mPad8[0x70];    // 0x08 - unproven gap (base class area)
  void* mField78;         // 0x78 - copied from global 0x12fb148 {ptr,count}
  uint32_t mField80;      // 0x80 - copied from global 0x12fb148+8
  uint32_t mField84;      // 0x84 - ctor writes 0
  uint64_t mField88;      // 0x88 - ctor writes 0; dst of 0x60b930(...,8)
  void* mField90;         // 0x90 - ctor writes 0
  uint32_t mField98;      // 0x98 - ctor writes 0
  uint8_t mPad9c[0x4];    // 0x9c - unproven padding (to 0xa0)
};
}  // namespace game
