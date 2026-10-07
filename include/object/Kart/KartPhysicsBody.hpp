#pragma once

#include <cstdint>

#include "gear/Actor/Actor.hpp"

namespace object
{
    // Root physics body of the item/kart physics family (32 vtables share
    // the KartPhysicsBody_shapePos_710001299c slot). Vtable .data 0x11ada60
    // (GOT cell 0x12fb050), ctor 0x7100116a4(this, x1 = param block, w2).
    //
    // Concrete size 0x328: the intermediate base (KartPhysicsBodyMid,
    // ctor 0x3703c) starts its own fields at 0x328. Ctor-proven writes
    // only below; interior unproven gaps are pads.
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
        int32_t mField5c;      // 0x5c — -1 on ctor; runtime: per-player index
                               // (<=0xb; selects [raceinfo+0x238]+idx*8 -> +0x50
                               // object in the shapePos calc 0x7100012784)
        uint32_t mField60;     // 0x60 — ctor arg w2

        // Embedded member at 0x68 (ctor stores vptr 0x11addf8, n=4)
        uint8_t mPad64[0x4]; // 0x64 — unproven gap
        char mSub68[8];        // 0x68 — extent to next write
        uint8_t mField70;      // 0x70 — 0 on ctor, then 0xb
        uint8_t mPad71;        // 0x71 — runtime: body-state enum read all over
                               // the shapePos calc 0x7100012784 (==1 branch,
                               // bitmask 0x62, dispatch 9..0xa, >6 test)
        uint8_t mField72;      // 0x72 — zeroed on ctor
        uint8_t mField73;      // 0x73 — 1 on ctor
        uint32_t mField74;     // 0x74 — zeroed on ctor
        void* mSelf78;         // 0x78 — ctor stores `this` here
        void* mArray80;        // 0x80 — new[](0xb0), zeroed head
        void* mArray88;        // 0x88 — new[](0xb0)
        void* mArray90;        // 0x90 — new[](0xb0)
        void* mQueryObj98;     // 0x98 — collision/terrain query object read
                               // by the shapePos calc (vcall slot 0x80 bool,
                               // axis getters 0x71001425c4/0x71001425f0,
                               // scale setter 0x71006a1194); not ctor-written
        char mPadA0[0x30];     // 0xa0 — to 0xd0
        uint64_t mFieldD0;     // 0xd0 — zeroed on ctor
        uint64_t mFieldD8;     // 0xd8 — zeroed on ctor
        uint32_t mFieldE0;     // 0xe0 — zeroed on ctor
        int32_t mFieldE4;      // 0xe4 — -1 on ctor
        float mScaleXe8;       // 0xe8 — per-axis scale cache vs the query
        float mScaleYec;       // 0xec — object's axis getters; when one
        float mScaleZf0;       // 0xf0 — drifts from the fresh value, the calc
        float mScaleWf4;       // 0xf4 — re-applies it via 0x71006a1194
                               // (all zeroed on ctor; 1.0 = no override)
        uint32_t mFieldF8;     // 0xf8 — zeroed on ctor
        char mPadFc[4];        // 0xfc — unproven padding

        // Embedded member at 0x100 (ctor 0x8dbc50; vptr 0x12d5b98, n=14)
        char mSub100[0xc];     // 0x100..0x10c — unproven gap
        float mF10c;           // 0x10c — 1.0f
        uint64_t mField110;    // 0x110 — zeroed on ctor
        uint8_t mField118;     // 0x118 — zeroed on ctor
        char mPad119[7];       // 0x119 — unproven padding
        // 0x120-0x177: kinematic state block (ctor memset 0x58; readers are
        // the isSurfaceValid slot 0x710013190: pos + vel*t + 0.5*accel*t^2)
        uint8_t mPad120[0xc];  // 0x120 — unproven padding
        float mPosX12c;        // 0x12c — position xyz (written by the
        float mPosY130;        // 0x130 — shapePos calc integration 0x7100137a0+;
        float mPosZ134;        // 0x134 — ==2 state branch copies them raw)
        uint8_t mPad138[0x1c]; // 0x138 — unproven padding
        float mVelX154;        // 0x154 — velocity xyz (written by the physics
        float mVelY158;        // 0x158 — integration 0x7100142d0-0x148e0)
        float mVelZ15c;        // 0x15c
        uint8_t mPad160[0x18]; // 0x160 — unproven padding
        uint16_t mField178;    // 0x178 — 1 on ctor
        char mPad17a[2];       // 0x17a — unproven padding
        float mAccX17c;        // 0x17c — acceleration xyz (written by fn
        float mAccY180;        // 0x180 — 0x710012e20-0x13190; ctor zeroes via
        float mAccZ184;        // 0x184 — unaligned u64 stores, split here)
        float mAccW188;        // 0x188
        float mF18c;           // 0x18c — ctor 0.05f (drag/damping constant?)
        const char* mName190;  // 0x190 — rodata 0xf20ea8 (name pair 2)
        const char* mName198;  // 0x198 — rodata 0xf20eac
        const char* mName1a0;  // 0x1a0 — rodata 0xf20eb0 (name pair 1)
        const char* mName1a8;  // 0x1a8 — rodata 0xf20eb4
        uint8_t mPad190[0x20]; // 0x190 — unproven gap
        uint16_t mField1b0;    // 0x1b0 — -1 on ctor
        uint16_t mField1b2;    // 0x1b2 — -1 on ctor
        uint8_t mField1b4;     // 0x1b4 — 1 on ctor
        char mPad1b5[3];       // 0x1b5 — unproven padding
        uint64_t mField1b8;    // 0x1b8 — zeroed on ctor
        uint64_t mField1c0;    // 0x1c0 — zeroed on ctor
        char mPad1c8[4];       // 0x1c8 — ctor zeroes u64 at unaligned 0x1c6
        uint8_t mPad1CC[0x4]; // 0x1CC — unproven gap
        uint64_t mField1d0;    // 0x1d0 — zeroed on ctor
        uint64_t mField1d8;    // 0x1d8 — zeroed on ctor
        uint64_t mField1e0;    // 0x1e0 — zeroed on ctor
        float mF1e8;           // 0x1e8 — 3.5f
        uint8_t mField1ec;     // 0x1ec — zeroed on ctor
        char mPad1ed[1];       // 0x1ed — unproven padding
        uint16_t mField1ee;    // 0x1ee — -1 on ctor
        uint32_t mField1f0;    // 0x1f0 — zeroed on ctor
        uint16_t mField1f4;    // 0x1f4 — zeroed on ctor
        char mPad1f6[2];       // 0x1f6 — unproven padding
        uint32_t mField1f8;    // 0x1f8 — 1 on ctor
        uint8_t mField1fc;     // 0x1fc — 1 on ctor
        char mPad1fd[3];       // 0x1fd — unproven padding
        uint64_t mField200;    // 0x200 — zeroed on ctor
        uint64_t mField208;    // 0x208 — zeroed on ctor
        char mPad210[8];       // 0x210 — unproven padding
        uint64_t mField218;    // 0x218 — zeroed on ctor
        uint64_t mField220;    // 0x220 — zeroed on ctor; runtime: rigid-body
                               // state enum (RigidBodyUpdate dispatches on
                               // cmp #7, fn 0x710013b2c)
        char mPad228[6];       // 0x228 — ctor zeroes u16 0x228, u8 0x22a

