#pragma once

#include <cstdint>

// nn::nex::DataStoreGetObjectEventListenerTemplate<unsigned int> -
// RTTI'd (typeinfo record 0x12f84b0, name at 0xf89da0). Installed
// inline by FUN_7100b2f270; extent 0x48 - details:
// doc/object/NexDataStoreGetObjectEventListenerTemplate.md

namespace object {

class NexDataStoreGetObjectEventListenerTemplate {
 public:
  void* vtable;       // 0x00 - 0x12f8478 (GOT cell 0x1315d30 holds
                      // 0x12f8468 = typeinfo slot; vptr = cell + 0x10)
  void* mSecondary;   // 0x08 - secondary vptr 0x12f7d48 (base nex
                      // listener; cell 0x1315d38 holds 0x12f7d58)
  void* mOwner;       // 0x10 - site this + 0xc0
  void* mEntry;       // 0x18 - element from owner array [owner+0x498]
  uint8_t m20;        // 0x20
  uint8_t mPad21[7];  // 0x21 - unproven gap
  uint64_t m28;       // 0x28
  uint64_t m30;       // 0x30
  uint32_t m38;       // 0x38
  uint16_t m3c;       // 0x3c
  uint8_t mPad3e[2];  // 0x3e - unproven gap
  uint32_t m40;       // 0x40
  uint8_t mPad44[4];  // 0x44 - tail pad (size 0x48, factory alloc)
};

}  // namespace object
