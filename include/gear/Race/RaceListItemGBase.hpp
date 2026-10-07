#pragma once

#include <cstdint>

#include "gear/Race/RaceDirectorBase38.hpp"

// RaceListItemGBase — PROVISIONAL vtable-anchored name. Vtable 0x12c8f68
// (GOT cell 0x1310240), far-family gap member reclassified: the PRIMARY
// BASE of RaceListItemG, not a member. Ctor 0x71007ee400 (called at
// offset 0 by the RaceListItemG ctor 0x710010adec; it runs ctor
// 0x71007b976c = RaceDirectorBase38 first and stores this vptr; the
// derived ctor then overwrites the vptr with its own, cell 0x12fcfe8).
// Extent 0x9b0 — the derived ctor starts its own fields at 0x9b0 (memset
// 0x48 + the -1/ptr block), so the base is 0x9b0 of the 0xa10 total.
// (The out-of-line copy at 0x878f94 belongs to RaceDirectorVt10's graph,
// not to this class.)
// Baptism audit: 0x9b0 base-subobject gap member (ctor 0x7ee400); identity from the derived ctor only.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
 class RaceListItemGBase : public RaceDirectorBase38
 {
 public:
 uint32_t mField38; //0x38 — ctor zero
 uint8_t pad3c[4]; //0x3c — unproven padding
 uint64_t mZero40; //0x40 — ctor zero
 uint64_t mZero48; //0x48 — ctor zero
 int32_t mFfff50; //0x50 — ctor sets -1
 uint8_t pad54[4]; //0x54 — unproven padding
 uint64_t mZero58; //0x58 — ctor zero
 uint64_t mZero60; //0x60 — ctor zero
 uint64_t mZero68; //0x68 — ctor zero
 void* mSub70; //0x70 — embedded member (secondary vptr, cell
 // 0x12fada0; ctor 0x710061cc48; field 0x80
 // set to 0x80 by the ctor)
 void* mNode78; //0x78 — self node head (set to this+0x84)
 uint8_t pad80[4]; //0x80 — unproven padding
 uint8_t mNode84[0x24]; //0x84 — node body reached by the back-ptr
 uint8_t padA8[0x60]; //0xa8 — (to 0x108)
 uint32_t m108; //0x108 — written by the DERIVED ctor
 // (0x80000008; the ctor's u64 store covers
 // 0x108..0x10f = this + m10c)
 uint32_t m10c; //0x10c — derived ctor sets 0xc
 uint32_t m110; //0x110 — derived ctor sets 4
 uint8_t pad114[4]; //0x114 — unproven padding
 uint8_t mPad118[0x898]; //0x118 — untouched by the ctors (to 0x9b0)
 // (0x9b0 total)
 };
}
