#pragma once

#include <cstdint>

// nn::pia::lan::LanMatchmakeUpdateJob — RTTI-confirmed (typeinfo 0x12dd3c0,
// base pia::common::StepSequenceJob); vptr 0x12dd378 = tsv row + 8.
// extent 0xec0 - details: doc/_nn/pia/lan/LanMatchmakeUpdateJob.md
namespace nn::pia::lan {
class LanMatchmakeUpdateJob {
 public:
  void* mVtable;         // 0x00 — 0x12dd378 (GOT cell 0x1313640 = vptr-0x10)
  char mJobBase8[0x50];  // 0x08 — shared pia job-base C1 0xb4a5e0 region (unproven gap)
  void* m58;             // 0x58 — C1 arg x1 (session/context ptr, 0x97bb44)
  void* mVtable60;       // 0x60 — sub-object vptr, sub-ctor 0xb49bb8 (region to 0xb18)
  char mPad68[0xab0];    // 0x68 — unproven gap (sub-object body, C1 stores only vptr)
  void* mB18;            // 0xb18 — sub-object built by 0x973a74 (region to 0xd78)
  char mPadB20[0x258];   // 0xb20 — unproven gap
  void* mVtableD78;      // 0xd78 — sub-object built by 0x929ec0 (region to 0xd98)
  char mPadD80[0x18];    // 0xd80 — unproven gap
  void* mD98;            // 0xd98 — 0 (0x97bb68)
  char mPadDa0[0x10];    // 0xda0 — memset 0 (0x97bb70-0x97bb80)
  char mPadDb0[0x10];    // 0xdb0 — memset 0 (0x97bb70-0x97bb80)
  char mPadDc0[0x100];   // 0xdc0 — unproven gap (allocator-only tail)
};
}  // namespace nn::pia::lan
