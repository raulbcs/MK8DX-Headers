#pragma once

#include <cstdint>

#include "_nn/ae/AppletThread.hpp"

namespace nn::ae
{
    // MiiEditAppletThread — rodata-named (0xf0cc3e). Vtable 0x12d0488
    // (cell 0x1310fc8). Ctor attr 0x1000. Extent 0x100: strb @0xf4, s32
    // -1 @0xf8.
    class MiiEditAppletThread : public AppletThread
    {
    public:
        uint8_t mOwn08[0xec];  // 0x08
        uint8_t mFlagF4;       // 0xf4 — ctor zero
        int32_t mFffF8;        // 0xf8 — ctor sets -1
        // (0x100 total)
    };
}
