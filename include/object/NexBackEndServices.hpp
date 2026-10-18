#pragma once

#include <cstdint>

// object::NexBackEndServices - RTTI'd nn::nex::BackEndServices (typeinfo 0x12e7480);
// never heap-allocated standalone (base subobject of RendezVous, alloc 0x270); size
// lower bound only. extent 0x1b4 - details: doc/object/NexBackEndServices.md

namespace object {

class NexBackEndServices {
 public:
  void* vtable;          // 0x00 - installed 0x12e6b78 (GOT cell 0x1314bd0 holds
                         //        0x12e6b68 = vptr-0x10; typeinfo* at vptr-8 = 0x12e7480)
  uint32_t m10;          // 0x10 - zeroed by ctor
  uint8_t mPad8[0x8];    // 0x08 - unproven (RefCountedObject tail)
  uint8_t mPad14[0x4];   // 0x14 - unproven
  uint8_t m18;           // 0x18 - zeroed by ctor
  uint8_t mPad19[0x7];   // 0x19 - unproven
  uint8_t mCallCtx[0x58]; // 0x20 - embedded nn::nex::CallContext member (ctor installs
                          //        RefCountedObject vptr 0x128c798 then CallContext vptr
                          //        0x128cc20; atomic 1 at +0x28; waiter list self-ref at
                          //        +0x40/+0x48 -> this+0x40)
  uint8_t m78[0x18];     // 0x78 - member inited by 0x5788e0(this+0x78, &timeout) with
                         //        timeout word 0x80010000
  void* m90;             // 0x90 - zeroed by ctor
  uint32_t m98;          // 0x98 - zeroed by ctor
  uint8_t mPad9C[0x4];   // 0x9C - unproven
  void* mA0;             // 0xA0 - zeroed by ctor
  void* mA8;             // 0xA8 - zeroed by ctor
  void* mB0;             // 0xB0 - zeroed by ctor
  uint32_t mB8;          // 0xB8 - ctor stores 30000 (timeout ms)
  uint8_t mPadBC[0x4];   // 0xBC - unproven
  void* mC0;             // 0xC0 - zeroed by ctor (backend ptr; read by slots 4/5)
  uint8_t mPadC8[0x50];  // 0xC8..0x117 - unproven
  uint32_t m118;         // 0x118 - zeroed by ctor
  uint8_t mPad11C[0x4];  // 0x11C - unproven
  void* m120;            // 0x120 - zeroed by ctor
  void* m128;            // 0x128 - zeroed by ctor
  uint8_t m130;          // 0x130 - ctor stores 1
  uint8_t mPad131[0x7];  // 0x131 - unproven
  uint8_t m138[0x74];    // 0x138 - member inited by 0x9f5754(this+0x138)
  uint8_t m1AC[0x8];     // 0x1AC - member inited by 0xa2a008(this+0x1ac)
};

}  // namespace object
