#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object {
// KartBodyVt71Profile14 — behavioral-profile name in the KartBodyVt71
// family.
// Profile = the set of band slots 0x80/0x88/0x90/0x98/0xa0 a member overrides
// vs the family base 0x11bb5c0 (slot-diff analysis); per-slot semantics are
// documented in KartBodyVt71.hpp. No layout beyond the base is implied: the
// per-combo behavior lives in each member's vtable, not in new fields.
//
// All addresses are dump-relative VMAs (runtime = +0x7100000000).
// alloc=none: no alloc call adjacent to the construction site (in-place or other alloc path).
//
// Band overrides: 0x80, 0x98.
// Covers 13 of the 665 family vtables; member vtable sizes n=73..73.
// Other diff slots (members x count):
//      0x18 x13 0xc0 x13 0x108 x13 0x1c0 x13 0x0 x12 0x8 x12 0xf8 x12 0x10 x10 0x198 x9
//     0x158 x7 0xf0 x6 0xd0 x3 0x78 x2 0x100 x2 0x148 x2
// MI offset-to-top: 12 of 13 members carry a secondary base
// (slots 0x0/0x8 differ from the base vtable).
//
// Members (13) — vptr n cell site ctor_fn alloc:
// - 0x11bc670 n=73 cell=0x12fd758 site=0x19df84 ctor=0x19df5c alloc=0x270
// - 0x11bccb8 n=73 cell=0x12fd760 site=0x19e080 ctor=0x19e018 alloc=0x270
// - 0x11bd2f8 n=73 cell=0x12fd770 site=0x19e1d0 ctor=0x19e168 alloc=0x270
// - 0x11bd648 n=73 cell=0x12fd818 site=0x19fb24 ctor=0x19f7b0 alloc=0x270
// - 0x11bd968 n=73 cell=0x12fd820 site=0x19fb78 ctor=0x19f7b0 alloc=0x278
// - 0x11bdc88 n=73 cell=0x12fd848 site=0x1a0074 ctor=0x19f7b0 alloc=0x278
// - 0x11c3f08 n=73 cell=0x12fdf28 site=0x1b4778 ctor=0x1b4500 alloc=0x250
// - 0x11c6948 n=73 cell=0x12fe338 site=0x1c0078 ctor=0x1c0050 alloc=0x208
// - 0x11e6360 n=73 cell=0x1300508 site=0x214d60 ctor=0x214d38 alloc=0x270
// - 0x1224718 n=73 cell=0x1304070 site=0x2d5448 ctor=0x2d5420 alloc=0x240
// - 0x1242e60 n=73 cell=0x13059e8 site=0x326ca0 ctor=0x326c74 alloc=0x248
// - 0x124f438 n=73 cell=0x13064f8 site=0x350d90 ctor=0x350d40 alloc=0x240
// - 0x1251648 n=73 cell=0x13065f8 site=0x351f48 ctor=0x351f20 alloc=0x250
class KartBodyVt71Profile14 : public KartBodyVt71 {
};
}  // namespace object

// Naming closure: the 665 family members are per kart+driver combination variants (shared ctors, vtable passed as argument); semantic per-combo names need the combination dictionary and are not derivable from the binary alone. Address-anchored name retained.
