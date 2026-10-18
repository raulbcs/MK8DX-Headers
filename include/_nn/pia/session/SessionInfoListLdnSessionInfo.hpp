#pragma once

#include <cstdint>

namespace nn::pia::session {
// nn::pia::session::SessionInfoList<nn::pia::local::LdnSessionInfo> —
// RTTI-named (typeinfo 0x12dfe80, base ISessionInfoList). C2 0x9be4ac.
// extent 0x18 - details: doc/_nn/pia/session/SessionInfoListLdnSessionInfo.md
class SessionInfoListLdnSessionInfo {
 public:
  void* vtable;         // 0x00 - 0x12dfe38 (GOT cell 0x1313d28 + 0x10)
  uint16_t m08;         // 0x08 - live entry count (u16; reset by 0x9be718)
  uint16_t m0a;         // 0x0a - capacity (u16, C2 arg w1)
  char pad0c[0x04];     // 0x0c..0x0f - unverified gap
  LdnSessionInfo** m10; // 0x10 - new'd array of m0a pointers (count*8), each
                        //   entry new 0xbe0 via LdnSessionInfo C2 0x9c1a80
};
}  // namespace nn::pia::session
