#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object {
// KartBodyVt71Profile9 — behavioral-profile name in the KartBodyVt71
// family.
// Profile = the set of band slots 0x80/0x88/0x90/0x98/0xa0 a member overrides
// vs the family base 0x11bb5c0 (slot-diff analysis); per-slot semantics are
// documented in KartBodyVt71.hpp. No layout beyond the base is implied: the
// per-combo behavior lives in each member's vtable, not in new fields.
//
// All addresses are dump-relative VMAs (runtime = +0x7100000000).
// alloc=none: no alloc call adjacent to the construction site (in-place or other alloc path).
//
// Band overrides: 0x80, 0x90, 0x98, 0xa0.
// Covers 19 of the 665 family vtables; member vtable sizes n=72..78.
// Other diff slots (members x count):
//      0x18 x19 0x1c0 x14 0x0 x8 0x8 x8 0xc0 x8 0xf8 x8 0x108 x8 0x28 x5 0xb8 x5 0x1b0 x5
//     0x198 x4 0x1e0 x4 0x10 x2 0x78 x2 0x138 x1 0x148 x1 0x210 x1
// MI offset-to-top: 8 of 19 members carry a secondary base
// (slots 0x0/0x8 differ from the base vtable).
//
// Members (19) — vptr n cell site ctor_fn alloc:
// - 0x11c5960 n=74 cell=0x12fe130 site=0x1bb388 ctor=0x1bb35c alloc=none
// - 0x11c5c88 n=74 cell=0x12fe138 site=0x1bb444 ctor=0x1bb418 alloc=0xe8
// - 0x11c5fb0 n=74 cell=0x12fe140 site=0x1bb500 ctor=0x1bb4d4 alloc=0xe8
// - 0x11c6c68 n=78 cell=0x12fe350 site=0x1c0168 ctor=0x1c00b8 alloc=0x208
// - 0x1203800 n=73 cell=0x1301b10 site=0x25857c ctor=0x25825c alloc=0x230
// - 0x1203b20 n=73 cell=0x1301bb0 site=0x259288 ctor=0x258f50 alloc=0x208
// - 0x1204278 n=73 cell=0x1301ae8 site=0x25820c ctor=0x257f48 alloc=0x218
// - 0x1204e08 n=73 cell=0x1301af8 site=0x258360 ctor=0x25825c alloc=0x218
// - 0x1205128 n=73 cell=0x1301b00 site=0x258414 ctor=0x25825c alloc=0x218
// - 0x121b470 n=72 cell=0x1303798 site=0x2ae648 ctor=0x2ae2cc alloc=0x260
// - 0x121b788 n=72 cell=0x13037a0 site=0x2ae714 ctor=0x2ae2cc alloc=0x260
// - 0x121baa0 n=72 cell=0x13037a8 site=0x2ae7e0 ctor=0x2ae2cc alloc=0x260
// - 0x1232128 n=76 cell=0x1304c78 site=0x2fb1d8 ctor=0x2fb070 alloc=0x230
// - 0x1232460 n=76 cell=0x1304c90 site=0x2fb2d4 ctor=0x2fb070 alloc=0x230
// - 0x1232798 n=76 cell=0x1304c88 site=0x2fb288 ctor=0x2fb070 alloc=0x230
// - 0x1232ad0 n=76 cell=0x1304c80 site=0x2fb214 ctor=0x2fb070 alloc=0x230
// - 0x1232e08 n=76 cell=0x1304c70 site=0x2fb128 ctor=0x2fb070 alloc=0x248
// - 0x1258678 n=73 cell=0x1306bb8 site=0x36d1d4 ctor=0x36d1ac alloc=0x298
// - 0x1258998 n=73 cell=0x1306bd0 site=0x36dc00 ctor=0x36dbd8 alloc=0x220
class KartBodyVt71Profile9 : public KartBodyVt71 {
};
}  // namespace object

// Naming closure: the 665 family members are per kart+driver combination variants (shared ctors, vtable passed as argument); semantic per-combo names need the combination dictionary and are not derivable from the binary alone. Address-anchored name retained.
