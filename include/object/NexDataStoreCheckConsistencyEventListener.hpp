#pragma once

#include <cstdint>

// nn::nex::DataStoreCheckConsistencyEventListener - RTTI'd (typeinfo
// record 0x12f8420, name at 0xf89d20). Installed inline by
// FUN_7100b2d374; extent 0x38 - details:
// doc/object/NexDataStoreCheckConsistencyEventListener.md

namespace object {

class NexDataStoreCheckConsistencyEventListener {
 public:
  void* vtable;       // 0x00 - 0x12f83e8 (GOT cell 0x1315cc8 holds
                      // 0x12f83d8 = typeinfo slot; vptr = cell + 0x10)
  void* mSecondary;   // 0x08 - secondary vptr 0x12f7c88 (base nex
                      // listener; cell 0x1315cd0 holds 0x12f7c78)
  void* mOwner;       // 0x10 - site this + 0xc0
  void* mEntry;       // 0x18 - element from owner array [owner+0x498]
  uint8_t m20;        // 0x20
  uint8_t mPad21[3];  // 0x21 - unproven gap
  uint32_t m24;       // 0x24
  uint64_t m28;       // 0x28
  uint32_t m30;       // 0x30
  uint16_t m34;       // 0x34
  uint16_t m36;       // 0x36
};

}  // namespace object
