#pragma once

#include <cstdint>

// nn::pia::session::JoinSessionJob — RTTI-confirmed (descriptor 0x12ddc70, name
// N2nn3pia7session14JoinSessionJobE). vptr 0x12ddbd8 = tsv row + 8; cell 0x1313760
// holds vptr-0x10. extent 0x118 - details: doc/_nn/pia/session/JoinSessionJob.md
namespace nn::pia::session {
class JoinSessionJob {
 public:
  void* mVtable;         // 0x00 — 0x12ddbd8 (GOT cell 0x1313760 = vptr-0x10)
  char mJobBase8[0x50];  // 0x08 — shared base C1 0xb4a5e0 region (unproven gap)
  void* m58;             // 0x58 — 0 (C1 0x9823f4)
  void* mVtable60;       // 0x60 — same vptr 0x12ddbd8 (D1 post-inc store 0x982450);
                         //        sub-object ctor 0x929ec0
  char mPad68[0x18];     // 0x68 — unproven gap
  void* mVtable80;       // 0x80 — vptr of sub-object built by 0x9b1fe8 (unverified)
  char mPad88[0x70];     // 0x88 — unproven gap
  void* mF8;             // 0xf8 — 0 (0x982410)
  uint8_t m100;          // 0x100 — 0 (0x982414)
  char mPad101[0x7];     // 0x101 — unproven
  void* m108;            // 0x108 — 0 (0x982418)
  void* m110;            // 0x110 — 0 (0x98241c)
};
}  // namespace nn::pia::session
