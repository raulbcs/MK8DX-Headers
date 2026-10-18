#pragma once

#include <cstdint>

// nn::nex::qProtectedList<StationURL> - RTTI'd (typeinfo record 0x12e4e28).
// Static singleton at .bss 0x13616c0 with rodata sentinel pair at +0x18.
// extent 0x28 - details: doc/object/NexProtectedListStationURL.md

namespace object {

class NexProtectedListStationURL {
 public:
  void* vtable;         // 0x00 - installed 0x12e4e48 (GOT cell 0x1314570 holds
                        //        0x12e4e38 = vptr-0x10; typeinfo* at vptr-8)
  uint32_t mZero08;     // 0x08 - zeroed by static init
  char mPad0c[0x4];     // 0x0c - unproven
  void* mZero10;        // 0x10 - zeroed by static init 0x9f74d0 cluster
  void* mSentinel18;    // 0x18 - rodata sentinel 0xed6af8 (list end marker,
  void* mSentinel20;    // 0x20 - stored twice by init 0x9f7538)
                        //        (size lower bound; exact extent unverified)
};

}  // namespace object
