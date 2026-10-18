#pragma once

#include <cstdint>

namespace nn::pia::lan {
// nn::pia::lan::LanSessionSearchCriteria - RTTI-named (typeinfo slot 0x12dc970
// -> record 0x12dc9a0, "N2nn3pia3lan24LanSessionSearchCriteriaE", base
// nn::pia::session::SessionSearchCriteria). vptr 0x12dc978, 5 slots.
// extent 0x258 (lb) - details: doc/_nn/pia/lan/LanSessionSearchCriteria.md
class LanSessionSearchCriteria {
 public:
  void* vtable;       // 0x00 - 0x12dc978 (GOT cell 0x13133e8 + 0x10)
  uint32_t m08;       // 0x08 - base C1 0x99d294 member
  uint32_t m0c;       // 0x0c - C1 sets 100
  char pad10[4];      // pad - unproven gap
  uint32_t m14[2];    // 0x14 - C1 zero pair
  uint8_t m1c[0x50];  // 0x1c - C1 memset 0x50
  uint8_t m6c[0x50];  // 0x6c - C1 memset 0x50
  char padbc[0xa0];   // pad - unproven gap
  uint8_t m15c[0x50]; // 0x15c - C1 memset 0x50
  uint8_t m1ac[0x50]; // 0x1ac - C1 memset 0x50
  char m1fc[0x54];    // 0x1fc - C1 zero block, split unverified
  uint8_t m250[2];    // 0x250 - C1 sets 0xffff
  uint8_t m252;       // 0x252 - C1 sets 1
  uint8_t m253;       // 0x253 - C1 sets 1
  uint32_t m254;      // 0x254 - C1 zero
};
}  // namespace nn::pia::lan
