#pragma once

#include <cstdint>

namespace nn::atk
{
    // BiquadFilter family, fully RTTI-confirmed. The recensus flagged a
    // 10-entry vtable cluster at 0x12ae7a0-0x12ae9f8 (n=3 each, stride 0x40,
    // shared first slot 0x5e3c30): every cell is one subclass vtable followed
    // by its typeinfo, i.e. ten named nn::atk::detail::BiquadFilter*
    // classes deriving from nn::atk::BiquadFilterCallback (base typeinfo
    // 0x12ae7b8; base vtable not part of the cluster).
    //
    // The 10 vptrs form a static table at 0x12ae090..0x12ae0d8 which the
    // sound-driver constructor (FUN_71005e483c region, site 0x5e4df8) stores
    // entry-by-entry into fields +0x1e8..+0x220 of the driver object — one
    // pre-bound filter per BiquadFilterType. No other construction sites.
    //
    // Slot layout per subclass: +0x00 shared 0x5e3c30 (base operation),
    // +0x08/+0x10 unique per class (filter apply + deleting dtor; mapping
    // pending). Each vtable has full RTTI (offset-to-top 0, ti at vptr-0x8).
    class BiquadFilterCallback
    {
    public:
        void* vtable;          // 0x00 — base table outside the cluster
        uint8_t mPad08[0x8];   // 0x08 — unproven padding
        // (base extent unproven)
    };
}

namespace nn::atk::detail
{
    // Subclass vtables (vptr / slots +0x08 / +0x10 / typeinfo):
    class BiquadFilterLpf                 { void* vtable; /* 0x12ae7a0: 0x5e3c30 0x5f6eac 0x5f6bbc, ti 0x12ae7d0 */ };
    class BiquadFilterHpf                 { void* vtable; /* 0x12ae7f8: 0x5e3c30 0x5f6eb0 0x5f6c00, ti 0x12ae810 */ };
    class BiquadFilterBpf512              { void* vtable; /* 0x12ae838: 0x5e3c30 0x5f6eb4 0x5f6c44, ti 0x12ae850 */ };
    class BiquadFilterBpf1024             { void* vtable; /* 0x12ae878: 0x5e3c30 0x5f6eb8 0x5f6c94, ti 0x12ae890 */ };
    class BiquadFilterBpf2048             { void* vtable; /* 0x12ae8b8: 0x5e3c30 0x5f6ebc 0x5f6ce4, ti 0x12ae8d0 */ };
    class BiquadFilterLpfNw4fCompatible48k { void* vtable; /* 0x12ae8f8: 0x5e3c30 0x5f6ec0 0x5f6d34, ti 0x12ae910 */ };
    class BiquadFilterHpfNw4fCompatible48k { void* vtable; /* 0x12ae938: 0x5e3c30 0x5f6ec4 0x5f6d78, ti 0x12ae950 */ };
    class BiquadFilterBpf512Nw4fCompatible48k { void* vtable; /* 0x12ae978: 0x5e3c30 0x5f6ec8 0x5f6dbc, ti 0x12ae990 */ };
    class BiquadFilterBpf1024Nw4fCompatible48k { void* vtable; /* 0x12ae9b8: 0x5e3c30 0x5f6ecc 0x5f6e0c, ti 0x12ae9d0 */ };
    class BiquadFilterBpf2048Nw4fCompatible48k { void* vtable; /* 0x12ae9f8: 0x5e3c30 0x5f6ed0 0x5f6e5c, ti 0x12aea10 */ };
}
