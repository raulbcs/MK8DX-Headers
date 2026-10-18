#pragma once

#include <cstdint>

// Vt12d6340 - PLACEHOLDER name; zero-initialized 0x40 intrusive node created
// inline by SystemEngine::postCalc, back-linked to syseng+0x178/+0x1a8.
// extent 0x40 - details: doc/object/Vt12d6340.md

namespace object {

class Vt12d6340 {
 public:
  void* mVtable;        // 0x00 - 0x12d6340 (GOT cell 0x13119b0 holds 0x12d6330
                       //        = vt-0x10; no typeinfo row, ot = 0)
  char mPad08[0x10];   // 0x08..0x17 - zero-filled by the creator, unproven
  void* mSelf18;       // 0x18 - set to this by the creator (list node)
  char mPad20[0x8];    // 0x20 - cleared; prior value refcount-decremented
  void* mOwner28;      // 0x28 - syseng+0x178 (owner back-pointer)
  void* mField30;      // 0x30 - [syseng+0x1a8] copy
  char mPad38[0x8];    // 0x38..0x3f - zero-filled, unproven
};

}  // namespace object
