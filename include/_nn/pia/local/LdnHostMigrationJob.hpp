#pragma once

#include <cstdint>

// nn::pia::local::LdnHostMigrationJob — RTTI-confirmed (descriptor 0x12e1220, name
// N2nn3pia5local19LdnHostMigrationJobE, base LocalHostMigrationJob). vptr
// 0x12e11b8 = tsv row + 8. extent 0xa8 - details: doc/_nn/pia/local/LdnHostMigrationJob.md
namespace nn::pia::local {
class LdnHostMigrationJob {
 public:
  void* mVtable;      // 0x00 — 0x12e11b8 (GOT cell 0x1313e80 = vptr-0x10)
  char mBase8[0x80];  // 0x08 — base subobject, see LocalHostMigrationJob (unproven gap)
  uint32_t m88;       // 0x88 — 100 (0x9cb968)
  uint32_t m8C;       // 0x8c — 500 (0x9cb96c)
  uint8_t m90;        // 0x90 — 5 (0x9cb98c)
  char mPad91[0x7];   // 0x91 — unproven
  void* m98;          // 0x98 — 0 (0x9cb97c)
  uint8_t mA0;        // 0xa0 — 0 (0x9cb980)
  char mPadA1[0x7];   // 0xa1 — unproven
};
}  // namespace nn::pia::local
