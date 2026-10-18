#pragma once

#include <cstdint>

// nn::pia::transport::DisconnectStationJob — RTTI-confirmed (typeinfo 0x12decf0,
// base pia::common::StepSequenceJob); vptr 0x12deca8 = tsv row + 8.
// extent 0x80 - details: doc/_nn/pia/transport/DisconnectStationJob.md
namespace nn::pia::transport {
class DisconnectStationJob {
 public:
  void* mVtable;         // 0x00 — 0x12deca8 (GOT cell 0x1313af0 = vptr-0x10)
  char mJobBase8[0x50];  // 0x08 — shared pia job-base C1 0xb4a5e0 region (unproven gap)
  void* m58;             // 0x58 — 0 (C1 0x9a2ecc)
  uint32_t m60;          // 0x60 — 4000 (C1 0x9a2ee0, timeout ms?)
  char mPad64[0x4];      // 0x64 — unproven gap
  void* m68;             // 0x68 — 0 (C1 0x9a2ed8)
  void* m70;             // 0x70 — 0 (C1 0x9a2ed8)
  uint32_t m78;          // 0x78 — 500 (C1 0x9a2ef0, retry/step ms?)
  uint8_t m7c;           // 0x7c — 0 (C1 0x9a2ee8)
  char mPad7d[0x3];      // 0x7d — unproven gap
};
}  // namespace nn::pia::transport
