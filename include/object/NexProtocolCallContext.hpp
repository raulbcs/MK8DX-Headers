#pragma once

#include <cstdint>

// object::NexProtocolCallContext - RTTI'd nn::nex::ProtocolCallContext (typeinfo
// 0x12e62a0); CallContext/RefCountedObject chain; stack-constructed (sret), no
// heap alloc site. extent 0xc0 - details: doc/object/NexProtocolCallContext.md

namespace object {

class NexProtocolCallContext {
 public:
  void* vtable;          // 0x00 - installed 0x12e5de8 (GOT cell 0x13149c0 holds
                         //        0x12e5dd8 = vptr-0x10; typeinfo* at vptr-8 = 0x12e62a0);
                         //        ctor first installs RefCountedObject 0x128c798 (cell
                         //        0x130b618) then CallContext 0x128cc20 (cell 0x130b740)
  uint32_t mAtomic8;     // 0x08 - stlr 1 (state/flag, release semantics)
  uint8_t mC;            // 0x0C - zeroed by ctor
  uint8_t mPadD[0x3];    // 0x0D - unproven
  void* m10;             // 0x10 - zeroed by ctor
  uint32_t m18;          // 0x18 - zeroed by ctor
  uint8_t mPad1C[0x4];   // 0x1C - unproven
  void* mList20;         // 0x20 - waiter list head: [0x20]=[0x28]=this+0x20
  void* mList28;         // 0x28 - (list next/prev self-ref)
  void* m30;             // 0x30 - zeroed by ctor
  void* m38;             // 0x38 - zeroed by ctor
  void* m40;             // 0x40 - zeroed by ctor
  void* m48;             // 0x48 - zeroed by ctor
  void* m50;             // 0x50 - zeroed by ctor
  uint8_t m58[0x18];     // 0x58 - member inited by 0x5788e0(this+0x58, &timeout) with
                         //        timeout word 0x80010000
  void* m70;             // 0x70 - zeroed by ctor
  uint32_t m78;          // 0x78 - zeroed by ctor
  uint8_t mPad7C[0x4];   // 0x7C - unproven
  void* m80;             // 0x80 - zeroed by ctor
  void* m88;             // 0x88 - zeroed by ctor
  void* m90;             // 0x90 - zeroed by ctor
  void* m98;             // 0x98 - zeroed by ctor
  void* mA0;             // 0xA0 - zeroed by ctor
  void* mA8;             // 0xA8 - zeroed by ctor
  void* mB0;             // 0xB0 - zeroed by ctor
  void* mB8;             // 0xB8 - Credentials* (ctor arg x1, stored by 0xa2c030)
};

}  // namespace object
