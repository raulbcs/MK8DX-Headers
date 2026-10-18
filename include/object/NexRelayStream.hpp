#pragma once

#include <cstdint>

// object::NexRelayStream - RTTI'd nn::nex::RelayStream (typeinfo 0x12e3fe0);
// derived from nn::nex::RefCountedObject (base ctor 0x9e4484, vptr 0x12e3410).
// extent 0x60 - details: doc/object/NexRelayStream.md

namespace object {

class NexRelayStream {
 public:
  void* vtable;          // 0x00 - installed 0x12e3658 (GOT cell 0x1314670 holds
                         //        0x12e3648 = vptr-0x10; typeinfo* at vptr-8 = 0x12e3fe0)
  uint32_t mRefCount;    // 0x08 - RefCountedObject base body, init 11 by base ctor
  uint8_t mPadC[0x4];    // 0x0C - unproven
  void* m10;             // 0x10 - zeroed by ctor
  uint8_t mPad18[0x8];   // 0x18 - unproven
  void* mList20;         // 0x20 - ctor stores this+0x28 (list-head node)
  void* m28;             // 0x28 - zeroed by ctor
  void* m30;             // 0x30 - zeroed by ctor
  uint32_t m38;          // 0x38 - ctor stores 3*n (n from a global NPL table entry+0xb8)
  uint8_t mPad3C[0x4];   // 0x3C - unproven
  uint8_t m40[0x8];      // 0x40 - member inited by 0x575b3c(this+0x40)
  uint32_t m48;          // 0x48 - ctor stores -1
  uint32_t m4C;          // 0x4C - ctor stores -1
  void* m50;             // 0x50 - zeroed by ctor
  uint32_t m58;          // 0x58 - zeroed by ctor
  uint8_t mPad5C[0x4];   // 0x5C - unproven
};

}  // namespace object
