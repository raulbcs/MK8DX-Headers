#pragma once

#include <cstdint>

// nn::nex::NATTraversalEngine - RTTI'd (typeinfo record 0x12e41f0). URLProbe
// List secondary at +0xf8; qVector of SharedPtr<Socket> at +0x1b0.
// extent 0x1c8 - details: doc/object/NexNatTraversalEngine.md

namespace object {

class NexNatTraversalEngine {
 public:
  void* vtable;         // 0x00 - installed 0x12e30f8 (GOT cell 0x1314480 holds
                        //        0x12e30e8 = vptr-0x10; typeinfo* at vptr-8)
  uint32_t mZero08;     // 0x08 - zeroed by factory
  char mPad0c[0x4];     // 0x0c - unproven
  char mPad10[0x20];    // 0x10..0x2f - zeroed by factory
  void* mListPred30;    // 0x30 - 0 by factory (self-referencing link pair
  void* mListSelf38;    // 0x38 - factory stores this+0x38 here and at 0x40)
  void* mListSelf40;    // 0x40 - = this+0x38
  void* mZero48;        // 0x48 - zeroed by factory
  void* mSec50;         // 0x50 - stp {secondary vptr 0x12e3580, ...} pair
  void* mSec58;         // 0x58 - second pair word (factory 0x9f269c)
  char mPad60[0x98];    // 0x60..0xf7 - unproven
  void* mVptrF8;        // 0xf8 - secondary vptr 0x12e3580 (cell 0x1314428,
                        //        typeinfo record 0x12e4450 "URLProbeList")
  char mPad100[0xb0];   // 0x100..0x1af - unproven
  void* mVecElems1b0;   // 0x1b0 - qVector storage (SharedPtr<Socket>)
  void* mVecEnd1b8;     // 0x1b8 - vector end
  void* mVecCap1c0;     // 0x1c0 - vector capacity end (D2 0x9eb400 unlinks)
};

}  // namespace object
