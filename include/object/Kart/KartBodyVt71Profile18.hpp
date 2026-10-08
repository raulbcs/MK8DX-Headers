#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object {
// KartBodyVt71Profile18 — behavioral-profile name in the KartBodyVt71
// family.
// Profile = the set of band slots 0x80/0x88/0x90/0x98/0xa0 a member overrides
// vs the family base 0x11bb5c0 (slot-diff analysis); per-slot semantics are
// documented in KartBodyVt71.hpp. No layout beyond the base is implied: the
// per-combo behavior lives in each member's vtable, not in new fields.
//
// All addresses are dump-relative VMAs (runtime = +0x7100000000).
// alloc=none: no alloc call adjacent to the construction site (in-place or other alloc path).
//
// Band overrides: 0x88, 0x90, 0x98.
// Covers 7 of the 665 family vtables; member vtable sizes n=71..73.
// Other diff slots (members x count):
//      0x18 x7 0x10 x6 0x1c0 x6 0x0 x4 0x8 x4 0xc0 x4 0xf8 x4 0x108 x4 0x1b0 x3 0x168 x2
//     0x138 x1 0x148 x1 0x1e0 x1
// MI offset-to-top: 4 of 7 members carry a secondary base
// (slots 0x0/0x8 differ from the base vtable).
//
// Members (7) — vptr n cell site ctor_fn alloc:
// - 0x12108e0 n=72 cell=0x1302c70 site=0x287988 ctor=0x287964 alloc=0x1a18
// - 0x1224050 n=73 cell=0x1304020 site=0x2d4018 ctor=0x2d3ff4 alloc=0x2b8
// - 0x1237420 n=71 cell=0x1305078 site=0x30ac94 ctor=0x30aae0 alloc=0x2d0
// - 0x1237a80 n=71 cell=0x1305080 site=0x30ad38 ctor=0x30aae0 alloc=0x2d0
// - 0x123ed40 n=73 cell=0x1305678 site=0x32016c ctor=0x32011c alloc=0x250
// - 0x12478a8 n=73 cell=0x1305ee8 site=0x33a94c ctor=0x33a924 alloc=0x208
// - 0x124a270 n=73 cell=0x13061c0 site=0x343a04 ctor=0x3439e8 alloc=0x278
class KartBodyVt71Profile18 : public KartBodyVt71 {
};
}  // namespace object

// Naming closure: the 665 family members are per kart+driver combination variants (shared ctors, vtable passed as argument); semantic per-combo names need the combination dictionary and are not derivable from the binary alone. Address-anchored name retained.
