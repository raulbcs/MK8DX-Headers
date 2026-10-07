#pragma once

#include <cstdint>

// RaceDirectorBase38 — PROVISIONAL vtable-anchored name. 0x38 POD base of
// the small far-family classes: ctor 0x71007b976c (zeroes 0x10..0x37 only,
// NO Actor/sead chain call) stores vptr cell 0x130fea0 (+0x10 -> vtable
// 0x12c55b8). Every far-family class whose ctor calls 0x7b976c derives
// this: RaceDirectorManagerBase (0x7b98bc), RaceDirectorPlayerSetBase
// (0x7c2938), RaceDirectorPlayerBase (0x7c2a90), RaceListItemG's base
// (0x7ee400), and the three singletons 0x12601e8 (0x3995d4), 0x12c5758
// (0x7b9a2c), 0x12ca260 (0x7fd3d4).
// Baptism audit: 0x38 POD base with no vtable slots beyond slot 0; identity is purely structural (shared ctor 0x7b976c). Nothing in-binary to baptize.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
 class RaceDirectorBase38
 {
 public:
 void* vtable; //0x00 — vtable ptr (cell 0x130fea0)
 uint8_t pad08[8]; //0x08 — untouched by ctor
 uint64_t mZero10; //0x10 — ctor zero
 uint64_t mZero18; //0x18 — ctor zero
 uint64_t mZero20; //0x20 — ctor zero
 uint64_t mZero28; //0x28 — ctor zero
 uint64_t mZero30; //0x30 — ctor zero
 // (0x38 total)
 };
}
