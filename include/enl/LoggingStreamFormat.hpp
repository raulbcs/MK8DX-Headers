#pragma once

#include <cstdint>

// enl::LoggingStreamFormat — stream-format wrapper that logs every access
// (printf-style table 0xeeff31); vptr 0x12b08d0, ctor FUN_7100625f60.
// extent 0xa0 - details: doc/enl/LoggingStreamFormat.md

namespace enl {
class LoggingStreamFormat {
 public:
  void* vtable;          // 0x00 — 0x12b08d0 (ctor 0x625f98)
  void* mFormatter;      // 0x08 — subobject w/ own vptr (cells 0x12fada0/0x12fc1e0/0x12fb180), unverified
  void* mNamePtr;        // 0x10 — this+0x1c or rodata literal 0xeef0f31 (0x625f8c)
  uint32_t mNameCap;     // 0x18 — 0x80 (0x625f9c/0x625fa8)
  char mName[0x80];      // 0x1c — delimiter-scanned name, memcpy 0x626040, unverified
  char mPad9c[0x4];      // 0x9c — gap to allocation size, unproven
};
}  // namespace enl
