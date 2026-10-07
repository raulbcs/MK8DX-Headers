#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object
{
    // KartParamCacheMid — PROVISIONAL vtable-anchored name (vptr 0x12b3478,
    // GOT cell 0x130daf0, n=11). Mid base of the big KartParamCache
    // variants: ctor 0x710065ede8 calls the KartParamCache ctor
    // (0x7100669954), builds an embedded member at 0x68 (ctor 0x710066a2a4)
    // and THREE 0x20-byte recorder channel-pair members at 0xb0/0xd0/0xf0
    // (ctor pair 0x7100662f30 + 0x7100662f70; fn cell 0x12fae28; rodata
    // names 0xef8f59/0xef8f60, 0xef9c27, 0xef9c2e; cells 0x130d908/
    // 0x130daa0), then -1 at 0x108 and init 0x7100669a10(this, w1=param).
    // Extent 0x110. The factory 0x710065efbc (jump table on w0, 0..6)
    // allocates the derived sizes over this ctor; no standalone
    // construction site is known.
    class KartParamCacheMid : public KartParamCache
    {
    public:
        uint8_t pad40[8];      // 0x40
        uint64_t mZero48;      // 0x48 — ctor zero
        uint64_t mZero50;      // 0x50 — ctor zero
        void* mSelf58;         // 0x58 — ctor stores this; 0x60 zero
        void* mZero60;         // 0x60
        char mSub68[0x30];     // 0x68 — embedded member (ctor 0x710066a2a4)
        uint64_t mZero98;      // 0x98 — ctor zero
        uint64_t mZeroA0;      // 0xa0 — ctor zero
        uint32_t mIdA8;        // 0xa8 — ctor arg w1
        uint32_t mIdAc;        // 0xac — ctor: (w1<<8)+0x100+(w2+1)
        char mChanB0[0x20];    // 0xb0 — channel-pair member (cells 0x130d908;
                               // ctor zeroes a flag byte at 0xc8 = chan+0x18 —
                               // the +0x18 field here is a byte, NOT the float
                               // seen in the Vt3130 instances)
        char mChanD0[0x20];    // 0xd0 — channel-pair member (flag byte at 0xe8)
        char mChanF0[0x18];    // 0xf0 — channel-pair member (to 0x108)
        int32_t mFffF108;      // 0x108 — ctor sets -1
        // (0x110 total)
    };
}
