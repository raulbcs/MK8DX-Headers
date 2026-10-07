#pragma once

#include <cstdint>

#include "gear/Actor/Actor.hpp"

namespace gear
{
    // RaceDirector-family director (shares the prepare/enter/calc/exit hook
    // block, slot4 SharedThunk_30vtables_710004cfbc). Vtable .data 0x12d0a60
    // (GOT cell 0x1311088), ctor 0x710087d9b8, 0x168 bytes (allocation at
    // 0x398964: operator new[](0x168, nothrow)).
    //
    // Base of a derived director (ctor 0x3a16a8 calls this then swaps the
    // vptr to 0x1260dd8's; same 0x168 size). Both are spawned by the race
    // job manager init (count at manager+0x1c0, list at +0x210, owner
    // back-ptrs at +0x28/+0x30 per child).
    //
    // Ctor field writes: 0x38 = 0 (u32), 0x40-0x80 zeroed, a time record
    // built at 0xe8 with (9, 59, 999), and three 0x28-byte channel
    // descriptors at 0xf8/0x120/0x148 — {vptr, fn ptr (GOT 0x12fae28),
    // name "" (rodata 0xed6af8), owner = this}, matching the recorder
    // channel shape of RaceCheckerVt3's 0x38 sub-object.
    class RaceDirectorVt8 : public Actor
    {
    public:
        uint32_t mField38;     // 0x38 — zeroed on ctor
        uint8_t mPad3c[4];     // 0x3c — unproven padding
        char mPad40[0x40];     // 0x40 — zeroed on ctor (to 0x80)
        char mPad80[0x68];     // 0x80 — untouched by ctor (to 0xe8)

        // {u32 id, u8 min, u8 sec, u16 ms} — same record shape as
        // RaceKartChecker (builder 0x888c30).
        uint32_t mTimeId_e8;   // 0xe8
        uint8_t mTimeMin_ec;   // 0xec
        uint8_t mTimeSec_ed;   // 0xed
        uint16_t mTimeMs_ee;   // 0xee
        uint64_t mPadF0;       // 0xf0 — untouched by ctor

        // 0xf8..0x168 — three 0x28-byte recorder channel descriptors, as
        // built by the ctor (cells are GOT addresses):
        //   +0x00 0xf8  vt  (cell 0x1311090)   +0x08 fn (cell 0x12fae28)
        //   +0x10 name ""                    +0x18 vt2 (cell 0x13110a0)
        //   +0x20 owner = this
        //   second: 0x120 vt (cell 0x1311098), 0x128 0, 0x130 cell 0x1311098
        //   third:  0x148 vt (cell 0x13110a0), 0x150 owner = this,
        //           0x158 fn, 0x160 0
        void* mChanF8;         // 0xf8
        void* mChan100;        // 0x100 — fn (cell 0x12fae28)
        const char* mChan108;  // 0x108 — ""
        void* mChan110;        // 0x110
        void* mChan118;        // 0x118 — owner back-ptr = this
        void* mChan120;        // 0x120
        void* mChan128;        // 0x128 — 0
        void* mChan130;        // 0x130
        void* mChan138;        // 0x138 — fn
        const char* mChan140;  // 0x140 — ""
        void* mChan148;        // 0x148
        void* mChan150;        // 0x150 — owner back-ptr = this
        void* mChan158;        // 0x158 — fn
        void* mChan160;        // 0x160 — 0
    };
}
