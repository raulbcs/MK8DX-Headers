#pragma once

#include <cstdint>

// nn::nex::ConnectionManager - RTTI'd (typeinfo record 0x12e3f30, base
// TransportEventHandler 0x12e3f10). StreamTable subobject at +0x108.
// extent 0x128 - details: doc/object/NexConnectionManager.md

namespace object {

class NexConnectionManager {
 public:
  void* vtable;         // 0x00 - installed 0x12e2bf8 (GOT cell 0x13142b0 holds
                        //        0x12e2be8 = vptr-0x10; typeinfo* at vptr-8)
  char mPad08[0x100];   // 0x08..0x107 - unproven (TransportEventHandler base
                        //        body per record base ptr 0x12e3f10)
  void* mStreamTable;   // 0x108 - secondary vptr 0x12e3488 (cell 0x13142c0,
                        //        typeinfo record 0x12e4370 "StreamTable")
  void* mListPred;      // 0x110 - list link pred (unlinked by D2 0x9e3a20)
  void* mListNext;      // 0x118 - list link next
  void* mListHead;      // 0x120 - head checked non-null before unlink
                        //        (size lower bound; exact extent unverified)
};

}  // namespace object
