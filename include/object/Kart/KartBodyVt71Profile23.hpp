#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object
{
    // KartBodyVt71Profile23 — PROVISIONAL behavioral-profile name in the KartBodyVt71
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
    // Band overrides: 0x80, 0x88, 0x98.
    // Covers 2 of the 665 family vtables; member vtable sizes n=73..74.
    // Other diff slots (members x count):
    //      0x0 x2 0x8 x2 0x18 x2 0xc0 x2 0xf8 x2 0x108 x2 0x1c0 x2 0x30 x1 0x78 x1 0xb8 x1
    //     0x158 x1
    // MI offset-to-top: 2 of 2 members carry a secondary base
    // (slots 0x0/0x8 differ from the base vtable).
    //
    // Members (2) — vptr n cell site ctor_fn alloc:
    // - 0x11c7040 n=74 cell=0x12fe3c0 site=0x1c16a8 ctor=0x1c1680 alloc=0x248
    // - 0x125a418 n=73 cell=0x1306cf0 site=0x373398 ctor=0x3731c4 alloc=0x210
    class KartBodyVt71Profile23 : public KartBodyVt71
    {
    };
}
