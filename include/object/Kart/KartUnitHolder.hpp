#pragma once

#include <cstdint>

#include "KartVehicle.hpp"

namespace object
{
    /*
     * Per-slot entry of KartDirector::mKartUnitHolders. NOT a subclass of
     * KartVehicle; it stores a pointer at +0x8.
     *
     * Anchored to the decomp (all verified in the 400 binary):
     *   - +0x08  KartVehicle pointer — FUN_710016dab0 reads
     *            [this+0x8] then the vehicle's +0xd3 flag; FUN_710016cabc
     *            and the reset helpers at 0x173bfc/0x173c40 do the same
     *   - +0x30  list/container head — FUN_710016dae0 reads [this+0x30]
     *   - +0x38  job/state object (int at +0x8, state 2 = ready) —
     *            FUN_710016dab0 / FUN_710016cabc
     *   - +0x248 array of 0x78-stride entries, flag byte at entry+0x38
     *            (FUN_710016e6e4: element i at 0x248 + i*0x78, flag 0x280)
     *   - +0x348 int (clamped < 2), +0x358 state counter (1..10),
     *            +0x35c gate (checked >= 3), +0x361 set-by-VT8 helper,
     *            +0x362 bool (FUN_710016e6e4 / FUN_710016ef3c)
     * Total size is at least 0x368; the end is still unmapped.
     */
    class KartUnitHolder
    {
        public:
            uint8_t pad00[0x8];      // 0x00
            KartVehicle* mVehicle;  // 0x08 — verified
            uint8_t pad10[0x20];     // 0x10
            void* mContainer30;      // 0x30 — list/container head
            void* mJob38;            // 0x38 — state object (int state at +0x8)
            uint8_t pad40[0x208];    // 0x40
            uint8_t mEntries248[0x120];  // 0x248 — 0x78-stride entries, flag at +0x38
            int32_t m348;            // 0x348 — clamped to < 2
            uint8_t pad34C[0xC];     // 0x34c
            uint32_t m358;           // 0x358 — state counter (values 1..10)
            uint32_t m35C;           // 0x35c — gate (checked >= 3)
            uint8_t m361;            // 0x361 — set to 1 by FUN_710016ef3c
            bool m362;               // 0x362
            uint8_t pad363[0x5];     // 0x363
    };
}  // namespace object
