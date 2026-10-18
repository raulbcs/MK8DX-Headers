#pragma once

#include <cstdint>

namespace nn::pia::session {
// SessionInfoList<nn::pia::lan::LanSessionInfoPrivate> — RTTI-named (typeinfo
// 0x12dc430, name "N2nn3pia7session15SessionInfoListINS0_3lan21LanSessionInfo
// PrivateEEE"; base session::ISessionInfoList). 9 slots; GOT cell 0x1313318
// holds vptr-0x10 (vptr 0x12dc3e8).
// extent 0x18 - details:
// doc/_nn/pia/session/SessionInfoListLanSessionInfoPrivate.md
class SessionInfoListLanSessionInfoPrivate {
 public:
  void* mVtable;        // 0x00 - vptr 0x12dc3e8 (cell 0x1313318 + 0x10)
  uint16_t mCount08;    // 0x08 - element count (u16)
  uint16_t mCap0a;      // 0x0a - capacity (u16, C1 arg w1)
  uint8_t mPad0c[0x4];  // 0x0c - pad to pointer field
  void* mElems10;       // 0x10 - new[] array of cap*8 pointers (freed by D1)
};
}  // namespace nn::pia::session
