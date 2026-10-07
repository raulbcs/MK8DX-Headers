#pragma once

#include <cstdint>

#include "_nn/ae/AppletThread.hpp"
#include "_nn/ae/ControllerAppletThread.hpp"
#include "_nn/ae/ErrorAppletThread.hpp"
#include "_nn/ae/KeyboardAppletThread.hpp"
#include "_nn/ae/MiiEditAppletThread.hpp"
#include "_nn/ae/NifmAppletThread.hpp"
#include "_nn/ae/NSAAppletThread.hpp"
#include "_nn/ae/OfflineWebAppletThread.hpp"

// Baptism audit 2026-10-07: sole ctor 0x872004 builds all seven named applet threads but the host object itself has no rodata name and no MethodTree entry.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace nn::err
{
    // fwd — SDK type, no header in nnheaders vendor; ctor C1 via plt
    // (host 0x872004 site 0x872240); size unverified.
    struct ErrorResultVariant;
}

namespace nn::ae
{
    // AppletThreadHost — PROVISIONAL name (vtable 0x12d02c8, cell 0x1310fb0;
    // slot 0x10 = 0x87275c, its own family). Ctor 0x7100872004(this): base
    // 0x71007b976c, priority [0x130d250], then SEVEN in-place applet
    // threads (each via 0x7100628a54 with {cell+0x10, rodata name} on the
    // stack), buffers from nn::swkbd, nn::err::ErrorResultVariant @0xb94,
    // and a member-init pass 0x7100628f3c over all seven. Sole
    // construction site 0x8bca3c. Extent >= 0xda0.
    class AppletThreadHost
    {
    public:
        void* vptr;                        // 0x00
        uint8_t pad08[0x30];               // 0x08 — base 0x71007b976c region
        ControllerAppletThread mController38;   // 0x38  "ControllerAppletThread" (0x318)
        KeyboardAppletThread mKeyboard350;      // 0x350 "KeyboardAppletThread"   (0x548)
        OfflineWebAppletThread mOfflineWeb898;  // 0x898 "OfflineWebAppletThread" (0xf8)
        MiiEditAppletThread mMiiEdit990;        // 0x990 "MiiEditAppletThread"    (0x100)
        ErrorAppletThread mErrorA90;            // 0xa90 "ErrorAppletThread"      (0xfc)
        void* mZeroB8c;                    // 0xb8c
        nn::err::ErrorResultVariant* mErrB94; // 0xb94 — ErrorResultVariant C1'd IN PLACE here (0x872240); modelled as ptr placeholder, size unverified
        uint32_t mZeroBa0;                 // 0xba0
        uint8_t padBa4[4];                 // 0xba4
        NifmAppletThread mNifmBa8;         // 0xba8 "NifmAppletThread" (0x100)
        NSAAppletThread mNsaCa8;           // 0xca8 "NSAAppletThread"  (0xf8)
        // (extent >= 0xda0, tail unmapped)
    };
}
