#pragma once

#include <cstdint>

#include "gear/Actor/Actor.hpp"

namespace object
{
    // Root physics body of the item/kart physics family (32 vtables share
    // the KartPhysicsBody_shapePos_710001299c slot). Vtable .data 0x11ada60
    // (GOT cell 0x12fb050), ctor 0x7100116a4(this, x1 = param block, w2).
    //
    // Concrete size NOT yet pinned: the ctor runs past 0x330 and derived
    // items extend it (Koura allocation 0x460 at 0x35f10 bounds it from
    // above). Ctor-proven writes only below; interior unproven gaps are
    // pads.
    //
    // Derived evidence: Koura ctor 0x30d50 (vptr 0x11b0d98, n=126) calls
    // the root ctor; TogezoBomb's inlined ctor (vptr 0x11b0898, n=128)
    // calls the Koura ctor. Item factories inline the ctors — the
    // out-of-line copies have no direct callers.
    class KartPhysicsBody : public gear::Actor
    {
    public:
        uint64_t mField38;     // 0x38 — zeroed on ctor
        uint64_t mField40;     // 0x40 — zeroed on ctor
        uint64_t mField48;     // 0x48 — zeroed on ctor
        int64_t mField50;      // 0x50 — -1 on ctor
        uint32_t mField58;     // 0x58 — copied from *x1 (param block)
        int32_t mField5c;      // 0x5c — -1 on ctor
        uint32_t mField60;     // 0x60 — ctor arg w2

        // Embedded member at 0x68 (ctor stores vptr 0x11addf8, n=4)
        char mSub68[8];        // 0x68 — extent to next write
        uint8_t mField70;      // 0x70 — 0 on ctor, then 0xb
        uint8_t mPad71;        // 0x71
        uint8_t mField72;      // 0x72 — zeroed on ctor
        uint8_t mField73;      // 0x73 — 1 on ctor
        uint32_t mField74;     // 0x74 — zeroed on ctor
        void* mSelf78;         // 0x78 — ctor stores `this` here
        void* mArray80;        // 0x80 — new[](0xb0), zeroed head
        void* mArray88;        // 0x88 — new[](0xb0)
        void* mArray90;        // 0x90 — new[](0xb0)
        char mPad98[0x38];     // 0x98 — to 0xd0
        uint64_t mFieldD0;     // 0xd0 — zeroed on ctor
        uint64_t mFieldD8;     // 0xd8 — zeroed on ctor
        uint32_t mFieldE0;     // 0xe0 — zeroed on ctor
        int32_t mFieldE4;      // 0xe4 — -1 on ctor
        uint64_t mFieldE8;     // 0xe8 — zeroed on ctor
        uint64_t mFieldF0;     // 0xf0 — zeroed on ctor
        uint32_t mFieldF8;     // 0xf8 — zeroed on ctor
        char mPadFc[4];        // 0xfc

        // Embedded member at 0x100 (ctor 0x8dbc50; vptr 0x12d5b98, n=14)
        char mSub100[0xc];     // 0x100..0x10c
        float mF10c;           // 0x10c — 1.0f
        uint64_t mField110;    // 0x110 — zeroed on ctor
        uint8_t mField118;     // 0x118 — zeroed on ctor
        char mPad119[7];       // 0x119
        char mPad120[0x58];    // 0x120 — memset(this+0x120, 0, 0x58)
        uint16_t mField178;    // 0x178 — 1 on ctor
        char mPad17a[0xa];     // 0x17a
        uint64_t mField184;    // 0x184 — zeroed on ctor
        char mPad18c[0x14];    // 0x18c
        const char* mName1a0;  // 0x1a0 — rodata 0xf20eb0
        const char* mName1a8;  // 0x1a8 — rodata 0xf20eb4
        uint16_t mField1b0;    // 0x1b0 — -1 on ctor
        uint16_t mField1b2;    // 0x1b2 — -1 on ctor
        char mPad1b4[4];       // 0x1b4
        uint64_t mField1b8;    // 0x1b8 — zeroed on ctor
        uint64_t mField1c0;    // 0x1c0 — zeroed on ctor
        char mPad1c8[4];       // 0x1c8 — ctor zeroes u64 at unaligned 0x1c6
        uint64_t mField1d0;    // 0x1d0 — zeroed on ctor
        uint64_t mField1d8;    // 0x1d8 — zeroed on ctor
        uint64_t mField1e0;    // 0x1e0 — zeroed on ctor
        float mF1e8;           // 0x1e8 — 3.5f
        uint8_t mField1ec;     // 0x1ec — zeroed on ctor
        char mPad1ed[1];       // 0x1ed
        uint16_t mField1ee;    // 0x1ee — -1 on ctor
        uint32_t mField1f0;    // 0x1f0 — zeroed on ctor
        uint16_t mField1f4;    // 0x1f4 — zeroed on ctor
        char mPad1f6[2];       // 0x1f6
        uint32_t mField1f8;    // 0x1f8 — 1 on ctor
        uint8_t mField1fc;     // 0x1fc — 1 on ctor
        char mPad1fd[3];       // 0x1fd
        uint64_t mField200;    // 0x200 — zeroed on ctor
        uint64_t mField208;    // 0x208 — zeroed on ctor
        char mPad210[8];       // 0x210
        uint64_t mField218;    // 0x218 — zeroed on ctor
        uint64_t mField220;    // 0x220 — zeroed on ctor
        char mPad228[6];       // 0x228 — ctor zeroes u16 0x228, u8 0x22a

        // Recorder channel descriptor at 0x230 (shape of RaceCheckerVt3's
        // channel: fn cell 0x12fae28, empty-string name, owner back-ptr)
        void* mChan230;        // 0x230 — cell 0x12fb108+0x10
        void* mChan238;        // 0x238 — fn (cell 0x12fae28+0x10)
        const char* mChan240;  // 0x240 — ""
        void* mChan248;        // 0x248 — cell 0x12fb110+0x10
        void* mChan250;        // 0x250 — owner = this
        void* mChan258;        // 0x258 — cell 0x12fb110+0x10 (ctor also
                               // stores cell 0x12fb118 at 0x260)
        char mPad260[0x14];    // 0x260 — ctor zeroes + stores more cells
        uint16_t mField274;    // 0x274
        uint64_t mField278;    // 0x278 — zeroed on ctor
        uint64_t mField280;    // 0x280 — zeroed on ctor
        uint32_t mField288;    // 0x288 — zeroed on ctor
        char mPad28c[0x30];    // 0x28c
        uint32_t mField2bc;    // 0x2bc — zeroed on ctor
        char mPad2c0[0x18];    // 0x2c0
        uint32_t mField2d8;    // 0x2d8 — zeroed on ctor
        char mPad2dc[0xc];     // 0x2dc
        uint64_t mField2e8;    // 0x2e8 — zeroed on ctor
        uint16_t mField2f0;    // 0x2f0
        int32_t mField2f4;     // 0x2f4 — -1 on ctor
        int32_t mField2f8;     // 0x2f8 — -1 on ctor
        char mPad2fc[0x18];    // 0x2fc
        uint32_t mField314;    // 0x314 — zeroed on ctor
        char mPad318[2];       // 0x318
        uint16_t mField31a;    // 0x31a — -1 on ctor
        uint32_t mField31c;    // 0x31c — zeroed on ctor
        uint16_t mField320;    // 0x320 — -1 on ctor
        uint16_t mField322;    // 0x322 — -1 on ctor
        // ctor continues past 0x324 (three 0xb0 arrays, more fields) —
        // size TBD pending the tail pass.
    };
}
