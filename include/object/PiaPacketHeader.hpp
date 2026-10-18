#pragma once

#include <cstdint>

// nn::pia::common::Packet::Header - RTTI'd (typeinfo record 0x12f8be0,
// name at 0xf8a730). vptr 0x12f8bb8 installed at [this] by
// FUN_7100b48d6c; extent 0x620 - details:
// doc/object/PiaPacketHeader.md

namespace object {

class PiaPacketHeader {
 public:
  void* vtable;          // 0x00 - 0x12f8bb8 (GOT cell 0x1315f60 holds
                         // 0x12f8ba8 = typeinfo slot; vptr = cell + 0x10)
  uint8_t mPad8[0x5f8];  // 0x08 - body region, unproven gap (ctor writes
                         // magic 0x986432ab @0x8, flags @0xc-0x12,
                         // memset regions 0x14 len 8 / 0x1c len 0x10)
  uint8_t m600[0x18];    // 0x600 - member constructed by 0x92a1e0
                         // two members 0x600..0x618/0x618..0x620 by 0x92a1e0; sizes unproven
  void* m618;            // 0x618 - member constructed by 0x92a1e0
                         // (0x618..0x620; exact size unproven)
                         // (0x620 total, size lower bound)
};

}  // namespace object
