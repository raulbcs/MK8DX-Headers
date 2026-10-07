#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object
{
    // KartBodyVt71Profile15 — PROVISIONAL behavioral-profile name in the KartBodyVt71
    // family.
    // Profile = the set of band slots 0x80/0x88/0x90/0x98/0xa0 a member overrides
    // vs the family base 0x11bb5c0 (census slot_diff); per-slot semantics are
    // documented in KartBodyVt71.hpp. No layout beyond the base is implied: the
    // per-combo behavior lives in each member's vtable, not in new fields.
    //
    // All addresses are census VMA (dump-relative; runtime = +0x7100000000).
    // alloc=none: no alloc call adjacent to the construction site was found by
    // the census (in-place or other alloc path).
    //
    // Band overrides: 0x80.
    // Covers 11 of the 665 family vtables; member vtable sizes n=71..71.
    // Other diff slots (members x count):
    //      0x18 x11 0x1c0 x11 0x198 x4 0x10 x1 0x100 x1 0x148 x1 0x158 x1 0x1e0 x1
    // MI offset-to-top: none (no secondary base in this profile).
    //
    // Members (11) — vptr n cell site ctor_fn alloc:
    // - 0x11c9340 n=71 cell=0x12fe608 site=0x1c7418 ctor=0x1c73ec alloc=none
    // - 0x11c9650 n=71 cell=0x12fe610 site=0x1c752c ctor=0x1c7504 alloc=none
    // - 0x11cac20 n=71 cell=0x12fe6d0 site=0x1c933c ctor=0x1c9314 alloc=none
    // - 0x11caf30 n=71 cell=0x12fe6e8 site=0x1c943c ctor=0x1c93b4 alloc=none
    // - 0x11cbc68 n=71 cell=0x12fe8e0 site=0x1cbb2c ctor=0x1cba2c alloc=0x210
    // - 0x11cc1a8 n=71 cell=0x12fe8e8 site=0x1c5e8c ctor=0x1c5dc8 alloc=0x2b8
    // - 0x11cc4b8 n=71 cell=0x12fe8f0 site=0x1cbcf8 ctor=0x1cba2c alloc=0x210
    // - 0x11cc7c8 n=71 cell=0x12fe8f8 site=0x1cbdb8 ctor=0x1cba2c alloc=0x210
    // - 0x121c428 n=71 cell=0x13037f0 site=0x2afebc ctor=0x2afbb8 alloc=0x208
    // - 0x124fa78 n=71 cell=0x13064f0 site=0x350d0c ctor=0x350ce4 alloc=0x240
    // - 0x12500a8 n=71 cell=0x1306530 site=0x350fdc ctor=0x350fb4 alloc=0x240
    class KartBodyVt71Profile15 : public KartBodyVt71
    {
    };
}
