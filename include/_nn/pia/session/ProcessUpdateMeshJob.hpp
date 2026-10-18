#pragma once

#include <cstdint>

// nn::pia::session::ProcessUpdateMeshJob — RTTI-confirmed (typeinfo 0x12de2e0,
// base nn::pia::common::StepSequenceJob); vptr 0x12de2a8 = tsv row + 8.
// extent 0x120 - details: doc/_nn/pia/session/ProcessUpdateMeshJob.md
namespace nn::pia::session {
class ProcessUpdateMeshJob {
 public:
  void* mVtable;         // 0x00 — 0x12de2a8 (GOT cell 0x1313948 = vptr-0x10)
  char mJobBase8[0x40];  // 0x08 — shared pia job-base C1 0xb4a5e0 region (unproven gap)
  uint8_t mJobBase48;    // 0x48 — cleared by shared slot-2 fn 0xb4a654 (unproven gap)
  char mPad49[0xf];      // 0x49 — unproven gap
  void* m58;             // 0x58 — 0 (C1 0x992874)
  uint32_t m60;          // 0x60 — 20000 (0x4e20, C1 0x992874)
  uint32_t m64;          // 0x64 — 20000 (0x4e20, C1 0x992874)
  void* m68;             // 0x68 — 0 (C1 0x992874)
  uint32_t m70;          // 0x70 — 10000 (0x2710, C1 0x992874)
  char mPad74[0xc];      // 0x74 — unproven gap
  char mBuffer80[0x20];  // 0x80 — memset 0xff (C1 0x992874)
  char mPadA0[0x28];     // 0xa0 — unproven gap
  uint16_t mC8;          // 0xc8 — 0 (C1 0x992874)
  uint16_t mCa;          // 0xca — 0 (C1 0x992874)
  uint8_t mCc;           // 0xcc — 0 (C1 0x992874)
  char mPadCd[0x3];      // 0xcd — unproven gap
  uint32_t mD0;          // 0xd0 — 0 (C1 0x992874)
  uint8_t mD4;           // 0xd4 — 0 (C1 0x992874)
  char mPadD5[0xb];      // 0xd5 — unproven gap
  void* mE0;             // 0xe0 — 0 (C1 0x992874)
  void* mE8;             // 0xe8 — 0 (C1 0x992874)
  uint32_t mF0;          // 0xf0 — 0 (C1 0x992874)
  char mPadF4;           // 0xf4 — unproven gap
  uint8_t mF5;           // 0xf5 — 0 (C1 0x992874)
  uint8_t mF6;           // 0xf6 — 0 (C1 0x992874)
  char mPadF7;           // 0xf7 — unproven gap
  uint32_t mF8;          // 0xf8 — 0 (C1 0x992874)
  uint8_t mFc;           // 0xfc — 1 (C1 0x992874)
  char mPadFd[0x3];      // 0xfd — unproven gap
  char mSub100[0x20];    // 0x100 — sub-object, builder 0x929ec0 (vtable-proven region)
};
}  // namespace nn::pia::session
