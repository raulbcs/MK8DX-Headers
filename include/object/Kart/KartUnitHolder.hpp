#pragma once

#include <cstdint>

#include "KartVehicle.hpp"

namespace object
{
    /*
     * Per-slot entry of KartDirector::mKartUnitHolders (points to these,
     * not to KartVehicle directly).
     *
     * Polymorphic: primary vtable (group 0x11bac70: dtor 0x710016e494,
     * deleting dtor 0x710016e614, 0x710016ed9c, 0x710016ea8c) and a
     * SECONDARY base subobject at +0x218 (offset-to-top -0x218, vtable
     * 0x11baca0 -> 0x710016e554 / deleting dtor 0x710016e6dc). Ctor =
     * FUN_710016e1ec (base ctor FUN_710016c778).
     *
     * Size: >= 0x368 (ctor writes through +0x363; no allocation site
     * found — exact total unproven).
     */
    class KartUnitHolder
    {
        public:
            uint8_t pad00[8];       // 0x00 — primary vtable ptr
            KartVehicle* mVehicle;  // 0x08 — verified (FUN_710016dab0 reads [veh+0xD3])
            uint8_t pad10[0x20];    // 0x10
            void* mContainer30;     // 0x30 — list head; dtor frees via FUN_7100147fd8
            void* mJob38;           // 0x38 — job/state object (int at +0x8, 2 = ready)
            uint32_t mId40;         // 0x40 — unit id passed to FUN_710016dd04 (0x16ec04)
            uint8_t pad44[8];       // 0x44
            uint8_t mFlag4C;        // 0x4C — set 1 each calc pass; gates FUN_710016da1c(this,0x1E)
            uint8_t pad4D[0x1CB];   // 0x4D
            uint8_t pad218[8];      // 0x218 — SECONDARY vtable ptr (base subobject)
            uint8_t pad220[0x18];   // 0x220
            uint64_t mZero238;      // 0x238 — zeroed pair (args to FUN_710016dd04)
            uint64_t mZero240;      // 0x240
            void* mListHead248;     // 0x248 — intrusive list head (sentinel = self),
                                    // one per active entry index (ctor 0x16e23c)
            void* mListNext250;     // 0x250
            uint32_t mZero258;      // 0x258
            uint8_t pad25C[8];      // 0x25C
            uint64_t mZero260;      // 0x260
            uint64_t mZero268;      // 0x268
            int32_t mS270;          // 0x270 — ctor -1
            int32_t mS274;          // 0x274 — ctor -1
            uint64_t mZero278;      // 0x278
            uint8_t mFlag280;       // 0x280 — per-entry flag byte (entry i at 0x248+i*0x78,
                                    // flag at entry+0x38; FUN_710016e6e4 0x16e74c)
            uint8_t pad281[7];      // 0x281
            void* mNode288;         // 0x288 — sead-style node (vt from [0x12fa0da]+0x10)
            void* mNode290;         // 0x290 — byte from [0x12fa0da8]
            uint8_t pad298[0x28];   // 0x298
            void* mListHead2C0;     // 0x2C0 — second list head (sentinel = self)
            void* mListNext2C8;     // 0x2C8
            uint32_t mZero2D0;      // 0x2D0
            uint8_t pad2D4[0x14];   // 0x2D4
            int32_t mS2E8;          // 0x2E8 — ctor -1
            int32_t mS2EC;          // 0x2EC — ctor -1
            uint8_t pad2F0[0x10];   // 0x2F0
            void* mNode300;         // 0x300 — third node obj; later set to [0x12fb0728]+0x10
            void* mNode308;         // 0x308 — byte from [0x12fa0da8]
            uint32_t m320;          // 0x310 — ctor sets 0x20
            uint8_t pad314[0x24];   // 0x314
            uint32_t mEntryCount338; // 0x338 — entry count {1,2} (ctor: (arg&1)?2:1);
                                     // dtor loop bound
            uint8_t pad33C[4];      // 0x33C
            void* mEntries340;      // 0x340 — 0x78*count entry array (nn heap alloc
                                    // 0x16e370, size 0x8000|(n<<20)); entry+0x278 object
                                    // ptr gets vt calls at slots 0x58/0x80/0x30
            int32_t mIndex348;      // 0x348 — active entry index, clamped < 2 (0x16e72c)
            int32_t mIndex34C;      // 0x34C — mirror index (1 - mIndex348)
            uint8_t mZero350;       // 0x350 — cleared by per-unit reset FUN_710013f430
            uint8_t pad351[3];      // 0x351
            uint32_t mZero354;      // 0x354 — cleared by per-unit reset
            uint32_t mState358;     // 0x358 — state-machine counter {1,2,3,7,8,9,10};
                                    // transitions write m35C=0 then m358=new
            uint32_t mGate35C;      // 0x35C — compared >= 3, incremented in FUN_710016e6e4
            uint8_t mFlag360;       // 0x360 — ((RaceCheck+8)|2)==7 result (0x16eab8)
            uint8_t mFlag361;       // 0x361 — set 1 by FUN_710016ef3c (KartDirectorVt8)
            uint8_t mFlag362;       // 0x362 — read as list-walk arg (payload+0x48 flag)
            uint8_t mFlag363;       // 0x363 — ctor sets 1 (read at 0x16e9bc)
            uint8_t pad364[4];      // 0x364 — to 0x368 (size unproven beyond)
    };
}  // namespace object
