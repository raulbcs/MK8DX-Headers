#pragma once

#include <cstdint>

// nn::pia::local::LdnCreateSessionSetting — RTTI-confirmed (descriptor 0x12dfad0,
// name N2nn3pia5local23LdnCreateSessionSettingE, base LocalCreateSessionSetting).
// vptr 0x12dfa68 = tsv row + 8. extent 0x238 - details: doc/_nn/pia/local/LdnCreateSessionSetting.md
namespace nn::pia::local {
class LdnCreateSessionSetting {
 public:
  void* mVtable;      // 0x00 — 0x12dfa68 (GOT cell 0x1313d10 = vptr-0x10)
  char mBase8[0x48];  // 0x08 — base C1 0x9c293c region (unproven gap)
  void* m50;          // 0x50 — 0x9762c8 static (cell 0x1313478 + 0x10, 0x9bdd08)
  void* m58;          // 0x58 — 0 (0x9bdd08)
  uint32_t m60;       // 0x60 — 0 (0x9bdcd8)
  char mPad64[0x40];  // 0x64 — memset 0 (0x9bdd0c)
  uint8_t mA4;        // 0xa4 — 0 (0x9bdce4)
  char mA5[0x180];    // 0xa5 — memset 0 (0x9bdd10)
  char mPad225[0x3];  // 0x225 — unproven
  uint32_t m228;      // 0x228 — 0 (0x9bdce8)
  uint16_t m22C;      // 0x22c — 0 (0x9bdcec)
  char mPad22E[0x2];  // 0x22e — unproven
  uint8_t m230;       // 0x230 — 0 (0x9bdd20)
  char mPad231[0x7];  // 0x231 — unproven
};
}  // namespace nn::pia::local
