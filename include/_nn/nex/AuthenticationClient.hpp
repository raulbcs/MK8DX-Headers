#pragma once

#include <cstdint>

namespace nn::nex {
// AuthenticationClient — RTTI-named (typeinfo 0x12e7420, name
// "N2nn3nex20AuthenticationClientE"; base 0x12e73c0 ServiceClient). GOT cell
// 0x1314b68 holds vptr-0x10; heap size 0x48 proven (new at 0xa39bac).
// extent 0x48 - details: doc/_nn/nex/AuthenticationClient.md
class AuthenticationClient {
 public:
  void* mVtable;         // 0x00 - 0x12e6a28 (cell 0x1314b68 + 0x10)
  uint8_t mPad8[0x18];   // 0x08..0x1f - ServiceClient base region (base C1
                         //   0xa326c8); unproven gap
  void* m20;             // 0x20 - member (0x573f04 alloc), init
                         //   0xa2f24c(x, 10) (0xa32b44)
  void* m28;             // 0x28 - member, large alloc, init 0xa29504;
                         //   released by D1 via 0xa29534
  void* m30;             // 0x30 - intrusive list node, alloc 0x28; released
                         //   by D1 via 0xa42414(this+8)
  void* m38;             // 0x38 - zeroed by C1
  uint64_t m40;          // 0x40 - zeroed by C1 (0xa32aec)
};
}  // namespace nn::nex
