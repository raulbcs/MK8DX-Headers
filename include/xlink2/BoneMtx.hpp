#pragma once

#include <cstdint>

#include <math/seadMatrix.h>

namespace xlink2
{
    // BoneMtx — trivially-copyable value wrapper (ptr to sead::Matrix34<f32>
    // + int tag), returned by value from Locator::getOverwriteBoneMtx.
    // No vtable. Evidence standard as TriggerType: type name
    // load-bearing, layout provisional beyond the leading pointer.
    class BoneMtx
    {
    public:
        sead::Matrix34<float>* mMtx; // 0x00
        int32_t mPad08; // 0x08
    };
}