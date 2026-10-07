#pragma once

#include <cstdint>

namespace nn::nex
{
    class Credentials
    {
    public:
        // SDK-internal; no game-side ctor evidence (nn::nex lib layout).
        uint8_t mPad00[0x10]; // SDK-internal; no game-side ctor evidence (nn::nex lib layout)
    };
}
