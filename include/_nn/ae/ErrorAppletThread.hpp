#pragma once

#include <cstdint>

#include "_nn/ae/AppletThread.hpp"

namespace nn::ae
{
    // ErrorAppletThread — rodata-named (0xf0cc52). Vtable 0x12d0528
    // (cell 0x1310fd0). Ctor attr 0x1000. Extent 0xfc (strb @0xf4,
    // 0xb84 rel; host stores nn::err::ErrorResultVariant right after).
    class ErrorAppletThread : public AppletThread
    {
    public:
        uint8_t mOwn08[0xec];  // 0x08
        uint8_t mFlagF4;       // 0xf4 — ctor zero
        uint8_t padF5[7];      // 0xf5
        // (0xfc total)
    };
}
