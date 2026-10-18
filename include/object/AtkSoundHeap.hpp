#pragma once

#include <cstdint>

// nn::atk::SoundHeap - RTTI'd (typeinfo record 0x12f1c20). Built as base
// subobject of game classes; size lower bound 0x40 - details:
// doc/object/AtkSoundHeap.md

namespace object {

class AtkSoundHeap {
 public:
  void* vtable;         // 0x00 - installed 0x12f1bf8 (GOT cell 0x1314fb8
                        //        holds 0x12f1be8 = vptr-0x10; typeinfo* at
                        //        vptr-8 = 0x12f1bf0)
  char mMutex08[0x20];  // 0x08 - nn::os::MutexType (InitializeMutex 1, 0)
  void* mList28;        // 0x28 - list head, zeroed; teardown 0xa7dc2c
  void* mList30;        // 0x30 - first = this+0x30
  void* mList38;        // 0x38 - last = this+0x30
};

}  // namespace object
