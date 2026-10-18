#pragma once

#include <cstdint>

// nn::pia::local::LdnJoinSessionSetting — RTTI-confirmed (descriptor 0x12dfb60,
// name N2nn3pia5local21LdnJoinSessionSettingE, base LocalJoinSessionSetting).
// vptr 0x12dfaf8 = tsv row + 8. extent 0x98 - details: doc/_nn/pia/local/LdnJoinSessionSetting.md
namespace nn::pia::local {
class LdnJoinSessionSetting {
 public:
  void* mVtable;      // 0x00 — 0x12dfaf8 (GOT cell 0x1313d18 = vptr-0x10)
  char mBase8[0x50];  // 0x08 — base C1 0x9c3840 region (unproven gap)
  char m58[0x40];     // 0x58 — memset 0 (0x9bdfc4)
};
}  // namespace nn::pia::local
