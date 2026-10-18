#pragma once

#include <cstdint>

// nn::nex::LogicalClockTmpl<int, unsigned short, short> - RTTI'd (typeinfo
// record 0x12e4d38). Static singleton registered in the nex instance tree.
// extent 0x20 - details: doc/object/NexLogicalClock.md

namespace object {

class NexLogicalClock {
 public:
  void* vtable;         // 0x00 - installed 0x12e4d58 (GOT cell 0x1314438 holds
                        //        0x12e4d48 = vptr-0x10; typeinfo* at vptr-8)
  char mPad08[0x8];     // 0x08..0x0f - unproven
  void* mZero10;        // 0x10 - zeroed by static init 0x9f7434
  uint16_t mHw18;       // 0x18 - halfword zeroed by static init
  char mPad1a[0x6];     // 0x1a..0x1f - unproven (size lower bound; static
                        //        global, exact extent unverified)
};

}  // namespace object
