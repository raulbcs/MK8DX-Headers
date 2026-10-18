#pragma once

#include <cstdint>

namespace nn::pia::local {
// nn::pia::local::LocalJoinSessionSetting — RTTI-named (typeinfo 0x12e0700,
// name "N2nn3pia5local23LocalJoinSessionSettingE", base
// session::JoinSessionSetting). C2 0x9c3840, D2 0x9c38dc.
// extent 0x58 - details: doc/_nn/pia/local/LocalJoinSessionSetting.md
class LocalJoinSessionSetting {
 public:
  void* vtable;      // 0x00 - 0x12e0698 (GOT cell 0x1313da8 + 0x10)
  char pad08[0x10];  // 0x08..0x17 - JoinSessionSetting base fields (base C2
                     //   0x98324c: +0x08 zero, +0x10 zero, h +0x14 zero;
                     //   base vptr cell 0x1313790)
  void* m18;         // 0x18 - secondary base subobject, vptr 0x12d9748 (cell
                     //   0x1312858 + 0x10); name unverified
  uint32_t m20;      // 0x20 - set to this+0x34 by C2 (list head, unverified)
  char pad24[0x04];  // 0x24 - padding
  uint32_t m28;      // 0x28 - C2 sets 0x20
  uint32_t m2c;      // 0x2c - C2 zero
  char pad30[0x04];  // 0x30..0x33 - padding
  char m34[0x24];    // 0x34..0x57 - zeroed 0x34-byte block (byte/halfword
                     //   stores)
};
}  // namespace nn::pia::local
