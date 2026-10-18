#pragma once

#include <cstdint>

// nn::pia::local::LdnUpdateSessionSetting — RTTI-confirmed (descriptor 0x12e0450,
// name N2nn3pia5local23LdnUpdateSessionSettingE, base LocalUpdateSessionSetting).
// vptr 0x12e03e8 = tsv row + 8. extent 0x178 - details: doc/_nn/pia/local/LdnUpdateSessionSetting.md
namespace nn::pia::local {
class LdnUpdateSessionSetting {
 public:
  void* mVtable;    // 0x00 — 0x12e03e8 (GOT cell 0x1313d70 = vptr-0x10)
  char mPad8[0x4];  // 0x08 — unproven gap
  uint32_t mC;      // 0x0c — 0 (base C1 0x9c9d70)
  char m10[0x168];  // 0x10 — memset 0 (0x9c2444)
};
}  // namespace nn::pia::local
