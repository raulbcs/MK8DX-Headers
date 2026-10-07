#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object
{
    // KartBodyVt71Profile24 — behavioral-profile name in the KartBodyVt71
    // family.
    // Profile = the set of band slots 0x80/0x88/0x90/0x98/0xa0 a member overrides
    // vs the family base 0x11bb5c0 (slot-diff analysis); per-slot semantics are
    // documented in KartBodyVt71.hpp. No layout beyond the base is implied: the
    // per-combo behavior lives in each member's vtable, not in new fields.
    //
    // All addresses are dump-relative VMAs (runtime = +0x7100000000).
    // alloc=none: no alloc call adjacent to the construction site (in-place or other alloc path).
    //
    // Band overrides: 0x80, 0x88, 0x98, 0xa0.
    // Covers 2 of the 665 family vtables; member vtable sizes n=72..73.
    // Other diff slots (members x count):
    //      0x18 x2 0x1c0 x2 0x28 x1 0xb8 x1 0x1b0 x1
    // MI offset-to-top: none (no secondary base in this profile).
    //
    // Members (2) — vptr n cell site ctor_fn alloc:
    // - 0x11f9f20 n=72 cell=0x13014a8 site=0x245e08 ctor=0x245dcc alloc=none
    // - 0x1203e40 n=73 cell=0x1301bc0 site=0x259390 ctor=0x258f50 alloc=0x208
    class KartBodyVt71Profile24 : public KartBodyVt71
    {
    };
}

// Naming closure: the 665 family members are per kart+driver combination variants (shared ctors, vtable passed as argument); semantic per-combo names need the combination dictionary and are not derivable from the binary alone. Address-anchored name retained.
