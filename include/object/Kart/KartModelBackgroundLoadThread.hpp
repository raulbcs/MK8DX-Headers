#pragma once

#include <cstdint>

namespace object
{
    // KartModelBackgroundLoadThread — an nn::ae::AppletThread subclass (vptr 0x1264980, cell 0x1308288, n=21, site 0x3d9e24).
    // Evidence: constructed in the kart-model resource loader FUN_71003d8718 (strings Body, Driver,
    // Emblem, Tire, ModelSmartCacheList(Stable)): the ctor call 0x71008911a0 (BackgroundLoadThread,
    // thread name "BackgroundLoad") runs first and the vptr is then overwritten with 0x1264980
    // (cell 0x1308288, +0x10 convention) at 0x3d9e20-0x3d9e34 — a BackgroundLoadThread subclass.
    // "KartModelBackgroundLoadThread" is a descriptive name from this proven construction context;
    // no dedicated thread-name string exists for the subclass (it inherits "BackgroundLoad").
    // Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor).
    // Own fields unmapped — evidence insufficient.
    class KartModelBackgroundLoadThread
    {
    public:
        void* vptr;            // 0x00 — written at 0x3d9e34 (cell 0x1308288 +0x10)
        // (own fields unmapped)
    };
}
