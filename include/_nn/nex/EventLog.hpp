#pragma once

#include <cstdint>

namespace nn::nex {
// EventLog — RTTI-confirmed (ti 0x128c460); vptr 0x128c000 (n=5); 44
// refs in 0x583154-0x583cxx; writer objects 0x50 B (helper 0x576368).
// extent 0x50 (writer alloc / WebSocketClient instantiation)
class EventLog {
 public:
  void* vtable;           // 0x00 — 0x128c000
  uint8_t mBase08[0x18];  // 0x08 — Log/LockChecker base region
  void* mField20;         // 0x20 — vptr+caller qword stored by the writer
  uint8_t mPad28[0x8];    // 0x28 — unproven padding
  uint32_t mFlag30;       // 0x30 — stlr w9 (=1, 32-bit) at site 0x583254
  uint8_t mZero34;        // 0x34 — ctor zero
  uint8_t mPad35[0x3];    // 0x35 — unproven padding
  uint8_t pad_38[0x18];   //0x38 — unproven gap
                          // (writer objects are 0x50 bytes; tail unmapped)
};
}  // namespace nn::nex
