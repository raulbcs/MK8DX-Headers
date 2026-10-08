#pragma once

#include <cstdint>

#include "_nn/ae/AppletThread.hpp"

namespace nn::ae {
// NifmAppletThread — rodata-named (0xf0cc64). Vtable 0x12d05c8
// (cell 0x1310fd8). Ctor attr 0x2000. Extent 0x100 (strb @0xf4).
class NifmAppletThread : public AppletThread {
 public:
  uint8_t mOwn08[0xec];  // 0x08 — SDK-internal (AppletThread interior), map pending
  uint8_t mFlagF4;       // 0xf4 — ctor zero
  uint8_t padF5[7];      // 0xf5 — unproven padding
  uint8_t padFc[4];      // 0xfc — to host's next member
                         // (0x100 total)
};
}  // namespace nn::ae