        // Recorder channel descriptor at 0x230 (shape of RaceCheckerVt3's
        // channel: fn cell 0x12fae28, empty-string name, owner back-ptr)
        uint8_t mPad22E[0x2]; // 0x22E — unproven gap
        void* mChan230;        // 0x230 — cell 0x12fb108+0x10
        void* mChan238;        // 0x238 — fn (cell 0x12fae28+0x10)
        const char* mChan240;  // 0x240 — ""
        uint8_t mPad240[0x8]; // 0x240 — unproven gap
        void* mChan248;        // 0x248 — cell 0x12fb110+0x10
        void* mChan250;        // 0x250 — owner = this
        void* mChan258;        // 0x258 — cell 0x12fb110+0x10 (ctor also
                               // stores cell 0x12fb118 at 0x260)
        char mPad260[0x14];    // 0x260 — ctor zeroes + stores more cells
        uint16_t mField274;    // 0x274
        uint8_t mPad276[0x2]; // 0x276 — unproven gap
        uint64_t mField278;    // 0x278 — zeroed on ctor; runtime: collision
                               // helper object (CollisionScale 0x710013338
                               // vcalls its slots 0x98/0xa8)
        uint64_t mField280;    // 0x280 — zeroed on ctor
        uint32_t mField288;    // 0x288 — zeroed on ctor
        char mPad28c[0x30];    // 0x28c — unproven padding
        uint32_t mField2bc;    // 0x2bc — zeroed on ctor
        char mPad2c0[0x18];    // 0x2c0 — unproven padding
        uint32_t mField2d8;    // 0x2d8 — zeroed on ctor
        char mPad2dc[0xc];     // 0x2dc — unproven padding
        uint32_t mCur2e8;      // 0x2e8 — current/previous value pair: the
        uint32_t mPrev2ec;     // 0x2ec — setter fn 0x710013278 moves the old
                               // value to 0x2ec (guard byte 0x1f3), same
                               // pattern as the axis-scale cache. 0x2fc-0x310
                               // is the rigid-body update record
                               // (RigidBodyUpdate 0x710013adc stores the
                               // input pose u32 quad into
                               // 0x304/0x308/0x30c/0x310).
        uint16_t mField2f0;    // 0x2f0
        uint8_t mPad2F2[0x2]; // 0x2F2 — unproven gap
        int32_t mField2f4;     // 0x2f4 — -1 on ctor (update-record field)
        int32_t mField2f8;     // 0x2f8 — -1 on ctor (update-record field)
        char mPad2fc[0x18];    // 0x2fc — unproven padding
        uint32_t mField314;    // 0x314 — zeroed on ctor
        char mPad318[2];       // 0x318 — unproven padding
        uint16_t mField31a;    // 0x31a — -1 on ctor
        uint32_t mField31c;    // 0x31c — zeroed on ctor
        uint16_t mField320;    // 0x320 — -1 on ctor; runtime: rescue/player
                               // state i16 pair, read by RescueBodyStateSet2
        uint16_t mField322;    // 0x322 — (0x710012ae8), capped against 0xa
                               // (player index bound)
        uint8_t mPad324[4];    // 0x324 — to end of root (0x328); the ctor's
                               // tail only fills the three 0xb0 arrays
    };
}
