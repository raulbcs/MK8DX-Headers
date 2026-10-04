#pragma once

#include <cstdint>

// Per-kart recorder key/writer — size 0x298, proven by operator new(0x298)
// in the KartVehicle init (v400 0x7100170458, stored at KartVehicle+0x80;
// setup 0x71003ae42c, part of the recorder per-kart setup cluster next to
// recorderSetupKartChannels_71003aef8c). Allocated only when the recorder is
// active — skipped when (managerBits|2)==7 (ghosts/replays), together with
// KartRecorderChannels at +0x88. Name matches the rodata schema tag
// "RecorderKey" (replay frame format, see recorder/Recorder.hpp).
namespace object
{
    struct KartRecorderKey
    {
        uint8_t pad_00[0x288]; //0x00 — vtable at +0x00 (global 0x1307868+0x10);
            // bulk region initialized by 0x7ad494(this, 8, 10) in the setup
        void* param_288; //0x288 — copies [x1] (param pointer)
        uint64_t param_290; //0x290 — copies [x1+8]
        // Setup registers this into a global player table: registry[0x190 +
        // playerIdx*8] -> obj->0x230 -> ... -> slot+0x1F0 = this (0x3ae51c-0x3ae524).
    };
}
