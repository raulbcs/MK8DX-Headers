#pragma once

#include <cstdint>

// Vt12b9a28 - PLACEHOLDER name (agl resource-handler object keyed by "txt",
// ids 0x31/0x33; two factory variants share this vtable). Composite 0x1b8
// object built inline in FUN_71006ceab0; base vtable row 0x12b9ad8.
// extent 0x1b8 - details: doc/object/Vt12b9a28.md

namespace object {
class Vt12b9a28 {
 public:
  void* vtable;         // 0x00 - installed 0x12b9a28 (initial base-row vptr
                        //        [0x130e260]+0x10 = 0x12b9ae8, then replaced)
  void* mManager_08;    // 0x08 - registry/manager ptr (x22 in factory)
  uint32_t mId_10;      // 0x10 - resource-type id 0x31 (49) or 0x33 (51)
  char mPad14[4];       // 0x14 - alignment padding
  void* mEntry_18;      // 0x18 - manager table entry (x25 + idx*0x38)
  void* mSelf_20;       // 0x20 - this+0x20 (twice)
  void* mSelf_28;       // 0x28
  uint64_t mZero_30;    // 0x30 - zeroed
  uint64_t mZero_38;    // 0x38 - zeroed
  void* mMemberA_40;    // 0x40 - embedded member vptr (GOT 0x12fada0 =
                        //        0x11ad0f8, overridden 0x11ad158 via GOT
                        //        0x12fadb0)
  char mPad48[0x10];    // 0x48 - member A: ptr this+0x54 (+0x48), guard
                        //        0x40 (+0x50), payload byte (+0x54)
  char mPad58[0x40];    // 0x58..0x97 - member A body (unproven)
  void* mMemberB_98;    // 0x98 - embedded member vptr (overridden to
                        //        [0x12fbd88]+0x10 = 0x11b39b8)
  char mPadA0[0x10];    // 0xa0 - member B: ptr this+0xac (+0xa0), guard
                        //        0x100 (+0xa8), payload byte (+0xac)
  char mPadB0[0x100];   // 0xb0..0x1af - member B body (unproven)
  uint32_t mFlags_1B0;  // 0x1b0 - 8
  uint32_t mExtHash_1B4;// 0x1b4 - hash("txt", rodata 0xf02be4) via
                        //        FUN_710062fd48
};
}  // namespace object
