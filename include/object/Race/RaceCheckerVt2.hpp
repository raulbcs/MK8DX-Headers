#pragma once

#include "RaceKartChecker.hpp"

namespace object
{
    // Checker-family sibling of RaceKartChecker: vtable .data 0x12d0d18
    // (GOT cell 0x1311118), ctor 0x7100881bb0. Direct construction sites
    // allocate 0x118 bytes (operator new[](0x118, nothrow) at 0x3a206c and
    // 0x3a2088; five further ctor wrappers receive pre-allocated this),
    // call the RaceKartChecker ctor 0x710087ffd0 first, then swap the vptr.
    //
    // Custom-RTTI id 10 (getTypeId10_7100881868, `mov w0,#0xa; ret`) is
    // UNIQUE to this vtable — a distinct concrete type.
    //
    // Ctor field writes: 0xb8 = 0x71135d94c (rw-data buffer cell), 0xc8-0xd8
    // and 0x10c/0x110 zeroed. The family method at 0x881c00 (calls enter
    // body 0x8802f4, reads flag 0x99) then invokes vtable slots 0xd8 and
    // 0x110 and reads fields 0xc0/0xd8/0x110.
    class RaceCheckerVt2 : public RaceKartChecker
    {
    public:
        virtual void slotD0(); //0xd0
        virtual void slotD8(); //0xd8 — invoked by the 0x881c00 method
        virtual void slotE0(); //0xe0
        virtual void slotE8(); //0xe8
        virtual void slotF0(); //0xf0
        virtual void slotF8(); //0xf8
        virtual void slot100(); //0x100
        virtual void slot108(); //0x108
        virtual void slot110(); //0x110 — invoked by the 0x881c00 method
        virtual void slot118(); //0x118
        virtual void slot120(); //0x120
        virtual void slot128(); //0x128
        virtual void slot130(); //0x130
        virtual void slot138(); //0x138
        virtual void slot140(); //0x140
        virtual void slot148(); //0x148

        void* mBufferB8;       // 0xb8 — rw-data buffer cell 0x71135d94c
        char mPadC0[0x8];      // 0xc0 — zeroed on ctor (also by 0x881c00)
        uint64_t mFieldC8;     // 0xc8 — zeroed on ctor
        uint64_t mFieldD0;     // 0xd0 — zeroed on ctor
        uint32_t mFieldD8;     // 0xd8 — zeroed on ctor (also by 0x881c00)
        char mPadDc[0x30];     // 0xdc — unproven padding
        uint32_t mField10c;    // 0x10c — zeroed on ctor
        uint16_t mField110;    // 0x110 — zeroed on ctor (u16; also by 0x881c00)
        char mPad112[0x6];     // 0x112 — unproven padding
    };
}
