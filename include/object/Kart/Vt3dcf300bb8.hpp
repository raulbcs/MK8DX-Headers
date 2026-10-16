#pragma once

#include <cstdint>

namespace object {
// Vt3dcf300bb8 — GAP PROVEN: generic named-worker nn::ae::AppletThread base; no single class
class Vt3dcf300bb8 {
 public:
  void* vtable;          // 0x00
  uint8_t mPad08[0xe8];  // 0x08 — unproven gap
  uint32_t mFieldf0;     // 0xf0 — ctor-written (param pass-through)
                         // (extent unknown)
  // extent 0xf4 (ctor 0x7100628a54 stores reach 0xf4)
};
}  // namespace object
