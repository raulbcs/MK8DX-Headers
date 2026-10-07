#pragma once

#include <cstdint>

namespace nn::nex
{
    // RTTI-confirmed (typeinfo mangled name: N2nn3nex11EventLogE, ti object
    // 0x128c460). vptr 0x128c000 (n=5). Hottest live vtable missed by the
    // strict census: 44 code references, all concentrated in the nn::nex
    // event-log writer region 0x583154-0x583cxx (FUN_7100583154,
    // FUN_710058358c, ...): each site heap-allocates a 0x50-byte object
    // (alloc helper 0x576368), installs the vptr from GOT cell 0x130b618
    // (+0x10) at +0x20 together with a caller-supplied qword, stlr-sets a
    // flag at +0x30 and zeroes a bool at +0x34.
    //
    // Secondary vtables in the same cluster: nn::nex::Log (vptr 0x128c038,
    // ti 0x128c440) and nn::nex::LockChecker (vptr 0x128c050, ti 0x128c480)
    // — both RTTI-confirmed, covered by this family header.
    //
    // Slot map: +0x00/+0x08 dtor pair (0x575c84/0x575d18), +0x10 0x57619c,
    // +0x18 0x576234, +0x20 0x576054. Field map pending.
    class EventLog
    {
    public:
        void* vtable;          // 0x00 — 0x128c000
        uint8_t mBase08[0x18]; // 0x08 — Log/LockChecker base region
        void* mField20;        // 0x20 — vptr+caller qword stored by the writer
        uint8_t mPad28[0x8];   // 0x28
        uint64_t mFlag30;      // 0x30 — stlr 1 at site 0x583254
        uint8_t mZero34;       // 0x34 — ctor zero
        uint8_t mPad35[0x3];   // 0x35
        // (writer objects are 0x50 bytes; tail unmapped)
    };
}
