#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object {
// KartBodyVt71Profile7 — behavioral-profile name in the KartBodyVt71
// family.
// Profile = the set of band slots 0x80/0x88/0x90/0x98/0xa0 a member overrides
// vs the family base 0x11bb5c0 (slot-diff analysis); per-slot semantics are
// documented in KartBodyVt71.hpp. No layout beyond the base is implied: the
// per-combo behavior lives in each member's vtable, not in new fields.
//
// All addresses are dump-relative VMAs (runtime = +0x7100000000).
// alloc=none: no alloc call adjacent to the construction site (in-place or other alloc path).
//
// Band overrides: 0x80, 0x98, 0xa0.
// Covers 26 of the 665 family vtables; member vtable sizes n=71..74.
// Other diff slots (members x count):
//      0x18 x26 0x28 x25 0xb8 x25 0x1c0 x25 0x1e0 x20 0x1b0 x2 0x10 x1 0xd0 x1 0x220 x1
// MI offset-to-top: none (no secondary base in this profile).
//
// Members (26) — vptr n cell site ctor_fn alloc:
// - 0x11ccd80 n=73 cell=0x12fea18 site=0x1cdb5c ctor=0x1cd610 alloc=none
// - 0x11cd1b8 n=73 cell=0x12fea28 site=0x1cdff0 ctor=0x1cdbe0 alloc=none
// - 0x11ce308 n=71 cell=0x12febb8 site=0x1d52b4 ctor=0x1d528c alloc=0x230
// - 0x1202448 n=73 cell=0x1301ad0 site=0x25809c ctor=0x257f48 alloc=0x68
// - 0x1202880 n=73 cell=0x1301ad8 site=0x2580e8 ctor=0x257f48 alloc=0x68
// - 0x1202ba0 n=73 cell=0x1301b98 site=0x259058 ctor=0x258f50 alloc=none
// - 0x12034e0 n=73 cell=0x1301be0 site=0x25b5f0 ctor=0x25b580 alloc=none
// - 0x1204598 n=73 cell=0x1301ba8 site=0x2591c0 ctor=0x258f50 alloc=0x218
// - 0x1204ae8 n=73 cell=0x1301af0 site=0x2582b8 ctor=0x25825c alloc=0x218
// - 0x1205448 n=73 cell=0x1301b08 site=0x2584c4 ctor=0x25825c alloc=0x218
// - 0x1205880 n=73 cell=0x1301b58 site=0x258c78 ctor=0x25825c alloc=none
// - 0x1205ba0 n=73 cell=0x1301b68 site=0x258dd8 ctor=0x25825c alloc=none
// - 0x1205ec0 n=73 cell=0x1301b18 site=0x258648 ctor=0x25825c alloc=0x230
// - 0x12061e0 n=73 cell=0x1301ba0 site=0x259110 ctor=0x258f50 alloc=none
// - 0x1206500 n=73 cell=0x12ff660 site=0x1ebe7c ctor=0x1ebe28 alloc=none
// - 0x1206820 n=73 cell=0x1301b70 site=0x258e88 ctor=0x25825c alloc=none
// - 0x1206e88 n=73 cell=0x1301b20 site=0x2587a8 ctor=0x25825c alloc=0x230
// - 0x12071a8 n=74 cell=0x1301b28 site=0x258858 ctor=0x25825c alloc=0x230
// - 0x12074d0 n=74 cell=0x1301b30 site=0x258908 ctor=0x25825c alloc=0x230
// - 0x12077f8 n=74 cell=0x1301b38 site=0x2589b8 ctor=0x25825c alloc=none
// - 0x1207b20 n=74 cell=0x1301b40 site=0x258a68 ctor=0x25825c alloc=none
// - 0x1207e48 n=74 cell=0x1301b48 site=0x258b18 ctor=0x25825c alloc=none
// - 0x1208170 n=74 cell=0x1301b50 site=0x258bc8 ctor=0x25825c alloc=none
// - 0x1208498 n=73 cell=0x1301b60 site=0x258d28 ctor=0x25825c alloc=none
// - 0x1208c18 n=73 cell=0x1301bc8 site=0x259488 ctor=0x259410 alloc=0xd8
// - 0x1208f38 n=73 cell=0x1301bd0 site=0x259598 ctor=0x259520 alloc=0x218
class KartBodyVt71Profile7 : public KartBodyVt71 {
};
}  // namespace object

// Naming closure: the 665 family members are per kart+driver combination variants (shared ctors, vtable passed as argument); semantic per-combo names need the combination dictionary and are not derivable from the binary alone. Address-anchored name retained.
