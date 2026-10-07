#pragma once

#include <cstdint>
#include "FlagAccessor.hpp"

namespace gear
{
    class SaveData
    {
    public:
        // Unproven — Switch ctor not identified (no RTTI, stripped binary);
        // extent fixed by mFlagAccessor at 0x190.
        uint8_t mPad00[0x190];
        FlagAccessor mFlagAccessor;
    };

    SaveData* GetCurrentUserSaveData();
}