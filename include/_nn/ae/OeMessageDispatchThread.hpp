#pragma once

#include <cstdint>

namespace nn::ae {
// OeMessageDispatchThread — nn::ae::AppletThread subclass; vptr 0x12d62a0
// (cell 0x1311f68, n=18); field ctor 0x8e8fe4; 5x in-place (stride 0xc00).
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
  // extent 0xc00 (prior-survey 0xc00 total)
};
}  // namespace nn::ae
