#pragma once

#include <cstdint>

#include "gear/Race/RaceDirectorBase38.hpp"

// Baptism audit 2026-10-07: no consumers beyond the allocation site 0x820ff0 examined (mii::Database calls nearby but unlinked); no binary name evidence.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
    // RaceDirectorVtb5d0 — PROVISIONAL vtable-anchored name (vptr written by
    // the ctor from cell 0x1310788; .data 0x12cb5d0). Far-family director,
    // 24 slots. Ctor 0x81eacc, size 0x880 (alloc 0x820ff0: new 0x880;
    // mii::Database calls nearby).
    // Base: RaceDirectorBase38 (ctor 0x7b976c).
    //
    // Ctor field map: 0x38 u32 = 0; 0x40/0x48 u64 = 0; 0x50 u8 = 0;
    // 0x58 ptr pair (new 0x98 obj via ctor 0x81e65c from a 0x61a5f0
    // singleton, + null); 0x60 big member (memset 0x4e8, then sub-ctor
    // 0x81ec70 building ~10 stride-0x78 channel blocks — each {u32 @+0x8,
    // u64 @+0x10, sub-ctor 0x628628 @+0x28}; member-init 0x628f3c and
    // init 0x628dc4 close it); scattered u64 zeros at 0xc8/0x130/0x198/
    // 0x200/0x268/0x2d0/0x338/0x3a0/0x408/0x470/0x4d8 (stride 0x68 pointer
    // table inside the memset region); 0x540/0x550 u32 = 0; 0x548/0x558
    // u64 = 0; 0x560 sub-object (ctor 0x628628); 0x5a0 u32 = 0;
    // 0x5a8 ptr = cell 0x1310790 (+0x10); 0x5b0 = this; 0x5b8 ptr =
    // cell 0x1310798 (+0x10); 0x5c0 u64 = 0; 0x5c8 embedded thread (create
    // 0x629270: prio 18, attr 0x10000, rodata name 0xf0bf1e); 0x6c8 ptr =
    // this+0x6e0; 0x6d0 = 1; 0x6d8 u32 = 0; 0x7e0 sub-object (ctor
    // 0x628628); 0x820 memset 0x60 (to 0x880).
    // Gap: 0x6dc..0x6c7 and 0x7e0-struct interiors beyond the ctor writes.
    class RaceDirectorVtb5d0 : public RaceDirectorBase38
    {
    public:
        uint32_t mZero38;      // 0x38 — ctor zero
        uint8_t pad3c[4];      // 0x3c — unproven padding
        uint64_t mZero40;      // 0x40 — ctor zero
        uint64_t mZero48;      // 0x48 — ctor zero
        uint8_t mZero50;       // 0x50 — ctor zero
        uint8_t pad51[7];      // 0x51 — unproven padding
        void* mObj58;          // 0x58 — new 0x98 (ctor 0x81e65c from the 0x61a5f0 singleton); null partner at 0x60
        void* mNull60;         // 0x60 — ctor null
        uint8_t mBig68[0x4d8]; // 0x68 — memset 0x4e8 region minus head (sub-ctor 0x81ec70)
        uint32_t mZero540;     // 0x540 — ctor zero
        uint32_t pad544;       // 0x544 — unproven padding
        uint64_t mZero548;     // 0x548 — ctor zero
        uint32_t mZero550;     // 0x550 — ctor zero
        uint32_t pad554;       // 0x554 — unproven padding
        uint64_t mZero558;     // 0x558 — ctor zero
        uint8_t mSub560[0x40]; // 0x560 — sub-object (ctor 0x628628)
        uint32_t mZero5a0;     // 0x5a0 — ctor zero
        void* mVptr5a8;        // 0x5a8 — cell 0x1310790 (+0x10), vptr-shaped
        void* mSelf5b0;        // 0x5b0 — ctor sets this
        void* mVptr5b8;        // 0x5b8 — cell 0x1310798 (+0x10), vptr-shaped
        uint64_t mZero5c0;     // 0x5c0 — ctor zero
        uint8_t mThread5c8[0x100]; // 0x5c8 — embedded thread (create 0x629270)
        void* mNext6c8;        // 0x6c8 — ctor sets this+0x6e0
        uint64_t mOne6d0;      // 0x6d0 — ctor sets 1
        uint32_t mZero6d8;     // 0x6d8 — ctor zero
        uint8_t mSub7e0[0x40]; // 0x7e0 — sub-object (ctor 0x628628)
        uint8_t mTail820[0x60]; // 0x820 — memset 0x60
        // (0x880 total)
    };
}
