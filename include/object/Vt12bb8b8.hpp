#pragma once

#include <cstdint>

// Vt12bb8b8 - PLACEHOLDER name; 0xd890-byte destroy-once singleton
// ("Turbo_area0"/"Diffuse" strings in its big C1) with 16 embedded
// 0xc0-stride sub-objects; instance cell 0x130e558, guard 0x12fce58.
// extent 0xd890 - details: doc/object/Vt12bb8b8.md

namespace object {
class Vt12bb8b8 {
 public:
  void* vtable;            // 0x00 - 0x12bb8b8 (GOT cell 0x130e560 holds
                           // 0x12bb8a8 = vt-0x10; no typeinfo row)
  void* mMember08;         // 0x08 - embedded member vptr, row 0x12bb898
                           // (GOT cell 0x130e550 = 0x12bb888 = vt-0x10)
  char mPad10[0x28];       // 0x10..0x37 - unproven
  uint64_t mField38;       // 0x38 - member initialized by 0x63194c
  char mPad40[0x18];       // 0x40..0x57 - unproven
  void* mField58;          // 0x58 - zeroed by C1
  void* mField60;          // 0x60 - zeroed by C1
  void* mField68;          // 0x68 - zeroed by C1
  char mPad70[0xf0];       // 0x70..0x15f - unproven
  uint8_t mElems160[16 * 0xc0];  // 0x160..0xd5f - 16 x 0xc0 sub-objects;
                           // C1 loop (0x6ffec8-0x6ffeec) installs primary
                           // vptr (cell 0x130e568 row 0x12bb8a0) at each
                           // +0x160+i*0xc0 and a secondary from cell
                           // 0x12fae28+0x10 next to it
  char mPadD760[0x130];    // 0xd60..0xd88f - unproven (ctor continues
                           // past 0xc160 with further init)
};
}  // namespace object
