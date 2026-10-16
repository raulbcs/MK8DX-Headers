#pragma once

#include <cstdint>

// AppletThread — PROVISIONAL name (SDK/glue); applet-thread family base;
// shared ctor 0x7100628a54, member-init 0x7100628f3c; vtable 0x12b0a58;
// extent 0xf8.

namespace nn::ae {
class AppletThread {
 public:
  void* vptr;            // 0x00 — 0x12b0a58 for the base class
  uint8_t mOwn08[0xec];  // 0x08 — SDK-internal (thread/event/queue), own fields unmapped
  uint8_t mFlagF4;       // 0xf4 — shared ctor strb zero
  uint8_t padF5[3];      // 0xf5 — unproven padding
  // (0xf8 total)
};
}  // namespace nn::ae
