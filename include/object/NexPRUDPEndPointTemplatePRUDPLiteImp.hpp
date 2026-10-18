#pragma once

#include <cstdint>

// object::NexPRUDPEndPointTemplatePRUDPLiteImp - RTTI'd
// nn::nex::PRUDPEndPointTemplatePRUDPLiteImp (typeinfo 0x12e4740); embeds a
// DummyPacketEncDec subobject at +0x10.
// extent 0x18 - details: doc/object/NexPRUDPEndPointTemplatePRUDPLiteImp.md

namespace object {

class NexPRUDPEndPointTemplatePRUDPLiteImp {
 public:
  void* vtable;         // 0x00 - installed 0x12e3bf8 (GOT cell 0x1314700 holds
                        //        0x12e3be8 = vptr-0x10; typeinfo* at vptr-8 = 0x12e4740)
  uint32_t mId;         // 0x08 - endpoint id (factory arg w22)
  uint8_t mPadC[0x4];   // 0x0C - unproven
  void* mVtable10;      // 0x10 - embedded nn::nex::DummyPacketEncDec subobject,
                        //        vptr 0x12e4bc8 (GOT cell 0x1314708 holds 0x12e4bb8
                        //        = vptr-0x10; typeinfo* at vptr-8 = 0x12e4c20)
};

}  // namespace object
