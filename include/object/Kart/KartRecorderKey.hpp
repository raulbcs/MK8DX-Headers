#pragma once

#include <cstdint>

// KartRecorderKey — size 0x298, proven by operator new(0x298) in the
// KartVehicle init (v400 0x7100170458, stored at KartVehicle+0x80; ctor
// 0x71003ae42c). Allocated only when (managerBits|2)!=7, i.e. skipped for
// ghosts/replays, together with KartPathJob. PROVISIONAL: name reflects the
// recorder-adjacent allocation block; no MethodTree string.
namespace object
{
    struct KartRecorderKey
    {
        uint8_t pad_00[0x288]; //0x00 — vtable at +0x00 (global 0x1307868+0x10);
            // bulk region initialized by 0x7ad494(this, 8, 10) in the ctor
        void* param_288; //0x288 — ctor copies [x1] (param pointer)
        uint64_t param_290; //0x290 — ctor copies [x1+8]
        // Ctor registers this into a global player table: registry[0x190 +
        // playerIdx*8] -> obj->0x230 -> ... -> slot+0x1F0 = this (0x3ae51c-0x3ae524).
    };
}
