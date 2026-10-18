#pragma once

#include <cstdint>

// nn::pia::local::LdnOutputStream — RTTI-confirmed (typeinfo 0x12dff10, no base
// class_type_info); vptr 0x12dfea8 = tsv row + 8, secondary vptr 0x12dfef8 at
// +0x10. extent 0x600 - details: doc/_nn/pia/local/LdnOutputStream.md
namespace nn::pia::local {
class LdnOutputStream {
 public:
  void* mVtable;       // 0x00 — 0x12dfea8 (GOT cell 0x1313d30 = vptr-0x10)
  uint64_t m8;         // 0x08 — 0 (base C1 0x9c41dc)
  void* mVtable10;     // 0x10 — secondary vptr 0x12dfef8 (C1; sub-base C1 0xb4a570)
  uint8_t m18;         // 0x18 — 0 (sub C1 0xb4a578; polled by slot 3)
  char mPad19[0x7];    // 0x19 — unproven gap
  void* m20;           // 0x20 — 0 (sub C1 0xb4a57c)
  char mPad28[0x5d8];  // 0x28 — unproven gap (allocator-only tail)
};
}  // namespace nn::pia::local
