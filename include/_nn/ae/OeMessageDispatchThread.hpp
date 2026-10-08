#pragma once

#include <cstdint>

namespace nn::ae {
// OeMessageDispatchThread — an nn::ae::AppletThread subclass (vptr
// 0x12d62a0, cell 0x1311f68, n=18, field ctor 0x8e8fe4). Evidence:
// Thread name "OeMessageDispatchThread" (rodata 0xf0d6e4, len 0xd,
// prio 13, attr 0x2000) passed to the shared nn::ae ctor 0x7100628a54
// at site 0x8ea6d8; the site then writes 0xf4/0xf5/0xf6/0xf7 and the
// 0xf8 qword, and stores this at host+0x38. Constructed IN PLACE five
// times (host offsets 0xc4e8/0xd0e8/0xdce8/0xe8e8/0xf4e8 — stride
// 0xc00, the object size).
//
// Field ctor: 0x08 u32 = 0; TWENTY 0x98-stride blocks starting at 0x00
// (loop to 0xbe0): per block B, B+0x10 u64 = 0, B+0x18 u32 = 0,
// B+0x1c u8 = 0, memset(B+0x20, 0, 0x84); B+0x00..0x10 untouched
// (per-block gap). Final: 0xbf0/0xbf8 u64 = 0.
// Site extras: 0xf4 u8 = 0; 0xf5 u8 = (nn::oe::GetOperationMode() == 0);
// 0xf6 u8 = (nn::oe::GetPerformanceMode() == 1); 0xf7 u8 = 0;
// 0xf8 u64 = 0x1'00000001 (two u32 1s).
class OeMessageDispatchThread {
 public:
  struct Block {
    uint8_t gap00[0x10];  // +0x00 — untouched by ctor
    uint64_t zero10;      // +0x10 — ctor zero
    uint32_t zero18;      // +0x18 — ctor zero
    uint8_t zero1c;       // +0x1c — ctor zero
    uint8_t pad1d[3];     // +0x1d
    uint8_t buf20[0x84];  // +0x20 — memset 0x84
    uint8_t pada4[0x14];  // +0xa4 — untouched by ctor (to 0x98 stride)
                          // (0x98 per block)
  };

  void* vptr;         // 0x00 — cell 0x1311f68
  uint32_t mZero08;   // 0x08 — ctor zero
  uint32_t pad0c;     // 0x0c — unproven padding
  Block mBlocks[20];  // 0x10 — 20 x 0x98 (to 0xbf0)
  uint64_t mZeroBf0;  // 0xbf0 — ctor zero
  uint64_t mZeroBf8;  // 0xbf8 — ctor zero
                      // (0xc00 total)
};
}  // namespace nn::ae
