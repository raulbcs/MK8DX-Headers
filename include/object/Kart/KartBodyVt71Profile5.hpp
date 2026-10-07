#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object
{
    // KartBodyVt71Profile5 — behavioral-profile name in the KartBodyVt71
    // family.
    // Profile = the set of band slots 0x80/0x88/0x90/0x98/0xa0 a member overrides
    // vs the family base 0x11bb5c0 (slot-diff analysis); per-slot semantics are
    // documented in KartBodyVt71.hpp. No layout beyond the base is implied: the
    // per-combo behavior lives in each member's vtable, not in new fields.
    //
    // All addresses are dump-relative VMAs (runtime = +0x7100000000).
    // alloc=none: no alloc call adjacent to the construction site (in-place or other alloc path).
    //
    // Band overrides: 0x80, 0xa0.
    // Covers 39 of the 665 family vtables; member vtable sizes n=71..75.
    // Other diff slots (members x count):
    //      0x18 x39 0x1c0 x39 0x28 x38 0xb8 x38 0x1e0 x12 0x198 x8 0x30 x3 0x170 x2 0x10 x1
    //     0xf0 x1 0x110 x1 0x138 x1 0x158 x1 0x1b0 x1
    // MI offset-to-top: none (no secondary base in this profile).
    //
    // Members (39) — vptr n cell site ctor_fn alloc:
    // - 0x11bc028 n=71 cell=0x12fd710 site=0x19d56c ctor=0x19d544 alloc=0x208
    // - 0x11c7598 n=71 cell=0x12fe3d0 site=0x1c177c ctor=0x1c1754 alloc=0x68
    // - 0x11e9718 n=71 cell=0x1300750 site=0x21d86c ctor=0x21d844 alloc=0x208
    // - 0x11f82a8 n=71 cell=0x13012d8 site=0x23b25c ctor=0x23a7b4 alloc=none
    // - 0x11ff370 n=71 cell=0x1301818 site=0x24f3ac ctor=0x24f384 alloc=0x240
    // - 0x12031d0 n=71 cell=0x1301ae0 site=0x258150 ctor=0x257f48 alloc=0x68
    // - 0x120fca0 n=71 cell=0x1302c10 site=0x285cbc ctor=0x285c94 alloc=none
    // - 0x1211ca8 n=72 cell=0x1302de0 site=0x28bf20 ctor=0x28b274 alloc=none
    // - 0x12122d0 n=72 cell=0x1302dc8 site=0x28bddc ctor=0x28b274 alloc=none
    // - 0x12125e8 n=72 cell=0x1302dd0 site=0x28be48 ctor=0x28b274 alloc=none
    // - 0x1212900 n=72 cell=0x1302dd8 site=0x28beb4 ctor=0x28b274 alloc=none
    // - 0x1212c18 n=72 cell=0x1302de8 site=0x28bf8c ctor=0x28b274 alloc=none
    // - 0x1212f30 n=72 cell=0x1302df0 site=0x28bff8 ctor=0x28b274 alloc=none
    // - 0x12156a0 n=71 cell=0x1303080 site=0x2913c0 ctor=0x29107c alloc=0x248
    // - 0x121aa30 n=73 cell=0x13036c0 site=0x2ac200 ctor=0x2ac12c alloc=0x238
    // - 0x121ad50 n=73 cell=0x13036b8 site=0x2ac18c ctor=0x2ac12c alloc=0x238
    // - 0x1222048 n=71 cell=0x1303d58 site=0x2974d0 ctor=0x2974a8 alloc=none
    // - 0x12392c0 n=71 cell=0x1305228 site=0x312cec ctor=0x3122c8 alloc=none
    // - 0x123a3e8 n=72 cell=0x13052d0 site=0x315bbc ctor=0x315b94 alloc=none
    // - 0x123a700 n=72 cell=0x13052d8 site=0x315c28 ctor=0x315c00 alloc=none
    // - 0x12401c8 n=72 cell=0x1305800 site=0x324cf0 ctor=0x324cc8 alloc=none
    // - 0x12404e0 n=72 cell=0x1305818 site=0x324e10 ctor=0x324de8 alloc=none
    // - 0x12407f8 n=72 cell=0x1305808 site=0x324d50 ctor=0x324d28 alloc=none
    // - 0x1240b10 n=72 cell=0x1305810 site=0x324db0 ctor=0x324d88 alloc=none
    // - 0x1240e28 n=72 cell=0x1305820 site=0x324e80 ctor=0x324e58 alloc=none
    // - 0x1241140 n=72 cell=0x1305828 site=0x324ef0 ctor=0x324ec8 alloc=none
    // - 0x1241458 n=72 cell=0x1305830 site=0x324f60 ctor=0x324f38 alloc=none
    // - 0x1241770 n=72 cell=0x1305838 site=0x324fd4 ctor=0x324fac alloc=none
    // - 0x1241a88 n=72 cell=0x1305840 site=0x325048 ctor=0x325020 alloc=none
    // - 0x1241da0 n=72 cell=0x1305848 site=0x3250a8 ctor=0x325080 alloc=none
    // - 0x12420b8 n=72 cell=0x1305850 site=0x325108 ctor=0x3250e0 alloc=none
    // - 0x12522c8 n=71 cell=0x13066a8 site=0x354d80 ctor=0x354d58 alloc=none
    // - 0x12525d8 n=71 cell=0x13066b0 site=0x354dec ctor=0x354dc4 alloc=none
    // - 0x1253c20 n=75 cell=0x13068a8 site=0x360bd4 ctor=0x360bac alloc=none
    // - 0x1253f50 n=75 cell=0x13068b0 site=0x360c40 ctor=0x360c18 alloc=none
    // - 0x1254280 n=75 cell=0x13068b8 site=0x360cac ctor=0x360c84 alloc=none
    // - 0x12548c0 n=71 cell=0x1306908 site=0x361238 ctor=0x361210 alloc=none
    // - 0x12562d0 n=71 cell=0x1306958 site=0x362010 ctor=0x361fe8 alloc=0x240
    // - 0x12565e0 n=71 cell=0x1306960 site=0x362070 ctor=0x362048 alloc=0x240
    class KartBodyVt71Profile5 : public KartBodyVt71
    {
    };
}

// Naming closure: the 665 family members are per kart+driver combination variants (shared ctors, vtable passed as argument); semantic per-combo names need the combination dictionary and are not derivable from the binary alone. Address-anchored name retained.
