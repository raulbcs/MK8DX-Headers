#pragma once

#include <cstdint>

#include "_nn/ae/AppletThread.hpp"

namespace nn::ae
{
    // OfflineWebAppletThread — rodata-named (0xf0cc27). Vtable 0x12d03e8
    // (cell 0x1310fc0). Ctor attr 0x2000. Extent 0xf8 (strb @0xf4).
    class OfflineWebAppletThread : public AppletThread
    {
    public:
        uint8_t mOwn08[0xec];  // 0x08
        uint8_t mFlagF4;       // 0xf4 — ctor zero
        // (0xf8 total)
    };
}
