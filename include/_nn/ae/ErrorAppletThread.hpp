#pragma once

#include <cstdint>

#include "_nn/ae/AppletThread.hpp"

namespace nn::ae {
// ErrorAppletThread — rodata-named (0xf0cc52). Vtable 0x12d0528
// (cell 0x1310fd0; vptr reaches code only through that cell — sites
// 0x10aa44 and 0x1b649c, the latter embedding the thread as a
// sub-object at host+0x298). Extent 0xfc: strb at 0xf4 is the last
// field; the D1 dtor 0x628dfc touches at most 0xe0 (ptr freed, +8 =
// 0xe8). The host object continues right after this sub-object with
// its inline nn::err::ErrorResultVariant — that host-side block is the
// source of the large extents seen in the enclosing host, not this class.
class ErrorAppletThread : public AppletThread {
 public:
  uint8_t mOwn08[0xec];  // 0x08
  uint8_t mFlagF4;       // 0xf4 — ctor zero
  uint8_t padF5[7];      // 0xf5 — unproven padding
                         // (0xfc total)
};
}  // namespace nn::ae
