#pragma once

#include <cstdint>

// object::NexRoutingStream - RTTI'd nn::nex::RoutingStream (typeinfo 0x12e47e0);
// derived from nn::nex::RefCountedObject (base ctor 0x9e4484, vptr 0x12e3410).
// extent 0xd0 - details: doc/object/NexRoutingStream.md

namespace object {

class NexRoutingStream {
 public:
  void* vtable;         // 0x00 - installed 0x12e3c90 (GOT cell 0x13147d8 holds
                        //        0x12e3c80 = vptr-0x10; typeinfo* at vptr-8 = 0x12e47e0)
  uint32_t mRefCount;   // 0x08 - RefCountedObject base body, init 8 by base ctor
  uint8_t mPadC[0x4];   // 0x0C - unproven
  void* mList10;        // 0x10 - list-head trio: ctor stores this+0x18; [0x18]=[0x20]=0
  void* m18;            // 0x18 - zeroed by ctor
  void* m20;            // 0x20 - zeroed by ctor
  void* mList28;        // 0x28 - second list-head trio: ctor stores this+0x30;
                        //        [0x30]=[0x38]=0 (member torn down by D1 via 0xa1ac24)
  void* m30;            // 0x30 - zeroed by ctor
  void* m38;            // 0x38 - zeroed by ctor
  uint8_t m40[0x58];    // 0x40..0x97 - member inited by 0x574a70(this+0x48, 1, 1);
                        //             torn down by D1 via 0x576340(this+0x48)
  void* m98;            // 0x98 - member ptr (arg of D1 teardown 0xa1b1f4)
  void* mA0;            // 0xA0 - member ptr (second arg of D1 teardown 0xa1b1f4)
  uint8_t mPadA8[0x28]; // 0xA8..0xCF - unproven
};

}  // namespace object
