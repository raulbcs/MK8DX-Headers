#pragma once

#include <cstdint>

#include "_nn/ae/AppletThread.hpp"

namespace gear {
// NetworkTaskThread — nn::ae::AppletThread subclass (vptr 0x12cdd30, cell 0x1310da8, ctor 0x7100851060, new 0x258)
struct Record {
  void* bufA;      // +0x00 — new[](0xc0, nothrow)
  uint64_t lenA;   // +0x08 — ctor sets 8
  uint32_t rsv10;  // +0x10 — ctor zero
  uint32_t pad14;  // +0x14
  void* bufB;      // +0x18 — new[](0xc0, nothrow)
  uint64_t lenB;   // +0x20 — ctor sets 8
  uint32_t rsv28;  // +0x28 — ctor zero
  uint32_t pad2c;  // +0x2c — untouched by ctor
  uint32_t rsv30;  // +0x30 — ctor zero
  uint32_t pad34;  // +0x34 — untouched by ctor
                   // (0x38 per record)
};

class NetworkTaskThread : public nn::ae::AppletThread {
 public:
  struct Record mRecords[5];  // 0xf8 — 5 x 0x38
  uint8_t mSub210[0x40];      // 0x210 — member sub-object (ctor 0x628628)
  uint8_t mFlag250;           // 0x250 — ctor zero
  uint8_t pad251[7];          // 0x251 — to alloc size
                              // (0x258 total)
  // extent 0x258 (ctor 0x7100851060, sole alloc 0x83806c: new 0x258 (docblock))
};
}  // namespace gear
