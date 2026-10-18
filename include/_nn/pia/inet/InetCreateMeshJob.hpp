#pragma once

#include <cstdint>

// nn::pia::inet::InetCreateMeshJob — RTTI-named (embedded typeinfo at
// 0x12da530). Size 0x60 proven: alloc wrapper 0x931814 (new 0x60) before C1.
// extent 0x60 - details: doc/_nn/pia/inet/InetCreateMeshJob.md

namespace nn::pia::inet {
class InetCreateMeshJob {
 public:
  void* mVtable;         // 0x00 — vptr 0x12da4d8 (GOT cell 0x1312a18
                         //   holds vptr-0x10; C1 adds 0x10, 0x9373c8)
  uint8_t mPad08[0x28];  // 0x08 — base region (base C1 0x97e0e4)
  void* mField30;        // 0x30 — cell 0x1312a20 value (Setup
                         //   0x93744c)
  void* mField38;        // 0x38 — xzr (Setup 0x937444 stp)
  void* mField40;        // 0x40 — 0xf0e048 static string/table ptr
  uint8_t mPad48[0x18];  // 0x48 — unverified tail to 0x60
};
}  // namespace nn::pia::inet
