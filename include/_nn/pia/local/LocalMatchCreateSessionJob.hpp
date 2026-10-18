#pragma once

#include <cstdint>

// nn::pia::local::LocalMatchCreateSessionJob — RTTI-confirmed (typeinfo
// 0x12e1ac0, "N2nn3pia5local26LocalMatchCreateSessionJobE"); base
// nn::pia::session::CreateSessionJob (vptr 0x12dd988). 10 slots.
// extent 0xa0 - details: doc/_nn/pia/local/LocalMatchCreateSessionJob.md

namespace nn::pia::local {
class LocalMatchCreateSessionJob {
 public:
  void* mVtable;        // 0x00 — 0x12e1a68 (GOT cell 0x1314080 = vptr-0x10)
  char mJobBase8[0x50]; // 0x08 — job-base C1 0xb4a5e0 region (unproven)
  void* mField58;       // 0x58 — 0 (base C1 0x97e8f4)
  char mSub60[0x20];    // 0x60 — 0x20-byte sub-object ctor 0x929ec0 (0x97e920)
  uint32_t mField80;    // 0x80 — 0 (base C1 0x97e924)
  char mPad84[0x4];     // 0x84 — unproven
  void* mField88;       // 0x88 — 0 (derived C1 FUN_71009d1a70, 0x9d1a94)
  void* mField90;       // 0x90 — x1 of the derived C1, a manager singleton
                        //   loaded from cell 0x1312638 (0x9c3ddc, 0x9d1a94)
  void* mField98;       // 0x98 — 0 (derived C1, 0x9d1a90)
};
}  // namespace nn::pia::local
