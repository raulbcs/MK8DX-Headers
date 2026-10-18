#pragma once

#include <cstdint>

// Vt12b9ba8 - PLACEHOLDER name (agl resource-handler object keyed by "txt",
// ids 0x2d/0x30; two factory variants share this vtable). Composite 0x160
// object built inline in FUN_71006ceab0; base vtable row 0x12b9c58.
// extent 0x160 - details: doc/object/Vt12b9ba8.md

namespace object {
class Vt12b9ba8 {
 public:
  void* vtable;         // 0x00 - installed 0x12b9ba8 (initial base-row vptr
                        //        [0x130e268]+0x10 = 0x12b9c68, then replaced)
  void* mManager_08;    // 0x08 - registry/manager ptr (x22 in factory)
  uint32_t mId_10;      // 0x10 - resource-type id 0x2d (45) or 0x30 (48)
  char mPad14[4];        // 0x14 - alignment padding
  void* mEntry_18;      // 0x18 - manager table entry (x25 + idx*0x38)
  void* mSelf_20;       // 0x20 - this+0x20 (twice)
  void* mSelf_28;       // 0x28
  uint64_t mZero_30;    // 0x30 - zeroed
  uint64_t mZero_38;    // 0x38 - zeroed
  void* mMemberA_40;    // 0x40 - embedded member vptr ([0x12fada0]+0x10 =
                        //        0x11ad0f8, overridden 0x11ad158)
  char mPad48[0x10];    // 0x48 - member A: ptr this+0x54 (+0x48), guard
                        //        0x40 (+0x50), payload byte (+0x54)
  char mPad58[0x40];    // 0x58..0x97 - member A body (unproven)
  void* mMemberB_98;    // 0x98 - embedded member vptr (0x11ad0f8 ->
                        //        0x11ad158)
  char mPadA0[0x10];    // 0xa0 - member B: ptr this+0xac (+0xa0), guard
                        //        0x100 (+0xa8), payload byte (+0xac)
  char mPadB0[0x40];    // 0xb0..0xef - member B body (unproven)
  uint32_t mNeg1_F0;    // 0xf0 - -1
  char mPadF4[4];       // 0xf4 - alignment padding
  void* mMemberC_F8;    // 0xf8 - embedded member vptr (0x11ad0f8 ->
                        //        0x11ad158)
  char mPad100[0x10];   // 0x100 - member C: ptr this+0x10c (+0x100), guard
                        //        0x40 (+0x108), payload byte (+0x10c)
  char mPad110[0x40];   // 0x110..0x14f - member C body (unproven)
  uint32_t mNeg1_150;   // 0x150 - -1
  uint32_t mFlags_154;  // 0x154 - 8
  uint8_t mZero_158;   // 0x158 - 0 (variant B writes it; variant A leaves
                       //        the alloc-zeroed byte)
  char mPad159[7];     // 0x159 - padding to alloc size 0x160
};
}  // namespace object
