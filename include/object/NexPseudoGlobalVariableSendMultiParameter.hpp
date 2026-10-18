#pragma once

#include <cstdint>

// nn::nex::PseudoGlobalVariable<SendMultiParameter> - RTTI'd (typeinfo record
// 0x12e28b0, name "N2nn3nex20PseudoGlobalVariableI18SendMultiParameterEE").
// Global-lifetime wrapper registered into the nex instance tree.
// extent 0x170 - details: doc/object/NexPseudoGlobalVariableSendMultiParameter.md

namespace object {

class NexPseudoGlobalVariableSendMultiParameter {
 public:
  void* vtable;         // 0x00 - installed 0x12e2868 (GOT cell 0x1314180 holds
                        //        0x12e2858 = vptr-0x10; typeinfo* at vptr-8)
  char mPad08[0x160];   // 0x08..0x167 - unproven
  void* mMember168;     // 0x168 - subobject destroyed by D1 0x9d4b98
                        //        (size lower bound; exact extent unverified)
};

}  // namespace object
