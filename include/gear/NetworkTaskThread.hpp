#pragma once

#include <cstdint>

#include "_nn/ae/AppletThread.hpp"

namespace gear {
// NetworkTaskThread — an nn::ae::AppletThread subclass (vptr 0x12cdd30,
// cell 0x1310da8, n=18, ctor 0x851060, sole alloc 0x83806c: new 0x258).
// Evidence: Thread name "gear::NetworkTaskThread" (rodata 0xf0c5ed,
// prio 25, attr 0x10000) passed to the shared nn::ae ctor 0x7100628a54.
//
// Own region: FIVE 0x38-byte descriptor records at 0xf8 (loop i=0..4,
// base 0xf8 + i*0x38). Each record: {void* bufA (+0x00, operator
// new[](0xc0, nothrow, dtor-arg GOT 0x12fae80)), u64 8 (+0x08),
// u32 0 (+0x10), void* bufB (+0x18, new 0xc0), u64 8 (+0x20),
// u32 0 (+0x28), u32 0 (+0x30)}. The scan path (0x8511b4+) walks the
// records (stride 0x38) and indexes bufB contents with a 0x18 stride.
// 0x210: member sub-object (ctor 0x628628, extent 0x40, to 0x250).
class NetworkTaskThread : public nn::ae::AppletThread {
 public:
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

  Record mRecords[5];     // 0xf8 — 5 x 0x38
  uint8_t mSub210[0x40];  // 0x210 — member sub-object (ctor 0x628628)
  uint8_t mFlag250;       // 0x250 — ctor zero
  uint8_t pad251[7];      // 0x251 — to alloc size
                          // (0x258 total)
};
}  // namespace gear
