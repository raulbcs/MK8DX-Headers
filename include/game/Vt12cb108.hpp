#pragma once

#include <cstdint>

namespace game {
// Byml-driven parameter-table record (base): C1 0x8144d0, parse-from-node
// virtual in slot 0 (0x8147d8). Ten interleaved default/limit blocks
// (0xa8..0x2b3) seeded from global cells 0x12fb148/0x12fb178/0x12fb150.
// extent 0x360 - details: doc/game/Vt12cb108.md
class Vt12cb108 {
 public:
  void* vtable;        // 0x00 - vptr 0x12cb108 (GOT cell 0x13106a8 holds
                       // 0x12cb0f8 = vptr-0x10)
  int32_t mField8;     // 0x08 - -1 at C1
  void* mFieldC;       // 0x0c - 8 bytes from global cell 0x12fb148
  uint32_t mField14;   // 0x14 - u32 from cell 0x12fb148+0x8
  uint8_t mField18[0xc];  // 0x18 - written by parse slot 0 (0x8147d8)
  void* mField24;      // 0x24 - 8 bytes from cell 0x12fb148
  uint32_t mField2c;   // 0x2c - u32 from cell 0x12fb148+0x8
  uint64_t mSentries30[0xb];  // 0x30..0x87 - -1 sentinel words (C1)
  uint32_t mField88;   // 0x88 - u32 from cell 0x12fb3e8
  uint32_t mField8c;   // 0x8c - u32 from cell 0x12fb7c8
  void* mField90;      // 0x90 - 8 bytes from cell 0x12fb148
  uint32_t mField98;   // 0x98 - u32 from cell 0x12fb148
  void* mField9c;      // 0x9c - 8 bytes from cell 0x12fb150
  uint8_t mPadA4[0x4]; // 0xa4 - padding
  uint8_t mBlocksA8[0x23a];  // 0xa8..0x2e1 - default/limit table:
                             // 10x {x,y,z,extra} triplets (stride 0xc,
                             // bases 0xa8/0x170/0x210), 10x float 0x7f7fffff
                             // at 0x120, 10x 0xffff at 0x288, 10x
                             // 0x7f7fffff at 0x2b0 region - default/
                             // limit table, unverified per-slot split
  uint16_t mFlag2e2;   // 0x2e2 - u16 = 1 at C1 (parse writes here)
  uint16_t mFlags2e4;  // 0x2e4 - flag read by slot getters 1-4 (csel on
                       // this halfword); 0 at C1
  uint16_t mPad2e6;    // 0x2e6 - padding
  uint32_t mField2e8;  // 0x2e8 - s16 from parse node, zeroed at C1
  uint32_t mField2ec;  // 0x2ec - zeroed at C1
  uint32_t mListCount2f0;  // 0x2f0 - list count/head
  uint32_t mListCap2f4;    // 0x2f4
  void* mListArray2f8;     // 0x2f8 - node array (stride-8)
  void* mLists300[0x7];    // 0x300..0x337 - intrusive list links/heads
                           // (self-ptrs 0x310..0x330 at C1)
  uint8_t mTail338[0x28];  // 0x338..0x35f - 5 x 8 link cells (arg 3 of
                           // InitList(this+0x2f0, 5, this+0x338))
};
}  // namespace game
