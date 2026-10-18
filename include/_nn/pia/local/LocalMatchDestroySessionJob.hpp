#pragma once

#include <cstdint>

// nn::pia::local::LocalMatchDestroySessionJob — RTTI-confirmed (typeinfo
// 0x12e1b40, "N2nn3pia5local27LocalMatchDestroySessionJobE"); base
// nn::pia::session::DestroySessionJob (vptr 0x12dda70). 10 slots.
// extent 0x90 - details: doc/_nn/pia/local/LocalMatchDestroySessionJob.md

namespace nn::pia::local {
class LocalMatchDestroySessionJob {
 public:
  void* mVtable;        // 0x00 — 0x12e1ae8 (GOT cell 0x13140c0 = vptr-0x10)
  char mJobBase8[0x50]; // 0x08 — job-base C1 0xb4a5e0 region (unproven)
  void* mField58;       // 0x58 — 0 (base C1 0x97f094)
  char mSub60[0x20];    // 0x60 — 0x20-byte sub-object ctor 0x929ec0 (0x97f0c0)
  void* mField80;       // 0x80 — 0 (base C1 0x97f0c4)
  char mPad88[0x8];     // 0x88 — unproven (ctor writes nothing)
};
}  // namespace nn::pia::local
