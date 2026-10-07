#pragma once

#include <cstdint>

#include "_nn/ae/AppletThread.hpp"

namespace nn::ae
{
    // KeyboardAppletThread — rodata-named (0xf0cbd4). Vtable 0x12d0228
    // (cell 0x1310fa8). Ctor attr 0x4000. Extent 0x548: strb @0xf4
    // (0x444 rel), memset 0xf8-0x528, four nn::swkbd work buffers
    // (GetRequiredWorkBufferSize/TextCheck/String):
    //   0x518 mStrBuf (size @0x544), 0x520 mWorkBuf, 0x528 mTextCheckBuf,
    //   0x530 mWorkBuf2 (0x878 rel), u32 size @0x544 (0x894 rel).
    class KeyboardAppletThread : public AppletThread
    {
    public:
        uint8_t mOwn08[0xec];  // 0x08
        uint8_t mFlagF4;       // 0xf4 — ctor zero
        uint8_t padF5[0x523];  // 0xf5 — memset 0
        void* mBuf518;         // 0x518 — swkbd string buffer (0x868)
        void* mBuf520;         // 0x520 — swkbd string buffer copy (0x870)
        void* mBuf528;         // 0x528 — text-check work (0x878)
        void* mBuf530;         // 0x530 — swkbd work (0x880)
        uint8_t pad538[0xc];   // 0x538 — unproven padding
        uint32_t mBufSize544;  // 0x544 — GetRequiredStringBufferSize()
        // (0x548 total)
    };
}
