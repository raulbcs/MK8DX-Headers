#pragma once

#include <cstdint>

// recorder::ChannelSetVt12d1580 — ChannelSet derivative built by
// recorderCreateRotChannel_710088ad40: base recorderCreateRotTransChannels_71007ae16c,
// then vptr override (GOT cell 0x1311280, vptr = cell+0x10). Factories 0x288.
// extent 0x288 - details: doc/recorder/ChannelSetVt12d1580.md

namespace recorder {
class ChannelSetVt12d1580 {
 public:
  void* mVtable;          // 0x00 — 0x12d1580
  uint8_t mPad8[0x270];   // 0x08 — ChannelSet base fields (see doc/recorder/ChannelSet.md)
  void* mRotChild;        // 0x278 — rot channel (new 0x290, vptr 0x12d18f8/0x12d1a20)
  void* mTransChild;      // 0x280 — trans channel (new 0x288, vptr 0x12d16a8/0x12d17d0)
};
}  // namespace recorder
