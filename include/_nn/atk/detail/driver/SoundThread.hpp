#pragma once

#include <cstdint>

namespace nn::atk::detail::driver
{
    // RTTI-confirmed (typeinfo mangled name:
    // N2nn3atk6detail6driver11SoundThreadE, ti object 0x12ae120).
    // vptr 0x12ae0f0 (n=3): 0x5e7d04 / 0x5e87c4 (dtor pair) / 0x5e85c8.
    //
    // The driver-side audio worker thread class of nn::atk. Single code
    // reference at 0x5e4f20 inside the sound-driver setup/teardown region
    // FUN_71005e4f14 (same region that wires the BiquadFilter table and the
    // BasicSound base machinery). Field map pending.
    class SoundThread
    {
    public:
        void* vtable;          // 0x00 — 0x12ae0f0
        uint8_t mPad08[0x8];   // 0x08 — unproven gap
        // (extent unproven)
    };
}
