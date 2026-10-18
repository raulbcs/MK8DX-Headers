#pragma once

#include <cstdint>

// object::NexPRUDPEndPointTemplateImp - RTTI'd nn::nex::PRUDPEndPointTemplateImp
// (typeinfo 0x12e46e0); embeds an RC4PacketEncDec member at +0x10.
// extent 0xd0 - details: doc/object/NexPRUDPEndPointTemplateImp.md

namespace object {

class NexPRUDPEndPointTemplateImp {
 public:
  void* vtable;          // 0x00 - installed 0x12e3b68 (GOT cell 0x1314710 holds
                         //        0x12e3b58 = vptr-0x10; typeinfo* at vptr-8 = 0x12e46e0)
  uint32_t mId;          // 0x08 - endpoint id (ctor arg w22, stored by factory 0xa03894)
  uint8_t mPadC[0x4];    // 0x0C - unproven
  void* mVtable10;       // 0x10 - embedded nn::nex::RC4PacketEncDec member, vptr 0x12e3240
                         //        (cell 0x1314560; member ctor 0x9f3574)
  uint8_t mPad18[0x8];   // 0x18 - member body: [0x18]=node+8, list self-ref trio at
                         //        [0x18]/[0x20] built by 0x9f35a0-0x9f35ac
  void* m20;             // 0x20 - member list node (see above)
  void* m28;             // 0x28 - zeroed by member ctor
  uint8_t mPad30[0xa0];  // 0x30..0xCF - unproven (RC4PacketEncDec body)
};

}  // namespace object
