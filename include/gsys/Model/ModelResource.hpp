#pragma once

#include <cstdint>
#include <_nn/g3d/ResFile.h>

namespace gsys
{
    class ModelResource
    {
    public:
        // Unproven — Switch ctor not identified (no RTTI, stripped binary);
        // extent fixed by mResFile at 0x30.
        uint8_t mPad00[0x30];
        nn::g3d::ResFile* mResFile; // 0x30
    };
}