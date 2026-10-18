#pragma once

#include <cstdint>

// nn::pia::session::RandomMatchmakeJob — RTTI-confirmed (typeinfo 0x12de3a0,
// "N2nn3pia7session18RandomMatchmakeJobE"); 12 slots + one null entry; base of
// nn::pia::lan::LanMatchRandomMatchmakeJob. GOT cell 0x1313988 holds
// vptr-0x10. extent 0x120 - details: doc/_nn/pia/session/RandomMatchmakeJob.md

namespace nn::pia::session {
class RandomMatchmakeJob {
 public:
  void* mVtable;         // 0x00 — 0x12de308 (cell 0x1313988 + 0x10)
  char mJobBase8[0x50];  // 0x08 — job-base C1 0xb4a5e0 region (unproven)
  char mField58[0x10];   // 0x58 — zeroed as a pair (C1 0x9957fc stp xzr,xzr)
  uint16_t mField68;     // 0x68 — 0 (C1 0x9957f8 strh)
  char mPad6a[0x2];      // 0x6a — unproven (ctor writes nothing)
  uint32_t mField6c;     // 0x6c — 0 (C1 0x995808 str)
  char mPad70[0x10];     // 0x70 — unproven (ctor writes nothing)
  char mSub80[0x78];     // 0x80 — 0x78-byte sub-object, elem ctor 0x9b1fe8
                         //   (0x995810; size per JoinMeshJob entry arrays)
  char mSubF8[0x20];     // 0xf8 — 0x20-byte sub-object ctor 0x929ec0 (0x995818)
  void* mField118;       // 0x118 — 0 (C1 0x99581c)
};
}  // namespace nn::pia::session
