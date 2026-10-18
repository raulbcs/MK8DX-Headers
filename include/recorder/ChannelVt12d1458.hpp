#pragma once

#include <cstdint>

// recorder::ChannelVt12d1458 — read-side recorder channel derived from the
// QuantChannelReadVt (0x12c3da0) family: ctor FUN_7100889c6c calls the read
// head 0x7ad494 (quantum 0x18) then overrides the vptr (cell 0x13111e0).
// extent 0x288 - details: doc/recorder/ChannelVt12d1458.md

namespace recorder {
class ChannelVt12d1458 {
 public:
  void* mVtable;          // 0x00 — 0x12d1458
  uint8_t mPad8[0x280];   // 0x08 — read-channel head fields (see doc/recorder/QuantChannelReadVt.md)
};
}  // namespace recorder
