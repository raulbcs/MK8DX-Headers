#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object
{
    // KartBodyVt71Profile21 — behavioral-profile name in the KartBodyVt71
    // family.
    // Profile = the set of band slots 0x80/0x88/0x90/0x98/0xa0 a member overrides
    // vs the family base 0x11bb5c0 (slot-diff analysis); per-slot semantics are
    // documented in KartBodyVt71.hpp. No layout beyond the base is implied: the
    // per-combo behavior lives in each member's vtable, not in new fields.
    //
    // All addresses are dump-relative VMAs (runtime = +0x7100000000).
    // alloc=none: no alloc call adjacent to the construction site (in-place or other alloc path).
    //
    // Band overrides: 0x90.
    // Covers 4 of the 665 family vtables; member vtable sizes n=71..71.
    // Other diff slots (members x count):
    //      0x18 x4 0x1c0 x3 0xb8 x1
    // MI offset-to-top: none (no secondary base in this profile).
    //
    // Members (4) — vptr n cell site ctor_fn alloc:
    // - 0x11bbbe0 n=71 cell=0x1310568 site=0x80995c ctor=0x809934 alloc=none
    // - 0x11d27e8 n=71 cell=0x12ff108 site=0x1e0eec ctor=0x1e0ec4 alloc=none
    // - 0x11d2af8 n=71 cell=0x12ff110 site=0x1e1060 ctor=0x1e0f24 alloc=none
    // - 0x11d2e08 n=71 cell=0x12ff118 site=0x1e11d4 ctor=0x1e1098 alloc=none
    class KartBodyVt71Profile21 : public KartBodyVt71
    {
    };
}

// Naming closure: the 665 family members are per kart+driver combination variants (shared ctors, vtable passed as argument); semantic per-combo names need the combination dictionary and are not derivable from the binary alone. Address-anchored name retained.
