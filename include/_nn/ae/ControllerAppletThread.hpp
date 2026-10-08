#pragma once

#include <cstdint>

#include "_nn/ae/AppletThread.hpp"

namespace nn::ae {
// ControllerAppletThread — rodata-named (0xf0cc10). Vtable 0x12d0348
// (cell 0x1310fb8). Ctor attr 0x2000. Extent 0x318: strb @0xf4
// (0x12c rel), u32 @0x314 (0x34c rel), memset 0xf5-0x312.
class ControllerAppletThread : public AppletThread {
 public:
  uint8_t mOwn08[0xec];  // 0x08 — SDK-internal (AppletThread interior), map pending
  uint8_t mFlagF4;       // 0xf4 — ctor zero
  uint8_t padF5[0x21f];  // 0xf5 — memset 0
  uint32_t mZero314;     // 0x314 — ctor zero
                         // (0x318 total)
};
}  // namespace nn::ae
